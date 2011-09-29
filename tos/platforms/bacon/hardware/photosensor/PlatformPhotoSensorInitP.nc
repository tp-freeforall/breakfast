module PlatformPhotoSensorInitP {
  provides {
    interface Init;
  }
  uses {
    interface HplMsp430GeneralIO as PhotoSensorIO;
  }
} implementation {
  command error_t Init.init() {
    call PhotoSensorIO.makeOutput();
    call PhotoSensorIO.clr();
    return SUCCESS;
  }
}
