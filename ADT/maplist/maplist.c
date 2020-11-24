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
#define Next(P) (P)->next
#define First(M) ((M).First)
*/


boolean IsEmpty (Map M)
/* Mengirim true jika First(M) = nil */
{
	return First(M) == Nil;
}

/* *** Kreator *** */
void CreateEmptyMap (Map *M)
/* I.S. sembarang */
/* F.S. Sebuah First Map M terbentuk dan salah satu kondisi sbb: */
/* First(M) = nil*/
{
	First(*M) = Nil;
}


/* *** Destruktor *** */
address Alokasi (KeyType X, ValType Y )
/* I.S. sembarang */
/* F.S. Sebuah First Map M terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Key(M) = nil dan Val(M) = nil dan Next(M) = nil */
/* alokasi dilakuka sampai berhasil*/
{
	address P;
	P = Nil;
	P = (ElmtMap *) malloc(sizeof(ElmtMap));
	if(P != Nil){
		Key(P) = X;
		Val(P) = Y;
		Next(P) = Nil;
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
	address P = Alokasi(X,Y);
	if(P != Nil){
		if(IsEmpty(*M)){
			First(*M) = Alokasi(X,Y);
		}else{
			P = First(*M);
			while(Next(P) != Nil){
				P = Next(P);
			}
			//Kondisi Next = nill
			Next(P) = Alokasi(X,Y);
		}
	}
}

boolean SearcKey(Map *M,KeyType X)
// menegmbakikan true jika key ada 
{
	address P;
	P = First(*M);
	while (P != Nil && !IsKataSamaKata (Key(P), X)){
		P = Next(P);
	}
	return IsKataSamaKata (Key(P), X);
}

int SearcVal(Map *M,KeyType X)
// menegmbakikan val dari key jika ada , jika tidak val = -1
{
	address P;
	P = First(*M);
	while (P != Nil && !IsKataSamaKata (Key(P), X)){
		P = Next(P);
	}
	if (IsKataSamaKata (Key(P), X)){
		return Val(P);
	}else{
		return -1;
	}
}