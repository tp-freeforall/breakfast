interface RegisterUser{
  command error_t write(uint16_t slaveAddr, uint8_t pos, uint8_t len, 
    register_packet_t* pkt);
  event void writeDone(error_t error, uint16_t slaveAddr, uint8_t pos,
    uint8_t len, register_packet_t* pkt);

  command error_t read(uint16_t slaveAddr, uint8_t pos,
    register_packet_t* pkt, uint8_t len);
  event void readDone(error_t error, uint16_t slaveAddr, uint8_t pos, 
    register_packet_t* pkt, uint8_t len);
  
}
