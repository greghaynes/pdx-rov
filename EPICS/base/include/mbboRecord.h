#ifndef INCmbboH
#define INCmbboH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
typedef struct mbboRecord {
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
	epicsEnum16	val;	/* Desired Value */
	DBLINK		dol;	/* Desired Output Loc */
	epicsEnum16	omsl;	/* Output Mode Select */
	epicsInt16	nobt;	/* Number of Bits */
	DBLINK		out;	/* Output Specification */
	epicsUInt32	zrvl;	/* Zero Value */
	epicsUInt32	onvl;	/* One Value */
	epicsUInt32	twvl;	/* Two Value */
	epicsUInt32	thvl;	/* Three Value */
	epicsUInt32	frvl;	/* Four Value */
	epicsUInt32	fvvl;	/* Five Value */
	epicsUInt32	sxvl;	/* Six Value */
	epicsUInt32	svvl;	/* Seven Value */
	epicsUInt32	eivl;	/* Eight Value */
	epicsUInt32	nivl;	/* Nine Value */
	epicsUInt32	tevl;	/* Ten Value */
	epicsUInt32	elvl;	/* Eleven Value */
	epicsUInt32	tvvl;	/* Twelve Value */
	epicsUInt32	ttvl;	/* Thirteen Value */
	epicsUInt32	ftvl;	/* Fourteen Value */
	epicsUInt32	ffvl;	/* Fifteen Value */
	char		zrst[26];	/* Zero String */
	char		onst[26];	/* One String */
	char		twst[26];	/* Two String */
	char		thst[26];	/* Three String */
	char		frst[26];	/* Four String */
	char		fvst[26];	/* Five String */
	char		sxst[26];	/* Six String */
	char		svst[26];	/* Seven String */
	char		eist[26];	/* Eight String */
	char		nist[26];	/* Nine String */
	char		test[26];	/* Ten String */
	char		elst[26];	/* Eleven String */
	char		tvst[26];	/* Twelve String */
	char		ttst[26];	/* Thirteen String */
	char		ftst[26];	/* Fourteen String */
	char		ffst[26];	/* Fifteen String */
	epicsEnum16	zrsv;	/* State Zero Severity */
	epicsEnum16	onsv;	/* State One Severity */
	epicsEnum16	twsv;	/* State Two Severity */
	epicsEnum16	thsv;	/* State Three Severity */
	epicsEnum16	frsv;	/* State Four Severity */
	epicsEnum16	fvsv;	/* State Five Severity */
	epicsEnum16	sxsv;	/* State Six Severity */
	epicsEnum16	svsv;	/* State Seven Severity */
	epicsEnum16	eisv;	/* State Eight Severity */
	epicsEnum16	nisv;	/* State Nine Severity */
	epicsEnum16	tesv;	/* State Ten Severity */
	epicsEnum16	elsv;	/* State Eleven Severity */
	epicsEnum16	tvsv;	/* State Twelve Severity */
	epicsEnum16	ttsv;	/* State Thirteen Sevr */
	epicsEnum16	ftsv;	/* State Fourteen Sevr */
	epicsEnum16	ffsv;	/* State Fifteen Sevr */
	epicsEnum16	unsv;	/* Unknown State Sevr */
	epicsEnum16	cosv;	/* Change of State Sevr */
	epicsUInt32	rval;	/* Raw Value */
	epicsUInt32	oraw;	/* Prev Raw Value */
	epicsUInt32	rbv;	/* Readback Value */
	epicsUInt32	orbv;	/* Prev Readback Value */
	epicsUInt32	mask;	/* Hardware Mask */
	epicsUInt16	mlst;	/* Last Value Monitored */
	epicsUInt16	lalm;	/* Last Value Alarmed */
	epicsInt16	sdef;	/* States Defined */
	epicsUInt16	shft;	/* Shift */
	DBLINK		siol;	/* Sim Output Specifctn */
	DBLINK		siml;	/* Sim Mode Location */
	epicsEnum16	simm;	/* Simulation Mode */
	epicsEnum16	sims;	/* Sim mode Alarm Svrty */
	epicsEnum16	ivoa;	/* INVALID outpt action */
	epicsUInt16	ivov;	/* INVALID output value */
} mbboRecord;
#define mbboRecordNAME	0
#define mbboRecordDESC	1
#define mbboRecordASG	2
#define mbboRecordSCAN	3
#define mbboRecordPINI	4
#define mbboRecordPHAS	5
#define mbboRecordEVNT	6
#define mbboRecordTSE	7
#define mbboRecordTSEL	8
#define mbboRecordDTYP	9
#define mbboRecordDISV	10
#define mbboRecordDISA	11
#define mbboRecordSDIS	12
#define mbboRecordMLOK	13
#define mbboRecordMLIS	14
#define mbboRecordDISP	15
#define mbboRecordPROC	16
#define mbboRecordSTAT	17
#define mbboRecordSEVR	18
#define mbboRecordNSTA	19
#define mbboRecordNSEV	20
#define mbboRecordACKS	21
#define mbboRecordACKT	22
#define mbboRecordDISS	23
#define mbboRecordLCNT	24
#define mbboRecordPACT	25
#define mbboRecordPUTF	26
#define mbboRecordRPRO	27
#define mbboRecordASP	28
#define mbboRecordPPN	29
#define mbboRecordPPNR	30
#define mbboRecordSPVT	31
#define mbboRecordRSET	32
#define mbboRecordDSET	33
#define mbboRecordDPVT	34
#define mbboRecordRDES	35
#define mbboRecordLSET	36
#define mbboRecordPRIO	37
#define mbboRecordTPRO	38
#define mbboRecordBKPT	39
#define mbboRecordUDF	40
#define mbboRecordTIME	41
#define mbboRecordFLNK	42
#define mbboRecordVAL	43
#define mbboRecordDOL	44
#define mbboRecordOMSL	45
#define mbboRecordNOBT	46
#define mbboRecordOUT	47
#define mbboRecordZRVL	48
#define mbboRecordONVL	49
#define mbboRecordTWVL	50
#define mbboRecordTHVL	51
#define mbboRecordFRVL	52
#define mbboRecordFVVL	53
#define mbboRecordSXVL	54
#define mbboRecordSVVL	55
#define mbboRecordEIVL	56
#define mbboRecordNIVL	57
#define mbboRecordTEVL	58
#define mbboRecordELVL	59
#define mbboRecordTVVL	60
#define mbboRecordTTVL	61
#define mbboRecordFTVL	62
#define mbboRecordFFVL	63
#define mbboRecordZRST	64
#define mbboRecordONST	65
#define mbboRecordTWST	66
#define mbboRecordTHST	67
#define mbboRecordFRST	68
#define mbboRecordFVST	69
#define mbboRecordSXST	70
#define mbboRecordSVST	71
#define mbboRecordEIST	72
#define mbboRecordNIST	73
#define mbboRecordTEST	74
#define mbboRecordELST	75
#define mbboRecordTVST	76
#define mbboRecordTTST	77
#define mbboRecordFTST	78
#define mbboRecordFFST	79
#define mbboRecordZRSV	80
#define mbboRecordONSV	81
#define mbboRecordTWSV	82
#define mbboRecordTHSV	83
#define mbboRecordFRSV	84
#define mbboRecordFVSV	85
#define mbboRecordSXSV	86
#define mbboRecordSVSV	87
#define mbboRecordEISV	88
#define mbboRecordNISV	89
#define mbboRecordTESV	90
#define mbboRecordELSV	91
#define mbboRecordTVSV	92
#define mbboRecordTTSV	93
#define mbboRecordFTSV	94
#define mbboRecordFFSV	95
#define mbboRecordUNSV	96
#define mbboRecordCOSV	97
#define mbboRecordRVAL	98
#define mbboRecordORAW	99
#define mbboRecordRBV	100
#define mbboRecordORBV	101
#define mbboRecordMASK	102
#define mbboRecordMLST	103
#define mbboRecordLALM	104
#define mbboRecordSDEF	105
#define mbboRecordSHFT	106
#define mbboRecordSIOL	107
#define mbboRecordSIML	108
#define mbboRecordSIMM	109
#define mbboRecordSIMS	110
#define mbboRecordIVOA	111
#define mbboRecordIVOV	112
#endif /*INCmbboH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsExport.h>
static int mbboRecordSizeOffset(dbRecordType *pdbRecordType)
{
    mbboRecord *prec = 0;
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
  pdbRecordType->papFldDes[44]->size=sizeof(prec->dol);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->dol - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->omsl);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->omsl - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->nobt);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->nobt - (char *)prec);
  pdbRecordType->papFldDes[47]->size=sizeof(prec->out);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->out - (char *)prec);
  pdbRecordType->papFldDes[48]->size=sizeof(prec->zrvl);
  pdbRecordType->papFldDes[48]->offset=(short)((char *)&prec->zrvl - (char *)prec);
  pdbRecordType->papFldDes[49]->size=sizeof(prec->onvl);
  pdbRecordType->papFldDes[49]->offset=(short)((char *)&prec->onvl - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->twvl);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->twvl - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->thvl);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->thvl - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->frvl);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->frvl - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->fvvl);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->fvvl - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->sxvl);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->sxvl - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->svvl);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->svvl - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->eivl);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->eivl - (char *)prec);
  pdbRecordType->papFldDes[57]->size=sizeof(prec->nivl);
  pdbRecordType->papFldDes[57]->offset=(short)((char *)&prec->nivl - (char *)prec);
  pdbRecordType->papFldDes[58]->size=sizeof(prec->tevl);
  pdbRecordType->papFldDes[58]->offset=(short)((char *)&prec->tevl - (char *)prec);
  pdbRecordType->papFldDes[59]->size=sizeof(prec->elvl);
  pdbRecordType->papFldDes[59]->offset=(short)((char *)&prec->elvl - (char *)prec);
  pdbRecordType->papFldDes[60]->size=sizeof(prec->tvvl);
  pdbRecordType->papFldDes[60]->offset=(short)((char *)&prec->tvvl - (char *)prec);
  pdbRecordType->papFldDes[61]->size=sizeof(prec->ttvl);
  pdbRecordType->papFldDes[61]->offset=(short)((char *)&prec->ttvl - (char *)prec);
  pdbRecordType->papFldDes[62]->size=sizeof(prec->ftvl);
  pdbRecordType->papFldDes[62]->offset=(short)((char *)&prec->ftvl - (char *)prec);
  pdbRecordType->papFldDes[63]->size=sizeof(prec->ffvl);
  pdbRecordType->papFldDes[63]->offset=(short)((char *)&prec->ffvl - (char *)prec);
  pdbRecordType->papFldDes[64]->size=sizeof(prec->zrst);
  pdbRecordType->papFldDes[64]->offset=(short)((char *)&prec->zrst - (char *)prec);
  pdbRecordType->papFldDes[65]->size=sizeof(prec->onst);
  pdbRecordType->papFldDes[65]->offset=(short)((char *)&prec->onst - (char *)prec);
  pdbRecordType->papFldDes[66]->size=sizeof(prec->twst);
  pdbRecordType->papFldDes[66]->offset=(short)((char *)&prec->twst - (char *)prec);
  pdbRecordType->papFldDes[67]->size=sizeof(prec->thst);
  pdbRecordType->papFldDes[67]->offset=(short)((char *)&prec->thst - (char *)prec);
  pdbRecordType->papFldDes[68]->size=sizeof(prec->frst);
  pdbRecordType->papFldDes[68]->offset=(short)((char *)&prec->frst - (char *)prec);
  pdbRecordType->papFldDes[69]->size=sizeof(prec->fvst);
  pdbRecordType->papFldDes[69]->offset=(short)((char *)&prec->fvst - (char *)prec);
  pdbRecordType->papFldDes[70]->size=sizeof(prec->sxst);
  pdbRecordType->papFldDes[70]->offset=(short)((char *)&prec->sxst - (char *)prec);
  pdbRecordType->papFldDes[71]->size=sizeof(prec->svst);
  pdbRecordType->papFldDes[71]->offset=(short)((char *)&prec->svst - (char *)prec);
  pdbRecordType->papFldDes[72]->size=sizeof(prec->eist);
  pdbRecordType->papFldDes[72]->offset=(short)((char *)&prec->eist - (char *)prec);
  pdbRecordType->papFldDes[73]->size=sizeof(prec->nist);
  pdbRecordType->papFldDes[73]->offset=(short)((char *)&prec->nist - (char *)prec);
  pdbRecordType->papFldDes[74]->size=sizeof(prec->test);
  pdbRecordType->papFldDes[74]->offset=(short)((char *)&prec->test - (char *)prec);
  pdbRecordType->papFldDes[75]->size=sizeof(prec->elst);
  pdbRecordType->papFldDes[75]->offset=(short)((char *)&prec->elst - (char *)prec);
  pdbRecordType->papFldDes[76]->size=sizeof(prec->tvst);
  pdbRecordType->papFldDes[76]->offset=(short)((char *)&prec->tvst - (char *)prec);
  pdbRecordType->papFldDes[77]->size=sizeof(prec->ttst);
  pdbRecordType->papFldDes[77]->offset=(short)((char *)&prec->ttst - (char *)prec);
  pdbRecordType->papFldDes[78]->size=sizeof(prec->ftst);
  pdbRecordType->papFldDes[78]->offset=(short)((char *)&prec->ftst - (char *)prec);
  pdbRecordType->papFldDes[79]->size=sizeof(prec->ffst);
  pdbRecordType->papFldDes[79]->offset=(short)((char *)&prec->ffst - (char *)prec);
  pdbRecordType->papFldDes[80]->size=sizeof(prec->zrsv);
  pdbRecordType->papFldDes[80]->offset=(short)((char *)&prec->zrsv - (char *)prec);
  pdbRecordType->papFldDes[81]->size=sizeof(prec->onsv);
  pdbRecordType->papFldDes[81]->offset=(short)((char *)&prec->onsv - (char *)prec);
  pdbRecordType->papFldDes[82]->size=sizeof(prec->twsv);
  pdbRecordType->papFldDes[82]->offset=(short)((char *)&prec->twsv - (char *)prec);
  pdbRecordType->papFldDes[83]->size=sizeof(prec->thsv);
  pdbRecordType->papFldDes[83]->offset=(short)((char *)&prec->thsv - (char *)prec);
  pdbRecordType->papFldDes[84]->size=sizeof(prec->frsv);
  pdbRecordType->papFldDes[84]->offset=(short)((char *)&prec->frsv - (char *)prec);
  pdbRecordType->papFldDes[85]->size=sizeof(prec->fvsv);
  pdbRecordType->papFldDes[85]->offset=(short)((char *)&prec->fvsv - (char *)prec);
  pdbRecordType->papFldDes[86]->size=sizeof(prec->sxsv);
  pdbRecordType->papFldDes[86]->offset=(short)((char *)&prec->sxsv - (char *)prec);
  pdbRecordType->papFldDes[87]->size=sizeof(prec->svsv);
  pdbRecordType->papFldDes[87]->offset=(short)((char *)&prec->svsv - (char *)prec);
  pdbRecordType->papFldDes[88]->size=sizeof(prec->eisv);
  pdbRecordType->papFldDes[88]->offset=(short)((char *)&prec->eisv - (char *)prec);
  pdbRecordType->papFldDes[89]->size=sizeof(prec->nisv);
  pdbRecordType->papFldDes[89]->offset=(short)((char *)&prec->nisv - (char *)prec);
  pdbRecordType->papFldDes[90]->size=sizeof(prec->tesv);
  pdbRecordType->papFldDes[90]->offset=(short)((char *)&prec->tesv - (char *)prec);
  pdbRecordType->papFldDes[91]->size=sizeof(prec->elsv);
  pdbRecordType->papFldDes[91]->offset=(short)((char *)&prec->elsv - (char *)prec);
  pdbRecordType->papFldDes[92]->size=sizeof(prec->tvsv);
  pdbRecordType->papFldDes[92]->offset=(short)((char *)&prec->tvsv - (char *)prec);
  pdbRecordType->papFldDes[93]->size=sizeof(prec->ttsv);
  pdbRecordType->papFldDes[93]->offset=(short)((char *)&prec->ttsv - (char *)prec);
  pdbRecordType->papFldDes[94]->size=sizeof(prec->ftsv);
  pdbRecordType->papFldDes[94]->offset=(short)((char *)&prec->ftsv - (char *)prec);
  pdbRecordType->papFldDes[95]->size=sizeof(prec->ffsv);
  pdbRecordType->papFldDes[95]->offset=(short)((char *)&prec->ffsv - (char *)prec);
  pdbRecordType->papFldDes[96]->size=sizeof(prec->unsv);
  pdbRecordType->papFldDes[96]->offset=(short)((char *)&prec->unsv - (char *)prec);
  pdbRecordType->papFldDes[97]->size=sizeof(prec->cosv);
  pdbRecordType->papFldDes[97]->offset=(short)((char *)&prec->cosv - (char *)prec);
  pdbRecordType->papFldDes[98]->size=sizeof(prec->rval);
  pdbRecordType->papFldDes[98]->offset=(short)((char *)&prec->rval - (char *)prec);
  pdbRecordType->papFldDes[99]->size=sizeof(prec->oraw);
  pdbRecordType->papFldDes[99]->offset=(short)((char *)&prec->oraw - (char *)prec);
  pdbRecordType->papFldDes[100]->size=sizeof(prec->rbv);
  pdbRecordType->papFldDes[100]->offset=(short)((char *)&prec->rbv - (char *)prec);
  pdbRecordType->papFldDes[101]->size=sizeof(prec->orbv);
  pdbRecordType->papFldDes[101]->offset=(short)((char *)&prec->orbv - (char *)prec);
  pdbRecordType->papFldDes[102]->size=sizeof(prec->mask);
  pdbRecordType->papFldDes[102]->offset=(short)((char *)&prec->mask - (char *)prec);
  pdbRecordType->papFldDes[103]->size=sizeof(prec->mlst);
  pdbRecordType->papFldDes[103]->offset=(short)((char *)&prec->mlst - (char *)prec);
  pdbRecordType->papFldDes[104]->size=sizeof(prec->lalm);
  pdbRecordType->papFldDes[104]->offset=(short)((char *)&prec->lalm - (char *)prec);
  pdbRecordType->papFldDes[105]->size=sizeof(prec->sdef);
  pdbRecordType->papFldDes[105]->offset=(short)((char *)&prec->sdef - (char *)prec);
  pdbRecordType->papFldDes[106]->size=sizeof(prec->shft);
  pdbRecordType->papFldDes[106]->offset=(short)((char *)&prec->shft - (char *)prec);
  pdbRecordType->papFldDes[107]->size=sizeof(prec->siol);
  pdbRecordType->papFldDes[107]->offset=(short)((char *)&prec->siol - (char *)prec);
  pdbRecordType->papFldDes[108]->size=sizeof(prec->siml);
  pdbRecordType->papFldDes[108]->offset=(short)((char *)&prec->siml - (char *)prec);
  pdbRecordType->papFldDes[109]->size=sizeof(prec->simm);
  pdbRecordType->papFldDes[109]->offset=(short)((char *)&prec->simm - (char *)prec);
  pdbRecordType->papFldDes[110]->size=sizeof(prec->sims);
  pdbRecordType->papFldDes[110]->offset=(short)((char *)&prec->sims - (char *)prec);
  pdbRecordType->papFldDes[111]->size=sizeof(prec->ivoa);
  pdbRecordType->papFldDes[111]->offset=(short)((char *)&prec->ivoa - (char *)prec);
  pdbRecordType->papFldDes[112]->size=sizeof(prec->ivov);
  pdbRecordType->papFldDes[112]->offset=(short)((char *)&prec->ivov - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(mbboRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
