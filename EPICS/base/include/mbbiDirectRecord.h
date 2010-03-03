#ifndef INCmbbiDirectH
#define INCmbbiDirectH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
typedef struct mbbiDirectRecord {
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
	epicsUInt16	val;	/* Current Value */
	epicsInt16	nobt;	/* Number of Bits */
	DBLINK		inp;	/* Input Specification */
	epicsUInt32	rval;	/* Raw Value */
	epicsUInt32	oraw;	/* Prev Raw Value */
	epicsUInt32	mask;	/* Hardware Mask */
	epicsUInt16	mlst;	/* Last Value Monitored */
	epicsUInt16	lalm;	/* Last Value Alarmed */
	epicsInt16	sdef;	/* States Defined */
	epicsUInt16	shft;	/* Shift */
	DBLINK		siol;	/* Sim Input Specifctn */
	epicsUInt32	sval;	/* Simulation Value */
	DBLINK		siml;	/* Sim Mode Location */
	epicsEnum16	simm;	/* Simulation Mode */
	epicsEnum16	sims;	/* Sim mode Alarm Svrty */
	epicsUInt8	b0;	/* Bit 0 */
	epicsUInt8	b1;	/* Bit 1 */
	epicsUInt8	b2;	/* Bit 2 */
	epicsUInt8	b3;	/* Bit 3 */
	epicsUInt8	b4;	/* Bit 4 */
	epicsUInt8	b5;	/* Bit 5 */
	epicsUInt8	b6;	/* Bit 6 */
	epicsUInt8	b7;	/* Bit 7 */
	epicsUInt8	b8;	/* Bit 8 */
	epicsUInt8	b9;	/* Bit 9 */
	epicsUInt8	ba;	/* Bit A */
	epicsUInt8	bb;	/* Bit B */
	epicsUInt8	bc;	/* Bit C */
	epicsUInt8	bd;	/* Bit D */
	epicsUInt8	be;	/* Bit E */
	epicsUInt8	bf;	/* Bit F */
} mbbiDirectRecord;
#define mbbiDirectRecordNAME	0
#define mbbiDirectRecordDESC	1
#define mbbiDirectRecordASG	2
#define mbbiDirectRecordSCAN	3
#define mbbiDirectRecordPINI	4
#define mbbiDirectRecordPHAS	5
#define mbbiDirectRecordEVNT	6
#define mbbiDirectRecordTSE	7
#define mbbiDirectRecordTSEL	8
#define mbbiDirectRecordDTYP	9
#define mbbiDirectRecordDISV	10
#define mbbiDirectRecordDISA	11
#define mbbiDirectRecordSDIS	12
#define mbbiDirectRecordMLOK	13
#define mbbiDirectRecordMLIS	14
#define mbbiDirectRecordDISP	15
#define mbbiDirectRecordPROC	16
#define mbbiDirectRecordSTAT	17
#define mbbiDirectRecordSEVR	18
#define mbbiDirectRecordNSTA	19
#define mbbiDirectRecordNSEV	20
#define mbbiDirectRecordACKS	21
#define mbbiDirectRecordACKT	22
#define mbbiDirectRecordDISS	23
#define mbbiDirectRecordLCNT	24
#define mbbiDirectRecordPACT	25
#define mbbiDirectRecordPUTF	26
#define mbbiDirectRecordRPRO	27
#define mbbiDirectRecordASP	28
#define mbbiDirectRecordPPN	29
#define mbbiDirectRecordPPNR	30
#define mbbiDirectRecordSPVT	31
#define mbbiDirectRecordRSET	32
#define mbbiDirectRecordDSET	33
#define mbbiDirectRecordDPVT	34
#define mbbiDirectRecordRDES	35
#define mbbiDirectRecordLSET	36
#define mbbiDirectRecordPRIO	37
#define mbbiDirectRecordTPRO	38
#define mbbiDirectRecordBKPT	39
#define mbbiDirectRecordUDF	40
#define mbbiDirectRecordTIME	41
#define mbbiDirectRecordFLNK	42
#define mbbiDirectRecordVAL	43
#define mbbiDirectRecordNOBT	44
#define mbbiDirectRecordINP	45
#define mbbiDirectRecordRVAL	46
#define mbbiDirectRecordORAW	47
#define mbbiDirectRecordMASK	48
#define mbbiDirectRecordMLST	49
#define mbbiDirectRecordLALM	50
#define mbbiDirectRecordSDEF	51
#define mbbiDirectRecordSHFT	52
#define mbbiDirectRecordSIOL	53
#define mbbiDirectRecordSVAL	54
#define mbbiDirectRecordSIML	55
#define mbbiDirectRecordSIMM	56
#define mbbiDirectRecordSIMS	57
#define mbbiDirectRecordB0	58
#define mbbiDirectRecordB1	59
#define mbbiDirectRecordB2	60
#define mbbiDirectRecordB3	61
#define mbbiDirectRecordB4	62
#define mbbiDirectRecordB5	63
#define mbbiDirectRecordB6	64
#define mbbiDirectRecordB7	65
#define mbbiDirectRecordB8	66
#define mbbiDirectRecordB9	67
#define mbbiDirectRecordBA	68
#define mbbiDirectRecordBB	69
#define mbbiDirectRecordBC	70
#define mbbiDirectRecordBD	71
#define mbbiDirectRecordBE	72
#define mbbiDirectRecordBF	73
#endif /*INCmbbiDirectH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsExport.h>
static int mbbiDirectRecordSizeOffset(dbRecordType *pdbRecordType)
{
    mbbiDirectRecord *prec = 0;
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
  pdbRecordType->papFldDes[44]->size=sizeof(prec->nobt);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->nobt - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->inp);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->inp - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->rval);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->rval - (char *)prec);
  pdbRecordType->papFldDes[47]->size=sizeof(prec->oraw);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->oraw - (char *)prec);
  pdbRecordType->papFldDes[48]->size=sizeof(prec->mask);
  pdbRecordType->papFldDes[48]->offset=(short)((char *)&prec->mask - (char *)prec);
  pdbRecordType->papFldDes[49]->size=sizeof(prec->mlst);
  pdbRecordType->papFldDes[49]->offset=(short)((char *)&prec->mlst - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->lalm);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->lalm - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->sdef);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->sdef - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->shft);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->shft - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->siol);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->siol - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->sval);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->sval - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->siml);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->siml - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->simm);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->simm - (char *)prec);
  pdbRecordType->papFldDes[57]->size=sizeof(prec->sims);
  pdbRecordType->papFldDes[57]->offset=(short)((char *)&prec->sims - (char *)prec);
  pdbRecordType->papFldDes[58]->size=sizeof(prec->b0);
  pdbRecordType->papFldDes[58]->offset=(short)((char *)&prec->b0 - (char *)prec);
  pdbRecordType->papFldDes[59]->size=sizeof(prec->b1);
  pdbRecordType->papFldDes[59]->offset=(short)((char *)&prec->b1 - (char *)prec);
  pdbRecordType->papFldDes[60]->size=sizeof(prec->b2);
  pdbRecordType->papFldDes[60]->offset=(short)((char *)&prec->b2 - (char *)prec);
  pdbRecordType->papFldDes[61]->size=sizeof(prec->b3);
  pdbRecordType->papFldDes[61]->offset=(short)((char *)&prec->b3 - (char *)prec);
  pdbRecordType->papFldDes[62]->size=sizeof(prec->b4);
  pdbRecordType->papFldDes[62]->offset=(short)((char *)&prec->b4 - (char *)prec);
  pdbRecordType->papFldDes[63]->size=sizeof(prec->b5);
  pdbRecordType->papFldDes[63]->offset=(short)((char *)&prec->b5 - (char *)prec);
  pdbRecordType->papFldDes[64]->size=sizeof(prec->b6);
  pdbRecordType->papFldDes[64]->offset=(short)((char *)&prec->b6 - (char *)prec);
  pdbRecordType->papFldDes[65]->size=sizeof(prec->b7);
  pdbRecordType->papFldDes[65]->offset=(short)((char *)&prec->b7 - (char *)prec);
  pdbRecordType->papFldDes[66]->size=sizeof(prec->b8);
  pdbRecordType->papFldDes[66]->offset=(short)((char *)&prec->b8 - (char *)prec);
  pdbRecordType->papFldDes[67]->size=sizeof(prec->b9);
  pdbRecordType->papFldDes[67]->offset=(short)((char *)&prec->b9 - (char *)prec);
  pdbRecordType->papFldDes[68]->size=sizeof(prec->ba);
  pdbRecordType->papFldDes[68]->offset=(short)((char *)&prec->ba - (char *)prec);
  pdbRecordType->papFldDes[69]->size=sizeof(prec->bb);
  pdbRecordType->papFldDes[69]->offset=(short)((char *)&prec->bb - (char *)prec);
  pdbRecordType->papFldDes[70]->size=sizeof(prec->bc);
  pdbRecordType->papFldDes[70]->offset=(short)((char *)&prec->bc - (char *)prec);
  pdbRecordType->papFldDes[71]->size=sizeof(prec->bd);
  pdbRecordType->papFldDes[71]->offset=(short)((char *)&prec->bd - (char *)prec);
  pdbRecordType->papFldDes[72]->size=sizeof(prec->be);
  pdbRecordType->papFldDes[72]->offset=(short)((char *)&prec->be - (char *)prec);
  pdbRecordType->papFldDes[73]->size=sizeof(prec->bf);
  pdbRecordType->papFldDes[73]->offset=(short)((char *)&prec->bf - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(mbbiDirectRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
