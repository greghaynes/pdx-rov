#ifndef INCboH
#define INCboH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
typedef struct boRecord {
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
	epicsEnum16	val;	/* Current Value */
	epicsEnum16	omsl;	/* Output Mode Select */
	DBLINK		dol;	/* Desired Output Loc */
	DBLINK		out;	/* Output Specification */
	epicsFloat64	high;	/* Seconds to Hold High */
	char		znam[26];	/* Zero Name */
	char		onam[26];	/* One Name */
	epicsUInt32	rval;	/* Raw Value */
	epicsUInt32	oraw;	/* prev Raw Value */
	epicsUInt32	mask;	/* Hardware Mask */
	void *  rpvt;	/* Record Private */
	void *	wdpt;	/* Watch Dog Timer ID */
	epicsEnum16	zsv;	/* Zero Error Severity */
	epicsEnum16	osv;	/* One Error Severity */
	epicsEnum16	cosv;	/* Change of State Sevr */
	epicsUInt32	rbv;	/* Readback Value */
	epicsUInt32	orbv;	/* Prev Readback Value */
	epicsUInt16	mlst;	/* Last Value Monitored */
	epicsUInt16	lalm;	/* Last Value Alarmed */
	DBLINK		siol;	/* Sim Output Specifctn */
	DBLINK		siml;	/* Sim Mode Location */
	epicsEnum16	simm;	/* Simulation Mode */
	epicsEnum16	sims;	/* Sim mode Alarm Svrty */
	epicsEnum16	ivoa;	/* INVALID outpt action */
	epicsUInt16	ivov;	/* INVALID output value */
} boRecord;
#define boRecordNAME	0
#define boRecordDESC	1
#define boRecordASG	2
#define boRecordSCAN	3
#define boRecordPINI	4
#define boRecordPHAS	5
#define boRecordEVNT	6
#define boRecordTSE	7
#define boRecordTSEL	8
#define boRecordDTYP	9
#define boRecordDISV	10
#define boRecordDISA	11
#define boRecordSDIS	12
#define boRecordMLOK	13
#define boRecordMLIS	14
#define boRecordDISP	15
#define boRecordPROC	16
#define boRecordSTAT	17
#define boRecordSEVR	18
#define boRecordNSTA	19
#define boRecordNSEV	20
#define boRecordACKS	21
#define boRecordACKT	22
#define boRecordDISS	23
#define boRecordLCNT	24
#define boRecordPACT	25
#define boRecordPUTF	26
#define boRecordRPRO	27
#define boRecordASP	28
#define boRecordPPN	29
#define boRecordPPNR	30
#define boRecordSPVT	31
#define boRecordRSET	32
#define boRecordDSET	33
#define boRecordDPVT	34
#define boRecordRDES	35
#define boRecordLSET	36
#define boRecordPRIO	37
#define boRecordTPRO	38
#define boRecordBKPT	39
#define boRecordUDF	40
#define boRecordTIME	41
#define boRecordFLNK	42
#define boRecordVAL	43
#define boRecordOMSL	44
#define boRecordDOL	45
#define boRecordOUT	46
#define boRecordHIGH	47
#define boRecordZNAM	48
#define boRecordONAM	49
#define boRecordRVAL	50
#define boRecordORAW	51
#define boRecordMASK	52
#define boRecordRPVT	53
#define boRecordWDPT	54
#define boRecordZSV	55
#define boRecordOSV	56
#define boRecordCOSV	57
#define boRecordRBV	58
#define boRecordORBV	59
#define boRecordMLST	60
#define boRecordLALM	61
#define boRecordSIOL	62
#define boRecordSIML	63
#define boRecordSIMM	64
#define boRecordSIMS	65
#define boRecordIVOA	66
#define boRecordIVOV	67
#endif /*INCboH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsExport.h>
static int boRecordSizeOffset(dbRecordType *pdbRecordType)
{
    boRecord *prec = 0;
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
  pdbRecordType->papFldDes[44]->size=sizeof(prec->omsl);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->omsl - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->dol);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->dol - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->out);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->out - (char *)prec);
  pdbRecordType->papFldDes[47]->size=sizeof(prec->high);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->high - (char *)prec);
  pdbRecordType->papFldDes[48]->size=sizeof(prec->znam);
  pdbRecordType->papFldDes[48]->offset=(short)((char *)&prec->znam - (char *)prec);
  pdbRecordType->papFldDes[49]->size=sizeof(prec->onam);
  pdbRecordType->papFldDes[49]->offset=(short)((char *)&prec->onam - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->rval);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->rval - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->oraw);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->oraw - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->mask);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->mask - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->rpvt);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->rpvt - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->wdpt);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->wdpt - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->zsv);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->zsv - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->osv);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->osv - (char *)prec);
  pdbRecordType->papFldDes[57]->size=sizeof(prec->cosv);
  pdbRecordType->papFldDes[57]->offset=(short)((char *)&prec->cosv - (char *)prec);
  pdbRecordType->papFldDes[58]->size=sizeof(prec->rbv);
  pdbRecordType->papFldDes[58]->offset=(short)((char *)&prec->rbv - (char *)prec);
  pdbRecordType->papFldDes[59]->size=sizeof(prec->orbv);
  pdbRecordType->papFldDes[59]->offset=(short)((char *)&prec->orbv - (char *)prec);
  pdbRecordType->papFldDes[60]->size=sizeof(prec->mlst);
  pdbRecordType->papFldDes[60]->offset=(short)((char *)&prec->mlst - (char *)prec);
  pdbRecordType->papFldDes[61]->size=sizeof(prec->lalm);
  pdbRecordType->papFldDes[61]->offset=(short)((char *)&prec->lalm - (char *)prec);
  pdbRecordType->papFldDes[62]->size=sizeof(prec->siol);
  pdbRecordType->papFldDes[62]->offset=(short)((char *)&prec->siol - (char *)prec);
  pdbRecordType->papFldDes[63]->size=sizeof(prec->siml);
  pdbRecordType->papFldDes[63]->offset=(short)((char *)&prec->siml - (char *)prec);
  pdbRecordType->papFldDes[64]->size=sizeof(prec->simm);
  pdbRecordType->papFldDes[64]->offset=(short)((char *)&prec->simm - (char *)prec);
  pdbRecordType->papFldDes[65]->size=sizeof(prec->sims);
  pdbRecordType->papFldDes[65]->offset=(short)((char *)&prec->sims - (char *)prec);
  pdbRecordType->papFldDes[66]->size=sizeof(prec->ivoa);
  pdbRecordType->papFldDes[66]->offset=(short)((char *)&prec->ivoa - (char *)prec);
  pdbRecordType->papFldDes[67]->size=sizeof(prec->ivov);
  pdbRecordType->papFldDes[67]->offset=(short)((char *)&prec->ivov - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(boRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
