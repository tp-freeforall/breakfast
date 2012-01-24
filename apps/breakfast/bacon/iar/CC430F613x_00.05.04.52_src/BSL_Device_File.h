#include "cc430x513x.h"
#include "intrinsics.h"

//Device Specific Definitions
#define MASS_ERASE_DELAY 0x8000
#define INTERRUPT_VECTOR_START 0xFFE0
#define INTERRUPT_VECTOR_END   0xFFFF
#define SECURE_RAM_START 0x1c00

//#define TX_PORT_SEL P1SEL
//#define TX_PORT_DIR P1DIR
//#define RX_PORT_SEL P1SEL
//#define RX_PORT_DIR P1DIR
#define USCI_PORT_SEL P1SEL
#define RXD       BIT5                      // RXD on P1.5
#define TXD       BIT6                      // TXD on P1.6
#define DCO_SPEED 8000000
#define ACLK_SPEED 32768

//Device Specific Definitions for commands and bugs
#define FULL_FLASH_BSL
#define DO_NOT_CHECK_VPE

// standard command includes
#ifdef RAM_WRITE_ONLY_BSL
 #define SUPPORTS_RX_DATA_BLOCK_FAST
 #define SUPPORTS_RX_PASSWORD
 #define SUPPORTS_LOAD_PC
#endif

#ifdef FULL_FLASH_BSL
 #define FULL_GENERIC_COMMANDS
 #define FLASH_COMMANDS
#endif

#ifdef FULL_FRAM_BSL
 #define FULL_GENERIC_COMMANDS
#endif

#ifdef FULL_GENERIC_COMMANDS
 #define SUPPORTS_RX_DATA_BLOCK_FAST
 #define SUPPORTS_RX_PASSWORD
 #define SUPPORTS_LOAD_PC
 #define SUPPORTS_RX_DATA_BLOCK
 #define SUPPORTS_MASS_ERASE
 #define SUPPORTS_CRC_CHECK
 #define SUPPORTS_TX_DATA_BLOCK
 #define SUPPORTS_TX_BSL_VERSION
#endif

#ifdef FLASH_COMMANDS
 #define SUPPORTS_ERASE_SEGMENT
 #define SUPPORTS_TOGGLE_INFO
#endif