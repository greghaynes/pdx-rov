/*
 * SerialLED device support
 */

#include <epicsStdio.h>
#include <devCommonGpib.h>

/******************************************************************************
 *
 * The following define statements are used to declare the names to be used
 * for the dset tables.   
 *
 * A DSET_AI entry must be declared here and referenced in an application
 * database description file even if the device provides no AI records.
 *
 ******************************************************************************/
#define DSET_AI     devAiSerialLED
#define DSET_AO     devAoSerialLED
#define DSET_BI     devBiSerialLED
#define DSET_BO     devBoSerialLED
#define DSET_EV     devEvSerialLED
#define DSET_LI     devLiSerialLED
#define DSET_LO     devLoSerialLED
#define DSET_MBBI   devMbbiSerialLED
#define DSET_MBBID  devMbbidSerialLED
#define DSET_MBBO   devMbboSerialLED
#define DSET_MBBOD  devMbbodSerialLED
#define DSET_SI     devSiSerialLED
#define DSET_SO     devSoSerialLED
#define DSET_WF     devWfSerialLED

#include <devGpib.h> /* must be included after DSET defines */

#define TIMEOUT     1.0    /* I/O must complete within this time */
#define TIMEWINDOW  2.0    /* Wait this long after device timeout */

/******************************************************************************
 * Strings used by the init routines to fill in the znam,onam,...
 * fields in BI and BO record types.
 ******************************************************************************/

static char  *offOnList[] = { "Off","On" };
static struct devGpibNames   offOn = { 2,offOnList,0,1 };

/******************************************************************************
 * Structures used by the init routines to fill in the onst,twst,... and the
 * onvl,twvl,... fields in MBBI and MBBO record types.
 *
 * Note that the intExtSsBm and intExtSsBmStop structures use the same
 * intExtSsBmStopList and intExtSsBmStopVal lists but have a different number
 * of elements in them that they use... The intExtSsBm structure only represents
 * 4 elements,while the intExtSsBmStop structure represents 5.
 ******************************************************************************/

static char *intExtSsBmStopList[] = {
    "INTERNAL","EXTERNAL","SINGLE SHOT","BURST MODE","STOP" };
static unsigned long intExtSsBmStopVal[] = { 0,1,2,3,2 };
static struct devGpibNames intExtSsBm = {
    4,intExtSsBmStopList, intExtSsBmStopVal,2 };
static struct devGpibNames intExtSsBmStop = {
    5,intExtSsBmStopList,intExtSsBmStopVal,3 };

/******************************************************************************
 * String arrays for EFAST operations. The last entry must be 0.
 *
 * On input operations,only as many bytes as are found in the string array
 * elements are compared.  Additional bytes are ignored.
 * The first matching string  will be used as a match.
 *
 * For the input operations,the strings are compared literally!  This
 * can cause problems if the instrument is returning things like \r and \n
 * characters.  When defining input strings so you include them as well.
 ******************************************************************************/

static char *userOffOn[] = {"USER OFF;","USER ON;",0};

/******************************************************************************
 * Array of structures that define all GPIB messages
 * supported for this type of instrument.
 ******************************************************************************/

static struct gpibCmd gpibCmds[] = {
    {&DSET_LI, GPIBWRITE, IB_Q_LOW, NULL, "D6=%d\r\n", 0, 16, NULL, 0, 0, NULL, NULL, NULL},
};

/* The following is the number of elements in the command array above.  */
#define NUMPARAMS sizeof(gpibCmds)/sizeof(struct gpibCmd)

/******************************************************************************
 * Initialize device support parameters
 *
 *****************************************************************************/
static long init_ai(int parm)
{
    if(parm==0) {
        devSupParms.name = "devSerialLED";
        devSupParms.gpibCmds = gpibCmds;
        devSupParms.numparams = NUMPARAMS;
        devSupParms.timeout = TIMEOUT;
        devSupParms.timeWindow = TIMEWINDOW;
        devSupParms.respond2Writes = -1;
    }
    return(0);
}
