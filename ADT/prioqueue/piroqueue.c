/* File : prioqueue.c */

#include "prioqueue.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
    /* Mengirim true jika Q kosong: lihat definisi di atas */
    return(Head(Q) == Nil && Tail(Q) == Nil);
}
boolean IsFull (PrioQueueChar Q){
    /* Mengirim true jika tabel penampung elemen Q sudah penuh */
    /* yaitu mengandung elemen sebanyak MaxEl */
    return(NBElmt(Q) == MaxEl(Q));
}
int NBQueue (PrioQueueChar Q){
    /* Mengirimkan banyak orang di dalam antrian */
    /* ALGORITMA */
    if(IsEmpty(Q)){
        return 0;
    } else if (Tail(Q) == Head(Q)){
        return 1;
    } else {
       if (Head(Q) > Tail(Q)) {
            return ((Tail(Q) + 1) + (MaxEl(Q) - Head(Q)));
        }
        else {
            return Tail(Q) - Head(Q) + 1;
        }

    }
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max){
    /* I.S. sembarang */
    /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
    /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
    /* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
    /* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    /* ALGORITMA */
    (*Q).T = (infotype*)malloc(Max * sizeof(infotype));
    if((*Q).T == NULL){
        MaxEl(*Q) = 0;
    } else {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
    /* Proses: Mengembalikan memori Q */
    /* I.S. Q pernah dialokasi */
    /* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    /* ALGORITMA */
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X){
    /* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
    /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
    /* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
            TAIL "maju" dengan mekanisme circular buffer; */
    /* KAMUS */
    int i, next;
    int found = 0;
    infotype temp;
    /* ALGORITMA */
    if(IsEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoHead(*Q) = X;
    } else {
        i = Tail(*Q);
        while(i >= Head(*Q) && !found){
            if(Prio(Elmt(*Q, i)) > Prio(X)){
                temp = Elmt(*Q, i);
                if(i == Tail(*Q)){
                    Tail(*Q)++;
                    InfoTail(*Q) = temp;
                } else {
                    Elmt(*Q, i + 1) = temp;
                }
                if(i == 0 && i != Head(*Q)){
                    i = 0;
                } else {
                    i--;
                }
            } else {
                if(i == Tail(*Q)){
                    Tail(*Q)++;
                    InfoTail(*Q) = X;
                } else {
                    Elmt(*Q, i+1) = X;
                }
                found = 1;
            }
        }

        if(!found){
            InfoHead(*Q) = X;
        }
    }

}

void FirstEnqueue(PrioQueueChar *Q, infotype X){
    /* Menambahkan X ke dalam queue dengan prioritas terbesar */
    Prio(X) = 1;
    Enqueue(Q, X);
}

void Dequeue (PrioQueueChar * Q, infotype * X){
    /* Proses: Menghapus X pada Q dengan aturan FIFO */
    /* I.S. Q tidak mungkin kosong */
    /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
            Q mungkin kosong */
    /* ALGORITMA */
    *X = InfoHead(*Q);
    if(Head(*Q) == Tail(*Q)){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        if(Head(*Q) == MaxEl(*Q) - 1){
            Head(*Q) = 0;
        } else {
            Head(*Q)++;
        }
    }
}

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
    /* Mencetak isi queue Q ke layar */
    /* I.S. Q terdefinisi, mungkin kosong */
    /* F.S. Q tercetak ke layar dengan format:
    <prio-1> <elemen-1>
    ...
    <prio-n> <elemen-n>
    #
    */
   /* KAMUS */
   int i, idx;
   /* ALGORITMA */
   if(!IsEmpty(Q)){
    if(Head(Q) <= Tail(Q)){
        for(i = Head(Q); i <= Tail(Q); i++){
            printf("%d %c\n", Prio(Elmt(Q, i)), Info(Elmt(Q, i)));
        }
    } else {
        i = Head(Q);
        while(i <= Tail(Q)){
            printf("%d %c\n", Prio(Elmt(Q, i)), Info(Elmt(Q, i)));
            if(i == MaxEl(Q) - 1 && i != Tail(Q)){
                i = 0;
            } else {
                i++;
            }
        }
    }

   }

   
   printf("#\n");

}