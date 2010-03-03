
#ifndef INCdfanoutSELMH
#define INCdfanoutSELMH
typedef enum {
	dfanoutSELM_All,
	dfanoutSELM_Specified,
	dfanoutSELM_Mask
}dfanoutSELM;
#endif /*INCdfanoutSELMH*/
#ifndef INCdfanoutH
#define INCdfanoutH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
typedef struct dfanoutRecord {
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
	epicsEnum16	selm;	/* Select Mechanism */
	epicsUInt16	seln;	/* Link Selection */
	DBLINK		sell;	/* Link Selection Loc */
	DBLINK		outa;	/* Output Spec A */
	DBLINK		outb;	/* Output Spec B */
	DBLINK		outc;	/* Output Spec C */
	DBLINK		outd;	/* Output Spec D */
	DBLINK		oute;	/* Output Spec E */
	DBLINK		outf;	/* Output Spec F */
	DBLINK		outg;	/* Output Spec G */
	DBLINK		outh;	/* Output Spec H */
	DBLINK		dol;	/* Desired Output Loc */
	epicsEnum16	omsl;	/* Output Mode Select */
	char		egu[16];	/* Units name */
	epicsInt16	prec;	/* Display Precision */
	epicsFloat64	hopr;	/* High Operating Range */
	epicsFloat64	lopr;	/* Low Operating Range */
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
	epicsFloat64	lalm;	/* Last Value Alarmed */
	epicsFloat64	alst;	/* Last Value Archived */
	epicsFloat64	mlst;	/* Last Val Monitored */
} dfanoutRecord;
#define dfanoutRecordNAME	0
#define dfanoutRecordDESC	1
#define dfanoutRecordASG	2
#define dfanoutRecordSCAN	3
#define dfanoutRecordPINI	4
#define dfanoutRecordPHAS	5
#define dfanoutRecordEVNT	6
#define dfanoutRecordTSE	7
#define dfanoutRecordTSEL	8
#define dfanoutRecordDTYP	9
#define dfanoutRecordDISV	10
#define dfanoutRecordDISA	11
#define dfanoutRecordSDIS	12
#define dfanoutRecordMLOK	13
#define dfanoutRecordMLIS	14
#define dfanoutRecordDISP	15
#define dfanoutRecordPROC	16
#define dfanoutRecordSTAT	17
#define dfanoutRecordSEVR	18
#define dfanoutRecordNSTA	19
#define dfanoutRecordNSEV	20
#define dfanoutRecordACKS	21
#define dfanoutRecordACKT	22
#define dfanoutRecordDISS	23
#define dfanoutRecordLCNT	24
#define dfanoutRecordPACT	25
#define dfanoutRecordPUTF	26
#define dfanoutRecordRPRO	27
#define dfanoutRecordASP	28
#define dfanoutRecordPPN	29
#define dfanoutRecordPPNR	30
#define dfanoutRecordSPVT	31
#define dfanoutRecordRSET	32
#define dfanoutRecordDSET	33
#define dfanoutRecordDPVT	34
#define dfanoutRecordRDES	35
#define dfanoutRecordLSET	36
#define dfanoutRecordPRIO	37
#define dfanoutRecordTPRO	38
#define dfanoutRecordBKPT	39
#define dfanoutRecordUDF	40
#define dfanoutRecordTIME	41
#define dfanoutRecordFLNK	42
#define dfanoutRecordVAL	43
#define dfanoutRecordSELM	44
#define dfanoutRecordSELN	45
#define dfanoutRecordSELL	46
#define dfanoutRecordOUTA	47
#define dfanoutRecordOUTB	48
#define dfanoutRecordOUTC	49
#define dfanoutRecordOUTD	50
#define dfanoutRecordOUTE	51
#define dfanoutRecordOUTF	52
#define dfanoutRecordOUTG	53
#define dfanoutRecordOUTH	54
#define dfanoutRecordDOL	55
#define dfanoutRecordOMSL	56
#define dfanoutRecordEGU	57
#define dfanoutRecordPREC	58
#define dfanoutRecordHOPR	59
#define dfanoutRecordLOPR	60
#define dfanoutRecordHIHI	61
#define dfanoutRecordLOLO	62
#define dfanoutRecordHIGH	63
#define dfanoutRecordLOW	64
#define dfanoutRecordHHSV	65
#define dfanoutRecordLLSV	66
#define dfanoutRecordHSV	67
#define dfanoutRecordLSV	68
#define dfanoutRecordHYST	69
#define dfanoutRecordADEL	70
#define dfanoutRecordMDEL	71
#define dfanoutRecordLALM	72
#define dfanoutRecordALST	73
#define dfanoutRecordMLST	74
#endif /*INCdfanoutH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsExport.h>
static int dfanoutRecordSizeOffset(dbRecordType *pdbRecordType)
{
    dfanoutRecord *prec = 0;
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
  pdbRecordType->papFldDes[44]->size=sizeof(prec->selm);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->selm - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->seln);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->seln - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->sell);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->sell - (char *)prec);
  pdbRecordType->papFldDes[47]->size=sizeof(prec->outa);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->outa - (char *)prec);
  pdbRecordType->papFldDes[48]->size=sizeof(prec->outb);
  pdbRecordType->papFldDes[48]->offset=(short)((char *)&prec->outb - (char *)prec);
  pdbRecordType->papFldDes[49]->size=sizeof(prec->outc);
  pdbRecordType->papFldDes[49]->offset=(short)((char *)&prec->outc - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->outd);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->outd - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->oute);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->oute - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->outf);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->outf - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->outg);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->outg - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->outh);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->outh - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->dol);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->dol - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->omsl);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->omsl - (char *)prec);
  pdbRecordType->papFldDes[57]->size=sizeof(prec->egu);
  pdbRecordType->papFldDes[57]->offset=(short)((char *)&prec->egu - (char *)prec);
  pdbRecordType->papFldDes[58]->size=sizeof(prec->prec);
  pdbRecordType->papFldDes[58]->offset=(short)((char *)&prec->prec - (char *)prec);
  pdbRecordType->papFldDes[59]->size=sizeof(prec->hopr);
  pdbRecordType->papFldDes[59]->offset=(short)((char *)&prec->hopr - (char *)prec);
  pdbRecordType->papFldDes[60]->size=sizeof(prec->lopr);
  pdbRecordType->papFldDes[60]->offset=(short)((char *)&prec->lopr - (char *)prec);
  pdbRecordType->papFldDes[61]->size=sizeof(prec->hihi);
  pdbRecordType->papFldDes[61]->offset=(short)((char *)&prec->hihi - (char *)prec);
  pdbRecordType->papFldDes[62]->size=sizeof(prec->lolo);
  pdbRecordType->papFldDes[62]->offset=(short)((char *)&prec->lolo - (char *)prec);
  pdbRecordType->papFldDes[63]->size=sizeof(prec->high);
  pdbRecordType->papFldDes[63]->offset=(short)((char *)&prec->high - (char *)prec);
  pdbRecordType->papFldDes[64]->size=sizeof(prec->low);
  pdbRecordType->papFldDes[64]->offset=(short)((char *)&prec->low - (char *)prec);
  pdbRecordType->papFldDes[65]->size=sizeof(prec->hhsv);
  pdbRecordType->papFldDes[65]->offset=(short)((char *)&prec->hhsv - (char *)prec);
  pdbRecordType->papFldDes[66]->size=sizeof(prec->llsv);
  pdbRecordType->papFldDes[66]->offset=(short)((char *)&prec->llsv - (char *)prec);
  pdbRecordType->papFldDes[67]->size=sizeof(prec->hsv);
  pdbRecordType->papFldDes[67]->offset=(short)((char *)&prec->hsv - (char *)prec);
  pdbRecordType->papFldDes[68]->size=sizeof(prec->lsv);
  pdbRecordType->papFldDes[68]->offset=(short)((char *)&prec->lsv - (char *)prec);
  pdbRecordType->papFldDes[69]->size=sizeof(prec->hyst);
  pdbRecordType->papFldDes[69]->offset=(short)((char *)&prec->hyst - (char *)prec);
  pdbRecordType->papFldDes[70]->size=sizeof(prec->adel);
  pdbRecordType->papFldDes[70]->offset=(short)((char *)&prec->adel - (char *)prec);
  pdbRecordType->papFldDes[71]->size=sizeof(prec->mdel);
  pdbRecordType->papFldDes[71]->offset=(short)((char *)&prec->mdel - (char *)prec);
  pdbRecordType->papFldDes[72]->size=sizeof(prec->lalm);
  pdbRecordType->papFldDes[72]->offset=(short)((char *)&prec->lalm - (char *)prec);
  pdbRecordType->papFldDes[73]->size=sizeof(prec->alst);
  pdbRecordType->papFldDes[73]->offset=(short)((char *)&prec->alst - (char *)prec);
  pdbRecordType->papFldDes[74]->size=sizeof(prec->mlst);
  pdbRecordType->papFldDes[74]->offset=(short)((char *)&prec->mlst - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(dfanoutRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
