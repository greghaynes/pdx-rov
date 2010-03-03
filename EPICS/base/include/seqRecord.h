
#ifndef INCseqSELMH
#define INCseqSELMH
typedef enum {
	seqSELM_All,
	seqSELM_Specified,
	seqSELM_Mask
}seqSELM;
#endif /*INCseqSELMH*/
#ifndef INCseqH
#define INCseqH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
typedef struct seqRecord {
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
	epicsInt32	val;	/* Used to trigger */
	epicsEnum16	selm;	/* Select Mechanism */
	epicsUInt16	seln;	/* Link Selection */
	DBLINK		sell;	/* Link Selection Loc */
	epicsInt16	prec;	/* Display Precision */
	epicsFloat64	dly1;	/* Delay 1 */
	DBLINK		dol1;	/* Input link1 */
	epicsFloat64	do1;	/* Constant input 1 */
	DBLINK		lnk1;	/* Output Link 1 */
	epicsFloat64	dly2;	/* Delay 2 */
	DBLINK		dol2;	/* Input link 2 */
	epicsFloat64	do2;	/* Constant input 2 */
	DBLINK		lnk2;	/* Output Link 2 */
	epicsFloat64	dly3;	/* Delay 3 */
	DBLINK		dol3;	/* Input link 3 */
	epicsFloat64	do3;	/* Constant input 3 */
	DBLINK		lnk3;	/* Output Link 3 */
	epicsFloat64	dly4;	/* Delay 4 */
	DBLINK		dol4;	/* Input link 4 */
	epicsFloat64	do4;	/* Constant input 4 */
	DBLINK		lnk4;	/* Output Link 4 */
	epicsFloat64	dly5;	/* Delay 5 */
	DBLINK		dol5;	/* Input link 5 */
	epicsFloat64	do5;	/* Constant input 5 */
	DBLINK		lnk5;	/* Output Link 5 */
	epicsFloat64	dly6;	/* Delay 6 */
	DBLINK		dol6;	/* Input link 6 */
	epicsFloat64	do6;	/* Constant input 6 */
	DBLINK		lnk6;	/* Output Link 6 */
	epicsFloat64	dly7;	/* Delay 7 */
	DBLINK		dol7;	/* Input link 7 */
	epicsFloat64	do7;	/* Constant input 7 */
	DBLINK		lnk7;	/* Output Link 7 */
	epicsFloat64	dly8;	/* Delay 8 */
	DBLINK		dol8;	/* Input link 8 */
	epicsFloat64	do8;	/* Constant input 8 */
	DBLINK		lnk8;	/* Output Link 8 */
	epicsFloat64	dly9;	/* Delay 9 */
	DBLINK		dol9;	/* Input link 9 */
	epicsFloat64	do9;	/* Constant input 9 */
	DBLINK		lnk9;	/* Output Link 9 */
	epicsFloat64	dlya;	/* Delay 10 */
	DBLINK		dola;	/* Input link 10 */
	epicsFloat64	doa;	/* Constant input 10 */
	DBLINK		lnka;	/* Output Link 10 */
} seqRecord;
#define seqRecordNAME	0
#define seqRecordDESC	1
#define seqRecordASG	2
#define seqRecordSCAN	3
#define seqRecordPINI	4
#define seqRecordPHAS	5
#define seqRecordEVNT	6
#define seqRecordTSE	7
#define seqRecordTSEL	8
#define seqRecordDTYP	9
#define seqRecordDISV	10
#define seqRecordDISA	11
#define seqRecordSDIS	12
#define seqRecordMLOK	13
#define seqRecordMLIS	14
#define seqRecordDISP	15
#define seqRecordPROC	16
#define seqRecordSTAT	17
#define seqRecordSEVR	18
#define seqRecordNSTA	19
#define seqRecordNSEV	20
#define seqRecordACKS	21
#define seqRecordACKT	22
#define seqRecordDISS	23
#define seqRecordLCNT	24
#define seqRecordPACT	25
#define seqRecordPUTF	26
#define seqRecordRPRO	27
#define seqRecordASP	28
#define seqRecordPPN	29
#define seqRecordPPNR	30
#define seqRecordSPVT	31
#define seqRecordRSET	32
#define seqRecordDSET	33
#define seqRecordDPVT	34
#define seqRecordRDES	35
#define seqRecordLSET	36
#define seqRecordPRIO	37
#define seqRecordTPRO	38
#define seqRecordBKPT	39
#define seqRecordUDF	40
#define seqRecordTIME	41
#define seqRecordFLNK	42
#define seqRecordVAL	43
#define seqRecordSELM	44
#define seqRecordSELN	45
#define seqRecordSELL	46
#define seqRecordPREC	47
#define seqRecordDLY1	48
#define seqRecordDOL1	49
#define seqRecordDO1	50
#define seqRecordLNK1	51
#define seqRecordDLY2	52
#define seqRecordDOL2	53
#define seqRecordDO2	54
#define seqRecordLNK2	55
#define seqRecordDLY3	56
#define seqRecordDOL3	57
#define seqRecordDO3	58
#define seqRecordLNK3	59
#define seqRecordDLY4	60
#define seqRecordDOL4	61
#define seqRecordDO4	62
#define seqRecordLNK4	63
#define seqRecordDLY5	64
#define seqRecordDOL5	65
#define seqRecordDO5	66
#define seqRecordLNK5	67
#define seqRecordDLY6	68
#define seqRecordDOL6	69
#define seqRecordDO6	70
#define seqRecordLNK6	71
#define seqRecordDLY7	72
#define seqRecordDOL7	73
#define seqRecordDO7	74
#define seqRecordLNK7	75
#define seqRecordDLY8	76
#define seqRecordDOL8	77
#define seqRecordDO8	78
#define seqRecordLNK8	79
#define seqRecordDLY9	80
#define seqRecordDOL9	81
#define seqRecordDO9	82
#define seqRecordLNK9	83
#define seqRecordDLYA	84
#define seqRecordDOLA	85
#define seqRecordDOA	86
#define seqRecordLNKA	87
#endif /*INCseqH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsExport.h>
static int seqRecordSizeOffset(dbRecordType *pdbRecordType)
{
    seqRecord *prec = 0;
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
  pdbRecordType->papFldDes[47]->size=sizeof(prec->prec);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->prec - (char *)prec);
  pdbRecordType->papFldDes[48]->size=sizeof(prec->dly1);
  pdbRecordType->papFldDes[48]->offset=(short)((char *)&prec->dly1 - (char *)prec);
  pdbRecordType->papFldDes[49]->size=sizeof(prec->dol1);
  pdbRecordType->papFldDes[49]->offset=(short)((char *)&prec->dol1 - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->do1);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->do1 - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->lnk1);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->lnk1 - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->dly2);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->dly2 - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->dol2);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->dol2 - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->do2);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->do2 - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->lnk2);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->lnk2 - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->dly3);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->dly3 - (char *)prec);
  pdbRecordType->papFldDes[57]->size=sizeof(prec->dol3);
  pdbRecordType->papFldDes[57]->offset=(short)((char *)&prec->dol3 - (char *)prec);
  pdbRecordType->papFldDes[58]->size=sizeof(prec->do3);
  pdbRecordType->papFldDes[58]->offset=(short)((char *)&prec->do3 - (char *)prec);
  pdbRecordType->papFldDes[59]->size=sizeof(prec->lnk3);
  pdbRecordType->papFldDes[59]->offset=(short)((char *)&prec->lnk3 - (char *)prec);
  pdbRecordType->papFldDes[60]->size=sizeof(prec->dly4);
  pdbRecordType->papFldDes[60]->offset=(short)((char *)&prec->dly4 - (char *)prec);
  pdbRecordType->papFldDes[61]->size=sizeof(prec->dol4);
  pdbRecordType->papFldDes[61]->offset=(short)((char *)&prec->dol4 - (char *)prec);
  pdbRecordType->papFldDes[62]->size=sizeof(prec->do4);
  pdbRecordType->papFldDes[62]->offset=(short)((char *)&prec->do4 - (char *)prec);
  pdbRecordType->papFldDes[63]->size=sizeof(prec->lnk4);
  pdbRecordType->papFldDes[63]->offset=(short)((char *)&prec->lnk4 - (char *)prec);
  pdbRecordType->papFldDes[64]->size=sizeof(prec->dly5);
  pdbRecordType->papFldDes[64]->offset=(short)((char *)&prec->dly5 - (char *)prec);
  pdbRecordType->papFldDes[65]->size=sizeof(prec->dol5);
  pdbRecordType->papFldDes[65]->offset=(short)((char *)&prec->dol5 - (char *)prec);
  pdbRecordType->papFldDes[66]->size=sizeof(prec->do5);
  pdbRecordType->papFldDes[66]->offset=(short)((char *)&prec->do5 - (char *)prec);
  pdbRecordType->papFldDes[67]->size=sizeof(prec->lnk5);
  pdbRecordType->papFldDes[67]->offset=(short)((char *)&prec->lnk5 - (char *)prec);
  pdbRecordType->papFldDes[68]->size=sizeof(prec->dly6);
  pdbRecordType->papFldDes[68]->offset=(short)((char *)&prec->dly6 - (char *)prec);
  pdbRecordType->papFldDes[69]->size=sizeof(prec->dol6);
  pdbRecordType->papFldDes[69]->offset=(short)((char *)&prec->dol6 - (char *)prec);
  pdbRecordType->papFldDes[70]->size=sizeof(prec->do6);
  pdbRecordType->papFldDes[70]->offset=(short)((char *)&prec->do6 - (char *)prec);
  pdbRecordType->papFldDes[71]->size=sizeof(prec->lnk6);
  pdbRecordType->papFldDes[71]->offset=(short)((char *)&prec->lnk6 - (char *)prec);
  pdbRecordType->papFldDes[72]->size=sizeof(prec->dly7);
  pdbRecordType->papFldDes[72]->offset=(short)((char *)&prec->dly7 - (char *)prec);
  pdbRecordType->papFldDes[73]->size=sizeof(prec->dol7);
  pdbRecordType->papFldDes[73]->offset=(short)((char *)&prec->dol7 - (char *)prec);
  pdbRecordType->papFldDes[74]->size=sizeof(prec->do7);
  pdbRecordType->papFldDes[74]->offset=(short)((char *)&prec->do7 - (char *)prec);
  pdbRecordType->papFldDes[75]->size=sizeof(prec->lnk7);
  pdbRecordType->papFldDes[75]->offset=(short)((char *)&prec->lnk7 - (char *)prec);
  pdbRecordType->papFldDes[76]->size=sizeof(prec->dly8);
  pdbRecordType->papFldDes[76]->offset=(short)((char *)&prec->dly8 - (char *)prec);
  pdbRecordType->papFldDes[77]->size=sizeof(prec->dol8);
  pdbRecordType->papFldDes[77]->offset=(short)((char *)&prec->dol8 - (char *)prec);
  pdbRecordType->papFldDes[78]->size=sizeof(prec->do8);
  pdbRecordType->papFldDes[78]->offset=(short)((char *)&prec->do8 - (char *)prec);
  pdbRecordType->papFldDes[79]->size=sizeof(prec->lnk8);
  pdbRecordType->papFldDes[79]->offset=(short)((char *)&prec->lnk8 - (char *)prec);
  pdbRecordType->papFldDes[80]->size=sizeof(prec->dly9);
  pdbRecordType->papFldDes[80]->offset=(short)((char *)&prec->dly9 - (char *)prec);
  pdbRecordType->papFldDes[81]->size=sizeof(prec->dol9);
  pdbRecordType->papFldDes[81]->offset=(short)((char *)&prec->dol9 - (char *)prec);
  pdbRecordType->papFldDes[82]->size=sizeof(prec->do9);
  pdbRecordType->papFldDes[82]->offset=(short)((char *)&prec->do9 - (char *)prec);
  pdbRecordType->papFldDes[83]->size=sizeof(prec->lnk9);
  pdbRecordType->papFldDes[83]->offset=(short)((char *)&prec->lnk9 - (char *)prec);
  pdbRecordType->papFldDes[84]->size=sizeof(prec->dlya);
  pdbRecordType->papFldDes[84]->offset=(short)((char *)&prec->dlya - (char *)prec);
  pdbRecordType->papFldDes[85]->size=sizeof(prec->dola);
  pdbRecordType->papFldDes[85]->offset=(short)((char *)&prec->dola - (char *)prec);
  pdbRecordType->papFldDes[86]->size=sizeof(prec->doa);
  pdbRecordType->papFldDes[86]->offset=(short)((char *)&prec->doa - (char *)prec);
  pdbRecordType->papFldDes[87]->size=sizeof(prec->lnka);
  pdbRecordType->papFldDes[87]->offset=(short)((char *)&prec->lnka - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(seqRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
