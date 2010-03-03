
#ifndef INCserialSBITH
#define INCserialSBITH
typedef enum {
	serialSBIT_unknown,
	serialSBIT_1,
	serialSBIT_2
}serialSBIT;
#endif /*INCserialSBITH*/

#ifndef INCserialPRTYH
#define INCserialPRTYH
typedef enum {
	serialPRTY_unknown,
	serialPRTY_None,
	serialPRTY_Even,
	serialPRTY_Odd
}serialPRTY;
#endif /*INCserialPRTYH*/

#ifndef INCserialMCTLH
#define INCserialMCTLH
typedef enum {
	serialMCTL_unknown,
	serialMCTL_CLOCAL,
	serialMCTL_Yes
}serialMCTL;
#endif /*INCserialMCTLH*/

#ifndef INCserialFCTLH
#define INCserialFCTLH
typedef enum {
	serialFCTL_unknown,
	serialFCTL_None,
	serialFCTL_Hardware
}serialFCTL;
#endif /*INCserialFCTLH*/

#ifndef INCserialDBITH
#define INCserialDBITH
typedef enum {
	serialDBIT_unknown,
	serialDBIT_5,
	serialDBIT_6,
	serialDBIT_7,
	serialDBIT_8
}serialDBIT;
#endif /*INCserialDBITH*/

#ifndef INCserialBAUDH
#define INCserialBAUDH
typedef enum {
	serialBAUD_unknown,
	serialBAUD_300,
	serialBAUD_600,
	serialBAUD_1200,
	serialBAUD_2400,
	serialBAUD_4800,
	serialBAUD_9600,
	serialBAUD_19200,
	serialBAUD_38400,
	serialBAUD_57600,
	serialBAUD_115200,
	serialBAUD_230400
}serialBAUD;
#endif /*INCserialBAUDH*/

#ifndef INCgpibUCMDH
#define INCgpibUCMDH
typedef enum {
	gpibUCMD_None,
	gpibUCMD_Device_Clear__DCL_,
	gpibUCMD_Local_Lockout__LL0_,
	gpibUCMD_Serial_Poll_Disable__SPD_,
	gpibUCMD_Serial_Poll_Enable__SPE_,
	gpibUCMD_Unlisten__UNL_,
	gpibUCMD_Untalk__UNT_
}gpibUCMD;
#endif /*INCgpibUCMDH*/

#ifndef INCgpibACMDH
#define INCgpibACMDH
typedef enum {
	gpibACMD_None,
	gpibACMD_Group_Execute_Trig___GET_,
	gpibACMD_Go_To_Local__GTL_,
	gpibACMD_Selected_Dev__Clear__SDC_,
	gpibACMD_Take_Control__TCT_,
	gpibACMD_Serial_Poll
}gpibACMD;
#endif /*INCgpibACMDH*/

#ifndef INCasynTRACEH
#define INCasynTRACEH
typedef enum {
	asynTRACE_Off,
	asynTRACE_On
}asynTRACE;
#endif /*INCasynTRACEH*/

#ifndef INCasynTMODH
#define INCasynTMODH
typedef enum {
	asynTMOD_Write_Read,
	asynTMOD_Write,
	asynTMOD_Read,
	asynTMOD_Flush,
	asynTMOD_NoIO
}asynTMOD;
#endif /*INCasynTMODH*/

#ifndef INCasynINTERFACEH
#define INCasynINTERFACEH
typedef enum {
	asynINTERFACE_OCTET,
	asynINTERFACE_INT32,
	asynINTERFACE_UINT32,
	asynINTERFACE_FLOAT64
}asynINTERFACE;
#endif /*INCasynINTERFACEH*/

#ifndef INCasynFMTH
#define INCasynFMTH
typedef enum {
	asynFMT_ASCII,
	asynFMT_Hybrid,
	asynFMT_Binary
}asynFMT;
#endif /*INCasynFMTH*/

#ifndef INCasynEOMREASONH
#define INCasynEOMREASONH
typedef enum {
	asynEOMREASONNone,
	asynEOMREASONCNT,
	asynEOMREASONEOS,
	asynEOMREASONCNTEOS,
	asynEOMREASONEND,
	asynEOMREASONCNTEND,
	asynEOMREASONEOSEND,
	asynEOMREASONCNTEOSEND
}asynEOMREASON;
#endif /*INCasynEOMREASONH*/

