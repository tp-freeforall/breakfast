
module UartEchoP {
  uses {
    interface Boot;

    interface Leds;    

    interface StdControl as SerialControl;
    interface StdOut;

    interface Resource;
    interface UartStream as SecondUartStream;

  }  
  
} implementation {


  /***************************************************************************/
  
  /***************************************************************************/
  /* BOOT                                                                    */
  /***************************************************************************/

  event void Boot.booted() 
  {
    call SerialControl.start();

    if (!call Resource.isOwner())
    {
      call Resource.request();      
    }

//    call StdOut.print("UartEcho\n\r");
  }


  event void Resource.granted() 
  {
  }

  /***************************************************************************/
  /* SERIAL                                                                  */
  /***************************************************************************/

  char tmpchar;

  task void StdOutTask()
  {    
    uint8_t str[2];    
    atomic str[0] = tmpchar;
    
    switch(str[0]) {
    
      case '\r':  
                  call SecondUartStream.send("\n\r", 2);

//                  call StdOut.print("\n\r");
                  break;

      default:    
                  str[1] = '\0';
                  call SecondUartStream.send(str, 1);
//                  call StdOut.print(str);
                  break;
     }
  }
  
  /* incoming serial data */
  async event void StdOut.get(uint8_t data) 
  {
    call Leds.led2Toggle();

    tmpchar = data;
    
    post StdOutTask();
  }



  /***************************************************************************/


  async event void SecondUartStream.sendDone( uint8_t * buf, uint16_t len, error_t error ) 
  {    
  }

  async event void SecondUartStream.receiveDone( uint8_t* buf, uint16_t len, error_t error ) 
  {

  }

  /* incoming serial data */
  async event void SecondUartStream.receivedByte(uint8_t data) 
  {
    char str[2];

    str[0] = data;    
    str[1] = '\0';

    call Leds.led1Toggle();

    /* local echo */
//    call SecondUartStream.send(str, 1);

    /* remote echo */
    call StdOut.print(str);
  }



  /***************************************************************************/
  /***************************************************************************/
}
