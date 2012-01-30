interface DelayedSend{
  async event void sendReady();
  async command void completeSend();
}