#ifndef INCasynENABLEH
#define INCasynENABLEH
typedef enum {
	asynENABLE_Disable,
	asynENABLE_Enable
}asynENABLE;
#endif /*INCasynENABLEH*/

#ifndef INCasynCONNECTH
#define INCasynCONNECTH
typedef enum {
	asynCONNECT_Disconnect,
	asynCONNECT_Connect
}asynCONNECT;
#endif /*INCasynCONNECTH*/

#ifndef INCasynAUTOCONNECTH
#define INCasynAUTOCONNECTH
typedef enum {
	asynAUTOCONNECT_noAutoConnect,
	asynAUTOCONNECT_autoConnect
}asynAUTOCONNECT;
#endif /*INCasynAUTOCONNECTH*/
#ifndef INCasynH
#define INCasynH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
typedef struct asynRecord {
	char		name[61];	/* Record Name */
	char		desc[41];	/* Descriptor */
	char		asg[29];	/* Access Security Group */
	epicsEnum16	scan;	/* Scan Mechanism */
	epicsEnum16	pini;	/* Process at iocInit */
	epicsInt16	phas;	/* Scan Phase */
	epicsInt16	evnt;	/* Event Number */
	epicsInt16	tse;	/* Time Stamp Event */
	DBLINK		tsel;	/* Time Stamp Link */
	epicsEnum16	dtyp;	/* Device Type */
	epicsInt16	disv;	/* Disable Value */
	epicsInt16	disa;	/* Disable */
	DBLINK		sdis;	/* Scanning Disable */
	epicsMutexId	mlok;	/* Monitor lock */
	ELLLIST		mlis;	/* Monitor List */
	epicsUInt8	disp;	/* Disable putField */
	epicsUInt8	proc;	/* Force Processing */
	epicsEnum16	stat;	/* Alarm Status */
	epicsEnum16	sevr;	/* Alarm Severity */
	epicsEnum16	nsta;	/* New Alarm Status */
	epicsEnum16	nsev;	/* New Alarm Severity */
	epicsEnum16	acks;	/* Alarm Ack Severity */
	epicsEnum16	ackt;	/* Alarm Ack Transient */
	epicsEnum16	diss;	/* Disable Alarm Sevrty */
	epicsUInt8	lcnt;	/* Lock Count */
	epicsUInt8	pact;	/* Record active */
	epicsUInt8	putf;	/* dbPutField process */
	epicsUInt8	rpro;	/* Reprocess  */
	struct asgMember *asp;	/* Access Security Pvt */
	struct putNotify *ppn;	/* addr of PUTNOTIFY */
	struct putNotifyRecord *ppnr;	/* pputNotifyRecord */
	struct scan_element *spvt;	/* Scan Private */
	struct rset	*rset;	/* Address of RSET */
	struct dset	*dset;	/* DSET address */
	void		*dpvt;	/* Device Private */
	struct dbRecordType *rdes;	/* Address of dbRecordType */
	struct lockRecord *lset;	/* Lock Set */
	epicsEnum16	prio;	/* Scheduling Priority */
	epicsUInt8	tpro;	/* Trace Processing */
	char bkpt;	/* Break Point */
	epicsUInt8	udf;	/* Undefined */
	epicsTimeStamp	time;	/* Time */
	DBLINK		flnk;	/* Forward Process Link */
	char		val[40];	/* Value field (unused) */
	char		port[40];	/* asyn port */
	epicsInt32	addr;	/* asyn address */
	epicsEnum16	pcnct;	/* Port Connect/Disconnect */
	char		drvinfo[40];	/* Driver info string */
	epicsInt32	reason;	/* asynUser->reason */
	char		sock[40];	/* socket address */
	epicsEnum16	tmod;	/* Transaction mode */
	epicsFloat64	tmot;	/* Timeout (sec) */
	epicsEnum16	iface;	/* Interface */
	epicsInt32	octetiv;	/* asynOctet is valid */
	epicsInt32	optioniv;	/* asynOption is valid */
	epicsInt32	gpibiv;	/* asynGPIB is valid */
	epicsInt32	i32iv;	/* asynInt32 is valid */
	epicsInt32	ui32iv;	/* asynUInt32Digital is valid */
	epicsInt32	f64iv;	/* asynFloat64 is valid */
	char		aout[40];	/* Output (command) string */
	char		oeos[40];	/* Output delimiter */
	epicsInt8	bout;	/* Output binary data */
	void *optr;	/* Output buffer pointer */
	epicsInt32	omax;	/* Max. size of output array */
	epicsInt32	nowt;	/* Number of bytes to write */
	epicsInt32	nawt;	/* Number of bytes actually written */
	epicsEnum16	ofmt;	/* Output format */
	char		ainp[40];	/* Input (response) string */
	char		tinp[40];	/* Translated input string */
	char		ieos[40];	/* Input Delimiter */
	epicsInt8	binp;	/* Input binary data */
	void *iptr;	/* Input buffer pointer */
	epicsInt32	imax;	/* Max. size of input array */
	epicsInt32	nrrd;	/* Number of bytes to read */
	epicsInt32	nord;	/* Number of bytes read */
	epicsEnum16	ifmt;	/* Input format */
	epicsEnum16	eomr;	/* EOM reason */
	epicsInt32	i32inp;	/* asynInt32 input */
	epicsInt32	i32out;	/* asynInt32 output */
	epicsUInt32	ui32inp;	/* asynUInt32Digital input */
	epicsUInt32	ui32out;	/* asynUInt32Digital output */
	epicsUInt32	ui32mask;	/* asynUInt32Digital mask */
	epicsFloat64	f64inp;	/* asynFloat64 input */
	epicsFloat64	f64out;	/* asynFloat64 output */
	epicsEnum16	baud;	/* Baud rate */
	epicsEnum16	prty;	/* Parity */
	epicsEnum16	dbit;	/* Data bits */
	epicsEnum16	sbit;	/* Stop bits */
	epicsEnum16	mctl;	/* Modem control */
	epicsEnum16	fctl;	/* Flow control */
	epicsEnum16	ucmd;	/* Universal command */
	epicsEnum16	acmd;	/* Addressed command */
	epicsUInt8	spr;	/* Serial poll response */
	epicsInt32	tmsk;	/* Trace mask */
	epicsEnum16	tb0;	/* Trace error */
	epicsEnum16	tb1;	/* Trace IO device */
	epicsEnum16	tb2;	/* Trace IO filter */
	epicsEnum16	tb3;	/* Trace IO driver */
	epicsEnum16	tb4;	/* Trace flow */
	epicsInt32	tiom;	/* Trace I/O mask */
	epicsEnum16	tib0;	/* Trace IO ASCII */
	epicsEnum16	tib1;	/* Trace IO escape */
	epicsEnum16	tib2;	/* Trace IO hex */
	epicsInt32	tsiz;	/* Trace IO truncate size */
	char		tfil[40];	/* Trace IO file */
	epicsEnum16	auct;	/* Autoconnect */
	epicsEnum16	cnct;	/* Connect/Disconnect */
	epicsEnum16	enbl;	/* Enable/Disable */
	char *errs;	/* Error string */
	epicsUInt8	aqr;	/* Abort queueRequest */
} asynRecord;
#define asynRecordNAME	0
#define asynRecordDESC	1
#define asynRecordASG	2
#define asynRecordSCAN	3
#define asynRecordPINI	4
#define asynRecordPHAS	5
#define asynRecordEVNT	6
#define asynRecordTSE	7
#define asynRecordTSEL	8
#define asynRecordDTYP	9
#define asynRecordDISV	10
#define asynRecordDISA	11
#define asynRecordSDIS	12
#define asynRecordMLOK	13
#define asynRecordMLIS	14
#define asynRecordDISP	15
#define asynRecordPROC	16
#define asynRecordSTAT	17
#define asynRecordSEVR	18
#define asynRecordNSTA	19
#define asynRecordNSEV	20
#define asynRecordACKS	21
#define asynRecordACKT	22
#define asynRecordDISS	23
#define asynRecordLCNT	24
#define asynRecordPACT	25
#define asynRecordPUTF	26
#define asynRecordRPRO	27
#define asynRecordASP	28
#define asynRecordPPN	29
#define asynRecordPPNR	30
#define asynRecordSPVT	31
#define asynRecordRSET	32
#define asynRecordDSET	33
#define asynRecordDPVT	34
#define asynRecordRDES	35
#define asynRecordLSET	36
#define asynRecordPRIO	37
#define asynRecordTPRO	38
#define asynRecordBKPT	39
#define asynRecordUDF	40
#define asynRecordTIME	41
#define asynRecordFLNK	42
#define asynRecordVAL	43
#define asynRecordPORT	44
#define asynRecordADDR	45
#define asynRecordPCNCT	46
#define asynRecordDRVINFO	47
#define asynRecordREASON	48
#define asynRecordSOCK	49
#define asynRecordTMOD	50
#define asynRecordTMOT	51
#define asynRecordIFACE	52
#define asynRecordOCTETIV	53
#define asynRecordOPTIONIV	54
#define asynRecordGPIBIV	55
#define asynRecordI32IV	56
#define asynRecordUI32IV	57
#define asynRecordF64IV	58
#define asynRecordAOUT	59
#define asynRecordOEOS	60
#define asynRecordBOUT	61
#define asynRecordOPTR	62
#define asynRecordOMAX	63
#define asynRecordNOWT	64
#define asynRecordNAWT	65
#define asynRecordOFMT	66
#define asynRecordAINP	67
#define asynRecordTINP	68
#define asynRecordIEOS	69
#define asynRecordBINP	70
#define asynRecordIPTR	71
#define asynRecordIMAX	72
#define asynRecordNRRD	73
#define asynRecordNORD	74
#define asynRecordIFMT	75
#define asynRecordEOMR	76
#define asynRecordI32INP	77
#define asynRecordI32OUT	78
#define asynRecordUI32INP	79
#define asynRecordUI32OUT	80
#define asynRecordUI32MASK	81
#define asynRecordF64INP	82
#define asynRecordF64OUT	83
#define asynRecordBAUD	84
#define asynRecordPRTY	85
#define asynRecordDBIT	86
#define asynRecordSBIT	87
#define asynRecordMCTL	88
#define asynRecordFCTL	89
#define asynRecordUCMD	90
#define asynRecordACMD	91
#define asynRecordSPR	92
#define asynRecordTMSK	93
#define asynRecordTB0	94
#define asynRecordTB1	95
#define asynRecordTB2	96
#define asynRecordTB3	97
#define asynRecordTB4	98
#define asynRecordTIOM	99
#define asynRecordTIB0	100
#define asynRecordTIB1	101
#define asynRecordTIB2	102
#define asynRecordTSIZ	103
#define asynRecordTFIL	104
#define asynRecordAUCT	105
#define asynRecordCNCT	106
#define asynRecordENBL	107
#define asynRecordERRS	108
#define asynRecordAQR	109
#endif /*INCasynH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsExport.h>
static int asynRecordSizeOffset(dbRecordType *pdbRecordType)
{
    asynRecord *prec = 0;
  pdbRecordType->papFldDes[0]->size=sizeof(prec->name);
  pdbRecordType->papFldDes[0]->offset=(short)((char *)&prec->name - (char *)prec);
  pdbRecordType->papFldDes[1]->size=sizeof(prec->desc);
  pdbRecordType->papFldDes[1]->offset=(short)((char *)&prec->desc - (char *)prec);
  pdbRecordType->papFldDes[2]->size=sizeof(prec->asg);
  pdbRecordType->papFldDes[2]->offset=(short)((char *)&prec->asg - (char *)prec);
  pdbRecordType->papFldDes[3]->size=sizeof(prec->scan);
  pdbRecordType->papFldDes[3]->offset=(short)((char *)&prec->scan - (char *)prec);
  pdbRecordType->papFldDes[4]->size=sizeof(prec->pini);
  pdbRecordType->papFldDes[4]->offset=(short)((char *)&prec->pini - (char *)prec);
  pdbRecordType->papFldDes[5]->size=sizeof(prec->phas);
  pdbRecordType->papFldDes[5]->offset=(short)((char *)&prec->phas - (char *)prec);
  pdbRecordType->papFldDes[6]->size=sizeof(prec->evnt);
  pdbRecordType->papFldDes[6]->offset=(short)((char *)&prec->evnt - (char *)prec);
  pdbRecordType->papFldDes[7]->size=sizeof(prec->tse);
  pdbRecordType->papFldDes[7]->offset=(short)((char *)&prec->tse - (char *)prec);
  pdbRecordType->papFldDes[8]->size=sizeof(prec->tsel);
  pdbRecordType->papFldDes[8]->offset=(short)((char *)&prec->tsel - (char *)prec);
  pdbRecordType->papFldDes[9]->size=sizeof(prec->dtyp);
  pdbRecordType->papFldDes[9]->offset=(short)((char *)&prec->dtyp - (char *)prec);
  pdbRecordType->papFldDes[10]->size=sizeof(prec->disv);
  pdbRecordType->papFldDes[10]->offset=(short)((char *)&prec->disv - (char *)prec);
  pdbRecordType->papFldDes[11]->size=sizeof(prec->disa);
  pdbRecordType->papFldDes[11]->offset=(short)((char *)&prec->disa - (char *)prec);
  pdbRecordType->papFldDes[12]->size=sizeof(prec->sdis);
  pdbRecordType->papFldDes[12]->offset=(short)((char *)&prec->sdis - (char *)prec);
  pdbRecordType->papFldDes[13]->size=sizeof(prec->mlok);
  pdbRecordType->papFldDes[13]->offset=(short)((char *)&prec->mlok - (char *)prec);
  pdbRecordType->papFldDes[14]->size=sizeof(prec->mlis);
  pdbRecordType->papFldDes[14]->offset=(short)((char *)&prec->mlis - (char *)prec);
  pdbRecordType->papFldDes[15]->size=sizeof(prec->disp);
  pdbRecordType->papFldDes[15]->offset=(short)((char *)&prec->disp - (char *)prec);
  pdbRecordType->papFldDes[16]->size=sizeof(prec->proc);
  pdbRecordType->papFldDes[16]->offset=(short)((char *)&prec->proc - (char *)prec);
  pdbRecordType->papFldDes[17]->size=sizeof(prec->stat);
  pdbRecordType->papFldDes[17]->offset=(short)((char *)&prec->stat - (char *)prec);
  pdbRecordType->papFldDes[18]->size=sizeof(prec->sevr);
  pdbRecordType->papFldDes[18]->offset=(short)((char *)&prec->sevr - (char *)prec);
  pdbRecordType->papFldDes[19]->size=sizeof(prec->nsta);
  pdbRecordType->papFldDes[19]->offset=(short)((char *)&prec->nsta - (char *)prec);
  pdbRecordType->papFldDes[20]->size=sizeof(prec->nsev);
  pdbRecordType->papFldDes[20]->offset=(short)((char *)&prec->nsev - (char *)prec);
  pdbRecordType->papFldDes[21]->size=sizeof(prec->acks);
  pdbRecordType->papFldDes[21]->offset=(short)((char *)&prec->acks - (char *)prec);
  pdbRecordType->papFldDes[22]->size=sizeof(prec->ackt);
  pdbRecordType->papFldDes[22]->offset=(short)((char *)&prec->ackt - (char *)prec);
  pdbRecordType->papFldDes[23]->size=sizeof(prec->diss);
  pdbRecordType->papFldDes[23]->offset=(short)((char *)&prec->diss - (char *)prec);
  pdbRecordType->papFldDes[24]->size=sizeof(prec->lcnt);
  pdbRecordType->papFldDes[24]->offset=(short)((char *)&prec->lcnt - (char *)prec);
  pdbRecordType->papFldDes[25]->size=sizeof(prec->pact);
  pdbRecordType->papFldDes[25]->offset=(short)((char *)&prec->pact - (char *)prec);
  pdbRecordType->papFldDes[26]->size=sizeof(prec->putf);
  pdbRecordType->papFldDes[26]->offset=(short)((char *)&prec->putf - (char *)prec);
  pdbRecordType->papFldDes[27]->size=sizeof(prec->rpro);
  pdbRecordType->papFldDes[27]->offset=(short)((char *)&prec->rpro - (char *)prec);
  pdbRecordType->papFldDes[28]->size=sizeof(prec->asp);
  pdbRecordType->papFldDes[28]->offset=(short)((char *)&prec->asp - (char *)prec);
  pdbRecordType->papFldDes[29]->size=sizeof(prec->ppn);
  pdbRecordType->papFldDes[29]->offset=(short)((char *)&prec->ppn - (char *)prec);
  pdbRecordType->papFldDes[30]->size=sizeof(prec->ppnr);
  pdbRecordType->papFldDes[30]->offset=(short)((char *)&prec->ppnr - (char *)prec);
  pdbRecordType->papFldDes[31]->size=sizeof(prec->spvt);
  pdbRecordType->papFldDes[31]->offset=(short)((char *)&prec->spvt - (char *)prec);
  pdbRecordType->papFldDes[32]->size=sizeof(prec->rset);
  pdbRecordType->papFldDes[32]->offset=(short)((char *)&prec->rset - (char *)prec);
  pdbRecordType->papFldDes[33]->size=sizeof(prec->dset);
  pdbRecordType->papFldDes[33]->offset=(short)((char *)&prec->dset - (char *)prec);
  pdbRecordType->papFldDes[34]->size=sizeof(prec->dpvt);
  pdbRecordType->papFldDes[34]->offset=(short)((char *)&prec->dpvt - (char *)prec);
  pdbRecordType->papFldDes[35]->size=sizeof(prec->rdes);
  pdbRecordType->papFldDes[35]->offset=(short)((char *)&prec->rdes - (char *)prec);
  pdbRecordType->papFldDes[36]->size=sizeof(prec->lset);
  pdbRecordType->papFldDes[36]->offset=(short)((char *)&prec->lset - (char *)prec);
  pdbRecordType->papFldDes[37]->size=sizeof(prec->prio);
  pdbRecordType->papFldDes[37]->offset=(short)((char *)&prec->prio - (char *)prec);
  pdbRecordType->papFldDes[38]->size=sizeof(prec->tpro);
  pdbRecordType->papFldDes[38]->offset=(short)((char *)&prec->tpro - (char *)prec);
  pdbRecordType->papFldDes[39]->size=sizeof(prec->bkpt);
  pdbRecordType->papFldDes[39]->offset=(short)((char *)&prec->bkpt - (char *)prec);
  pdbRecordType->papFldDes[40]->size=sizeof(prec->udf);
  pdbRecordType->papFldDes[40]->offset=(short)((char *)&prec->udf - (char *)prec);
  pdbRecordType->papFldDes[41]->size=sizeof(prec->time);
  pdbRecordType->papFldDes[41]->offset=(short)((char *)&prec->time - (char *)prec);
  pdbRecordType->papFldDes[42]->size=sizeof(prec->flnk);
  pdbRecordType->papFldDes[42]->offset=(short)((char *)&prec->flnk - (char *)prec);
  pdbRecordType->papFldDes[43]->size=sizeof(prec->val);
  pdbRecordType->papFldDes[43]->offset=(short)((char *)&prec->val - (char *)prec);
  pdbRecordType->papFldDes[44]->size=sizeof(prec->port);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->port - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->addr);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->addr - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->pcnct);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->pcnct - (char *)prec);
  pdbRecordType->papFldDes[47]->size=sizeof(prec->drvinfo);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->drvinfo - (char *)prec);
  pdbRecordType->papFldDes[48]->size=sizeof(prec->reason);
  pdbRecordType->papFldDes[48]->offset=(short)((char *)&prec->reason - (char *)prec);
  pdbRecordType->papFldDes[49]->size=sizeof(prec->sock);
  pdbRecordType->papFldDes[49]->offset=(short)((char *)&prec->sock - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->tmod);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->tmod - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->tmot);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->tmot - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->iface);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->iface - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->octetiv);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->octetiv - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->optioniv);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->optioniv - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->gpibiv);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->gpibiv - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->i32iv);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->i32iv - (char *)prec);
  pdbRecordType->papFldDes[57]->size=sizeof(prec->ui32iv);
  pdbRecordType->papFldDes[57]->offset=(short)((char *)&prec->ui32iv - (char *)prec);
  pdbRecordType->papFldDes[58]->size=sizeof(prec->f64iv);
  pdbRecordType->papFldDes[58]->offset=(short)((char *)&prec->f64iv - (char *)prec);
  pdbRecordType->papFldDes[59]->size=sizeof(prec->aout);
  pdbRecordType->papFldDes[59]->offset=(short)((char *)&prec->aout - (char *)prec);
  pdbRecordType->papFldDes[60]->size=sizeof(prec->oeos);
  pdbRecordType->papFldDes[60]->offset=(short)((char *)&prec->oeos - (char *)prec);
  pdbRecordType->papFldDes[61]->size=sizeof(prec->bout);
  pdbRecordType->papFldDes[61]->offset=(short)((char *)&prec->bout - (char *)prec);
  pdbRecordType->papFldDes[62]->size=sizeof(prec->optr);
  pdbRecordType->papFldDes[62]->offset=(short)((char *)&prec->optr - (char *)prec);
  pdbRecordType->papFldDes[63]->size=sizeof(prec->omax);
  pdbRecordType->papFldDes[63]->offset=(short)((char *)&prec->omax - (char *)prec);
  pdbRecordType->papFldDes[64]->size=sizeof(prec->nowt);
  pdbRecordType->papFldDes[64]->offset=(short)((char *)&prec->nowt - (char *)prec);
  pdbRecordType->papFldDes[65]->size=sizeof(prec->nawt);
  pdbRecordType->papFldDes[65]->offset=(short)((char *)&prec->nawt - (char *)prec);
  pdbRecordType->papFldDes[66]->size=sizeof(prec->ofmt);
  pdbRecordType->papFldDes[66]->offset=(short)((char *)&prec->ofmt - (char *)prec);
  pdbRecordType->papFldDes[67]->size=sizeof(prec->ainp);
  pdbRecordType->papFldDes[67]->offset=(short)((char *)&prec->ainp - (char *)prec);
  pdbRecordType->papFldDes[68]->size=sizeof(prec->tinp);
  pdbRecordType->papFldDes[68]->offset=(short)((char *)&prec->tinp - (char *)prec);
  pdbRecordType->papFldDes[69]->size=sizeof(prec->ieos);
  pdbRecordType->papFldDes[69]->offset=(short)((char *)&prec->ieos - (char *)prec);
  pdbRecordType->papFldDes[70]->size=sizeof(prec->binp);
  pdbRecordType->papFldDes[70]->offset=(short)((char *)&prec->binp - (char *)prec);
  pdbRecordType->papFldDes[71]->size=sizeof(prec->iptr);
  pdbRecordType->papFldDes[71]->offset=(short)((char *)&prec->iptr - (char *)prec);
  pdbRecordType->papFldDes[72]->size=sizeof(prec->imax);
  pdbRecordType->papFldDes[72]->offset=(short)((char *)&prec->imax - (char *)prec);
  pdbRecordType->papFldDes[73]->size=sizeof(prec->nrrd);
  pdbRecordType->papFldDes[73]->offset=(short)((char *)&prec->nrrd - (char *)prec);
  pdbRecordType->papFldDes[74]->size=sizeof(prec->nord);
  pdbRecordType->papFldDes[74]->offset=(short)((char *)&prec->nord - (char *)prec);
  pdbRecordType->papFldDes[75]->size=sizeof(prec->ifmt);
  pdbRecordType->papFldDes[75]->offset=(short)((char *)&prec->ifmt - (char *)prec);
  pdbRecordType->papFldDes[76]->size=sizeof(prec->eomr);
  pdbRecordType->papFldDes[76]->offset=(short)((char *)&prec->eomr - (char *)prec);
  pdbRecordType->papFldDes[77]->size=sizeof(prec->i32inp);
  pdbRecordType->papFldDes[77]->offset=(short)((char *)&prec->i32inp - (char *)prec);
  pdbRecordType->papFldDes[78]->size=sizeof(prec->i32out);
  pdbRecordType->papFldDes[78]->offset=(short)((char *)&prec->i32out - (char *)prec);
  pdbRecordType->papFldDes[79]->size=sizeof(prec->ui32inp);
  pdbRecordType->papFldDes[79]->offset=(short)((char *)&prec->ui32inp - (char *)prec);
  pdbRecordType->papFldDes[80]->size=sizeof(prec->ui32out);
  pdbRecordType->papFldDes[80]->offset=(short)((char *)&prec->ui32out - (char *)prec);
  pdbRecordType->papFldDes[81]->size=sizeof(prec->ui32mask);
  pdbRecordType->papFldDes[81]->offset=(short)((char *)&prec->ui32mask - (char *)prec);
  pdbRecordType->papFldDes[82]->size=sizeof(prec->f64inp);
  pdbRecordType->papFldDes[82]->offset=(short)((char *)&prec->f64inp - (char *)prec);
  pdbRecordType->papFldDes[83]->size=sizeof(prec->f64out);
  pdbRecordType->papFldDes[83]->offset=(short)((char *)&prec->f64out - (char *)prec);
  pdbRecordType->papFldDes[84]->size=sizeof(prec->baud);
  pdbRecordType->papFldDes[84]->offset=(short)((char *)&prec->baud - (char *)prec);
  pdbRecordType->papFldDes[85]->size=sizeof(prec->prty);
  pdbRecordType->papFldDes[85]->offset=(short)((char *)&prec->prty - (char *)prec);
  pdbRecordType->papFldDes[86]->size=sizeof(prec->dbit);
  pdbRecordType->papFldDes[86]->offset=(short)((char *)&prec->dbit - (char *)prec);
  pdbRecordType->papFldDes[87]->size=sizeof(prec->sbit);
  pdbRecordType->papFldDes[87]->offset=(short)((char *)&prec->sbit - (char *)prec);
  pdbRecordType->papFldDes[88]->size=sizeof(prec->mctl);
  pdbRecordType->papFldDes[88]->offset=(short)((char *)&prec->mctl - (char *)prec);
  pdbRecordType->papFldDes[89]->size=sizeof(prec->fctl);
  pdbRecordType->papFldDes[89]->offset=(short)((char *)&prec->fctl - (char *)prec);
  pdbRecordType->papFldDes[90]->size=sizeof(prec->ucmd);
  pdbRecordType->papFldDes[90]->offset=(short)((char *)&prec->ucmd - (char *)prec);
  pdbRecordType->papFldDes[91]->size=sizeof(prec->acmd);
  pdbRecordType->papFldDes[91]->offset=(short)((char *)&prec->acmd - (char *)prec);
  pdbRecordType->papFldDes[92]->size=sizeof(prec->spr);
  pdbRecordType->papFldDes[92]->offset=(short)((char *)&prec->spr - (char *)prec);
  pdbRecordType->papFldDes[93]->size=sizeof(prec->tmsk);
  pdbRecordType->papFldDes[93]->offset=(short)((char *)&prec->tmsk - (char *)prec);
  pdbRecordType->papFldDes[94]->size=sizeof(prec->tb0);
  pdbRecordType->papFldDes[94]->offset=(short)((char *)&prec->tb0 - (char *)prec);
  pdbRecordType->papFldDes[95]->size=sizeof(prec->tb1);
  pdbRecordType->papFldDes[95]->offset=(short)((char *)&prec->tb1 - (char *)prec);
  pdbRecordType->papFldDes[96]->size=sizeof(prec->tb2);
  pdbRecordType->papFldDes[96]->offset=(short)((char *)&prec->tb2 - (char *)prec);
  pdbRecordType->papFldDes[97]->size=sizeof(prec->tb3);
  pdbRecordType->papFldDes[97]->offset=(short)((char *)&prec->tb3 - (char *)prec);
  pdbRecordType->papFldDes[98]->size=sizeof(prec->tb4);
  pdbRecordType->papFldDes[98]->offset=(short)((char *)&prec->tb4 - (char *)prec);
  pdbRecordType->papFldDes[99]->size=sizeof(prec->tiom);
  pdbRecordType->papFldDes[99]->offset=(short)((char *)&prec->tiom - (char *)prec);
  pdbRecordType->papFldDes[100]->size=sizeof(prec->tib0);
  pdbRecordType->papFldDes[100]->offset=(short)((char *)&prec->tib0 - (char *)prec);
  pdbRecordType->papFldDes[101]->size=sizeof(prec->tib1);
  pdbRecordType->papFldDes[101]->offset=(short)((char *)&prec->tib1 - (char *)prec);
  pdbRecordType->papFldDes[102]->size=sizeof(prec->tib2);
  pdbRecordType->papFldDes[102]->offset=(short)((char *)&prec->tib2 - (char *)prec);
  pdbRecordType->papFldDes[103]->size=sizeof(prec->tsiz);
  pdbRecordType->papFldDes[103]->offset=(short)((char *)&prec->tsiz - (char *)prec);
  pdbRecordType->papFldDes[104]->size=sizeof(prec->tfil);
  pdbRecordType->papFldDes[104]->offset=(short)((char *)&prec->tfil - (char *)prec);
  pdbRecordType->papFldDes[105]->size=sizeof(prec->auct);
  pdbRecordType->papFldDes[105]->offset=(short)((char *)&prec->auct - (char *)prec);
  pdbRecordType->papFldDes[106]->size=sizeof(prec->cnct);
  pdbRecordType->papFldDes[106]->offset=(short)((char *)&prec->cnct - (char *)prec);
  pdbRecordType->papFldDes[107]->size=sizeof(prec->enbl);
  pdbRecordType->papFldDes[107]->offset=(short)((char *)&prec->enbl - (char *)prec);
  pdbRecordType->papFldDes[108]->size=sizeof(prec->errs);
  pdbRecordType->papFldDes[108]->offset=(short)((char *)&prec->errs - (char *)prec);
  pdbRecordType->papFldDes[109]->size=sizeof(prec->aqr);
  pdbRecordType->papFldDes[109]->offset=(short)((char *)&prec->aqr - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(asynRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
