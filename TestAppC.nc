/*
 * Copyright (c) 2012-2015 Sinbinet Corp.
 * All rights reserved.
 */

/**
 * Configuration for test.
 *
 * @author Suchang Lee <suchanglee@sinbinet.com>
 * @author Sukun Kim <sukunkim@sinbinet.com>
 */

includes Test;
includes DataCollector;

configuration TestAppC
{
}

implementation
{
  components TestC, MainC;
  components LedsC, new TimerMilliC();

  components ActiveMessageC as AMC;
  components SerialActiveMessageC as  SAMC;

  components new AMSenderC(AM_TEST_DATA_MSG) as AMSC;
  components new SerialAMSenderC(AM_TEST_DATA_MSG) as SAMSC;


  TestC.Boot -> MainC;
  TestC.Leds -> LedsC;
  TestC.MilliTimer -> TimerMilliC;

  TestC.RadioControl -> AMC;
  TestC.SerialControl -> SAMC;

  TestC.RadioSend -> AMSC;
  TestC.SerialSend -> SAMSC;
}
