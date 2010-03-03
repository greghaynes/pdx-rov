
#ifndef INCaSubLFLGH
#define INCaSubLFLGH
typedef enum {
	aSubLFLG_IGNORE,
	aSubLFLG_READ
}aSubLFLG;
#endif /*INCaSubLFLGH*/

#ifndef INCaSubEFLGH
#define INCaSubEFLGH
typedef enum {
	aSubEFLG_NEVER,
	aSubEFLG_ON_CHANGE,
	aSubEFLG_ALWAYS
}aSubEFLG;
#endif /*INCaSubEFLGH*/
#ifndef INCaSubH
#define INCaSubH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
struct aSubRecord;
typedef struct aSubRecord {
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
	epicsInt32	val;	/* Subr. return value */
	epicsInt32	oval;	/* Old return value */
	char		inam[41];	/* Initialize Subr. Name */
	epicsEnum16	lflg;	/* Subr. Input Enable */
	DBLINK		subl;	/* Subroutine Name Link */
	char		snam[41];	/* Process Subr. Name */
	char		onam[41];	/* Old Subr. Name */
	long (*sadr)(struct aSubRecord *);	/* Subroutine Address */
	epicsEnum16	brsv;	/* Bad Return Severity */
	epicsInt16	prec;	/* Display Precision */
	epicsEnum16	eflg;	/* Output Event Flag */
	DBLINK		inpa;	/* Input Link A */
	DBLINK		inpb;	/* Input Link B */
	DBLINK		inpc;	/* Input Link C */
	DBLINK		inpd;	/* Input Link D */
	DBLINK		inpe;	/* Input Link E */
	DBLINK		inpf;	/* Input Link F */
	DBLINK		inpg;	/* Input Link G */
	DBLINK		inph;	/* Input Link H */
	DBLINK		inpi;	/* Input Link I */
	DBLINK		inpj;	/* Input Link J */
	DBLINK		inpk;	/* Input Link K */
	DBLINK		inpl;	/* Input Link L */
	DBLINK		inpm;	/* Input Link M */
	DBLINK		inpn;	/* Input Link N */
	DBLINK		inpo;	/* Input Link O */
	DBLINK		inpp;	/* Input Link P */
	DBLINK		inpq;	/* Input Link Q */
	DBLINK		inpr;	/* Input Link R */
	DBLINK		inps;	/* Input Link S */
	DBLINK		inpt;	/* Input Link T */
	DBLINK		inpu;	/* Input Link U */
	void *a;	/* Input value A */
	void *b;	/* Input value B */
	void *c;	/* Input value C */
	void *d;	/* Input value D */
	void *e;	/* Input value E */
	void *f;	/* Input value F */
	void *g;	/* Input value G */
	void *h;	/* Input value H */
	void *i;	/* Input value I */
	void *j;	/* Input value J */
	void *k;	/* Input value K */
	void *l;	/* Input value L */
	void *m;	/* Input value M */
	void *n;	/* Input value N */
	void *o;	/* Input value O */
	void *p;	/* Input value P */
	void *q;	/* Input value Q */
	void *r;	/* Input value R */
	void *s;	/* Input value S */
	void *t;	/* Input value T */
	void *u;	/* Input value U */
	epicsEnum16	fta;	/* Type of A */
	epicsEnum16	ftb;	/* Type of B */
	epicsEnum16	ftc;	/* Type of C */
	epicsEnum16	ftd;	/* Type of D */
	epicsEnum16	fte;	/* Type of E */
	epicsEnum16	ftf;	/* Type of F */
	epicsEnum16	ftg;	/* Type of G */
	epicsEnum16	fth;	/* Type of H */
	epicsEnum16	fti;	/* Type of I */
	epicsEnum16	ftj;	/* Type of J */
	epicsEnum16	ftk;	/* Type of K */
	epicsEnum16	ftl;	/* Type of L */
	epicsEnum16	ftm;	/* Type of M */
	epicsEnum16	ftn;	/* Type of N */
	epicsEnum16	fto;	/* Type of O */
	epicsEnum16	ftp;	/* Type of P */
	epicsEnum16	ftq;	/* Type of Q */
	epicsEnum16	ftr;	/* Type of R */
	epicsEnum16	fts;	/* Type of S */
	epicsEnum16	ftt;	/* Type of T */
	epicsEnum16	ftu;	/* Type of U */
	epicsUInt32	noa;	/* Max. elements in A */
	epicsUInt32	nob;	/* Max. elements in B */
	epicsUInt32	noc;	/* Max. elements in C */
	epicsUInt32	nod;	/* Max. elements in D */
	epicsUInt32	noe;	/* Max. elements in E */
	epicsUInt32	nof;	/* Max. elements in F */
	epicsUInt32	nog;	/* Max. elements in G */
	epicsUInt32	noh;	/* Max. elements in H */
	epicsUInt32	noi;	/* Max. elements in I */
	epicsUInt32	noj;	/* Max. elements in J */
	epicsUInt32	nok;	/* Max. elements in K */
	epicsUInt32	nol;	/* Max. elements in L */
	epicsUInt32	nom;	/* Max. elements in M */
	epicsUInt32	non;	/* Max. elements in N */
	epicsUInt32	noo;	/* Max. elements in O */
	epicsUInt32	nop;	/* Max. elements in P */
	epicsUInt32	noq;	/* Max. elements in Q */
	epicsUInt32	nor;	/* Max. elements in R */
	epicsUInt32	nos;	/* Max. elements in S */
	epicsUInt32	not;	/* Max. elements in T */
	epicsUInt32	nou;	/* Max. elements in U */
	epicsUInt32	nea;	/* Num. elements in A */
	epicsUInt32	neb;	/* Num. elements in B */
	epicsUInt32	nec;	/* Num. elements in C */
	epicsUInt32	ned;	/* Num. elements in D */
	epicsUInt32	nee;	/* Num. elements in E */
	epicsUInt32	nef;	/* Num. elements in F */
	epicsUInt32	neg;	/* Num. elements in G */
	epicsUInt32	neh;	/* Num. elements in H */
	epicsUInt32	nei;	/* Num. elements in I */
	epicsUInt32	nej;	/* Num. elements in J */
	epicsUInt32	nek;	/* Num. elements in K */
	epicsUInt32	nel;	/* Num. elements in L */
	epicsUInt32	nem;	/* Num. elements in M */
	epicsUInt32	nen;	/* Num. elements in N */
	epicsUInt32	neo;	/* Num. elements in O */
	epicsUInt32	nep;	/* Num. elements in P */
	epicsUInt32	neq;	/* Num. elements in Q */
	epicsUInt32	ner;	/* Num. elements in R */
	epicsUInt32	nes;	/* Num. elements in S */
	epicsUInt32	net;	/* Num. elements in T */
	epicsUInt32	neu;	/* Num. elements in U */
	DBLINK		outa;	/* Output Link A */
	DBLINK		outb;	/* Output Link B */
	DBLINK		outc;	/* Output Link C */
	DBLINK		outd;	/* Output Link D */
	DBLINK		oute;	/* Output Link E */
	DBLINK		outf;	/* Output Link F */
	DBLINK		outg;	/* Output Link G */
	DBLINK		outh;	/* Output Link H */
	DBLINK		outi;	/* Output Link I */
	DBLINK		outj;	/* Output Link J */
	DBLINK		outk;	/* Output Link K */
	DBLINK		outl;	/* Output Link L */
	DBLINK		outm;	/* Output Link M */
	DBLINK		outn;	/* Output Link N */
	DBLINK		outo;	/* Output Link O */
	DBLINK		outp;	/* Output Link P */
	DBLINK		outq;	/* Output Link Q */
	DBLINK		outr;	/* Output Link R */
	DBLINK		outs;	/* Output Link S */
	DBLINK		outt;	/* Output Link T */
	DBLINK		outu;	/* Output Link U */
	void *vala;	/* Output value A */
	void *valb;	/* Output value B */
	void *valc;	/* Output value C */
	void *vald;	/* Output value D */
	void *vale;	/* Output value E */
	void *valf;	/* Output value F */
	void *valg;	/* Output value G */
	void *valh;	/* Output value H */
	void *vali;	/* Output value I */
	void *valj;	/* Output value J */
	void *valk;	/* Output value K */
	void *vall;	/* Output value L */
	void *valm;	/* Output value M */
	void *valn;	/* Output value N */
	void *valo;	/* Output value O */
	void *valp;	/* Output value P */
	void *valq;	/* Output value Q */
	void *valr;	/* Output value R */
	void *vals;	/* Output value S */
	void *valt;	/* Output value T */
	void *valu;	/* Output value U */
	void *ovla;	/* Old Output A */
	void *ovlb;	/* Old Output B */
	void *ovlc;	/* Old Output C */
	void *ovld;	/* Old Output D */
	void *ovle;	/* Old Output E */
	void *ovlf;	/* Old Output F */
	void *ovlg;	/* Old Output G */
	void *ovlh;	/* Old Output H */
	void *ovli;	/* Old Output I */
	void *ovlj;	/* Old Output J */
	void *ovlk;	/* Old Output K */
	void *ovll;	/* Old Output L */
	void *ovlm;	/* Old Output M */
	void *ovln;	/* Old Output N */
	void *ovlo;	/* Old Output O */
	void *ovlp;	/* Old Output P */
	void *ovlq;	/* Old Output Q */
	void *ovlr;	/* Old Output R */
	void *ovls;	/* Old Output S */
	void *ovlt;	/* Old Output T */
	void *ovlu;	/* Old Output U */
	epicsEnum16	ftva;	/* Type of VALA */
	epicsEnum16	ftvb;	/* Type of VALB */
	epicsEnum16	ftvc;	/* Type of VALC */
	epicsEnum16	ftvd;	/* Type of VALD */
	epicsEnum16	ftve;	/* Type of VALE */
	epicsEnum16	ftvf;	/* Type of VALF */
	epicsEnum16	ftvg;	/* Type of VALG */
	epicsEnum16	ftvh;	/* Type of VALH */
	epicsEnum16	ftvi;	/* Type of VALI */
	epicsEnum16	ftvj;	/* Type of VALJ */
	epicsEnum16	ftvk;	/* Type of VALK */
	epicsEnum16	ftvl;	/* Type of VALL */
	epicsEnum16	ftvm;	/* Type of VALM */
	epicsEnum16	ftvn;	/* Type of VALN */
	epicsEnum16	ftvo;	/* Type of VALO */
	epicsEnum16	ftvp;	/* Type of VALP */
	epicsEnum16	ftvq;	/* Type of VALQ */
	epicsEnum16	ftvr;	/* Type of VALR */
	epicsEnum16	ftvs;	/* Type of VALS */
	epicsEnum16	ftvt;	/* Type of VALT */
	epicsEnum16	ftvu;	/* Type of VALU */
	epicsUInt32	nova;	/* Max. elements in VALA */
	epicsUInt32	novb;	/* Max. elements in VALB */
	epicsUInt32	novc;	/* Max. elements in VALC */
	epicsUInt32	novd;	/* Max. elements in VALD */
	epicsUInt32	nove;	/* Max. elements in VALE */
	epicsUInt32	novf;	/* Max. elements in VALF */
	epicsUInt32	novg;	/* Max. elements in VALG */
	epicsUInt32	novh;	/* Max. elements in VAlH */
	epicsUInt32	novi;	/* Max. elements in VALI */
	epicsUInt32	novj;	/* Max. elements in VALJ */
	epicsUInt32	novk;	/* Max. elements in VALK */
	epicsUInt32	novl;	/* Max. elements in VALL */
	epicsUInt32	novm;	/* Max. elements in VALM */
	epicsUInt32	novn;	/* Max. elements in VALN */
	epicsUInt32	novo;	/* Max. elements in VALO */
	epicsUInt32	novp;	/* Max. elements in VALP */
	epicsUInt32	novq;	/* Max. elements in VALQ */
	epicsUInt32	novr;	/* Max. elements in VALR */
	epicsUInt32	novs;	/* Max. elements in VALS */
	epicsUInt32	novt;	/* Max. elements in VALT */
	epicsUInt32	novu;	/* Max. elements in VALU */
	epicsUInt32	neva;	/* Num. elements in VALA */
	epicsUInt32	nevb;	/* Num. elements in VALB */
	epicsUInt32	nevc;	/* Num. elements in VALC */
	epicsUInt32	nevd;	/* Num. elements in VALD */
	epicsUInt32	neve;	/* Num. elements in VALE */
	epicsUInt32	nevf;	/* Num. elements in VALF */
	epicsUInt32	nevg;	/* Num. elements in VALG */
	epicsUInt32	nevh;	/* Num. elements in VAlH */
	epicsUInt32	nevi;	/* Num. elements in VALI */
	epicsUInt32	nevj;	/* Num. elements in VALJ */
	epicsUInt32	nevk;	/* Num. elements in VALK */
	epicsUInt32	nevl;	/* Num. elements in VALL */
	epicsUInt32	nevm;	/* Num. elements in VALM */
	epicsUInt32	nevn;	/* Num. elements in VALN */
	epicsUInt32	nevo;	/* Num. elements in VALO */
	epicsUInt32	nevp;	/* Num. elements in VALP */
	epicsUInt32	nevq;	/* Num. elements in VALQ */
	epicsUInt32	nevr;	/* Num. elements in VALR */
	epicsUInt32	nevs;	/* Num. elements in VALS */
	epicsUInt32	nevt;	/* Num. elements in VALT */
	epicsUInt32	nevu;	/* Num. elements in VALU */
} aSubRecord;
#define aSubRecordNAME	0
#define aSubRecordDESC	1
#define aSubRecordASG	2
#define aSubRecordSCAN	3
#define aSubRecordPINI	4
#define aSubRecordPHAS	5
#define aSubRecordEVNT	6
#define aSubRecordTSE	7
#define aSubRecordTSEL	8
#define aSubRecordDTYP	9
#define aSubRecordDISV	10
#define aSubRecordDISA	11
#define aSubRecordSDIS	12
#define aSubRecordMLOK	13
#define aSubRecordMLIS	14
#define aSubRecordDISP	15
#define aSubRecordPROC	16
#define aSubRecordSTAT	17
#define aSubRecordSEVR	18
#define aSubRecordNSTA	19
#define aSubRecordNSEV	20
#define aSubRecordACKS	21
#define aSubRecordACKT	22
#define aSubRecordDISS	23
#define aSubRecordLCNT	24
#define aSubRecordPACT	25
#define aSubRecordPUTF	26
#define aSubRecordRPRO	27
#define aSubRecordASP	28
#define aSubRecordPPN	29
#define aSubRecordPPNR	30
#define aSubRecordSPVT	31
#define aSubRecordRSET	32
#define aSubRecordDSET	33
#define aSubRecordDPVT	34
#define aSubRecordRDES	35
#define aSubRecordLSET	36
#define aSubRecordPRIO	37
#define aSubRecordTPRO	38
#define aSubRecordBKPT	39
#define aSubRecordUDF	40
#define aSubRecordTIME	41
#define aSubRecordFLNK	42
#define aSubRecordVAL	43
#define aSubRecordOVAL	44
#define aSubRecordINAM	45
#define aSubRecordLFLG	46
#define aSubRecordSUBL	47
#define aSubRecordSNAM	48
#define aSubRecordONAM	49
#define aSubRecordSADR	50
#define aSubRecordBRSV	51
#define aSubRecordPREC	52
#define aSubRecordEFLG	53
#define aSubRecordINPA	54
#define aSubRecordINPB	55
#define aSubRecordINPC	56
#define aSubRecordINPD	57
#define aSubRecordINPE	58
#define aSubRecordINPF	59
#define aSubRecordINPG	60
#define aSubRecordINPH	61
#define aSubRecordINPI	62
#define aSubRecordINPJ	63
#define aSubRecordINPK	64
#define aSubRecordINPL	65
#define aSubRecordINPM	66
#define aSubRecordINPN	67
#define aSubRecordINPO	68
#define aSubRecordINPP	69
#define aSubRecordINPQ	70
#define aSubRecordINPR	71
#define aSubRecordINPS	72
#define aSubRecordINPT	73
#define aSubRecordINPU	74
#define aSubRecordA	75
#define aSubRecordB	76
#define aSubRecordC	77
#define aSubRecordD	78
#define aSubRecordE	79
#define aSubRecordF	80
#define aSubRecordG	81
#define aSubRecordH	82
#define aSubRecordI	83
#define aSubRecordJ	84
#define aSubRecordK	85
#define aSubRecordL	86
#define aSubRecordM	87
#define aSubRecordN	88
#define aSubRecordO	89
#define aSubRecordP	90
#define aSubRecordQ	91
#define aSubRecordR	92
#define aSubRecordS	93
#define aSubRecordT	94
#define aSubRecordU	95
#define aSubRecordFTA	96
#define aSubRecordFTB	97
#define aSubRecordFTC	98
#define aSubRecordFTD	99
#define aSubRecordFTE	100
#define aSubRecordFTF	101
#define aSubRecordFTG	102
#define aSubRecordFTH	103
#define aSubRecordFTI	104
#define aSubRecordFTJ	105
#define aSubRecordFTK	106
#define aSubRecordFTL	107
#define aSubRecordFTM	108
#define aSubRecordFTN	109
#define aSubRecordFTO	110
#define aSubRecordFTP	111
#define aSubRecordFTQ	112
#define aSubRecordFTR	113
#define aSubRecordFTS	114
#define aSubRecordFTT	115
#define aSubRecordFTU	116
#define aSubRecordNOA	117
#define aSubRecordNOB	118
#define aSubRecordNOC	119
#define aSubRecordNOD	120
#define aSubRecordNOE	121
#define aSubRecordNOF	122
#define aSubRecordNOG	123
#define aSubRecordNOH	124
#define aSubRecordNOI	125
#define aSubRecordNOJ	126
#define aSubRecordNOK	127
#define aSubRecordNOL	128
#define aSubRecordNOM	129
#define aSubRecordNON	130
#define aSubRecordNOO	131
#define aSubRecordNOP	132
#define aSubRecordNOQ	133
#define aSubRecordNOR	134
#define aSubRecordNOS	135
#define aSubRecordNOT	136
#define aSubRecordNOU	137
#define aSubRecordNEA	138
#define aSubRecordNEB	139
#define aSubRecordNEC	140
#define aSubRecordNED	141
#define aSubRecordNEE	142
#define aSubRecordNEF	143
#define aSubRecordNEG	144
#define aSubRecordNEH	145
#define aSubRecordNEI	146
#define aSubRecordNEJ	147
#define aSubRecordNEK	148
#define aSubRecordNEL	149
#define aSubRecordNEM	150
#define aSubRecordNEN	151
#define aSubRecordNEO	152
#define aSubRecordNEP	153
#define aSubRecordNEQ	154
#define aSubRecordNER	155
#define aSubRecordNES	156
#define aSubRecordNET	157
#define aSubRecordNEU	158
#define aSubRecordOUTA	159
#define aSubRecordOUTB	160
#define aSubRecordOUTC	161
#define aSubRecordOUTD	162
#define aSubRecordOUTE	163
#define aSubRecordOUTF	164
#define aSubRecordOUTG	165
#define aSubRecordOUTH	166
#define aSubRecordOUTI	167
#define aSubRecordOUTJ	168
#define aSubRecordOUTK	169
#define aSubRecordOUTL	170
#define aSubRecordOUTM	171
#define aSubRecordOUTN	172
#define aSubRecordOUTO	173
#define aSubRecordOUTP	174
#define aSubRecordOUTQ	175
#define aSubRecordOUTR	176
#define aSubRecordOUTS	177
#define aSubRecordOUTT	178
#define aSubRecordOUTU	179
#define aSubRecordVALA	180
#define aSubRecordVALB	181
#define aSubRecordVALC	182
#define aSubRecordVALD	183
#define aSubRecordVALE	184
#define aSubRecordVALF	185
#define aSubRecordVALG	186
#define aSubRecordVALH	187
#define aSubRecordVALI	188
#define aSubRecordVALJ	189
#define aSubRecordVALK	190
#define aSubRecordVALL	191
#define aSubRecordVALM	192
#define aSubRecordVALN	193
#define aSubRecordVALO	194
#define aSubRecordVALP	195
#define aSubRecordVALQ	196
#define aSubRecordVALR	197
#define aSubRecordVALS	198
#define aSubRecordVALT	199
#define aSubRecordVALU	200
#define aSubRecordOVLA	201
#define aSubRecordOVLB	202
#define aSubRecordOVLC	203
#define aSubRecordOVLD	204
#define aSubRecordOVLE	205
#define aSubRecordOVLF	206
#define aSubRecordOVLG	207
#define aSubRecordOVLH	208
#define aSubRecordOVLI	209
#define aSubRecordOVLJ	210
#define aSubRecordOVLK	211
#define aSubRecordOVLL	212
#define aSubRecordOVLM	213
#define aSubRecordOVLN	214
#define aSubRecordOVLO	215
#define aSubRecordOVLP	216
#define aSubRecordOVLQ	217
#define aSubRecordOVLR	218
#define aSubRecordOVLS	219
#define aSubRecordOVLT	220
#define aSubRecordOVLU	221
#define aSubRecordFTVA	222
#define aSubRecordFTVB	223
#define aSubRecordFTVC	224
#define aSubRecordFTVD	225
#define aSubRecordFTVE	226
#define aSubRecordFTVF	227
#define aSubRecordFTVG	228
#define aSubRecordFTVH	229
#define aSubRecordFTVI	230
#define aSubRecordFTVJ	231
#define aSubRecordFTVK	232
#define aSubRecordFTVL	233
#define aSubRecordFTVM	234
#define aSubRecordFTVN	235
#define aSubRecordFTVO	236
#define aSubRecordFTVP	237
#define aSubRecordFTVQ	238
#define aSubRecordFTVR	239
#define aSubRecordFTVS	240
#define aSubRecordFTVT	241
#define aSubRecordFTVU	242
#define aSubRecordNOVA	243
#define aSubRecordNOVB	244
#define aSubRecordNOVC	245
#define aSubRecordNOVD	246
#define aSubRecordNOVE	247
#define aSubRecordNOVF	248
#define aSubRecordNOVG	249
#define aSubRecordNOVH	250
#define aSubRecordNOVI	251
#define aSubRecordNOVJ	252
#define aSubRecordNOVK	253
#define aSubRecordNOVL	254
#define aSubRecordNOVM	255
#define aSubRecordNOVN	256
#define aSubRecordNOVO	257
#define aSubRecordNOVP	258
#define aSubRecordNOVQ	259
#define aSubRecordNOVR	260
#define aSubRecordNOVS	261
#define aSubRecordNOVT	262
#define aSubRecordNOVU	263
#define aSubRecordNEVA	264
#define aSubRecordNEVB	265
#define aSubRecordNEVC	266
#define aSubRecordNEVD	267
#define aSubRecordNEVE	268
#define aSubRecordNEVF	269
#define aSubRecordNEVG	270
#define aSubRecordNEVH	271
#define aSubRecordNEVI	272
#define aSubRecordNEVJ	273
#define aSubRecordNEVK	274
#define aSubRecordNEVL	275
#define aSubRecordNEVM	276
#define aSubRecordNEVN	277
#define aSubRecordNEVO	278
#define aSubRecordNEVP	279
#define aSubRecordNEVQ	280
#define aSubRecordNEVR	281
#define aSubRecordNEVS	282
#define aSubRecordNEVT	283
#define aSubRecordNEVU	284
#endif /*INCaSubH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsExport.h>
static int aSubRecordSizeOffset(dbRecordType *pdbRecordType)
{
    aSubRecord *prec = 0;
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
  pdbRecordType->papFldDes[44]->size=sizeof(prec->oval);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->oval - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->inam);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->inam - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->lflg);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->lflg - (char *)prec);
  pdbRecordType->papFldDes[47]->size=sizeof(prec->subl);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->subl - (char *)prec);
  pdbRecordType->papFldDes[48]->size=sizeof(prec->snam);
  pdbRecordType->papFldDes[48]->offset=(short)((char *)&prec->snam - (char *)prec);
  pdbRecordType->papFldDes[49]->size=sizeof(prec->onam);
  pdbRecordType->papFldDes[49]->offset=(short)((char *)&prec->onam - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->sadr);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->sadr - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->brsv);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->brsv - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->prec);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->prec - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->eflg);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->eflg - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->inpa);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->inpa - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->inpb);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->inpb - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->inpc);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->inpc - (char *)prec);
  pdbRecordType->papFldDes[57]->size=sizeof(prec->inpd);
  pdbRecordType->papFldDes[57]->offset=(short)((char *)&prec->inpd - (char *)prec);
  pdbRecordType->papFldDes[58]->size=sizeof(prec->inpe);
  pdbRecordType->papFldDes[58]->offset=(short)((char *)&prec->inpe - (char *)prec);
  pdbRecordType->papFldDes[59]->size=sizeof(prec->inpf);
  pdbRecordType->papFldDes[59]->offset=(short)((char *)&prec->inpf - (char *)prec);
  pdbRecordType->papFldDes[60]->size=sizeof(prec->inpg);
  pdbRecordType->papFldDes[60]->offset=(short)((char *)&prec->inpg - (char *)prec);
  pdbRecordType->papFldDes[61]->size=sizeof(prec->inph);
  pdbRecordType->papFldDes[61]->offset=(short)((char *)&prec->inph - (char *)prec);
  pdbRecordType->papFldDes[62]->size=sizeof(prec->inpi);
  pdbRecordType->papFldDes[62]->offset=(short)((char *)&prec->inpi - (char *)prec);
  pdbRecordType->papFldDes[63]->size=sizeof(prec->inpj);
  pdbRecordType->papFldDes[63]->offset=(short)((char *)&prec->inpj - (char *)prec);
  pdbRecordType->papFldDes[64]->size=sizeof(prec->inpk);
  pdbRecordType->papFldDes[64]->offset=(short)((char *)&prec->inpk - (char *)prec);
  pdbRecordType->papFldDes[65]->size=sizeof(prec->inpl);
  pdbRecordType->papFldDes[65]->offset=(short)((char *)&prec->inpl - (char *)prec);
  pdbRecordType->papFldDes[66]->size=sizeof(prec->inpm);
  pdbRecordType->papFldDes[66]->offset=(short)((char *)&prec->inpm - (char *)prec);
  pdbRecordType->papFldDes[67]->size=sizeof(prec->inpn);
  pdbRecordType->papFldDes[67]->offset=(short)((char *)&prec->inpn - (char *)prec);
  pdbRecordType->papFldDes[68]->size=sizeof(prec->inpo);
  pdbRecordType->papFldDes[68]->offset=(short)((char *)&prec->inpo - (char *)prec);
  pdbRecordType->papFldDes[69]->size=sizeof(prec->inpp);
  pdbRecordType->papFldDes[69]->offset=(short)((char *)&prec->inpp - (char *)prec);
  pdbRecordType->papFldDes[70]->size=sizeof(prec->inpq);
  pdbRecordType->papFldDes[70]->offset=(short)((char *)&prec->inpq - (char *)prec);
  pdbRecordType->papFldDes[71]->size=sizeof(prec->inpr);
  pdbRecordType->papFldDes[71]->offset=(short)((char *)&prec->inpr - (char *)prec);
  pdbRecordType->papFldDes[72]->size=sizeof(prec->inps);
  pdbRecordType->papFldDes[72]->offset=(short)((char *)&prec->inps - (char *)prec);
  pdbRecordType->papFldDes[73]->size=sizeof(prec->inpt);
  pdbRecordType->papFldDes[73]->offset=(short)((char *)&prec->inpt - (char *)prec);
  pdbRecordType->papFldDes[74]->size=sizeof(prec->inpu);
  pdbRecordType->papFldDes[74]->offset=(short)((char *)&prec->inpu - (char *)prec);
  pdbRecordType->papFldDes[75]->size=sizeof(prec->a);
  pdbRecordType->papFldDes[75]->offset=(short)((char *)&prec->a - (char *)prec);
  pdbRecordType->papFldDes[76]->size=sizeof(prec->b);
  pdbRecordType->papFldDes[76]->offset=(short)((char *)&prec->b - (char *)prec);
  pdbRecordType->papFldDes[77]->size=sizeof(prec->c);
  pdbRecordType->papFldDes[77]->offset=(short)((char *)&prec->c - (char *)prec);
  pdbRecordType->papFldDes[78]->size=sizeof(prec->d);
  pdbRecordType->papFldDes[78]->offset=(short)((char *)&prec->d - (char *)prec);
  pdbRecordType->papFldDes[79]->size=sizeof(prec->e);
  pdbRecordType->papFldDes[79]->offset=(short)((char *)&prec->e - (char *)prec);
  pdbRecordType->papFldDes[80]->size=sizeof(prec->f);
  pdbRecordType->papFldDes[80]->offset=(short)((char *)&prec->f - (char *)prec);
  pdbRecordType->papFldDes[81]->size=sizeof(prec->g);
  pdbRecordType->papFldDes[81]->offset=(short)((char *)&prec->g - (char *)prec);
  pdbRecordType->papFldDes[82]->size=sizeof(prec->h);
  pdbRecordType->papFldDes[82]->offset=(short)((char *)&prec->h - (char *)prec);
  pdbRecordType->papFldDes[83]->size=sizeof(prec->i);
  pdbRecordType->papFldDes[83]->offset=(short)((char *)&prec->i - (char *)prec);
  pdbRecordType->papFldDes[84]->size=sizeof(prec->j);
  pdbRecordType->papFldDes[84]->offset=(short)((char *)&prec->j - (char *)prec);
  pdbRecordType->papFldDes[85]->size=sizeof(prec->k);
  pdbRecordType->papFldDes[85]->offset=(short)((char *)&prec->k - (char *)prec);
  pdbRecordType->papFldDes[86]->size=sizeof(prec->l);
  pdbRecordType->papFldDes[86]->offset=(short)((char *)&prec->l - (char *)prec);
  pdbRecordType->papFldDes[87]->size=sizeof(prec->m);
  pdbRecordType->papFldDes[87]->offset=(short)((char *)&prec->m - (char *)prec);
  pdbRecordType->papFldDes[88]->size=sizeof(prec->n);
  pdbRecordType->papFldDes[88]->offset=(short)((char *)&prec->n - (char *)prec);
  pdbRecordType->papFldDes[89]->size=sizeof(prec->o);
  pdbRecordType->papFldDes[89]->offset=(short)((char *)&prec->o - (char *)prec);
  pdbRecordType->papFldDes[90]->size=sizeof(prec->p);
  pdbRecordType->papFldDes[90]->offset=(short)((char *)&prec->p - (char *)prec);
  pdbRecordType->papFldDes[91]->size=sizeof(prec->q);
  pdbRecordType->papFldDes[91]->offset=(short)((char *)&prec->q - (char *)prec);
  pdbRecordType->papFldDes[92]->size=sizeof(prec->r);
  pdbRecordType->papFldDes[92]->offset=(short)((char *)&prec->r - (char *)prec);
  pdbRecordType->papFldDes[93]->size=sizeof(prec->s);
  pdbRecordType->papFldDes[93]->offset=(short)((char *)&prec->s - (char *)prec);
  pdbRecordType->papFldDes[94]->size=sizeof(prec->t);
  pdbRecordType->papFldDes[94]->offset=(short)((char *)&prec->t - (char *)prec);
  pdbRecordType->papFldDes[95]->size=sizeof(prec->u);
  pdbRecordType->papFldDes[95]->offset=(short)((char *)&prec->u - (char *)prec);
  pdbRecordType->papFldDes[96]->size=sizeof(prec->fta);
  pdbRecordType->papFldDes[96]->offset=(short)((char *)&prec->fta - (char *)prec);
  pdbRecordType->papFldDes[97]->size=sizeof(prec->ftb);
  pdbRecordType->papFldDes[97]->offset=(short)((char *)&prec->ftb - (char *)prec);
  pdbRecordType->papFldDes[98]->size=sizeof(prec->ftc);
  pdbRecordType->papFldDes[98]->offset=(short)((char *)&prec->ftc - (char *)prec);
  pdbRecordType->papFldDes[99]->size=sizeof(prec->ftd);
  pdbRecordType->papFldDes[99]->offset=(short)((char *)&prec->ftd - (char *)prec);
  pdbRecordType->papFldDes[100]->size=sizeof(prec->fte);
  pdbRecordType->papFldDes[100]->offset=(short)((char *)&prec->fte - (char *)prec);
  pdbRecordType->papFldDes[101]->size=sizeof(prec->ftf);
  pdbRecordType->papFldDes[101]->offset=(short)((char *)&prec->ftf - (char *)prec);
  pdbRecordType->papFldDes[102]->size=sizeof(prec->ftg);
  pdbRecordType->papFldDes[102]->offset=(short)((char *)&prec->ftg - (char *)prec);
  pdbRecordType->papFldDes[103]->size=sizeof(prec->fth);
  pdbRecordType->papFldDes[103]->offset=(short)((char *)&prec->fth - (char *)prec);
  pdbRecordType->papFldDes[104]->size=sizeof(prec->fti);
  pdbRecordType->papFldDes[104]->offset=(short)((char *)&prec->fti - (char *)prec);
  pdbRecordType->papFldDes[105]->size=sizeof(prec->ftj);
  pdbRecordType->papFldDes[105]->offset=(short)((char *)&prec->ftj - (char *)prec);
  pdbRecordType->papFldDes[106]->size=sizeof(prec->ftk);
  pdbRecordType->papFldDes[106]->offset=(short)((char *)&prec->ftk - (char *)prec);
  pdbRecordType->papFldDes[107]->size=sizeof(prec->ftl);
  pdbRecordType->papFldDes[107]->offset=(short)((char *)&prec->ftl - (char *)prec);
  pdbRecordType->papFldDes[108]->size=sizeof(prec->ftm);
  pdbRecordType->papFldDes[108]->offset=(short)((char *)&prec->ftm - (char *)prec);
  pdbRecordType->papFldDes[109]->size=sizeof(prec->ftn);
  pdbRecordType->papFldDes[109]->offset=(short)((char *)&prec->ftn - (char *)prec);
  pdbRecordType->papFldDes[110]->size=sizeof(prec->fto);
  pdbRecordType->papFldDes[110]->offset=(short)((char *)&prec->fto - (char *)prec);
  pdbRecordType->papFldDes[111]->size=sizeof(prec->ftp);
  pdbRecordType->papFldDes[111]->offset=(short)((char *)&prec->ftp - (char *)prec);
  pdbRecordType->papFldDes[112]->size=sizeof(prec->ftq);
  pdbRecordType->papFldDes[112]->offset=(short)((char *)&prec->ftq - (char *)prec);
  pdbRecordType->papFldDes[113]->size=sizeof(prec->ftr);
  pdbRecordType->papFldDes[113]->offset=(short)((char *)&prec->ftr - (char *)prec);
  pdbRecordType->papFldDes[114]->size=sizeof(prec->fts);
  pdbRecordType->papFldDes[114]->offset=(short)((char *)&prec->fts - (char *)prec);
  pdbRecordType->papFldDes[115]->size=sizeof(prec->ftt);
  pdbRecordType->papFldDes[115]->offset=(short)((char *)&prec->ftt - (char *)prec);
  pdbRecordType->papFldDes[116]->size=sizeof(prec->ftu);
  pdbRecordType->papFldDes[116]->offset=(short)((char *)&prec->ftu - (char *)prec);
  pdbRecordType->papFldDes[117]->size=sizeof(prec->noa);
  pdbRecordType->papFldDes[117]->offset=(short)((char *)&prec->noa - (char *)prec);
  pdbRecordType->papFldDes[118]->size=sizeof(prec->nob);
  pdbRecordType->papFldDes[118]->offset=(short)((char *)&prec->nob - (char *)prec);
  pdbRecordType->papFldDes[119]->size=sizeof(prec->noc);
  pdbRecordType->papFldDes[119]->offset=(short)((char *)&prec->noc - (char *)prec);
  pdbRecordType->papFldDes[120]->size=sizeof(prec->nod);
  pdbRecordType->papFldDes[120]->offset=(short)((char *)&prec->nod - (char *)prec);
  pdbRecordType->papFldDes[121]->size=sizeof(prec->noe);
  pdbRecordType->papFldDes[121]->offset=(short)((char *)&prec->noe - (char *)prec);
  pdbRecordType->papFldDes[122]->size=sizeof(prec->nof);
  pdbRecordType->papFldDes[122]->offset=(short)((char *)&prec->nof - (char *)prec);
  pdbRecordType->papFldDes[123]->size=sizeof(prec->nog);
  pdbRecordType->papFldDes[123]->offset=(short)((char *)&prec->nog - (char *)prec);
  pdbRecordType->papFldDes[124]->size=sizeof(prec->noh);
  pdbRecordType->papFldDes[124]->offset=(short)((char *)&prec->noh - (char *)prec);
  pdbRecordType->papFldDes[125]->size=sizeof(prec->noi);
  pdbRecordType->papFldDes[125]->offset=(short)((char *)&prec->noi - (char *)prec);
  pdbRecordType->papFldDes[126]->size=sizeof(prec->noj);
  pdbRecordType->papFldDes[126]->offset=(short)((char *)&prec->noj - (char *)prec);
  pdbRecordType->papFldDes[127]->size=sizeof(prec->nok);
  pdbRecordType->papFldDes[127]->offset=(short)((char *)&prec->nok - (char *)prec);
  pdbRecordType->papFldDes[128]->size=sizeof(prec->nol);
  pdbRecordType->papFldDes[128]->offset=(short)((char *)&prec->nol - (char *)prec);
  pdbRecordType->papFldDes[129]->size=sizeof(prec->nom);
  pdbRecordType->papFldDes[129]->offset=(short)((char *)&prec->nom - (char *)prec);
  pdbRecordType->papFldDes[130]->size=sizeof(prec->non);
  pdbRecordType->papFldDes[130]->offset=(short)((char *)&prec->non - (char *)prec);
  pdbRecordType->papFldDes[131]->size=sizeof(prec->noo);
  pdbRecordType->papFldDes[131]->offset=(short)((char *)&prec->noo - (char *)prec);
  pdbRecordType->papFldDes[132]->size=sizeof(prec->nop);
  pdbRecordType->papFldDes[132]->offset=(short)((char *)&prec->nop - (char *)prec);
  pdbRecordType->papFldDes[133]->size=sizeof(prec->noq);
  pdbRecordType->papFldDes[133]->offset=(short)((char *)&prec->noq - (char *)prec);
  pdbRecordType->papFldDes[134]->size=sizeof(prec->nor);
  pdbRecordType->papFldDes[134]->offset=(short)((char *)&prec->nor - (char *)prec);
  pdbRecordType->papFldDes[135]->size=sizeof(prec->nos);
  pdbRecordType->papFldDes[135]->offset=(short)((char *)&prec->nos - (char *)prec);
  pdbRecordType->papFldDes[136]->size=sizeof(prec->not);
  pdbRecordType->papFldDes[136]->offset=(short)((char *)&prec->not - (char *)prec);
  pdbRecordType->papFldDes[137]->size=sizeof(prec->nou);
  pdbRecordType->papFldDes[137]->offset=(short)((char *)&prec->nou - (char *)prec);
  pdbRecordType->papFldDes[138]->size=sizeof(prec->nea);
  pdbRecordType->papFldDes[138]->offset=(short)((char *)&prec->nea - (char *)prec);
  pdbRecordType->papFldDes[139]->size=sizeof(prec->neb);
  pdbRecordType->papFldDes[139]->offset=(short)((char *)&prec->neb - (char *)prec);
  pdbRecordType->papFldDes[140]->size=sizeof(prec->nec);
  pdbRecordType->papFldDes[140]->offset=(short)((char *)&prec->nec - (char *)prec);
  pdbRecordType->papFldDes[141]->size=sizeof(prec->ned);
  pdbRecordType->papFldDes[141]->offset=(short)((char *)&prec->ned - (char *)prec);
  pdbRecordType->papFldDes[142]->size=sizeof(prec->nee);
  pdbRecordType->papFldDes[142]->offset=(short)((char *)&prec->nee - (char *)prec);
  pdbRecordType->papFldDes[143]->size=sizeof(prec->nef);
  pdbRecordType->papFldDes[143]->offset=(short)((char *)&prec->nef - (char *)prec);
  pdbRecordType->papFldDes[144]->size=sizeof(prec->neg);
  pdbRecordType->papFldDes[144]->offset=(short)((char *)&prec->neg - (char *)prec);
  pdbRecordType->papFldDes[145]->size=sizeof(prec->neh);
  pdbRecordType->papFldDes[145]->offset=(short)((char *)&prec->neh - (char *)prec);
  pdbRecordType->papFldDes[146]->size=sizeof(prec->nei);
  pdbRecordType->papFldDes[146]->offset=(short)((char *)&prec->nei - (char *)prec);
  pdbRecordType->papFldDes[147]->size=sizeof(prec->nej);
  pdbRecordType->papFldDes[147]->offset=(short)((char *)&prec->nej - (char *)prec);
  pdbRecordType->papFldDes[148]->size=sizeof(prec->nek);
  pdbRecordType->papFldDes[148]->offset=(short)((char *)&prec->nek - (char *)prec);
  pdbRecordType->papFldDes[149]->size=sizeof(prec->nel);
  pdbRecordType->papFldDes[149]->offset=(short)((char *)&prec->nel - (char *)prec);
  pdbRecordType->papFldDes[150]->size=sizeof(prec->nem);
  pdbRecordType->papFldDes[150]->offset=(short)((char *)&prec->nem - (char *)prec);
  pdbRecordType->papFldDes[151]->size=sizeof(prec->nen);
  pdbRecordType->papFldDes[151]->offset=(short)((char *)&prec->nen - (char *)prec);
  pdbRecordType->papFldDes[152]->size=sizeof(prec->neo);
  pdbRecordType->papFldDes[152]->offset=(short)((char *)&prec->neo - (char *)prec);
  pdbRecordType->papFldDes[153]->size=sizeof(prec->nep);
  pdbRecordType->papFldDes[153]->offset=(short)((char *)&prec->nep - (char *)prec);
  pdbRecordType->papFldDes[154]->size=sizeof(prec->neq);
  pdbRecordType->papFldDes[154]->offset=(short)((char *)&prec->neq - (char *)prec);
  pdbRecordType->papFldDes[155]->size=sizeof(prec->ner);
  pdbRecordType->papFldDes[155]->offset=(short)((char *)&prec->ner - (char *)prec);
  pdbRecordType->papFldDes[156]->size=sizeof(prec->nes);
  pdbRecordType->papFldDes[156]->offset=(short)((char *)&prec->nes - (char *)prec);
  pdbRecordType->papFldDes[157]->size=sizeof(prec->net);
  pdbRecordType->papFldDes[157]->offset=(short)((char *)&prec->net - (char *)prec);
  pdbRecordType->papFldDes[158]->size=sizeof(prec->neu);
  pdbRecordType->papFldDes[158]->offset=(short)((char *)&prec->neu - (char *)prec);
  pdbRecordType->papFldDes[159]->size=sizeof(prec->outa);
  pdbRecordType->papFldDes[159]->offset=(short)((char *)&prec->outa - (char *)prec);
  pdbRecordType->papFldDes[160]->size=sizeof(prec->outb);
  pdbRecordType->papFldDes[160]->offset=(short)((char *)&prec->outb - (char *)prec);
  pdbRecordType->papFldDes[161]->size=sizeof(prec->outc);
  pdbRecordType->papFldDes[161]->offset=(short)((char *)&prec->outc - (char *)prec);
  pdbRecordType->papFldDes[162]->size=sizeof(prec->outd);
  pdbRecordType->papFldDes[162]->offset=(short)((char *)&prec->outd - (char *)prec);
  pdbRecordType->papFldDes[163]->size=sizeof(prec->oute);
  pdbRecordType->papFldDes[163]->offset=(short)((char *)&prec->oute - (char *)prec);
  pdbRecordType->papFldDes[164]->size=sizeof(prec->outf);
  pdbRecordType->papFldDes[164]->offset=(short)((char *)&prec->outf - (char *)prec);
  pdbRecordType->papFldDes[165]->size=sizeof(prec->outg);
  pdbRecordType->papFldDes[165]->offset=(short)((char *)&prec->outg - (char *)prec);
  pdbRecordType->papFldDes[166]->size=sizeof(prec->outh);
  pdbRecordType->papFldDes[166]->offset=(short)((char *)&prec->outh - (char *)prec);
  pdbRecordType->papFldDes[167]->size=sizeof(prec->outi);
  pdbRecordType->papFldDes[167]->offset=(short)((char *)&prec->outi - (char *)prec);
  pdbRecordType->papFldDes[168]->size=sizeof(prec->outj);
  pdbRecordType->papFldDes[168]->offset=(short)((char *)&prec->outj - (char *)prec);
  pdbRecordType->papFldDes[169]->size=sizeof(prec->outk);
  pdbRecordType->papFldDes[169]->offset=(short)((char *)&prec->outk - (char *)prec);
  pdbRecordType->papFldDes[170]->size=sizeof(prec->outl);
  pdbRecordType->papFldDes[170]->offset=(short)((char *)&prec->outl - (char *)prec);
  pdbRecordType->papFldDes[171]->size=sizeof(prec->outm);
  pdbRecordType->papFldDes[171]->offset=(short)((char *)&prec->outm - (char *)prec);
  pdbRecordType->papFldDes[172]->size=sizeof(prec->outn);
  pdbRecordType->papFldDes[172]->offset=(short)((char *)&prec->outn - (char *)prec);
  pdbRecordType->papFldDes[173]->size=sizeof(prec->outo);
  pdbRecordType->papFldDes[173]->offset=(short)((char *)&prec->outo - (char *)prec);
  pdbRecordType->papFldDes[174]->size=sizeof(prec->outp);
  pdbRecordType->papFldDes[174]->offset=(short)((char *)&prec->outp - (char *)prec);
  pdbRecordType->papFldDes[175]->size=sizeof(prec->outq);
  pdbRecordType->papFldDes[175]->offset=(short)((char *)&prec->outq - (char *)prec);
  pdbRecordType->papFldDes[176]->size=sizeof(prec->outr);
  pdbRecordType->papFldDes[176]->offset=(short)((char *)&prec->outr - (char *)prec);
  pdbRecordType->papFldDes[177]->size=sizeof(prec->outs);
  pdbRecordType->papFldDes[177]->offset=(short)((char *)&prec->outs - (char *)prec);
  pdbRecordType->papFldDes[178]->size=sizeof(prec->outt);
  pdbRecordType->papFldDes[178]->offset=(short)((char *)&prec->outt - (char *)prec);
  pdbRecordType->papFldDes[179]->size=sizeof(prec->outu);
  pdbRecordType->papFldDes[179]->offset=(short)((char *)&prec->outu - (char *)prec);
  pdbRecordType->papFldDes[180]->size=sizeof(prec->vala);
  pdbRecordType->papFldDes[180]->offset=(short)((char *)&prec->vala - (char *)prec);
  pdbRecordType->papFldDes[181]->size=sizeof(prec->valb);
  pdbRecordType->papFldDes[181]->offset=(short)((char *)&prec->valb - (char *)prec);
  pdbRecordType->papFldDes[182]->size=sizeof(prec->valc);
  pdbRecordType->papFldDes[182]->offset=(short)((char *)&prec->valc - (char *)prec);
  pdbRecordType->papFldDes[183]->size=sizeof(prec->vald);
  pdbRecordType->papFldDes[183]->offset=(short)((char *)&prec->vald - (char *)prec);
  pdbRecordType->papFldDes[184]->size=sizeof(prec->vale);
  pdbRecordType->papFldDes[184]->offset=(short)((char *)&prec->vale - (char *)prec);
  pdbRecordType->papFldDes[185]->size=sizeof(prec->valf);
  pdbRecordType->papFldDes[185]->offset=(short)((char *)&prec->valf - (char *)prec);
  pdbRecordType->papFldDes[186]->size=sizeof(prec->valg);
  pdbRecordType->papFldDes[186]->offset=(short)((char *)&prec->valg - (char *)prec);
  pdbRecordType->papFldDes[187]->size=sizeof(prec->valh);
  pdbRecordType->papFldDes[187]->offset=(short)((char *)&prec->valh - (char *)prec);
  pdbRecordType->papFldDes[188]->size=sizeof(prec->vali);
  pdbRecordType->papFldDes[188]->offset=(short)((char *)&prec->vali - (char *)prec);
  pdbRecordType->papFldDes[189]->size=sizeof(prec->valj);
  pdbRecordType->papFldDes[189]->offset=(short)((char *)&prec->valj - (char *)prec);
  pdbRecordType->papFldDes[190]->size=sizeof(prec->valk);
  pdbRecordType->papFldDes[190]->offset=(short)((char *)&prec->valk - (char *)prec);
  pdbRecordType->papFldDes[191]->size=sizeof(prec->vall);
  pdbRecordType->papFldDes[191]->offset=(short)((char *)&prec->vall - (char *)prec);
  pdbRecordType->papFldDes[192]->size=sizeof(prec->valm);
  pdbRecordType->papFldDes[192]->offset=(short)((char *)&prec->valm - (char *)prec);
  pdbRecordType->papFldDes[193]->size=sizeof(prec->valn);
  pdbRecordType->papFldDes[193]->offset=(short)((char *)&prec->valn - (char *)prec);
  pdbRecordType->papFldDes[194]->size=sizeof(prec->valo);
  pdbRecordType->papFldDes[194]->offset=(short)((char *)&prec->valo - (char *)prec);
  pdbRecordType->papFldDes[195]->size=sizeof(prec->valp);
  pdbRecordType->papFldDes[195]->offset=(short)((char *)&prec->valp - (char *)prec);
  pdbRecordType->papFldDes[196]->size=sizeof(prec->valq);
  pdbRecordType->papFldDes[196]->offset=(short)((char *)&prec->valq - (char *)prec);
  pdbRecordType->papFldDes[197]->size=sizeof(prec->valr);
  pdbRecordType->papFldDes[197]->offset=(short)((char *)&prec->valr - (char *)prec);
  pdbRecordType->papFldDes[198]->size=sizeof(prec->vals);
  pdbRecordType->papFldDes[198]->offset=(short)((char *)&prec->vals - (char *)prec);
  pdbRecordType->papFldDes[199]->size=sizeof(prec->valt);
  pdbRecordType->papFldDes[199]->offset=(short)((char *)&prec->valt - (char *)prec);
  pdbRecordType->papFldDes[200]->size=sizeof(prec->valu);
  pdbRecordType->papFldDes[200]->offset=(short)((char *)&prec->valu - (char *)prec);
  pdbRecordType->papFldDes[201]->size=sizeof(prec->ovla);
  pdbRecordType->papFldDes[201]->offset=(short)((char *)&prec->ovla - (char *)prec);
  pdbRecordType->papFldDes[202]->size=sizeof(prec->ovlb);
  pdbRecordType->papFldDes[202]->offset=(short)((char *)&prec->ovlb - (char *)prec);
  pdbRecordType->papFldDes[203]->size=sizeof(prec->ovlc);
  pdbRecordType->papFldDes[203]->offset=(short)((char *)&prec->ovlc - (char *)prec);
  pdbRecordType->papFldDes[204]->size=sizeof(prec->ovld);
  pdbRecordType->papFldDes[204]->offset=(short)((char *)&prec->ovld - (char *)prec);
  pdbRecordType->papFldDes[205]->size=sizeof(prec->ovle);
  pdbRecordType->papFldDes[205]->offset=(short)((char *)&prec->ovle - (char *)prec);
  pdbRecordType->papFldDes[206]->size=sizeof(prec->ovlf);
  pdbRecordType->papFldDes[206]->offset=(short)((char *)&prec->ovlf - (char *)prec);
  pdbRecordType->papFldDes[207]->size=sizeof(prec->ovlg);
  pdbRecordType->papFldDes[207]->offset=(short)((char *)&prec->ovlg - (char *)prec);
  pdbRecordType->papFldDes[208]->size=sizeof(prec->ovlh);
  pdbRecordType->papFldDes[208]->offset=(short)((char *)&prec->ovlh - (char *)prec);
  pdbRecordType->papFldDes[209]->size=sizeof(prec->ovli);
  pdbRecordType->papFldDes[209]->offset=(short)((char *)&prec->ovli - (char *)prec);
  pdbRecordType->papFldDes[210]->size=sizeof(prec->ovlj);
  pdbRecordType->papFldDes[210]->offset=(short)((char *)&prec->ovlj - (char *)prec);
  pdbRecordType->papFldDes[211]->size=sizeof(prec->ovlk);
  pdbRecordType->papFldDes[211]->offset=(short)((char *)&prec->ovlk - (char *)prec);
  pdbRecordType->papFldDes[212]->size=sizeof(prec->ovll);
  pdbRecordType->papFldDes[212]->offset=(short)((char *)&prec->ovll - (char *)prec);
  pdbRecordType->papFldDes[213]->size=sizeof(prec->ovlm);
  pdbRecordType->papFldDes[213]->offset=(short)((char *)&prec->ovlm - (char *)prec);
  pdbRecordType->papFldDes[214]->size=sizeof(prec->ovln);
  pdbRecordType->papFldDes[214]->offset=(short)((char *)&prec->ovln - (char *)prec);
  pdbRecordType->papFldDes[215]->size=sizeof(prec->ovlo);
  pdbRecordType->papFldDes[215]->offset=(short)((char *)&prec->ovlo - (char *)prec);
  pdbRecordType->papFldDes[216]->size=sizeof(prec->ovlp);
  pdbRecordType->papFldDes[216]->offset=(short)((char *)&prec->ovlp - (char *)prec);
  pdbRecordType->papFldDes[217]->size=sizeof(prec->ovlq);
  pdbRecordType->papFldDes[217]->offset=(short)((char *)&prec->ovlq - (char *)prec);
  pdbRecordType->papFldDes[218]->size=sizeof(prec->ovlr);
  pdbRecordType->papFldDes[218]->offset=(short)((char *)&prec->ovlr - (char *)prec);
  pdbRecordType->papFldDes[219]->size=sizeof(prec->ovls);
  pdbRecordType->papFldDes[219]->offset=(short)((char *)&prec->ovls - (char *)prec);
  pdbRecordType->papFldDes[220]->size=sizeof(prec->ovlt);
  pdbRecordType->papFldDes[220]->offset=(short)((char *)&prec->ovlt - (char *)prec);
  pdbRecordType->papFldDes[221]->size=sizeof(prec->ovlu);
  pdbRecordType->papFldDes[221]->offset=(short)((char *)&prec->ovlu - (char *)prec);
  pdbRecordType->papFldDes[222]->size=sizeof(prec->ftva);
  pdbRecordType->papFldDes[222]->offset=(short)((char *)&prec->ftva - (char *)prec);
  pdbRecordType->papFldDes[223]->size=sizeof(prec->ftvb);
  pdbRecordType->papFldDes[223]->offset=(short)((char *)&prec->ftvb - (char *)prec);
  pdbRecordType->papFldDes[224]->size=sizeof(prec->ftvc);
  pdbRecordType->papFldDes[224]->offset=(short)((char *)&prec->ftvc - (char *)prec);
  pdbRecordType->papFldDes[225]->size=sizeof(prec->ftvd);
  pdbRecordType->papFldDes[225]->offset=(short)((char *)&prec->ftvd - (char *)prec);
  pdbRecordType->papFldDes[226]->size=sizeof(prec->ftve);
  pdbRecordType->papFldDes[226]->offset=(short)((char *)&prec->ftve - (char *)prec);
  pdbRecordType->papFldDes[227]->size=sizeof(prec->ftvf);
  pdbRecordType->papFldDes[227]->offset=(short)((char *)&prec->ftvf - (char *)prec);
  pdbRecordType->papFldDes[228]->size=sizeof(prec->ftvg);
  pdbRecordType->papFldDes[228]->offset=(short)((char *)&prec->ftvg - (char *)prec);
  pdbRecordType->papFldDes[229]->size=sizeof(prec->ftvh);
  pdbRecordType->papFldDes[229]->offset=(short)((char *)&prec->ftvh - (char *)prec);
  pdbRecordType->papFldDes[230]->size=sizeof(prec->ftvi);
  pdbRecordType->papFldDes[230]->offset=(short)((char *)&prec->ftvi - (char *)prec);
  pdbRecordType->papFldDes[231]->size=sizeof(prec->ftvj);
  pdbRecordType->papFldDes[231]->offset=(short)((char *)&prec->ftvj - (char *)prec);
  pdbRecordType->papFldDes[232]->size=sizeof(prec->ftvk);
  pdbRecordType->papFldDes[232]->offset=(short)((char *)&prec->ftvk - (char *)prec);
  pdbRecordType->papFldDes[233]->size=sizeof(prec->ftvl);
  pdbRecordType->papFldDes[233]->offset=(short)((char *)&prec->ftvl - (char *)prec);
  pdbRecordType->papFldDes[234]->size=sizeof(prec->ftvm);
  pdbRecordType->papFldDes[234]->offset=(short)((char *)&prec->ftvm - (char *)prec);
  pdbRecordType->papFldDes[235]->size=sizeof(prec->ftvn);
  pdbRecordType->papFldDes[235]->offset=(short)((char *)&prec->ftvn - (char *)prec);
  pdbRecordType->papFldDes[236]->size=sizeof(prec->ftvo);
  pdbRecordType->papFldDes[236]->offset=(short)((char *)&prec->ftvo - (char *)prec);
  pdbRecordType->papFldDes[237]->size=sizeof(prec->ftvp);
  pdbRecordType->papFldDes[237]->offset=(short)((char *)&prec->ftvp - (char *)prec);
  pdbRecordType->papFldDes[238]->size=sizeof(prec->ftvq);
  pdbRecordType->papFldDes[238]->offset=(short)((char *)&prec->ftvq - (char *)prec);
  pdbRecordType->papFldDes[239]->size=sizeof(prec->ftvr);
  pdbRecordType->papFldDes[239]->offset=(short)((char *)&prec->ftvr - (char *)prec);
  pdbRecordType->papFldDes[240]->size=sizeof(prec->ftvs);
  pdbRecordType->papFldDes[240]->offset=(short)((char *)&prec->ftvs - (char *)prec);
  pdbRecordType->papFldDes[241]->size=sizeof(prec->ftvt);
  pdbRecordType->papFldDes[241]->offset=(short)((char *)&prec->ftvt - (char *)prec);
  pdbRecordType->papFldDes[242]->size=sizeof(prec->ftvu);
  pdbRecordType->papFldDes[242]->offset=(short)((char *)&prec->ftvu - (char *)prec);
  pdbRecordType->papFldDes[243]->size=sizeof(prec->nova);
  pdbRecordType->papFldDes[243]->offset=(short)((char *)&prec->nova - (char *)prec);
  pdbRecordType->papFldDes[244]->size=sizeof(prec->novb);
  pdbRecordType->papFldDes[244]->offset=(short)((char *)&prec->novb - (char *)prec);
  pdbRecordType->papFldDes[245]->size=sizeof(prec->novc);
  pdbRecordType->papFldDes[245]->offset=(short)((char *)&prec->novc - (char *)prec);
  pdbRecordType->papFldDes[246]->size=sizeof(prec->novd);
  pdbRecordType->papFldDes[246]->offset=(short)((char *)&prec->novd - (char *)prec);
  pdbRecordType->papFldDes[247]->size=sizeof(prec->nove);
  pdbRecordType->papFldDes[247]->offset=(short)((char *)&prec->nove - (char *)prec);
  pdbRecordType->papFldDes[248]->size=sizeof(prec->novf);
  pdbRecordType->papFldDes[248]->offset=(short)((char *)&prec->novf - (char *)prec);
  pdbRecordType->papFldDes[249]->size=sizeof(prec->novg);
  pdbRecordType->papFldDes[249]->offset=(short)((char *)&prec->novg - (char *)prec);
  pdbRecordType->papFldDes[250]->size=sizeof(prec->novh);
  pdbRecordType->papFldDes[250]->offset=(short)((char *)&prec->novh - (char *)prec);
  pdbRecordType->papFldDes[251]->size=sizeof(prec->novi);
  pdbRecordType->papFldDes[251]->offset=(short)((char *)&prec->novi - (char *)prec);
  pdbRecordType->papFldDes[252]->size=sizeof(prec->novj);
  pdbRecordType->papFldDes[252]->offset=(short)((char *)&prec->novj - (char *)prec);
  pdbRecordType->papFldDes[253]->size=sizeof(prec->novk);
  pdbRecordType->papFldDes[253]->offset=(short)((char *)&prec->novk - (char *)prec);
  pdbRecordType->papFldDes[254]->size=sizeof(prec->novl);
  pdbRecordType->papFldDes[254]->offset=(short)((char *)&prec->novl - (char *)prec);
  pdbRecordType->papFldDes[255]->size=sizeof(prec->novm);
  pdbRecordType->papFldDes[255]->offset=(short)((char *)&prec->novm - (char *)prec);
  pdbRecordType->papFldDes[256]->size=sizeof(prec->novn);
  pdbRecordType->papFldDes[256]->offset=(short)((char *)&prec->novn - (char *)prec);
  pdbRecordType->papFldDes[257]->size=sizeof(prec->novo);
  pdbRecordType->papFldDes[257]->offset=(short)((char *)&prec->novo - (char *)prec);
  pdbRecordType->papFldDes[258]->size=sizeof(prec->novp);
  pdbRecordType->papFldDes[258]->offset=(short)((char *)&prec->novp - (char *)prec);
  pdbRecordType->papFldDes[259]->size=sizeof(prec->novq);
  pdbRecordType->papFldDes[259]->offset=(short)((char *)&prec->novq - (char *)prec);
  pdbRecordType->papFldDes[260]->size=sizeof(prec->novr);
  pdbRecordType->papFldDes[260]->offset=(short)((char *)&prec->novr - (char *)prec);
  pdbRecordType->papFldDes[261]->size=sizeof(prec->novs);
  pdbRecordType->papFldDes[261]->offset=(short)((char *)&prec->novs - (char *)prec);
  pdbRecordType->papFldDes[262]->size=sizeof(prec->novt);
  pdbRecordType->papFldDes[262]->offset=(short)((char *)&prec->novt - (char *)prec);
  pdbRecordType->papFldDes[263]->size=sizeof(prec->novu);
  pdbRecordType->papFldDes[263]->offset=(short)((char *)&prec->novu - (char *)prec);
  pdbRecordType->papFldDes[264]->size=sizeof(prec->neva);
  pdbRecordType->papFldDes[264]->offset=(short)((char *)&prec->neva - (char *)prec);
  pdbRecordType->papFldDes[265]->size=sizeof(prec->nevb);
  pdbRecordType->papFldDes[265]->offset=(short)((char *)&prec->nevb - (char *)prec);
  pdbRecordType->papFldDes[266]->size=sizeof(prec->nevc);
  pdbRecordType->papFldDes[266]->offset=(short)((char *)&prec->nevc - (char *)prec);
  pdbRecordType->papFldDes[267]->size=sizeof(prec->nevd);
  pdbRecordType->papFldDes[267]->offset=(short)((char *)&prec->nevd - (char *)prec);
  pdbRecordType->papFldDes[268]->size=sizeof(prec->neve);
  pdbRecordType->papFldDes[268]->offset=(short)((char *)&prec->neve - (char *)prec);
  pdbRecordType->papFldDes[269]->size=sizeof(prec->nevf);
  pdbRecordType->papFldDes[269]->offset=(short)((char *)&prec->nevf - (char *)prec);
  pdbRecordType->papFldDes[270]->size=sizeof(prec->nevg);
  pdbRecordType->papFldDes[270]->offset=(short)((char *)&prec->nevg - (char *)prec);
  pdbRecordType->papFldDes[271]->size=sizeof(prec->nevh);
  pdbRecordType->papFldDes[271]->offset=(short)((char *)&prec->nevh - (char *)prec);
  pdbRecordType->papFldDes[272]->size=sizeof(prec->nevi);
  pdbRecordType->papFldDes[272]->offset=(short)((char *)&prec->nevi - (char *)prec);
  pdbRecordType->papFldDes[273]->size=sizeof(prec->nevj);
  pdbRecordType->papFldDes[273]->offset=(short)((char *)&prec->nevj - (char *)prec);
  pdbRecordType->papFldDes[274]->size=sizeof(prec->nevk);
  pdbRecordType->papFldDes[274]->offset=(short)((char *)&prec->nevk - (char *)prec);
  pdbRecordType->papFldDes[275]->size=sizeof(prec->nevl);
  pdbRecordType->papFldDes[275]->offset=(short)((char *)&prec->nevl - (char *)prec);
  pdbRecordType->papFldDes[276]->size=sizeof(prec->nevm);
  pdbRecordType->papFldDes[276]->offset=(short)((char *)&prec->nevm - (char *)prec);
  pdbRecordType->papFldDes[277]->size=sizeof(prec->nevn);
  pdbRecordType->papFldDes[277]->offset=(short)((char *)&prec->nevn - (char *)prec);
  pdbRecordType->papFldDes[278]->size=sizeof(prec->nevo);
  pdbRecordType->papFldDes[278]->offset=(short)((char *)&prec->nevo - (char *)prec);
  pdbRecordType->papFldDes[279]->size=sizeof(prec->nevp);
  pdbRecordType->papFldDes[279]->offset=(short)((char *)&prec->nevp - (char *)prec);
  pdbRecordType->papFldDes[280]->size=sizeof(prec->nevq);
  pdbRecordType->papFldDes[280]->offset=(short)((char *)&prec->nevq - (char *)prec);
  pdbRecordType->papFldDes[281]->size=sizeof(prec->nevr);
  pdbRecordType->papFldDes[281]->offset=(short)((char *)&prec->nevr - (char *)prec);
  pdbRecordType->papFldDes[282]->size=sizeof(prec->nevs);
  pdbRecordType->papFldDes[282]->offset=(short)((char *)&prec->nevs - (char *)prec);
  pdbRecordType->papFldDes[283]->size=sizeof(prec->nevt);
  pdbRecordType->papFldDes[283]->offset=(short)((char *)&prec->nevt - (char *)prec);
  pdbRecordType->papFldDes[284]->size=sizeof(prec->nevu);
  pdbRecordType->papFldDes[284]->offset=(short)((char *)&prec->nevu - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(aSubRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
