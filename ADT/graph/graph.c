#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

player Player;

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLink (ListLink L)
/* Mengirim true jika list kosong */
{
    // KAMUS

    // ALGORITMa
    return FirstLink(L) == NULL;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyLink (ListLink *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    // KAMUS

    // ALGORITMA
    FirstLink(*L) = NULL; 
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
    NextLink(P) = NULL;

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
    
    while(P != NULL && InfoLink(P) != X){
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
    if(P != NULL){
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

void CreateEmptyGraph(Graph *G){
    /* KAMUS LOKAL */
    addressGraph P;

    /* ALGORITMA */
    FirstGraph(*G) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk graph kosong */

boolean IsGraphEmpty(Graph G){
    return (FirstGraph(G) == NULL);
}
/* Mengirimkan true jika graph kosong */

addressGraph AlokasiGraph(int id, MATRIKS peta)
/* Mengirimkan addressGraph hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressGraph tidak nil, dan misalnya */
/* menghasilkan P, maka ID(P)=X, NextGraph(P)=NULL, dan Link(P) berisi list kosong */
/* Jika alokasi gagal, mengirimkan NULL */
{
    addressGraph P;

    P = (ElmtGraph *) malloc (sizeof(ElmtGraph));
    if (P != NULL) {
        ID(P) = id;
        Peta(P) = peta;
        NextGraph(P) = NULL;
        CreateEmptyLink(&Link(P));
    }

    return P;
}

void PrintGraph(Graph G)
/* I.S. Graph mungkin kosong */
/* F.S. Jika Graph tidak kosong, isi info Graph dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Graph kosong : menulis [] */
{
    /* KAMUS LOKAL */
    addressGraph P;

    /* ALGORITMA */
    P = FirstGraph(G);
    printf("[");
    while (NextGraph(P) != NULL) {
        printf("%d, ", ID(P));
        P = NextGraph(P);
    }
    printf("%d", ID(P));
    printf("]\n");
}


void AddLink(Graph *G, int n, int p){
    /* KAMUS LOKAL */
    addressGraph addrGn, addrGp;

    /* ALGORITMA */
    /* Proses menambahkan link elemen n dengan p */
    addrGn = FirstGraph(*G);
    while (ID(addrGn) != n) {
        addrGn = NextGraph(addrGn);
    }
    if (SearchLink(Link(addrGn), p) == NULL) {
        InsVLastLink(&Link(addrGn), p);
    }

    /* Proses menambahkan link elemen p dengan n */
    addrGp = FirstGraph(*G);
    while (ID(addrGp) != p) {
        addrGp = NextGraph(addrGp);
    }
    if (SearchLink(Link(addrGp), n) == NULL) {
        InsVLastLink(&Link(addrGp), n);
    }
}

void PrintLink(Graph G, infoTypeLink X){
    /* KAMUS LOKAL */
    addressGraph P;
    ListLink L;

    /* ALGORITMA */
    P = FirstGraph(G);
    while (ID(P) != X) {
        P = NextGraph(P);
    }
    L = Link(P);
    PrintID(L);

}

boolean IsLinked(Graph G, infoTypeLink n, infoTypeLink p){
    /* KAMUS LOKAL */
    addressGraph addrGn;

    /* ALGORITMA */
    /* Proses menambahkan link elemen n dengan p */
    addrGn = FirstGraph(G);
    while (ID(addrGn) != n) {
        addrGn = NextGraph(addrGn);
    }

    if (SearchLink(Link(addrGn), p) != NULL) {
        return true;
    } else {
        return false;
    }
}
/* Mengembalikan true jika pada link n ada p */

addressGraph SearchGraph(Graph G, infoTypeLink X){
    /* KAMUS LOKAL */
    addressGraph addrG;

    /* ALGORITMA */
    addrG = FirstGraph(G);
    while ((ID(addrG) != X) && (addrG != NULL)) {
        addrG = NextGraph(addrG);
    }

    return addrG;
}

void InsGraphLast(Graph * G, addressGraph P){
    addressGraph PSearch = FirstGraph(*G);
    if(IsGraphEmpty(*G)){
        FirstGraph(*G) = P;
    } else {
        while ((NextGraph(PSearch) != NULL)){
            PSearch = NextGraph(PSearch);
        }
        NextGraph(PSearch) = P;
    }
    
}

void MakeLink(addressGraph * P){
    int i, j;

    for (i = 0; i<NKolEff(Peta(*P)); i++){
        for(j = 0; j<NBrsEff(Peta(*P)); j++){
            if(Elmt(Peta(*P), j, i) == '1') InsVLastLink(&(Link(*P)), 1);
            else if(Elmt(Peta(*P), j, i) == '2') InsVLastLink(&(Link(*P)), 2);
            else if(Elmt(Peta(*P), j, i) == '3') InsVLastLink(&(Link(*P)), 3);
            else if(Elmt(Peta(*P), j, i) == '4') InsVLastLink(&(Link(*P)), 4);
        }
    }
}

void CreateGraphPeta(MATRIKS Peta1, MATRIKS Peta2, MATRIKS Peta3, MATRIKS Peta4, Graph * G){
    addressGraph P;

    CreateEmptyGraph(G);

    P = AlokasiGraph(1, Peta1);
    InsGraphLast(G, P);
    MakeLink(&P);

    P = AlokasiGraph(2, Peta2);
    InsGraphLast(G, P);
    MakeLink(&P);

    P = AlokasiGraph(3, Peta3);
    InsGraphLast(G, P);
    MakeLink(&P);

    P = AlokasiGraph(4, Peta4);
    InsGraphLast(G, P);
    MakeLink(&P);

}

void PrintPetaGraph(Graph G){
    addressGraph P = FirstGraph(G);

    while(P != NULL){
        TulisMATRIKS(Peta(P));
        printf("\n");
        PrintID(Link(P));
        printf("\n==============================\n");
        P = NextGraph(P);
    }
}