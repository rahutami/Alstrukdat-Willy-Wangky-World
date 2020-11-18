#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

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

addressGraph AlokasiGraph(int id, MATRIKS peta){
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
/* Mengirimkan addressGraph hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressGraph tidak nil, dan misalnya */
/* menghasilkan P, maka ID(P)=X, NextGraph(P)=NULL, dan Link(P) berisi list kosong */
/* Jika alokasi gagal, mengirimkan NULL */

// void initGraph(Graph *G, int n){
//     /* KAMUS LOKAL */
//     addressGraph P;
//     int i;

//     /* ALGORITMA */
//     CreateEmptyGraph(G);
//     FirstGraph(*G) = AlokasiGraph(1);
//     P = FirstGraph(*G);
//     for (i = 2; i <= n; i++) {
//         NextGraph(P) = AlokasiGraph(i);
//         P = NextGraph(P);
//     }
// }
/* I. S. Graph G sembarang, n adalah jumlah building/ jumlah elemen parent list
   F. S. Terbentuk Graph n elemen dan link tiap elemen berupa empty list */

void PrintGraph(Graph G){
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
/* I.S. Graph mungkin kosong */
/* F.S. Jika Graph tidak kosong, isi info Graph dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Graph kosong : menulis [] */

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
/* I. S. Graph G terdefinisi, n dan p pasti tidak lebih dari jumlah building
   F. S. Link dari elemen n bertambah dengan p, dan sebaliknya (soalnya bolak balik)
   contoh :
   1 2->3
   2 1
   3 1
   Add(&G, 2, 3) 
   1 2->3
   2 1->3
   3 1->3 */

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