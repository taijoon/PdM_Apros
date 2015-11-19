// $Id: DataCollector.h,v 1.1 2006/12/01 00:09:07 binetude Exp $

/*									tab:4
 * "Copyright (c) 2000-2003 The Regents of the University  of California.  
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the author appear in all copies of this software.
 * 
 * IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY OF
 * CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 * Copyright (c) 2002-2003 Intel Corporation
 * All rights reserved.
 *
 * This file is distributed under the terms in the attached INTEL-LICENSE     
 * file. If you do not find these files, copies can be found by writing to
 * Intel Research Berkeley, 2150 Shattuck Avenue, Suite 1300, Berkeley, CA, 
 * 94704.  Attention:  Intel License Inquiry.
 *
 * Copyright (c) 2015 Sinbinet Corp.
 * All rights reserved.
 */
/*
 *
 * Authors:		Sukun Kim
 * Date last modified:  11/30/06
 *
 */

/**
 * @author Sukun Kim
 * @author Suchang Lee <suchanglee@sinbinet.com>
 */

#ifndef DATACOLLECTOR_H
#define DATACOLLECTOR_H

#include "message.h"


enum {
  AM_DATACOLLECTOR_DATA_MSG = 0xF4,
};


typedef nx_struct datacollector_data_acc {
  nx_uint16_t x;
  nx_uint16_t y;
  nx_uint16_t z;
} datacollector_data_acc_t;

typedef nx_struct datacollector_data_energy {
  nx_uint16_t power;
} datacollector_data_energy_t;


typedef nx_union datacollector_data_data {
  datacollector_data_acc_t acc;
  datacollector_data_energy_t energy;
  nx_uint8_t reserved[TOSH_DATA_LENGTH - 5];
} datacollector_data_data_t;

typedef nx_struct datacollector_data_msg {
  nx_uint16_t srcId;
  nx_uint16_t seqNo;
  nx_uint8_t sensorType;
  datacollector_data_data_t sensorData;
} datacollector_data_msg_t;

#endif // DATACOLLECTOR_H
