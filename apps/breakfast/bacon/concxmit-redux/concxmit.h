#ifndef CONCXMIT_H
#define CONCXMIT_H

#define CONCXMIT_RADIO_AM_TEST 0xDC

#define CONCXMIT_SERIAL_AM_CMD 0xDC
#define CONCXMIT_SERIAL_AM_RECEIVER_REPORT 0xDD
#define CONCXMIT_SERIAL_AM_SENDER_REPORT 0xDE

typedef nx_struct {
  nx_uint16_t seqNum;
} test_packet_t;

#define CONCXMIT_CMD_NEXT 0x01
#define CONCXMIT_CMD_SEND 0x02

//Power levels
//-12   -6      0       10
//0x25  0x2D    0x8D    0xC3

#define TX_POWER_1 0x25
#define TX_POWER_2 0x8D

typedef nx_struct {
  nx_uint8_t cmd;
  nx_uint16_t send1Offset;
  nx_uint16_t sendCount;
} cmd_t;

typedef nx_struct{
  nx_uint16_t configId;
  nx_uint16_t seqNum;
  nx_uint8_t received;
  nx_uint16_t rssi;
  nx_uint16_t lqi;
  nx_uint16_t send1Offset;
} receiver_report_t;

typedef nx_struct{
  nx_uint16_t configId;
  nx_uint16_t seqNum;
} sender_report_t;

#define SEND_TIMEOUT 512

#endif
