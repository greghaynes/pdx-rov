
#ifndef INCwaveformPOSTH
#define INCwaveformPOSTH
typedef enum {
	waveformPOST_Always,
	waveformPOST_OnChange
}waveformPOST;
#endif /*INCwaveformPOSTH*/
#ifndef INCwaveformH
#define INCwaveformH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
typedef struct waveformRecord {
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
	epicsInt16	rarm;	/* Rearm the waveform */
	epicsInt16	prec;	/* Display Precision */
	DBLINK		inp;	/* Input Specification */
	char		egu[16];	/* Engineering Units Name */
	epicsFloat64	hopr;	/* High Operating Range */
	epicsFloat64	lopr;	/* Low Operating Range */
	epicsUInt32	nelm;	/* Number of Elements */
	epicsEnum16	ftvl;	/* Field Type of Value */
	epicsInt16	busy;	/* Busy Indicator */
	epicsUInt32	nord;	/* Number elements read */
	void *		bptr;	/* Buffer Pointer */
	DBLINK		siol;	/* Sim Input Specifctn */
	DBLINK		siml;	/* Sim Mode Location */
	epicsEnum16	simm;	/* Simulation Mode */
	epicsEnum16	sims;	/* Sim mode Alarm Svrty */
	epicsEnum16	mpst;	/* Post Value Monitors */
	epicsEnum16	apst;	/* Post Archive Monitors */
	epicsUInt32	hash;	/* Hash of OnChange data. */
} waveformRecord;
#define waveformRecordNAME	0
#define waveformRecordDESC	1
#define waveformRecordASG	2
#define waveformRecordSCAN	3
#define waveformRecordPINI	4
#define waveformRecordPHAS	5
#define waveformRecordEVNT	6
#define waveformRecordTSE	7
#define waveformRecordTSEL	8
#define waveformRecordDTYP	9
#define waveformRecordDISV	10
#define waveformRecordDISA	11
#define waveformRecordSDIS	12
#define waveformRecordMLOK	13
#define waveformRecordMLIS	14
#define waveformRecordDISP	15
#define waveformRecordPROC	16
#define waveformRecordSTAT	17
#define waveformRecordSEVR	18
#define waveformRecordNSTA	19
#define waveformRecordNSEV	20
#define waveformRecordACKS	21
#define waveformRecordACKT	22
#define waveformRecordDISS	23
#define waveformRecordLCNT	24
#define waveformRecordPACT	25
#define waveformRecordPUTF	26
#define waveformRecordRPRO	27
#define waveformRecordASP	28
#define waveformRecordPPN	29
#define waveformRecordPPNR	30
#define waveformRecordSPVT	31
#define waveformRecordRSET	32
#define waveformRecordDSET	33
#define waveformRecordDPVT	34
#define waveformRecordRDES	35
#define waveformRecordLSET	36
#define waveformRecordPRIO	37
#define waveformRecordTPRO	38
#define waveformRecordBKPT	39
#define waveformRecordUDF	40
#define waveformRecordTIME	41
#define waveformRecordFLNK	42
#define waveformRecordVAL	43
#define waveformRecordRARM	44
#define waveformRecordPREC	45
#define waveformRecordINP	46
#define waveformRecordEGU	47
#define waveformRecordHOPR	48
#define waveformRecordLOPR	49
#define waveformRecordNELM	50
#define waveformRecordFTVL	51
#define waveformRecordBUSY	52
#define waveformRecordNORD	53
#define waveformRecordBPTR	54
#define waveformRecordSIOL	55
#define waveformRecordSIML	56
#define waveformRecordSIMM	57
#define waveformRecordSIMS	58
#define waveformRecordMPST	59
#define waveformRecordAPST	60
#define waveformRecordHASH	61
#endif /*INCwaveformH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsExport.h>
static int waveformRecordSizeOffset(dbRecordType *pdbRecordType)
{
    waveformRecord *prec = 0;
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
  pdbRecordType->papFldDes[44]->size=sizeof(prec->rarm);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->rarm - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->prec);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->prec - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->inp);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->inp - (char *)prec);
  pdbRecordType->papFldDes[47]->size=sizeof(prec->egu);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->egu - (char *)prec);
  pdbRecordType->papFldDes[48]->size=sizeof(prec->hopr);
  pdbRecordType->papFldDes[48]->offset=(short)((char *)&prec->hopr - (char *)prec);
  pdbRecordType->papFldDes[49]->size=sizeof(prec->lopr);
  pdbRecordType->papFldDes[49]->offset=(short)((char *)&prec->lopr - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->nelm);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->nelm - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->ftvl);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->ftvl - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->busy);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->busy - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->nord);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->nord - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->bptr);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->bptr - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->siol);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->siol - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->siml);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->siml - (char *)prec);
  pdbRecordType->papFldDes[57]->size=sizeof(prec->simm);
  pdbRecordType->papFldDes[57]->offset=(short)((char *)&prec->simm - (char *)prec);
  pdbRecordType->papFldDes[58]->size=sizeof(prec->sims);
  pdbRecordType->papFldDes[58]->offset=(short)((char *)&prec->sims - (char *)prec);
  pdbRecordType->papFldDes[59]->size=sizeof(prec->mpst);
  pdbRecordType->papFldDes[59]->offset=(short)((char *)&prec->mpst - (char *)prec);
  pdbRecordType->papFldDes[60]->size=sizeof(prec->apst);
  pdbRecordType->papFldDes[60]->offset=(short)((char *)&prec->apst - (char *)prec);
  pdbRecordType->papFldDes[61]->size=sizeof(prec->hash);
  pdbRecordType->papFldDes[61]->offset=(short)((char *)&prec->hash - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(waveformRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
