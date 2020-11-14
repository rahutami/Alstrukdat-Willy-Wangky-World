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
        if(Search(InfoQueue(InfoHead(*Q)), W) == NilList){
            printf("Wahana salah\n");
        } else {
            // perlu data2 wahana dulu soalnya harus cek harga wahana, etc2
            printf("berhasil!");
        }
    } else {
        printf("Antrian kosong.\n");
    }
}