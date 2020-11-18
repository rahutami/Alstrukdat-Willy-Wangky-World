#include "linkgraph.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLink (ListLink L)
/* Mengirim true jika list kosong */
{
    // KAMUS

    // ALGORITMa
    return FirstLink(L) == NilLink;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyLink (ListLink *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    // KAMUS

    // ALGORITMA
    FirstLink(*L) = NilLink; 
}
/****************** Manajemen Memori ******************/
addressLink AlokasiLink (infoTypeLink X)
/* Mengirimkan addressLink hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLink tidak NilList, dan misalnya */
/* menghasilkan P, maka InfoList(P)=X, NextLink(P)=NilList */
/* Jika alokasi gagal, mengirimkan NilList */
{
    // KAMUS
    addressLink P;

    // ALGORITMA
    P = (ElmtListLink*) malloc (sizeof(ElmtListLink));

    InfoLink(P) = X;
    NextLink(P) = NilLink;

    return P;
}

void DealokasiLink (addressLink *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressLink P */
{
    free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressLink SearchLink (ListLink L, int X)
/* Mencari apakah ada elemen list dengan InfoList(P)= X */
/* Jika ada, mengirimkan addressLink elemen tersebut. */
/* Jika tidak ada, mengirimkan NilList */
{
    // KAMUS
    addressLink P;
    // ALGORITMA
    P = FirstLink(L);
    
    while(P != NilLink && InfoLink(P) != X){
        P = NextLink(P);
    }

    return P;
}

void InsVLastLink (ListLink *L, infoTypeLink X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    // KAMUS
    addressLink P;

    // ALGORITMA
    P = AlokasiLink(X);
    if(P != NilLink){
        NextLink(P) = FirstLink(*L);
        FirstLink(*L) = P;
    }
}

void PrintID (ListLink L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    // KAMUS
    addressLink P;

    // ALGORITMA
    P = FirstLink(L);
    printf("[");

    if(!IsEmptyLink(L)){
        while(NextLink(P) != NULL){
            printf("%d,", InfoLink(P));
            P = NextLink(P);
        }
        printf("%d", InfoLink(P));
    }

    printf("]");
}