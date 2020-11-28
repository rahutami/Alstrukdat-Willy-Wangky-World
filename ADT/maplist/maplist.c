/*
name_file : maplist.c
Nama : Muhammad Rizal Muhaimin
NIM : 13519136
Deskripsi: file body maplist.h

*/

#include "maplist.h"
#include <stdio.h>
#include <stdlib.h>

/* selektor tipe bentukan 

#define Key(P) (P)->key
#define Val(P) (P)->val
#define NextMap(P) (P)->next
#define FirstMap(M) ((M).FirstMap)
*/


boolean IsEmpty (Map M)
/* Mengirim true jika FirstMap(M) = nil */
{
	return FirstMap(M) == NULL;
}

/* *** Kreator *** */
void CreateEmptyMap (Map *M)
/* I.S. sembarang */
/* F.S. Sebuah FirstMap Map M terbentuk dan salah satu kondisi sbb: */
/* FirstMap(M) = nil*/
{
	FirstMap(*M) = NULL;
}


/* *** Destruktor *** */
address AlokasiMap (KeyType X, ValType Y )
/* I.S. sembarang */
/* F.S. Sebuah FirstMap Map M terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Key(M) = nil dan Val(M) = nil dan NextMap(M) = nil */
/* alokasi dilakuka sampai berhasil*/
{
	address P;
	P = NULL;
	P = (ElmtMap *) malloc(sizeof(ElmtMap));
	if(P != NULL){
		Key(P) = X;
		Val(P) = Y;
		NextMap(P) = NULL;
	}

	return P;
}


void DeAlokasi(address *M)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	free(*M);
	*M = NULL;
}

/* *** Primitif Add/Delete *** */
void Insert (Map *M, KeyType X, ValType Y)
/* Proses: menanmbahka key dan val */
{
	address P = AlokasiMap(X,Y);
	if(P != NULL){
		if(IsEmpty(*M)){
			FirstMap(*M) = AlokasiMap(X,Y);
		}else{
			P = FirstMap(*M);
			while(NextMap(P) != NULL){
				P = NextMap(P);
			}
			//Kondisi NextMap = nill
			NextMap(P) = AlokasiMap(X,Y);
		}
	}
}

boolean SearcKey(Map *M,KeyType X)
// menegmbakikan true jika key ada 
{
	address P;
	P = FirstMap(*M);
	while (P != NULL && !IsKataSamaKata (Key(P), X)){
		P = NextMap(P);
	}
	return IsKataSamaKata (Key(P), X);
}

int SearcVal(Map *M,KeyType X)
// menegmbakikan val dari key jika ada , jika tidak val = -1
{
	address P;
	P = FirstMap(*M);
	while (P != NULL && !IsKataSamaKata (Key(P), X)){
		P = NextMap(P);
	}
	if (IsKataSamaKata (Key(P), X)){
		return Val(P);
	}else{
		return -1;
	}
}