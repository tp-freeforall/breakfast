#ifndef TEST_TOAST_H
#define TEST_TOAST_H

#define UQ_TEST_CLIENT "TestToast.TestClient"

#define MAX_SLAVES 4

typedef struct test_state_t{
  uint8_t slaveCount;
  uint8_t currentSlave;
  uint16_t slaves[MAX_SLAVES];
} test_state_t;

#endif
