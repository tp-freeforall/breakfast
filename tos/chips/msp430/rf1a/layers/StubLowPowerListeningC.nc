module StubLowPowerListeningC {
  provides {
    interface LowPowerListening;
  }
} implementation {
  uint16_t local_wakeup_interval_ms;
  uint16_t remote_wakeup_interval_ms;

  command void LowPowerListening.setLocalWakeupInterval(uint16_t intervalMs) { local_wakeup_interval_ms = intervalMs; }
  command uint16_t LowPowerListening.getLocalWakeupInterval() { return local_wakeup_interval_ms; }
  command void LowPowerListening.setRemoteWakeupInterval(message_t *msg, uint16_t intervalMs) { remote_wakeup_interval_ms = intervalMs; }
  command uint16_t LowPowerListening.getRemoteWakeupInterval(message_t *msg) { return remote_wakeup_interval_ms; }
}
