#ifndef INCcalcH
#define INCcalcH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
#include "postfix.h"
typedef struct calcRecord {
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
	epicsFloat64	val;	/* Result */
	char		calc[40];	/* Calculation */
	DBLINK		inpa;	/* Input A */
	DBLINK		inpb;	/* Input B */
	DBLINK		inpc;	/* Input C */
	DBLINK		inpd;	/* Input D */
	DBLINK		inpe;	/* Input E */
	DBLINK		inpf;	/* Input F */
	DBLINK		inpg;	/* Input G */
	DBLINK		inph;	/* Input H */
	DBLINK		inpi;	/* Input I */
	DBLINK		inpj;	/* Input J */
	DBLINK		inpk;	/* Input K */
	DBLINK		inpl;	/* Input L */
	char		egu[16];	/* Units Name */
	epicsInt16	prec;	/* Display Precision */
	epicsFloat64	hopr;	/* High Operating Rng */
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
	epicsFloat64	a;	/* Value of Input A */
	epicsFloat64	b;	/* Value of Input B */
	epicsFloat64	c;	/* Value of Input C */
	epicsFloat64	d;	/* Value of Input D */
	epicsFloat64	e;	/* Value of Input E */
	epicsFloat64	f;	/* Value of Input F */
	epicsFloat64	g;	/* Value of Input G */
	epicsFloat64	h;	/* Value of Input H */
	epicsFloat64	i;	/* Value of Input I */
	epicsFloat64	j;	/* Value of Input J */
	epicsFloat64	k;	/* Value of Input K */
	epicsFloat64	l;	/* Value of Input L */
	epicsFloat64	la;	/* Prev Value of A */
	epicsFloat64	lb;	/* Prev Value of B */
	epicsFloat64	lc;	/* Prev Value of C */
	epicsFloat64	ld;	/* Prev Value of D */
	epicsFloat64	le;	/* Prev Value of E */
	epicsFloat64	lf;	/* Prev Value of F */
	epicsFloat64	lg;	/* Prev Value of G */
	epicsFloat64	lh;	/* Prev Value of H */
	epicsFloat64	li;	/* Prev Value of I */
	epicsFloat64	lj;	/* Prev Value of J */
	epicsFloat64	lk;	/* Prev Value of K */
	epicsFloat64	ll;	/* Prev Value of L */
	epicsFloat64	lalm;	/* Last Value Alarmed */
	epicsFloat64	alst;	/* Last Value Archived */
	epicsFloat64	mlst;	/* Last Val Monitored */
	char	rpcl[INFIX_TO_POSTFIX_SIZE(40)];	/* Reverse Polish Calc */
} calcRecord;
#define calcRecordNAME	0
#define calcRecordDESC	1
#define calcRecordASG	2
#define calcRecordSCAN	3
#define calcRecordPINI	4
#define calcRecordPHAS	5
#define calcRecordEVNT	6
#define calcRecordTSE	7
#define calcRecordTSEL	8
#define calcRecordDTYP	9
#define calcRecordDISV	10
#define calcRecordDISA	11
#define calcRecordSDIS	12
#define calcRecordMLOK	13
#define calcRecordMLIS	14
#define calcRecordDISP	15
#define calcRecordPROC	16
#define calcRecordSTAT	17
#define calcRecordSEVR	18
#define calcRecordNSTA	19
#define calcRecordNSEV	20
#define calcRecordACKS	21
#define calcRecordACKT	22
#define calcRecordDISS	23
#define calcRecordLCNT	24
#define calcRecordPACT	25
#define calcRecordPUTF	26
#define calcRecordRPRO	27
#define calcRecordASP	28
#define calcRecordPPN	29
#define calcRecordPPNR	30
#define calcRecordSPVT	31
#define calcRecordRSET	32
#define calcRecordDSET	33
#define calcRecordDPVT	34
#define calcRecordRDES	35
#define calcRecordLSET	36
#define calcRecordPRIO	37
#define calcRecordTPRO	38
#define calcRecordBKPT	39
#define calcRecordUDF	40
#define calcRecordTIME	41
#define calcRecordFLNK	42
#define calcRecordVAL	43
#define calcRecordCALC	44
#define calcRecordINPA	45
#define calcRecordINPB	46
#define calcRecordINPC	47
#define calcRecordINPD	48
#define calcRecordINPE	49
#define calcRecordINPF	50
#define calcRecordINPG	51
#define calcRecordINPH	52
#define calcRecordINPI	53
#define calcRecordINPJ	54
#define calcRecordINPK	55
#define calcRecordINPL	56
#define calcRecordEGU	57
#define calcRecordPREC	58
#define calcRecordHOPR	59
#define calcRecordLOPR	60
#define calcRecordHIHI	61
#define calcRecordLOLO	62
#define calcRecordHIGH	63
#define calcRecordLOW	64
#define calcRecordHHSV	65
#define calcRecordLLSV	66
#define calcRecordHSV	67
#define calcRecordLSV	68
#define calcRecordHYST	69
#define calcRecordADEL	70
#define calcRecordMDEL	71
#define calcRecordA	72
#define calcRecordB	73
#define calcRecordC	74
#define calcRecordD	75
#define calcRecordE	76
#define calcRecordF	77
#define calcRecordG	78
#define calcRecordH	79
#define calcRecordI	80
#define calcRecordJ	81
#define calcRecordK	82
#define calcRecordL	83
#define calcRecordLA	84
#define calcRecordLB	85
#define calcRecordLC	86
#define calcRecordLD	87
#define calcRecordLE	88
#define calcRecordLF	89
#define calcRecordLG	90
#define calcRecordLH	91
#define calcRecordLI	92
#define calcRecordLJ	93
#define calcRecordLK	94
#define calcRecordLL	95
#define calcRecordLALM	96
#define calcRecordALST	97
#define calcRecordMLST	98
#define calcRecordRPCL	99
#endif /*INCcalcH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsExport.h>
static int calcRecordSizeOffset(dbRecordType *pdbRecordType)
{
    calcRecord *prec = 0;
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
  pdbRecordType->papFldDes[44]->size=sizeof(prec->calc);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->calc - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->inpa);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->inpa - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->inpb);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->inpb - (char *)prec);
  pdbRecordType->papFldDes[47]->size=sizeof(prec->inpc);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->inpc - (char *)prec);
  pdbRecordType->papFldDes[48]->size=sizeof(prec->inpd);
  pdbRecordType->papFldDes[48]->offset=(short)((char *)&prec->inpd - (char *)prec);
  pdbRecordType->papFldDes[49]->size=sizeof(prec->inpe);
  pdbRecordType->papFldDes[49]->offset=(short)((char *)&prec->inpe - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->inpf);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->inpf - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->inpg);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->inpg - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->inph);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->inph - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->inpi);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->inpi - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->inpj);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->inpj - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->inpk);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->inpk - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->inpl);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->inpl - (char *)prec);
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
  pdbRecordType->papFldDes[72]->size=sizeof(prec->a);
  pdbRecordType->papFldDes[72]->offset=(short)((char *)&prec->a - (char *)prec);
  pdbRecordType->papFldDes[73]->size=sizeof(prec->b);
  pdbRecordType->papFldDes[73]->offset=(short)((char *)&prec->b - (char *)prec);
  pdbRecordType->papFldDes[74]->size=sizeof(prec->c);
  pdbRecordType->papFldDes[74]->offset=(short)((char *)&prec->c - (char *)prec);
  pdbRecordType->papFldDes[75]->size=sizeof(prec->d);
  pdbRecordType->papFldDes[75]->offset=(short)((char *)&prec->d - (char *)prec);
  pdbRecordType->papFldDes[76]->size=sizeof(prec->e);
  pdbRecordType->papFldDes[76]->offset=(short)((char *)&prec->e - (char *)prec);
  pdbRecordType->papFldDes[77]->size=sizeof(prec->f);
  pdbRecordType->papFldDes[77]->offset=(short)((char *)&prec->f - (char *)prec);
  pdbRecordType->papFldDes[78]->size=sizeof(prec->g);
  pdbRecordType->papFldDes[78]->offset=(short)((char *)&prec->g - (char *)prec);
  pdbRecordType->papFldDes[79]->size=sizeof(prec->h);
  pdbRecordType->papFldDes[79]->offset=(short)((char *)&prec->h - (char *)prec);
  pdbRecordType->papFldDes[80]->size=sizeof(prec->i);
  pdbRecordType->papFldDes[80]->offset=(short)((char *)&prec->i - (char *)prec);
  pdbRecordType->papFldDes[81]->size=sizeof(prec->j);
  pdbRecordType->papFldDes[81]->offset=(short)((char *)&prec->j - (char *)prec);
  pdbRecordType->papFldDes[82]->size=sizeof(prec->k);
  pdbRecordType->papFldDes[82]->offset=(short)((char *)&prec->k - (char *)prec);
  pdbRecordType->papFldDes[83]->size=sizeof(prec->l);
  pdbRecordType->papFldDes[83]->offset=(short)((char *)&prec->l - (char *)prec);
  pdbRecordType->papFldDes[84]->size=sizeof(prec->la);
  pdbRecordType->papFldDes[84]->offset=(short)((char *)&prec->la - (char *)prec);
  pdbRecordType->papFldDes[85]->size=sizeof(prec->lb);
  pdbRecordType->papFldDes[85]->offset=(short)((char *)&prec->lb - (char *)prec);
  pdbRecordType->papFldDes[86]->size=sizeof(prec->lc);
  pdbRecordType->papFldDes[86]->offset=(short)((char *)&prec->lc - (char *)prec);
  pdbRecordType->papFldDes[87]->size=sizeof(prec->ld);
  pdbRecordType->papFldDes[87]->offset=(short)((char *)&prec->ld - (char *)prec);
  pdbRecordType->papFldDes[88]->size=sizeof(prec->le);
  pdbRecordType->papFldDes[88]->offset=(short)((char *)&prec->le - (char *)prec);
  pdbRecordType->papFldDes[89]->size=sizeof(prec->lf);
  pdbRecordType->papFldDes[89]->offset=(short)((char *)&prec->lf - (char *)prec);
  pdbRecordType->papFldDes[90]->size=sizeof(prec->lg);
  pdbRecordType->papFldDes[90]->offset=(short)((char *)&prec->lg - (char *)prec);
  pdbRecordType->papFldDes[91]->size=sizeof(prec->lh);
  pdbRecordType->papFldDes[91]->offset=(short)((char *)&prec->lh - (char *)prec);
  pdbRecordType->papFldDes[92]->size=sizeof(prec->li);
  pdbRecordType->papFldDes[92]->offset=(short)((char *)&prec->li - (char *)prec);
  pdbRecordType->papFldDes[93]->size=sizeof(prec->lj);
  pdbRecordType->papFldDes[93]->offset=(short)((char *)&prec->lj - (char *)prec);
  pdbRecordType->papFldDes[94]->size=sizeof(prec->lk);
  pdbRecordType->papFldDes[94]->offset=(short)((char *)&prec->lk - (char *)prec);
  pdbRecordType->papFldDes[95]->size=sizeof(prec->ll);
  pdbRecordType->papFldDes[95]->offset=(short)((char *)&prec->ll - (char *)prec);
  pdbRecordType->papFldDes[96]->size=sizeof(prec->lalm);
  pdbRecordType->papFldDes[96]->offset=(short)((char *)&prec->lalm - (char *)prec);
  pdbRecordType->papFldDes[97]->size=sizeof(prec->alst);
  pdbRecordType->papFldDes[97]->offset=(short)((char *)&prec->alst - (char *)prec);
  pdbRecordType->papFldDes[98]->size=sizeof(prec->mlst);
  pdbRecordType->papFldDes[98]->offset=(short)((char *)&prec->mlst - (char *)prec);
  pdbRecordType->papFldDes[99]->size=sizeof(prec->rpcl);
  pdbRecordType->papFldDes[99]->offset=(short)((char *)&prec->rpcl - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(calcRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
