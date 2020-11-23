#include "ADT/prioqueue/prioqueue.h"
#include "ADT/listlinier/listlinier.h"
#include "ADT/listplayer/listplayer.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/wahana/wahana.h"
#include "ADT/player/player.h"
#include "ADT/jam/jam.h"
#include <stdio.h>


void Serve(player *P, Kata W, PrioQueue *Q, listPlayer *LP, TreeWahanaS T){
    /* I.S. W adalah wahana, bisa tidak valid. Q adalah priority queue */
    /* F.S. Jika wahana terdapat pada salah satu list wahana di priority queue, maka */
    /*      wahana akan dikeluarkan dari list tersebut. Jika list menjadi kosong, antrian berkurang */
    /* KAMUS */
    List L;
    addressList S;
    infotypeQueue del;
    infoLP customer;
    /* ALGORITMA */
    if(!IsEmptyQueue(*Q)){
        L = InfoQueue(InfoHead(*Q));
        S = Search(L, W);
        if(S == NilList){
            printf("Wahana tidak ada di dalam antrian pelanggan. Silahkan coba lagi. \n\n");
        } else {
            CJam(*P) = NextMenit(CJam(*P));
            /* Masih perlu implementasi ADT wahana untuk penambahan uang */
            /* Money(*P) += (Insert wahana price) */
            Dequeue(Q, &del);
            DelP(&InfoQueue(del), W);
            if (!IsEmptyList(InfoQueue(del))) {
                PlayerInfo(customer) = InfoQueue(del);
                Remaining(customer) = 10; // untuk sementara diset semua wahana durasinya 10 menit
                InsVLastLP(LP, customer);
            }
            printf("Selamat menikmati wahana ");
            PrintKata(W);
            printf("!\n\n");
        }
    } else {
        printf("Antrian kosong.\n\n");
    }
}