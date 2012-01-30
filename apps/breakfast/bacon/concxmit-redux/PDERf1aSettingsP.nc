#include "Rf1aConfigure.h"

module PDERf1aSettingsP{
  provides interface Rf1aConfigure;
} implementation{
  const rf1a_config_t cfg = {
    iocfg2:  0x29,   // IOCFG2    GDO2 output pin configuration.
    //?iocfg1 default value?
    iocfg0:  0x06,   // IOCFG0D   GDO0 output pin configuration. Refer to SmartRF® Studio User Manual for detailed pseudo register explanation.
    fifothr: 0x07,   // FIFOTHR   RXFIFO and TXFIFO thresholds.
    //?sync1
    //?sync0
    //?this does get set in sw, right?
    pktlen:  0x3D,    // PKTLEN    Packet length.
    pktctrl1:0x04,   // PKTCTRL1  Packet automation control.
    pktctrl0:0x05,   // PKTCTRL0  Packet automation control.
    //?this does get set in sw, right?
    addr:    0x00,   // ADDR      Device address.
    //?this does get set in sw, right?
    0x00,   // CHANNR    Channel number.
    fsctrl1: 0x0C,   // FSCTRL1   Frequency synthesizer control.
    fsctrl0: 0x00,   // FSCTRL0   Frequency synthesizer control.
    freq2:   0x23,   // FREQ2     Frequency control word, high byte.
    freq1:   0x31,   // FREQ1     Frequency control word, middle byte.
    freq0:   0x3B,   // FREQ0     Frequency control word, low byte.
    mdmcfg4: 0x2D,   // MDMCFG4   Modem configuration.
    mdmcfg3: 0x3B,   // MDMCFG3   Modem configuration.
    mdmcfg2: 0x03,   // MDMCFG2   Modem configuration.
    mdmcfg1: 0x22,   // MDMCFG1   Modem configuration.
    mdmcfg0: 0xF8,   // MDMCFG0   Modem configuration.
    deviatn: 0x62,   // DEVIATN   Modem deviation setting (when FSK modulation is enabled).
    //?mcsm2
    //?mcsm1 
    mcsm0:   0x10,   // MCSM0     Main Radio Control State Machine configuration.
    foccfg:  0x1D,   // FOCCFG    Frequency Offset Compensation Configuration.
    bscfg:   0x1C,   // BSCFG     Bit synchronization Configuration.
    agcctrl2:0xC7,   // AGCCTRL2  AGC control.
    agcctrl1:0x00,   // AGCCTRL1  AGC control.
    agcctrl0:0xB0,   // AGCCTRL0  AGC control.
    //?worevt1
    //?worevt0
    //?worctrl
    frend1:  0xB6,   // FREND1    Front end RX configuration.
    frend0:  0x10,   // FREND0    Front end TX configuration.
    fscal3:  0xEA,   // FSCAL3    Frequency synthesizer calibration.
    fscal2:  0x2A,   // FSCAL2    Frequency synthesizer calibration.
    fscal1:  0x00,   // FSCAL1    Frequency synthesizer calibration.
    fscal0:  0x1F,   // FSCAL0    Frequency synthesizer calibration.
    //?_rcctrl1
    //?_rcctrl0
    fstest:  0x59,   // FSTEST    Frequency synthesizer calibration.
    //?ptest
    //?agctest
    test2:   0x88,   // TEST2     Various test settings.
    test1:   0x31,   // TEST1     Various test settings.
    test0:   0x09,   // TEST0     Various test settings.
    //?patable (just patable0 is used)
  };

  async command const rf1a_config_t* Rf1aConfigure.getConfiguration(){
    return &cfg;
  }

  async command void Rf1aConfigure.preConfigure() { }
  async command void Rf1aConfigure.postConfigure() { }
  async command void Rf1aConfigure.preUnconfigure() { }
  async command void Rf1aConfigure.postUnconfigure() { }

}
