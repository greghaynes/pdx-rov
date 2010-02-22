TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = SerialLED
# SerialLED.dbd will be created and installed
DBD += SerialLED.dbd

# SerialLED.dbd will be made up from these files:
SerialLED_DBD += base.dbd

# Include dbd files from all support applications:
SerialLED_DBD += devSerialLED.dbd

# Add all the support libraries needed by this IOC
SerialLED_LIBS += devSerialLED
SerialLED_LIBS += asyn

# SerialLED_registerRecordDeviceDriver.cpp derives from SerialLED.dbd
SerialLED_SRCS += SerialLED_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
SerialLED_SRCS_DEFAULT += SerialLEDMain.cpp
SerialLED_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#SerialLED_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
SerialLED_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

