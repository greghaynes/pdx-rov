#ifndef INCbiH
#define INCbiH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
typedef struct biRecord {
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
	DBLINK		inp;	/* Input Specification */
	epicsEnum16	val;	/* Current Value */
	epicsEnum16	zsv;	/* Zero Error Severity */
	epicsEnum16	osv;	/* One Error Severity */
	epicsEnum16	cosv;	/* Change of State Svr */
	char		znam[26];	/* Zero Name */
	char		onam[26];	/* One Name */
	epicsUInt32	rval;	/* Raw Value */
	epicsUInt32	oraw;	/* prev Raw Value */
	epicsUInt32	mask;	/* Hardware Mask */
	epicsUInt16	lalm;	/* Last Value Alarmed */
	epicsUInt16	mlst;	/* Last Value Monitored */
	DBLINK		siol;	/* Sim Input Specifctn */
	epicsUInt32	sval;	/* Simulation Value */
	DBLINK		siml;	/* Sim Mode Location */
	epicsEnum16	simm;	/* Simulation Mode */
	epicsEnum16	sims;	/* Sim mode Alarm Svrty */
} biRecord;
#define biRecordNAME	0
#define biRecordDESC	1
#define biRecordASG	2
#define biRecordSCAN	3
#define biRecordPINI	4
#define biRecordPHAS	5
#define biRecordEVNT	6
#define biRecordTSE	7
#define biRecordTSEL	8
#define biRecordDTYP	9
#define biRecordDISV	10
#define biRecordDISA	11
#define biRecordSDIS	12
#define biRecordMLOK	13
#define biRecordMLIS	14
#define biRecordDISP	15
#define biRecordPROC	16
#define biRecordSTAT	17
#define biRecordSEVR	18
#define biRecordNSTA	19
#define biRecordNSEV	20
#define biRecordACKS	21
#define biRecordACKT	22
#define biRecordDISS	23
#define biRecordLCNT	24
#define biRecordPACT	25
#define biRecordPUTF	26
#define biRecordRPRO	27
#define biRecordASP	28
#define biRecordPPN	29
#define biRecordPPNR	30
#define biRecordSPVT	31
#define biRecordRSET	32
#define biRecordDSET	33
#define biRecordDPVT	34
#define biRecordRDES	35
#define biRecordLSET	36
#define biRecordPRIO	37
#define biRecordTPRO	38
#define biRecordBKPT	39
#define biRecordUDF	40
#define biRecordTIME	41
#define biRecordFLNK	42
#define biRecordINP	43
#define biRecordVAL	44
#define biRecordZSV	45
#define biRecordOSV	46
#define biRecordCOSV	47
#define biRecordZNAM	48
#define biRecordONAM	49
#define biRecordRVAL	50
#define biRecordORAW	51
#define biRecordMASK	52
#define biRecordLALM	53
#define biRecordMLST	54
#define biRecordSIOL	55
#define biRecordSVAL	56
#define biRecordSIML	57
#define biRecordSIMM	58
#define biRecordSIMS	59
#endif /*INCbiH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsExport.h>
static int biRecordSizeOffset(dbRecordType *pdbRecordType)
{
    biRecord *prec = 0;
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
  pdbRecordType->papFldDes[43]->size=sizeof(prec->inp);
  pdbRecordType->papFldDes[43]->offset=(short)((char *)&prec->inp - (char *)prec);
  pdbRecordType->papFldDes[44]->size=sizeof(prec->val);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->val - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->zsv);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->zsv - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->osv);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->osv - (char *)prec);
  pdbRecordType->papFldDes[47]->size=sizeof(prec->cosv);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->cosv - (char *)prec);
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
  pdbRecordType->papFldDes[53]->size=sizeof(prec->lalm);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->lalm - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->mlst);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->mlst - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->siol);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->siol - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->sval);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->sval - (char *)prec);
  pdbRecordType->papFldDes[57]->size=sizeof(prec->siml);
  pdbRecordType->papFldDes[57]->offset=(short)((char *)&prec->siml - (char *)prec);
  pdbRecordType->papFldDes[58]->size=sizeof(prec->simm);
  pdbRecordType->papFldDes[58]->offset=(short)((char *)&prec->simm - (char *)prec);
  pdbRecordType->papFldDes[59]->size=sizeof(prec->sims);
  pdbRecordType->papFldDes[59]->offset=(short)((char *)&prec->sims - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(biRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
