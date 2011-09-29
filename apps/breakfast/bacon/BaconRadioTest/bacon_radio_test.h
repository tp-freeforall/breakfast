#ifndef BACON_RADIO_TEST_H
#define BACON_RADIO_TEST_H

#define AM_TXRX   0xbe
#define AM_REPORT 0xef

  typedef nx_struct test_payload_t {
      nx_uint8_t node_id;
      nx_uint32_t sn;
      nx_int8_t powerLevel;
      nx_uint8_t hgm;
  } test_payload_t;

  typedef nx_struct report_t {
      nx_uint8_t node_id;
      nx_uint32_t sn;
      nx_int8_t powerLevel;
      nx_uint8_t hgmTx;
      nx_uint8_t hgmRx;
      nx_int8_t rssi;
      nx_int8_t lqi;
  } report_t;

#endif
