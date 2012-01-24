#ifndef BSL_PI_H
#define BSL_PI_H

#define RX_PACKET_ONGOING 0x00
#define DATA_RECEIVED 0x01
#define RX_ERROR_RECOVERABLE 0x02
#define RX_ERROR_REINIT 0x03
#define RX_ERROR_FATAL 0x04
#define PI_DATA_RECEIVED 0x05

#define PI_COMMAND_UPPER 0x50  

//PI version Signifiers
#define BSL430_TIMER_A_PI 0x00
#define BSL430_USB_PI     0x30
#define BSL430_USCIA_PI   0x50
#define BSL430_eUSCIA_PI  0x70

/*******************************************************************************
*Function:    init
*Description: Initialize the peripheral and ports to begin TX/RX
*******************************************************************************/
void PI_init();

/*******************************************************************************
*Function:    PI_receivePacket
*Description: Reads an entire packet, verifies it, and sends it to the core to be interpreted
*Returns:
*             DATA_RECEIVED         A packet has been received and can be processed
*             RX_ERROR_RECOVERABLE  An error has occured, the function can be called again to 
*                                   receive a new packet
*******************************************************************************/
char PI_receivePacket();

/*******************************************************************************
*Function:    PI_sendData
*Description: Sends the data in the data buffer
*Parameters: 
              int bufSize - the number of bytes to send
*******************************************************************************/
void PI_sendData(int bufSize);

/*******************************************************************************
*Function:    PI_getBufferSize
*Description: Returns the max Data Buffer Size for this PI
*Returns:     max buffer size
*******************************************************************************/
int PI_getBufferSize();
#endif
