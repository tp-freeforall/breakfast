#include "I2CADCReader.h"
interface I2CADCReaderMaster{
  command adc_reader_pkt_t* getSettings(i2c_message_t* msg);
  command adc_response_t* getResults(i2c_message_t* msg);

  command error_t sample(uint16_t slaveAddr, i2c_message_t* msg);
  event i2c_message_t* sampleDone(error_t error, uint16_t slaveAddr,
    i2c_message_t* cmdMsg, i2c_message_t* responseMsg, adc_response_t*
    response);
}
