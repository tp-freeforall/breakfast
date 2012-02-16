COMPONENT=TestAppC
CFLAGS+=-I$(TOSDIR)/lib/serialprintf
#CFLAGS+=-I../concxmit-redux

#defaults
IS_SENDER?=FALSE
POWER_INDEX?=3
HGM?=FALSE
CHANNEL?=0
USE_LONG_IPI?=TRUE
PRR_BUF_LEN?=200
REPORT?=TRUE
HAS_FE=3

#NOTE: to specify from command line:
# TEST_DESC=\\\"TEST_INFO\\\"
TEST_DESC?=\"NO_INFO\"
TEST_NUM?=0

#expose to app
CFLAGS+=-DIS_SENDER=$(IS_SENDER)
CFLAGS+=-DPOWER_INDEX=$(POWER_INDEX)
CFLAGS+=-DHGM=$(HGM)
CFLAGS+=-DCHANNEL=$(CHANNEL)
CFLAGS+=-DPRR_BUF_LEN=$(PRR_BUF_LEN)
CFLAGS+=-DREPORT=$(REPORT)
CFLAGS+=-DUSE_LONG_IPI=$(USE_LONG_IPI)
CFLAGS+=-DHAS_FE=$(HAS_FE)

CFLAGS+=-DTEST_DESC=$(TEST_DESC)
CFLAGS+=-DTEST_NUM=$(TEST_NUM)

#uncomment to receive packets with failed CRCs (or if rf1a config is
# set up to filter on CRC
CFLAGS+=-DRF1A_NO_CRC

CFLAGS+=-DQUIET

#TODO: set from command line. not a big deal, though, if non-amp mote
# thinks it has one
CFLAGS+=-DHAS_CC1190

PFLAGS+=-DCC2420_DEF_CHANNEL=$(CHANNEL)

include $(MAKERULES)
