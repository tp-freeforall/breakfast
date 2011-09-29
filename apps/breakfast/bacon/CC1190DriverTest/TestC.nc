configuration TestC{
  
} implementation {
  components MainC;
  components TestP;
  components CC1190C;
  TestP.Boot -> MainC;
  TestP.StdControl -> CC1190C;
  TestP.CC1190 -> CC1190C;
  
}
