/* File: maplist.h
definisi Map */


#ifndef __maplist_H_
#define __maplist_H_

#include "../mesinkata/mesinkata.h"

#define Nil NULL

typedef int ValType;
typedef Kata KeyType;
typedef struct tMap* address;

/* Deklarasi tipe bentukan */


typedef struct tMap {
	address next;  /*pointer selanjutnya */
	KeyType key; /* key map */
	ValType val;  /* val map */
} ElmtMap;

typedef struct {
	address First;
} Map;

/* selektor tipe bentukan */

#define Key(P) (P)->key
#define Val(P) (P)->val
#define Next(P) (P)->next
#define First(M) ((M).First)


boolean IsEmpty (Map M);
/* Mengirim true jika First(M) = nil */

/* *** Kreator *** */
void CreateEmptyMap (Map *M);
/* I.S. sembarang */
/* F.S. Sebuah First Map M terbentuk dan salah satu kondisi sbb: */
/* First(M) = nil


/* *** Destruktor *** */
address Alokasi (KeyType X, ValType Y );
/* I.S. sembarang */
/* F.S. Sebuah First Map M terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Key(M) = nil dan Val(M) = nil dan Next(M) = nil */
/* alokasi dilakuka sampai berhasil*/


void DeAlokasi(address *M);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Insert (Map *M, KeyType X, ValType Y);
/* Proses: menanmbahka key dan val */
boolean SearcKey(Map *M,KeyType X);
// menegmbakikan val dari key jika ada , jika tidak val = 

int SearcVal(Map *M,KeyType X);
// menegmbakikan val dari key jika ada , jika tidak val = -1


#endif
