interface HplMsp430UsciA{
  async command uint8_t getAbctl();
  async command void setAbctl();
  async command uint8_t getIrtctl();
  async command void setIrtctrl();
  async command uint8_t getMctl();
  async command void setMctl();
}
