module FormatFlashP
{
  uses {
    interface Boot;
    interface LogWrite;
    //interface LogRead;
    interface Leds;
  }
}

implementation
{
  event void Boot.booted()
  {
    if (call LogWrite.erase() == SUCCESS) {
      call Leds.set(2);   // _G_
    } else {
      call Leds.set(7);   // BGR
    }
  }
  
  event void LogWrite.eraseDone(error_t error)
  {
    if (error == SUCCESS) {
      call Leds.set(4);   // B__
    } else {
      call Leds.set(7);   // BGR
    }
  }
  
  //event void LogRead.readDone(void* buf, storage_len_t len, error_t error) {}
  //event void LogRead.seekDone(error_t error) {}
  
  event void LogWrite.syncDone(error_t error) {}
  event void LogWrite.appendDone(void* buf, storage_len_t len, bool recordsLost, error_t error) {}
}
