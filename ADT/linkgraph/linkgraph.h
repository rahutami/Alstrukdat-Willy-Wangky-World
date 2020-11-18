#ifndef linkgraph_H
#define linkgraph_H

#include "../boolean/boolean.h"

#define NilLink NULL

typedef int infoTypeLink;

typedef struct tElmtlink *addressLink;
typedef struct tElmtlink {
	infoTypeLink InfoList;
	addressLink next;
} ElmtListLink;

typedef struct {
	addressLink First;
} ListLink;

#define InfoLink(P) (P)->InfoList
#define NextLink(P) (P)->next
#define FirstLink(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLink (ListLink L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyLink (ListLink *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressLink AlokasiLink (infoTypeLink X);
/* Mengirimkan addressLink hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLink tidak NilList, dan misalnya */
/* menghasilkan P, maka InfoList(P)=X, Next(P)=NilList */
/* Jika alokasi gagal, mengirimkan NilList */
void DealokasiLink (addressLink *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressLink P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressLink SearchLink (ListLink L, int X);
/* Mencari apakah ada elemen list dengan InfoList(P)= X */
/* Jika ada, mengirimkan addressLink elemen tersebut. */
/* Jika tidak ada, mengirimkan NilList */

void InsVLastLink (ListLink *L, infoTypeLink X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void PrintID (ListLink L);
#endif