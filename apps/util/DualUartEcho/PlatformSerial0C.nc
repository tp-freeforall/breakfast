
configuration PlatformSerial0C {
  
  provides interface UartStream;
  provides interface UartByte;
  provides interface Resource;  
}

implementation {
  
  components new Msp430Uart0C() as UartC;
  UartStream = UartC;  
  UartByte = UartC;
  Resource = UartC;
  
  components TelosSerial0P;
  TelosSerial0P.Msp430UartConfigure <- UartC.Msp430UartConfigure;
  
}
