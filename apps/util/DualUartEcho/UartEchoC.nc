

configuration UartEchoC {

} implementation {
  components UartEchoP;

  components MainC;
  UartEchoP.Boot -> MainC;

  components LedsC;
  UartEchoP.Leds -> LedsC;

  /* Serial interface */
  components StdOutC;
  UartEchoP.SerialControl -> StdOutC;
  UartEchoP.StdOut -> StdOutC;

  components PlatformSerial0C;
  UartEchoP.Resource -> PlatformSerial0C;
  UartEchoP.SecondUartStream -> PlatformSerial0C;


}
