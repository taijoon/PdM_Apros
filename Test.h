/*
 * Copyright (c) 2010-2015 Sinbinet Corp.
 * All rights reserved.
 */

/**
 * Data structure, states, and constants for test.
 *
 * @author Suchang Lee <suchanglee@sinbinet.com>
 * @author Sukun Kim <sukunkim@sinbinet.com>
 */

#ifndef TEST_H
#define TEST_H

#include "message.h"

enum {
  TEST_PERIOD = 1024,
};


enum {
  DFLT_VAL = 0x11,
};

enum {
  TEST_DATA_LENGTH = TOSH_DATA_LENGTH - 6,
};


enum {
  AM_TEST_DATA_MSG = 0xA4,
};


typedef nx_struct test_data_msg {
  nx_am_addr_t srcID;
  nx_uint32_t seqNo;
  nx_uint8_t testData[TEST_DATA_LENGTH];
} test_data_msg_t;

#endif // TEST_H
