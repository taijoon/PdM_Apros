/*
 * Copyright (c) 2012-2015 Sinbinet Corp.
 * All rights reserved.
 */

/**
 * Implementation for test.
 *
 * @author Suchang Lee <suchanglee@sinbinet.com>
 * @author Sukun Kim <sukunkim@sinbinet.com>
 */

module TestC
{
  uses {
    interface Boot;
    interface Leds;
    interface Timer<TMilli> as MilliTimer;

    interface SplitControl as RadioControl;
    interface SplitControl as SerialControl;

    interface AMSend as RadioSend;
    interface AMSend as SerialSend;
  }
}

implementation
{
  message_t testMsgBffr;
  test_data_msg_t *testMsg;
	datacollector_data_msg_t *sensorMsg;
  uint32_t seqNo;


  event void Boot.booted() {
    sensorMsg = (datacollector_data_msg_t *)call RadioSend.getPayload(
      &testMsgBffr, sizeof(datacollector_data_msg_t));
    sensorMsg->srcId = TOS_NODE_ID;
    memset(&sensorMsg->sensorData, DFLT_VAL, sizeof(datacollector_data_data_t));

    seqNo = 0;

    call RadioControl.start();
  }

  task void startTimer();
  event void RadioControl.startDone(error_t error) {
    call SerialControl.start();
  }

  event void SerialControl.startDone(error_t error) {
    post startTimer();
  }

  event void RadioControl.stopDone(error_t error) {}
  event void SerialControl.stopDone(error_t error) {}


  task void startTimer() {
    call MilliTimer.startPeriodic(TEST_PERIOD);
  }

  task void sendTask();
  event void MilliTimer.fired() {
    call Leds.led0Toggle();

    post sendTask();
  }

  task void sendTask() {

    sensorMsg->sensorData.energy.power = 0xabcd;
    sensorMsg->seqNo = seqNo++;

    call RadioSend.send(AM_BROADCAST_ADDR, &testMsgBffr,
      sizeof(datacollector_data_msg_t));
  }

  event void RadioSend.sendDone(message_t* msg, error_t error) {}
  event void SerialSend.sendDone(message_t* msg, error_t error) {}
}
