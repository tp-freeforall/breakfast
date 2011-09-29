interface DelayedSendRf1aPhysical{
  async event void sendReady();
  async command void completeSend();
}
