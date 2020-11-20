#include "ADT/prioqueue/prioqueue.h"
#include "ADT/listlinier/listlinier.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/player/player.h"
#include <stdio.h>


void Serve(Kata W, PrioQueue *Q){
    /* I.S. W adalah wahana, bisa tidak valid. Q adalah priority queue */
    /* F.S. Jika wahana terdapat pada salah satu list wahana di priority queue, maka */
    /*      wahana akan dikeluarkan dari list tersebut. Jika list menjadi kosong, antrian berkurang */
    /* ALGORITMA */
    if(!IsEmptyQueue(*Q)){
        List L = InfoQueue(InfoHead(*Q));
        addressList P = Search(L, W);
        if(P == NilList){
            printf("Wahana tidak ada di dalam antrian pelanggan. Silahkan coba lagi. \n");
        } else {
            DelP(&L, W);
            printf("Selamat menikmati wahana ");
            PrintKata(W);
            printf("!\n");
            PrintPrioQueue(*Q);
        }
    } else {
        printf("Antrian kosong.\n");
    }
}