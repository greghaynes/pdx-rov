#!../../bin/linux-x86_64/SerialLED

## You may have to change SerialLED to something else
## everywhere it appears in this file

< envPaths

cd ${TOP}

## Register all support components
dbLoadDatabase "dbd/SerialLED.dbd"
SerialLED_registerRecordDeviceDriver pdbbase

## Load record instances
#dbLoadRecords("db/xxx.db","user=greghaynesHost")
dbLoadRecords("db/devSerialLED.db","P=SerialLED:,R=,L=0,A=0");

cd ${TOP}/iocBoot/${IOC}
iocInit

## Start any sequence programs
#seq sncxxx,"user=greghaynesHost"
