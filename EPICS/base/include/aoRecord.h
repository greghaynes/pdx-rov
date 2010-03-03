
#ifndef INCaoOIFH
#define INCaoOIFH
typedef enum {
	aoOIF_Full,
	aoOIF_Incremental
}aoOIF;
#endif /*INCaoOIFH*/
#ifndef INCaoH
#define INCaoH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
typedef struct aoRecord {
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
	epicsFloat64	val;	/* Desired Output */
	epicsFloat64	oval;	/* Output Value */
	DBLINK		out;	/* Output Specification */
	epicsFloat64	oroc;	/* Output Rate of Chang */
	DBLINK		dol;	/* Desired Output Loc */
	epicsEnum16	omsl;	/* Output Mode Select */
	epicsEnum16	oif;	/* Out Full/Incremental */
	epicsInt16	prec;	/* Display Precision */
	epicsEnum16	linr;	/* Linearization */
	epicsFloat64	eguf;	/* Eng Units Full */
	epicsFloat64	egul;	/* Eng Units Low */
	char		egu[16];	/* Engineering Units */
	epicsInt32	roff;	/* Raw Offset, obsolete */
	epicsFloat64	eoff;	/* EGU to Raw Offset */
	epicsFloat64	eslo;	/* EGU to Raw Slope */
	epicsFloat64	drvh;	/* Drive High Limit */
	epicsFloat64	drvl;	/* Drive Low Limit */
	epicsFloat64	hopr;	/* High Operating Range */
	epicsFloat64	lopr;	/* Low Operating Range */
	epicsFloat64	aoff;	/* Adjustment Offset */
	epicsFloat64	aslo;	/* Adjustment Slope */
	epicsFloat64	hihi;	/* Hihi Alarm Limit */
	epicsFloat64	lolo;	/* Lolo Alarm Limit */
	epicsFloat64	high;	/* High Alarm Limit */
	epicsFloat64	low;	/* Low Alarm Limit */
	epicsEnum16	hhsv;	/* Hihi Severity */
	epicsEnum16	llsv;	/* Lolo Severity */
	epicsEnum16	hsv;	/* High Severity */
	epicsEnum16	lsv;	/* Low Severity */
	epicsFloat64	hyst;	/* Alarm Deadband */
	epicsFloat64	adel;	/* Archive Deadband */
	epicsFloat64	mdel;	/* Monitor Deadband */
	epicsInt32	rval;	/* Current Raw Value */
	epicsInt32	oraw;	/* Previous Raw Value */
	epicsInt32	rbv;	/* Readback Value */
	epicsInt32	orbv;	/* Prev Readback Value */
	epicsFloat64	pval;	/* Previous value */
	epicsFloat64	lalm;	/* Last Value Alarmed */
	epicsFloat64	alst;	/* Last Value Archived */
	epicsFloat64	mlst;	/* Last Val Monitored */
	void *	pbrk;	/* Ptrto brkTable */
	epicsInt16	init;	/* Initialized? */
	epicsInt16	lbrk;	/* LastBreak Point */
	DBLINK		siol;	/* Sim Output Specifctn */
	DBLINK		siml;	/* Sim Mode Location */
	epicsEnum16	simm;	/* Simulation Mode */
	epicsEnum16	sims;	/* Sim mode Alarm Svrty */
	epicsEnum16	ivoa;	/* INVALID output action */
	epicsFloat64	ivov;	/* INVALID output value */
	epicsUInt8	omod;	/* Was OVAL modified? */
} aoRecord;
#define aoRecordNAME	0
#define aoRecordDESC	1
#define aoRecordASG	2
#define aoRecordSCAN	3
#define aoRecordPINI	4
#define aoRecordPHAS	5
#define aoRecordEVNT	6
#define aoRecordTSE	7
#define aoRecordTSEL	8
#define aoRecordDTYP	9
#define aoRecordDISV	10
#define aoRecordDISA	11
#define aoRecordSDIS	12
#define aoRecordMLOK	13
#define aoRecordMLIS	14
#define aoRecordDISP	15
#define aoRecordPROC	16
#define aoRecordSTAT	17
#define aoRecordSEVR	18
#define aoRecordNSTA	19
#define aoRecordNSEV	20
#define aoRecordACKS	21
#define aoRecordACKT	22
#define aoRecordDISS	23
#define aoRecordLCNT	24
#define aoRecordPACT	25
#define aoRecordPUTF	26
#define aoRecordRPRO	27
#define aoRecordASP	28
#define aoRecordPPN	29
#define aoRecordPPNR	30
#define aoRecordSPVT	31
#define aoRecordRSET	32
#define aoRecordDSET	33
#define aoRecordDPVT	34
#define aoRecordRDES	35
#define aoRecordLSET	36
#define aoRecordPRIO	37
#define aoRecordTPRO	38
#define aoRecordBKPT	39
#define aoRecordUDF	40
#define aoRecordTIME	41
#define aoRecordFLNK	42
#define aoRecordVAL	43
#define aoRecordOVAL	44
#define aoRecordOUT	45
#define aoRecordOROC	46
#define aoRecordDOL	47
#define aoRecordOMSL	48
#define aoRecordOIF	49
#define aoRecordPREC	50
#define aoRecordLINR	51
#define aoRecordEGUF	52
#define aoRecordEGUL	53
#define aoRecordEGU	54
#define aoRecordROFF	55
#define aoRecordEOFF	56
#define aoRecordESLO	57
#define aoRecordDRVH	58
#define aoRecordDRVL	59
#define aoRecordHOPR	60
#define aoRecordLOPR	61
#define aoRecordAOFF	62
#define aoRecordASLO	63
#define aoRecordHIHI	64
#define aoRecordLOLO	65
#define aoRecordHIGH	66
#define aoRecordLOW	67
#define aoRecordHHSV	68
#define aoRecordLLSV	69
#define aoRecordHSV	70
#define aoRecordLSV	71
#define aoRecordHYST	72
#define aoRecordADEL	73
#define aoRecordMDEL	74
#define aoRecordRVAL	75
#define aoRecordORAW	76
#define aoRecordRBV	77
#define aoRecordORBV	78
#define aoRecordPVAL	79
#define aoRecordLALM	80
#define aoRecordALST	81
#define aoRecordMLST	82
#define aoRecordPBRK	83
#define aoRecordINIT	84
#define aoRecordLBRK	85
#define aoRecordSIOL	86
#define aoRecordSIML	87
#define aoRecordSIMM	88
#define aoRecordSIMS	89
#define aoRecordIVOA	90
#define aoRecordIVOV	91
#define aoRecordOMOD	92
#endif /*INCaoH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsExport.h>
static int aoRecordSizeOffset(dbRecordType *pdbRecordType)
{
    aoRecord *prec = 0;
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
  pdbRecordType->papFldDes[44]->size=sizeof(prec->oval);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->oval - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->out);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->out - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->oroc);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->oroc - (char *)prec);
  pdbRecordType->papFldDes[47]->size=sizeof(prec->dol);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->dol - (char *)prec);
  pdbRecordType->papFldDes[48]->size=sizeof(prec->omsl);
  pdbRecordType->papFldDes[48]->offset=(short)((char *)&prec->omsl - (char *)prec);
  pdbRecordType->papFldDes[49]->size=sizeof(prec->oif);
  pdbRecordType->papFldDes[49]->offset=(short)((char *)&prec->oif - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->prec);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->prec - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->linr);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->linr - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->eguf);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->eguf - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->egul);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->egul - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->egu);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->egu - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->roff);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->roff - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->eoff);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->eoff - (char *)prec);
  pdbRecordType->papFldDes[57]->size=sizeof(prec->eslo);
  pdbRecordType->papFldDes[57]->offset=(short)((char *)&prec->eslo - (char *)prec);
  pdbRecordType->papFldDes[58]->size=sizeof(prec->drvh);
  pdbRecordType->papFldDes[58]->offset=(short)((char *)&prec->drvh - (char *)prec);
  pdbRecordType->papFldDes[59]->size=sizeof(prec->drvl);
  pdbRecordType->papFldDes[59]->offset=(short)((char *)&prec->drvl - (char *)prec);
  pdbRecordType->papFldDes[60]->size=sizeof(prec->hopr);
  pdbRecordType->papFldDes[60]->offset=(short)((char *)&prec->hopr - (char *)prec);
  pdbRecordType->papFldDes[61]->size=sizeof(prec->lopr);
  pdbRecordType->papFldDes[61]->offset=(short)((char *)&prec->lopr - (char *)prec);
  pdbRecordType->papFldDes[62]->size=sizeof(prec->aoff);
  pdbRecordType->papFldDes[62]->offset=(short)((char *)&prec->aoff - (char *)prec);
  pdbRecordType->papFldDes[63]->size=sizeof(prec->aslo);
  pdbRecordType->papFldDes[63]->offset=(short)((char *)&prec->aslo - (char *)prec);
  pdbRecordType->papFldDes[64]->size=sizeof(prec->hihi);
  pdbRecordType->papFldDes[64]->offset=(short)((char *)&prec->hihi - (char *)prec);
  pdbRecordType->papFldDes[65]->size=sizeof(prec->lolo);
  pdbRecordType->papFldDes[65]->offset=(short)((char *)&prec->lolo - (char *)prec);
  pdbRecordType->papFldDes[66]->size=sizeof(prec->high);
  pdbRecordType->papFldDes[66]->offset=(short)((char *)&prec->high - (char *)prec);
  pdbRecordType->papFldDes[67]->size=sizeof(prec->low);
  pdbRecordType->papFldDes[67]->offset=(short)((char *)&prec->low - (char *)prec);
  pdbRecordType->papFldDes[68]->size=sizeof(prec->hhsv);
  pdbRecordType->papFldDes[68]->offset=(short)((char *)&prec->hhsv - (char *)prec);
  pdbRecordType->papFldDes[69]->size=sizeof(prec->llsv);
  pdbRecordType->papFldDes[69]->offset=(short)((char *)&prec->llsv - (char *)prec);
  pdbRecordType->papFldDes[70]->size=sizeof(prec->hsv);
  pdbRecordType->papFldDes[70]->offset=(short)((char *)&prec->hsv - (char *)prec);
  pdbRecordType->papFldDes[71]->size=sizeof(prec->lsv);
  pdbRecordType->papFldDes[71]->offset=(short)((char *)&prec->lsv - (char *)prec);
  pdbRecordType->papFldDes[72]->size=sizeof(prec->hyst);
  pdbRecordType->papFldDes[72]->offset=(short)((char *)&prec->hyst - (char *)prec);
  pdbRecordType->papFldDes[73]->size=sizeof(prec->adel);
  pdbRecordType->papFldDes[73]->offset=(short)((char *)&prec->adel - (char *)prec);
  pdbRecordType->papFldDes[74]->size=sizeof(prec->mdel);
  pdbRecordType->papFldDes[74]->offset=(short)((char *)&prec->mdel - (char *)prec);
  pdbRecordType->papFldDes[75]->size=sizeof(prec->rval);
  pdbRecordType->papFldDes[75]->offset=(short)((char *)&prec->rval - (char *)prec);
  pdbRecordType->papFldDes[76]->size=sizeof(prec->oraw);
  pdbRecordType->papFldDes[76]->offset=(short)((char *)&prec->oraw - (char *)prec);
  pdbRecordType->papFldDes[77]->size=sizeof(prec->rbv);
  pdbRecordType->papFldDes[77]->offset=(short)((char *)&prec->rbv - (char *)prec);
  pdbRecordType->papFldDes[78]->size=sizeof(prec->orbv);
  pdbRecordType->papFldDes[78]->offset=(short)((char *)&prec->orbv - (char *)prec);
  pdbRecordType->papFldDes[79]->size=sizeof(prec->pval);
  pdbRecordType->papFldDes[79]->offset=(short)((char *)&prec->pval - (char *)prec);
  pdbRecordType->papFldDes[80]->size=sizeof(prec->lalm);
  pdbRecordType->papFldDes[80]->offset=(short)((char *)&prec->lalm - (char *)prec);
  pdbRecordType->papFldDes[81]->size=sizeof(prec->alst);
  pdbRecordType->papFldDes[81]->offset=(short)((char *)&prec->alst - (char *)prec);
  pdbRecordType->papFldDes[82]->size=sizeof(prec->mlst);
  pdbRecordType->papFldDes[82]->offset=(short)((char *)&prec->mlst - (char *)prec);
  pdbRecordType->papFldDes[83]->size=sizeof(prec->pbrk);
  pdbRecordType->papFldDes[83]->offset=(short)((char *)&prec->pbrk - (char *)prec);
  pdbRecordType->papFldDes[84]->size=sizeof(prec->init);
  pdbRecordType->papFldDes[84]->offset=(short)((char *)&prec->init - (char *)prec);
  pdbRecordType->papFldDes[85]->size=sizeof(prec->lbrk);
  pdbRecordType->papFldDes[85]->offset=(short)((char *)&prec->lbrk - (char *)prec);
  pdbRecordType->papFldDes[86]->size=sizeof(prec->siol);
  pdbRecordType->papFldDes[86]->offset=(short)((char *)&prec->siol - (char *)prec);
  pdbRecordType->papFldDes[87]->size=sizeof(prec->siml);
  pdbRecordType->papFldDes[87]->offset=(short)((char *)&prec->siml - (char *)prec);
  pdbRecordType->papFldDes[88]->size=sizeof(prec->simm);
  pdbRecordType->papFldDes[88]->offset=(short)((char *)&prec->simm - (char *)prec);
  pdbRecordType->papFldDes[89]->size=sizeof(prec->sims);
  pdbRecordType->papFldDes[89]->offset=(short)((char *)&prec->sims - (char *)prec);
  pdbRecordType->papFldDes[90]->size=sizeof(prec->ivoa);
  pdbRecordType->papFldDes[90]->offset=(short)((char *)&prec->ivoa - (char *)prec);
  pdbRecordType->papFldDes[91]->size=sizeof(prec->ivov);
  pdbRecordType->papFldDes[91]->offset=(short)((char *)&prec->ivov - (char *)prec);
  pdbRecordType->papFldDes[92]->size=sizeof(prec->omod);
  pdbRecordType->papFldDes[92]->offset=(short)((char *)&prec->omod - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(aoRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
