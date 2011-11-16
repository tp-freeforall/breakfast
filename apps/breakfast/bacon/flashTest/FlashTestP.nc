#include <stdio.h>
#include "decodeError.h"
module FlashTestP
{
  uses {
    interface Boot;
    interface LogWrite;
    interface LogRead;
    interface Leds;
    interface StdControl as UartCtl;
    interface UartStream;
  }
}

implementation
{
  uint8_t buf[BUF_SIZE];
  uint8_t errCount;

  task void formatTask();
  task void verifyTask();
  task void startVerifyTask();
  task void appendTask();
  task void startAppendTask();
  uint16_t actionCount;

  enum {
    S_IDLE = 0x00,
    S_APPENDING = 0x01,
    S_ERASING = 0x02,
    S_VERIFYING_WRITTEN = 0x03,
  };
  uint8_t state = S_IDLE;

  event void Boot.booted()
  {
    call UartCtl.start();
    printf("Flash Test\n\r");
  }

  async event void UartStream.receivedByte(uint8_t byte){
    if (state != S_IDLE){
      printf(".");
      return;
    }
    switch(byte){
      case 'q':
        WDTCTL = 0;
        break;
      case 'f':
        state = S_ERASING;
        post formatTask();
        break;
      case 'a':
        state = S_APPENDING;
        post startAppendTask();
        break;
      case 'v':
        state = S_VERIFYING_WRITTEN;
        post startVerifyTask();
        break;
      case '\r':
        printf("\n\r");
        break;
      default:
        printf("%c", byte);
    }
  }

  task void startVerifyTask(){
    error_t err;
    actionCount = 0;
    memset(buf, BUF_SIZE, 0x00);
    printf("Seeking...");
    err = call LogRead.seek(SEEK_BEGINNING);
    if (err == SUCCESS){
    } else {
      printf("error (seek): %s\n\r", decodeError(err));
      state = S_IDLE;
    }
  }

  event void LogRead.seekDone(error_t err){
    if (err == SUCCESS){
      //stupid format. is this right?
      printf("OK: position %lx \n\r", call LogRead.currentOffset());
      printf("Start verifying...");
      post verifyTask();
    } else {
      printf("error (seekDone): %s\n\r", decodeError(err));
      state = S_IDLE;
    }
  }

  task void verifyTask(){
    error_t err = call LogRead.read(buf, BUF_SIZE);
    if (err != SUCCESS){
      printf("error (read): %s\n\r", decodeError(err));
      state = S_IDLE;
    }
  }

  event void LogRead.readDone(void* buf_, storage_len_t len, error_t err){
    uint8_t i;
    actionCount++;
    if (actionCount == DOWNSAMPLE){
      actionCount = 0;
      printf(".");
    }
    if (err != SUCCESS){
      printf("error (readDone): %s\n\r", decodeError(err));
      state = S_IDLE;
    } else {
      if (buf_ != buf){
        printf("Expected &buf (%p) got %p\n\r", buf, buf_);
        state = S_IDLE;
      } else if (len < BUF_SIZE){
        printf("done, all is well (expected to read %x read %lx).\n\r", BUF_SIZE, len);
        state = S_IDLE;
      } else {
        for (i = 0; i < BUF_SIZE; i++){
          if (buf[i] != i){
            printf("%x != %x at %lx \n\r", buf[i], i, call LogRead.currentOffset());
            errCount++;
          }
        }
        if (errCount < MAX_ERR_COUNT){
          post verifyTask();
        } else {
          printf("maximum error count exceeded, aborting\n\r");
          state = S_IDLE;
        }
      }
    }
  }

  task void appendTask(){
    error_t err = call LogWrite.append(buf, BUF_SIZE);
    if (err == ESIZE){
      printf("done.\n\r");
      state = S_IDLE;
    } else if (err != SUCCESS){
      printf("error (append): %s\n\r", decodeError(err));
      state = S_IDLE;
    }  
  }

  task void startAppendTask(){
    uint8_t i;
    actionCount = 0;
    printf("Start appending...");
    for (i = 0; i < BUF_SIZE; i++){
      buf[i] = i;
    }
    post appendTask();
  }

  event void LogWrite.appendDone(void* buf_, storage_len_t len, bool recordsLost, error_t error){
    actionCount++;
    if (actionCount == DOWNSAMPLE){
      actionCount = 0;
      printf(".");
    }
    if( error == SUCCESS){
      post appendTask();
    } else if (error == ESIZE){
      printf("log full.\n\r");
      state = S_IDLE;
    } else {
      printf("error (append done): %s\n\r", decodeError(error));
      state = S_IDLE;
    }
  }

  task void formatTask(){
    error_t err = call LogWrite.erase();
    printf("Erase: %x %s\n\r", err, decodeError(err));
    if (err == SUCCESS){
      call Leds.set(2);   // _G_
    } else {
      call Leds.set(7);   // BGR
    }
  }

  event void LogWrite.eraseDone(error_t err)
  {
    printf("EraseDone: %x %s\n\r", err, decodeError(err));
    if (err == SUCCESS) {
      call Leds.set(4);   // B__
    } else {
      call Leds.set(7);   // BGR
    }
    state = S_IDLE;
  }
  
  
  event void LogWrite.syncDone(error_t error) {}
  async event void UartStream.receiveDone(uint8_t* buf_, uint16_t len, error_t err){}
  async event void UartStream.sendDone(uint8_t* buf_, uint16_t len, error_t err){}
}
