#ifndef INClongoutH
#define INClongoutH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
typedef struct longoutRecord {
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
	epicsInt32	val;	/* Desired Output */
	DBLINK		out;	/* Output Specification */
	DBLINK		dol;	/* Desired Output Loc */
	epicsEnum16	omsl;	/* Output Mode Select */
	char		egu[16];	/* Units name */
	epicsInt32	drvh;	/* Drive High Limit */
	epicsInt32	drvl;	/* Drive Low Limit */
	epicsInt32	hopr;	/* High Operating Range */
	epicsInt32	lopr;	/* Low Operating Range */
	epicsInt32	hihi;	/* Hihi Alarm Limit */
	epicsInt32	lolo;	/* Lolo Alarm Limit */
	epicsInt32	high;	/* High Alarm Limit */
	epicsInt32	low;	/* Low Alarm Limit */
	epicsEnum16	hhsv;	/* Hihi Severity */
	epicsEnum16	llsv;	/* Lolo Severity */
	epicsEnum16	hsv;	/* High Severity */
	epicsEnum16	lsv;	/* Low Severity */
	epicsInt32	hyst;	/* Alarm Deadband */
	epicsInt32	adel;	/* Archive Deadband */
	epicsInt32	mdel;	/* Monitor Deadband */
	epicsInt32	lalm;	/* Last Value Alarmed */
	epicsInt32	alst;	/* Last Value Archived */
	epicsInt32	mlst;	/* Last Val Monitored */
	DBLINK		siol;	/* Sim Output Specifctn */
	DBLINK		siml;	/* Sim Mode Location */
	epicsEnum16	simm;	/* Simulation Mode */
	epicsEnum16	sims;	/* Sim mode Alarm Svrty */
	epicsEnum16	ivoa;	/* INVALID output action */
	epicsInt32	ivov;	/* INVALID output value */
} longoutRecord;
#define longoutRecordNAME	0
#define longoutRecordDESC	1
#define longoutRecordASG	2
#define longoutRecordSCAN	3
#define longoutRecordPINI	4
#define longoutRecordPHAS	5
#define longoutRecordEVNT	6
#define longoutRecordTSE	7
#define longoutRecordTSEL	8
#define longoutRecordDTYP	9
#define longoutRecordDISV	10
#define longoutRecordDISA	11
#define longoutRecordSDIS	12
#define longoutRecordMLOK	13
#define longoutRecordMLIS	14
#define longoutRecordDISP	15
#define longoutRecordPROC	16
#define longoutRecordSTAT	17
#define longoutRecordSEVR	18
#define longoutRecordNSTA	19
#define longoutRecordNSEV	20
#define longoutRecordACKS	21
#define longoutRecordACKT	22
#define longoutRecordDISS	23
#define longoutRecordLCNT	24
#define longoutRecordPACT	25
#define longoutRecordPUTF	26
#define longoutRecordRPRO	27
#define longoutRecordASP	28
#define longoutRecordPPN	29
#define longoutRecordPPNR	30
#define longoutRecordSPVT	31
#define longoutRecordRSET	32
#define longoutRecordDSET	33
#define longoutRecordDPVT	34
#define longoutRecordRDES	35
#define longoutRecordLSET	36
#define longoutRecordPRIO	37
#define longoutRecordTPRO	38
#define longoutRecordBKPT	39
#define longoutRecordUDF	40
#define longoutRecordTIME	41
#define longoutRecordFLNK	42
#define longoutRecordVAL	43
#define longoutRecordOUT	44
#define longoutRecordDOL	45
#define longoutRecordOMSL	46
#define longoutRecordEGU	47
#define longoutRecordDRVH	48
#define longoutRecordDRVL	49
#define longoutRecordHOPR	50
#define longoutRecordLOPR	51
#define longoutRecordHIHI	52
#define longoutRecordLOLO	53
#define longoutRecordHIGH	54
#define longoutRecordLOW	55
#define longoutRecordHHSV	56
#define longoutRecordLLSV	57
#define longoutRecordHSV	58
#define longoutRecordLSV	59
#define longoutRecordHYST	60
#define longoutRecordADEL	61
#define longoutRecordMDEL	62
#define longoutRecordLALM	63
#define longoutRecordALST	64
#define longoutRecordMLST	65
#define longoutRecordSIOL	66
#define longoutRecordSIML	67
#define longoutRecordSIMM	68
#define longoutRecordSIMS	69
#define longoutRecordIVOA	70
#define longoutRecordIVOV	71
#endif /*INClongoutH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsExport.h>
static int longoutRecordSizeOffset(dbRecordType *pdbRecordType)
{
    longoutRecord *prec = 0;
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
  pdbRecordType->papFldDes[44]->size=sizeof(prec->out);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->out - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->dol);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->dol - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->omsl);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->omsl - (char *)prec);
  pdbRecordType->papFldDes[47]->size=sizeof(prec->egu);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->egu - (char *)prec);
  pdbRecordType->papFldDes[48]->size=sizeof(prec->drvh);
  pdbRecordType->papFldDes[48]->offset=(short)((char *)&prec->drvh - (char *)prec);
  pdbRecordType->papFldDes[49]->size=sizeof(prec->drvl);
  pdbRecordType->papFldDes[49]->offset=(short)((char *)&prec->drvl - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->hopr);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->hopr - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->lopr);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->lopr - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->hihi);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->hihi - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->lolo);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->lolo - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->high);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->high - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->low);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->low - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->hhsv);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->hhsv - (char *)prec);
  pdbRecordType->papFldDes[57]->size=sizeof(prec->llsv);
  pdbRecordType->papFldDes[57]->offset=(short)((char *)&prec->llsv - (char *)prec);
  pdbRecordType->papFldDes[58]->size=sizeof(prec->hsv);
  pdbRecordType->papFldDes[58]->offset=(short)((char *)&prec->hsv - (char *)prec);
  pdbRecordType->papFldDes[59]->size=sizeof(prec->lsv);
  pdbRecordType->papFldDes[59]->offset=(short)((char *)&prec->lsv - (char *)prec);
  pdbRecordType->papFldDes[60]->size=sizeof(prec->hyst);
  pdbRecordType->papFldDes[60]->offset=(short)((char *)&prec->hyst - (char *)prec);
  pdbRecordType->papFldDes[61]->size=sizeof(prec->adel);
  pdbRecordType->papFldDes[61]->offset=(short)((char *)&prec->adel - (char *)prec);
  pdbRecordType->papFldDes[62]->size=sizeof(prec->mdel);
  pdbRecordType->papFldDes[62]->offset=(short)((char *)&prec->mdel - (char *)prec);
  pdbRecordType->papFldDes[63]->size=sizeof(prec->lalm);
  pdbRecordType->papFldDes[63]->offset=(short)((char *)&prec->lalm - (char *)prec);
  pdbRecordType->papFldDes[64]->size=sizeof(prec->alst);
  pdbRecordType->papFldDes[64]->offset=(short)((char *)&prec->alst - (char *)prec);
  pdbRecordType->papFldDes[65]->size=sizeof(prec->mlst);
  pdbRecordType->papFldDes[65]->offset=(short)((char *)&prec->mlst - (char *)prec);
  pdbRecordType->papFldDes[66]->size=sizeof(prec->siol);
  pdbRecordType->papFldDes[66]->offset=(short)((char *)&prec->siol - (char *)prec);
  pdbRecordType->papFldDes[67]->size=sizeof(prec->siml);
  pdbRecordType->papFldDes[67]->offset=(short)((char *)&prec->siml - (char *)prec);
  pdbRecordType->papFldDes[68]->size=sizeof(prec->simm);
  pdbRecordType->papFldDes[68]->offset=(short)((char *)&prec->simm - (char *)prec);
  pdbRecordType->papFldDes[69]->size=sizeof(prec->sims);
  pdbRecordType->papFldDes[69]->offset=(short)((char *)&prec->sims - (char *)prec);
  pdbRecordType->papFldDes[70]->size=sizeof(prec->ivoa);
  pdbRecordType->papFldDes[70]->offset=(short)((char *)&prec->ivoa - (char *)prec);
  pdbRecordType->papFldDes[71]->size=sizeof(prec->ivov);
  pdbRecordType->papFldDes[71]->offset=(short)((char *)&prec->ivov - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(longoutRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
