#ifndef BSL_COMMAND_DEFINITIONS_H
#define BSL_COMMAND_DEFINITIONS_H

//Received commands
#define RX_DATA_BLOCK      0x10
#define RX_PASSWORD        0x11
#define ERASE_SEGMENT      0x12
#define TOGGLE_INFO        0x13
#define ERASE_BLOCK        0x14
#define MASS_ERASE         0x15
#define CRC_CHECK          0x16
#define LOAD_PC            0x17
#define TX_DATA_BLOCK      0x18
#define TX_BSL_VERSION     0x19
#define TX_BUFFER_SIZE     0x1A
#define RX_DATA_BLOCK_FAST 0x1B 

//Responses
#define BSL_DATA_REPLY    0x3A
#define BSL_MESSAGE_REPLY 0x3B
#define ACK               SUCCESSFUL_OPERATION

// Error Codes
// - From the API
#define SUCCESSFUL_OPERATION 0x00
#define NO_EXCEPTIONS 0x00
#define MEMORY_WRITE_CHECK_FAILED 0x01
#define FLASH_FAIL_BIT_SET 0x02
#define VOLTAGE_CHANGE_DURING_PROGRAM 0x03
#define BSL_LOCKED 0x04
#define BSL_PASSWORD_ERROR 0x05
#define BYTE_WRITE_FORBIDDEN 0x06
// - From the Command Interpreter
#define UNKNOWN_COMMAND 0x07
#define LENGTH_TOO_BIG_FOR_BUFFER 0x08

#endif
