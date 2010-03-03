#ifndef INCsubArrayH
#define INCsubArrayH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
typedef struct subArrayRecord {
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
	void *		val;	/* Value */
	epicsInt16	prec;	/* Display Precision */
	epicsEnum16	ftvl;	/* Field Type of Value */
	DBLINK		inp;	/* Input Specification */
	char		egu[16];	/* Engineering Units Name */
	epicsFloat64	hopr;	/* High Operating Range */
	epicsFloat64	lopr;	/* Low Operating Range */
	epicsUInt32	malm;	/* Maximum Elements   */
	epicsUInt32	nelm;	/* Number of Elements */
	epicsUInt32	indx;	/* Substring Index */
	epicsInt16	busy;	/* Busy Indicator */
	epicsInt32	nord;	/* Number elements read */
	void *		bptr;	/* Buffer Pointer */
} subArrayRecord;
#define subArrayRecordNAME	0
#define subArrayRecordDESC	1
#define subArrayRecordASG	2
#define subArrayRecordSCAN	3
#define subArrayRecordPINI	4
#define subArrayRecordPHAS	5
#define subArrayRecordEVNT	6
#define subArrayRecordTSE	7
#define subArrayRecordTSEL	8
#define subArrayRecordDTYP	9
#define subArrayRecordDISV	10
#define subArrayRecordDISA	11
#define subArrayRecordSDIS	12
#define subArrayRecordMLOK	13
#define subArrayRecordMLIS	14
#define subArrayRecordDISP	15
#define subArrayRecordPROC	16
#define subArrayRecordSTAT	17
#define subArrayRecordSEVR	18
#define subArrayRecordNSTA	19
#define subArrayRecordNSEV	20
#define subArrayRecordACKS	21
#define subArrayRecordACKT	22
#define subArrayRecordDISS	23
#define subArrayRecordLCNT	24
#define subArrayRecordPACT	25
#define subArrayRecordPUTF	26
#define subArrayRecordRPRO	27
#define subArrayRecordASP	28
#define subArrayRecordPPN	29
#define subArrayRecordPPNR	30
#define subArrayRecordSPVT	31
#define subArrayRecordRSET	32
#define subArrayRecordDSET	33
#define subArrayRecordDPVT	34
#define subArrayRecordRDES	35
#define subArrayRecordLSET	36
#define subArrayRecordPRIO	37
#define subArrayRecordTPRO	38
#define subArrayRecordBKPT	39
#define subArrayRecordUDF	40
#define subArrayRecordTIME	41
#define subArrayRecordFLNK	42
#define subArrayRecordVAL	43
#define subArrayRecordPREC	44
#define subArrayRecordFTVL	45
#define subArrayRecordINP	46
#define subArrayRecordEGU	47
#define subArrayRecordHOPR	48
#define subArrayRecordLOPR	49
#define subArrayRecordMALM	50
#define subArrayRecordNELM	51
#define subArrayRecordINDX	52
#define subArrayRecordBUSY	53
#define subArrayRecordNORD	54
#define subArrayRecordBPTR	55
#endif /*INCsubArrayH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsExport.h>
static int subArrayRecordSizeOffset(dbRecordType *pdbRecordType)
{
    subArrayRecord *prec = 0;
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
  pdbRecordType->papFldDes[44]->size=sizeof(prec->prec);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->prec - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->ftvl);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->ftvl - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->inp);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->inp - (char *)prec);
  pdbRecordType->papFldDes[47]->size=sizeof(prec->egu);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->egu - (char *)prec);
  pdbRecordType->papFldDes[48]->size=sizeof(prec->hopr);
  pdbRecordType->papFldDes[48]->offset=(short)((char *)&prec->hopr - (char *)prec);
  pdbRecordType->papFldDes[49]->size=sizeof(prec->lopr);
  pdbRecordType->papFldDes[49]->offset=(short)((char *)&prec->lopr - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->malm);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->malm - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->nelm);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->nelm - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->indx);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->indx - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->busy);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->busy - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->nord);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->nord - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->bptr);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->bptr - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(subArrayRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
