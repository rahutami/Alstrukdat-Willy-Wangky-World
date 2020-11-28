/* File: maplist.h
definisi Map */


#ifndef __maplist_H_
#define __maplist_H_

#include "../mesinkata/mesinkata.h"

//#define Nil NULL

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
	address FirstMap;
} Map;

/* selektor tipe bentukan */

#define Key(P) (P)->key
#define Val(P) (P)->val
#define NextMap(P) (P)->next
#define FirstMap(M) ((M).FirstMap)


boolean IsEmpty (Map M);
/* Mengirim true jika FirstMap(M) = nil */

/* *** Kreator *** */
void CreateEmptyMap (Map *M);
/* I.S. sembarang */
/* F.S. Sebuah FirstMap Map M terbentuk dan salah satu kondisi sbb: */
/* FirstMap(M) = nil */


/* *** Destruktor *** */
address AlokasiMap (KeyType X, ValType Y );
/* I.S. sembarang */
/* F.S. Sebuah FirstMap Map M terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Key(M) = nil dan Val(M) = nil dan NextMap(M) = nil */
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
