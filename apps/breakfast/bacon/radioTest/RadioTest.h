#ifndef RADIO_TEST_H
#define RADIO_TEST_H

#define AM_RADIO_TEST_PROBE 0x01
#define AM_RADIO_TEST_REPORT 0x02
//test modification

typedef nx_struct probe {
  nx_uint8_t node_id;
  nx_uint32_t bn;
  nx_uint32_t sn;
  nx_uint8_t powerLevel;
} probe_t;

typedef nx_struct report {
  probe_t probe;
  nx_int8_t rssi;
  nx_int8_t lqi;
} report_t;

#endif
