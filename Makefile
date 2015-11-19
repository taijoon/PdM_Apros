# Copyright (c) 2010-2015 Sinbinet Corp.
# All rights reserved.
#
# author Suchang Lee <suchanglee@sinbinet.com>
# author Sukun Kim <sukunkim@sinbinet.com>

COMPONENT=TestAppC

CC2420_CHANNEL=0x1A
DEFAULT_LOCAL_GROUP=0x2A
# CFLAGS += -DMG245XCOMM_DEF_RFPOWER=0 # For debugging
# CFLAGS += -DTOSH_DATA_LENGTH=40 # For debugging

include $(MAKERULES)
