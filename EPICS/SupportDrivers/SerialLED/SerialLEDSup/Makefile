TOP=..
include $(TOP)/configure/CONFIG
#=======================================

# Build devSerialLED as a library for an IOC:
LIBRARY_IOC += devSerialLED

# Library Source files
devSerialLED_SRCS += devSerialLED.c

# Link with the asyn and base libraries
devSerialLED_LIBS += asyn
devSerialLED_LIBS += $(EPICS_BASE_IOC_LIBS)

# Install .dbd and .db files
DBD += devSerialLED.dbd
DB_INSTALLS += devSerialLED.db

#=======================================
include $(TOP)/configure/RULES
