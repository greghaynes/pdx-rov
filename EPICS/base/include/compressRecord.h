
#ifndef INCcompressALGH
#define INCcompressALGH
typedef enum {
	compressALG_N_to_1_Low_Value,
	compressALG_N_to_1_High_Value,
	compressALG_N_to_1_Average,
	compressALG_Average,
	compressALG_Circular_Buffer,
	compressALG_N_to_1_Median
}compressALG;
#endif /*INCcompressALGH*/
#ifndef INCcompressH
#define INCcompressH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
typedef struct compressRecord {
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
	DBLINK		inp;	/* Input Specification */
	epicsInt16	res;	/* Reset */
	epicsEnum16	alg;	/* Compression Algorithm */
	epicsUInt32	nsam;	/* Number of Values */
	epicsUInt32	n;	/* N to 1 Compression */
	epicsFloat64	ihil;	/* Init High Interest Lim */
	epicsFloat64	ilil;	/* Init Low Interest Lim */
	epicsFloat64	hopr;	/* High Operating Range */
	epicsFloat64	lopr;	/* Low Operating Range */
	epicsInt16	prec;	/* Display Precision */
	char		egu[16];	/* EngineeringUnits */
	epicsUInt32	off;	/* Offset */
	epicsUInt32	nuse;	/* Number Used */
	double		*bptr;	/* Buffer Pointer */
	double		*sptr;	/* Summing Buffer Ptr */
	double		*wptr;	/* Working Buffer Ptr */
	epicsInt32	inpn;	/* Number of elements in Working Buffer */
	epicsFloat64	cvb;	/* Compress Value Buffer */
	epicsUInt32	inx;	/* Compressed Array Inx */
} compressRecord;
#define compressRecordNAME	0
#define compressRecordDESC	1
#define compressRecordASG	2
#define compressRecordSCAN	3
#define compressRecordPINI	4
#define compressRecordPHAS	5
#define compressRecordEVNT	6
#define compressRecordTSE	7
#define compressRecordTSEL	8
#define compressRecordDTYP	9
#define compressRecordDISV	10
#define compressRecordDISA	11
#define compressRecordSDIS	12
#define compressRecordMLOK	13
#define compressRecordMLIS	14
#define compressRecordDISP	15
#define compressRecordPROC	16
#define compressRecordSTAT	17
#define compressRecordSEVR	18
#define compressRecordNSTA	19
#define compressRecordNSEV	20
#define compressRecordACKS	21
#define compressRecordACKT	22
#define compressRecordDISS	23
#define compressRecordLCNT	24
#define compressRecordPACT	25
#define compressRecordPUTF	26
#define compressRecordRPRO	27
#define compressRecordASP	28
#define compressRecordPPN	29
#define compressRecordPPNR	30
#define compressRecordSPVT	31
#define compressRecordRSET	32
#define compressRecordDSET	33
#define compressRecordDPVT	34
#define compressRecordRDES	35
#define compressRecordLSET	36
#define compressRecordPRIO	37
#define compressRecordTPRO	38
#define compressRecordBKPT	39
#define compressRecordUDF	40
#define compressRecordTIME	41
#define compressRecordFLNK	42
#define compressRecordVAL	43
#define compressRecordINP	44
#define compressRecordRES	45
#define compressRecordALG	46
#define compressRecordNSAM	47
#define compressRecordN	48
#define compressRecordIHIL	49
#define compressRecordILIL	50
#define compressRecordHOPR	51
#define compressRecordLOPR	52
#define compressRecordPREC	53
#define compressRecordEGU	54
#define compressRecordOFF	55
#define compressRecordNUSE	56
#define compressRecordBPTR	57
#define compressRecordSPTR	58
#define compressRecordWPTR	59
#define compressRecordINPN	60
#define compressRecordCVB	61
#define compressRecordINX	62
#endif /*INCcompressH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsExport.h>
static int compressRecordSizeOffset(dbRecordType *pdbRecordType)
{
    compressRecord *prec = 0;
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
  pdbRecordType->papFldDes[44]->size=sizeof(prec->inp);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->inp - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->res);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->res - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->alg);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->alg - (char *)prec);
  pdbRecordType->papFldDes[47]->size=sizeof(prec->nsam);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->nsam - (char *)prec);
  pdbRecordType->papFldDes[48]->size=sizeof(prec->n);
  pdbRecordType->papFldDes[48]->offset=(short)((char *)&prec->n - (char *)prec);
  pdbRecordType->papFldDes[49]->size=sizeof(prec->ihil);
  pdbRecordType->papFldDes[49]->offset=(short)((char *)&prec->ihil - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->ilil);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->ilil - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->hopr);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->hopr - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->lopr);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->lopr - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->prec);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->prec - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->egu);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->egu - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->off);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->off - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->nuse);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->nuse - (char *)prec);
  pdbRecordType->papFldDes[57]->size=sizeof(prec->bptr);
  pdbRecordType->papFldDes[57]->offset=(short)((char *)&prec->bptr - (char *)prec);
  pdbRecordType->papFldDes[58]->size=sizeof(prec->sptr);
  pdbRecordType->papFldDes[58]->offset=(short)((char *)&prec->sptr - (char *)prec);
  pdbRecordType->papFldDes[59]->size=sizeof(prec->wptr);
  pdbRecordType->papFldDes[59]->offset=(short)((char *)&prec->wptr - (char *)prec);
  pdbRecordType->papFldDes[60]->size=sizeof(prec->inpn);
  pdbRecordType->papFldDes[60]->offset=(short)((char *)&prec->inpn - (char *)prec);
  pdbRecordType->papFldDes[61]->size=sizeof(prec->cvb);
  pdbRecordType->papFldDes[61]->offset=(short)((char *)&prec->cvb - (char *)prec);
  pdbRecordType->papFldDes[62]->size=sizeof(prec->inx);
  pdbRecordType->papFldDes[62]->offset=(short)((char *)&prec->inx - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(compressRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
