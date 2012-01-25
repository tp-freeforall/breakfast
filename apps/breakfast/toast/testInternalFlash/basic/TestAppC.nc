configuration TestAppC{
} implementation {
  components MainC;
  components TestP;
  components SerialPrintfC;

  TestP.Boot -> MainC.Boot;
}
