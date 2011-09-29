module AppendFlashP
{
  uses {
    interface Boot;
    interface LogWrite;
    interface LogRead;
    interface Leds;
  }
}

implementation
{
  typedef nx_struct LogEntry {
    nx_uint8_t led;
  } LogEntry;
  
  LogEntry entry;
  
  event void Boot.booted()
  {
    entry.led = 2;
    if (call LogWrite.append(&entry, sizeof(LogEntry)) == SUCCESS) {
      call Leds.led1On();
    } else {
      call Leds.led0On();
    }
  }
  
  event void LogRead.readDone(void* buf, 
                              storage_len_t len, 
                              error_t error)
  {
    if (buf == &entry && len == sizeof(LogEntry)) {
      switch (entry.led) {
        case 0:
          call Leds.led0On();
          break;
        case 1:
          call Leds.led1On();
          break;
        case 2:
          call Leds.led2On();
          break;
      }
    }
  }
  event void LogRead.seekDone(error_t error) {}
  
  event void LogWrite.syncDone(error_t error) {}
  
  event void LogWrite.eraseDone(error_t error) {}
  event void LogWrite.appendDone(void* buf,
                                 storage_len_t len,
                                 bool recordsLost,
                                 error_t error)
  {
    call Leds.led1Off();
    if (call LogRead.read(&entry, sizeof(LogEntry)) != SUCCESS) {
      call Leds.led0On();
    }
  }
}
