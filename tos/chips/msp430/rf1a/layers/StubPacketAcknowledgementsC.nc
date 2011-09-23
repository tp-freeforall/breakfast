module StubPacketAcknowledgementsC {
  provides {
    interface PacketAcknowledgements;
  }
} implementation {
  async command error_t PacketAcknowledgements.requestAck (message_t* msg) { return FAIL; }
  async command error_t PacketAcknowledgements.noAck (message_t* msg) { return FAIL; }
  async command bool PacketAcknowledgements.wasAcked (message_t* msg) { return FALSE; }
}
