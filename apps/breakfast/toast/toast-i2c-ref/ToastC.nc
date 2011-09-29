module ToastC @safe()
{
  uses 
  {
    interface Boot;
    interface StdControl as UartControl;
    interface UartStream;
    interface UartByte;

    interface Resource as I2CResource;
//    interface ResourceRequested as I2CResourceRequested;
    interface I2CPacket<TI2CBasicAddr> as I2CBasicAddr;
  }

  provides interface Msp430UsciConfigure;
}
implementation
{
  msp430_usci_config_t msp430_i2c_config;

  uint8_t welcome_string[] = "I2C Test Application\n\r";


  task void transmitTask()
  {
    call UartStream.send(welcome_string,22);
  }
  
  event void Boot.booted() 
  {
    call UartControl.start();

    post transmitTask();    

    call I2CResource.request();

    call I2CBasicAddr.setOwnAddress(0x0042);
    call I2CBasicAddr.enableSlave();
  }

  /***************************************************************************/
  /* I2C Resource                                                             */
  /***************************************************************************/

  uint8_t str_resource_granted[] = "Resource granted\n\r";
  uint8_t str_resource_requested[] = "Resource requested\n\r";
  uint8_t str_resource_requested_immediately[] = "Resource requested immediately\n\r";

  event void I2CResource.granted() 
  {
    call UartStream.send(str_resource_granted, 18);  
  }

//  async event void I2CResourceRequested.requested() 
//  {
//    call UartStream.send(str_resource_requested, 20);  
//  }

//  async event void I2CResourceRequested.immediateRequested() 
//  {
//    call UartStream.send(str_resource_requested_immediately, 32);  
//  }

  async command const msp430_usci_config_t* Msp430UsciConfigure.getConfiguration() {
    return &msp430_i2c_config;
  }

  /***************************************************************************/
  /* I2C                                                                     */
  /***************************************************************************/
  uint8_t str_i2c_read_done_nl[] = "I2C read done\n\r";
  uint8_t str_i2c_read_fail_nl[] = "I2C read fail\n\r";
  uint8_t i2c_length;
  uint8_t i2c_buffer[100];

  async event void I2CBasicAddr.readDone(error_t error, uint16_t addr, uint8_t length, uint8_t* data) 
  {
    if (error == SUCCESS)
    {
//      call UartStream.send(str_i2c_read_done_nl,15);  
      call UartStream.send(data,length);  
    } else {
      call UartStream.send(str_i2c_read_fail_nl,15);  
    }
  }
  
  uint8_t str_i2c_write_done_nl[] = "I2C write done\n\r";
  uint8_t str_i2c_write_fail_nl[] = "I2C write fail\n\r";
  
  async event void I2CBasicAddr.writeDone(error_t error, uint16_t addr, uint8_t length, uint8_t* data) 
  {
    if (error == SUCCESS)
    {
      call UartStream.send(str_i2c_write_done_nl,16);  
    } else {
      call UartStream.send(str_i2c_write_fail_nl,16);  
    }
  }

  uint8_t str_i2c_slave_receive_nl[] = "I2C slave receive\n\r";
  uint8_t str_i2c_slave_transmit_nl[] = "I2C slave transmit\n\r";
  uint8_t str_i2c_slave_start_nl[] = "I2C slave start\n\r";
  uint8_t str_i2c_slave_stop_nl[] = "I2C slave stop\n\r";

  task void slaveReceiveTask()
  {
    call UartStream.send(str_i2c_slave_receive_nl,19);  
  }
  
  task void slaveTransmitTask()
  {
    call UartStream.send(str_i2c_slave_transmit_nl,20);  
  }

  task void slaveStartTask()
  {
    call UartStream.send(str_i2c_slave_start_nl,17);  
  }

  task void slaveStopTask()
  {
    call UartStream.send(str_i2c_slave_stop_nl,17);  
  }

  async event error_t I2CBasicAddr.slaveReceive(uint8_t data)
  {
    call UartStream.send(&data,1);  

    post slaveReceiveTask();
    
    return SUCCESS;
  }

  uint8_t counter;

  async event uint8_t I2CBasicAddr.slaveTransmit()
  {
    post slaveTransmitTask();
    
    return counter++;
  }

  async event void I2CBasicAddr.slaveStart() 
  { 
    post slaveStartTask();
  }
  
  async event void I2CBasicAddr.slaveStop() 
  { 
    post slaveStopTask();
  }


  /***************************************************************************/
  /* SERIAL                                                                  */
  /***************************************************************************/

  async event void UartStream.sendDone( uint8_t* buf, uint16_t len, error_t error )
  {
    return;
  }
  
  async event void UartStream.receiveDone( uint8_t* buf, uint16_t len, error_t error )
  {
    return;
  }

  uint8_t tmpchar;

  task void StdOutTask()
  {    
    uint8_t str[2];    

    atomic str[0] = tmpchar;
    
    switch(str[0]) {
    

      case 'w':  
                  i2c_length = 10;
                  i2c_buffer[0] = 0x00;
                  i2c_buffer[1] = 0x01;
                  i2c_buffer[2] = 0x02;
                  i2c_buffer[3] = 0x03;
                  i2c_buffer[4] = 0x04;
                  i2c_buffer[5] = 0x05;
                  i2c_buffer[6] = 0x06;
                  i2c_buffer[7] = 0x07;
                  i2c_buffer[8] = 0x08;
                  i2c_buffer[9] = 0x09;
                  call I2CBasicAddr.write(I2C_START|I2C_STOP, 0x42, i2c_length, i2c_buffer);
                  break;

      case 'r':  
                  i2c_length = 10;
                  call I2CBasicAddr.read(I2C_START|I2C_STOP, 0x42, i2c_length, i2c_buffer);
                  break;

      case '\r':  
                  str[0] = '\n';
                  str[1] = '\r';
                  call UartStream.send(str,2);
                  break;
                  
      default:    
                  call UartStream.send(str,1);
                  break;
     }
  }
  
  /* incoming serial data */
  async event void UartStream.receivedByte( uint8_t byte )
  {
    tmpchar = byte;
    
    post StdOutTask();
  }

}

