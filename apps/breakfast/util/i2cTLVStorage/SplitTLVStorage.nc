interface SplitTLVStorage{
  command error_t loadTLVStorage(void* tlvs);
  event void loaded(error_t error, void* tlvs);

  command error_t persistTLVStorage(void* tlvs);
  event void persisted(error_t error, void* tlvs);
}
