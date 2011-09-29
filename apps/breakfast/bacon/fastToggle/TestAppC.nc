configuration TestAppC{
} implementation {
  components MainC;
  components TestP;

  TestP.Boot -> MainC.Boot;
  components UserButtonC;
  TestP.Notify -> UserButtonC;
  
  components BusyWaitMicroC;
  TestP.BusyWait -> BusyWaitMicroC;
}
