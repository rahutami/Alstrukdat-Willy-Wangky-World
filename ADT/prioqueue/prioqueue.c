/* File : prioqueue.c */

#include "prioqueue.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmptyQueue (PrioQueue Q){
    /* Mengirim true jika Q kosong: lihat definisi di atas */
    return(Head(Q) == NilQueue && Tail(Q) == NilQueue);
}
boolean IsFull (PrioQueue Q){
    /* Mengirim true jika tabel penampung elemen Q sudah penuh */
    /* yaitu mengandung elemen sebanyak MaxEl */
    return(NbElmtQueue(Q) == MaxEl(Q));
}
int NbElmtQueue (PrioQueue Q){
    /* Mengirimkan banyak orang di dalam antrian */
    /* ALGORITMA */
    if(IsEmptyQueue(Q)){
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
void CreateEmptyQueue (PrioQueue * Q, int Max){
    /* I.S. sembarang */
    /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
    /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
    /* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
    /* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    /* ALGORITMA */
    (*Q).T = (infotypeQueue*)malloc(Max * sizeof(infotypeQueue));
    if((*Q).T == NULL){
        MaxEl(*Q) = 0;
    } else {
        MaxEl(*Q) = Max;
        Head(*Q) = NilQueue;
        Tail(*Q) = NilQueue;
    }
}

/* *** Destruktor *** */
void DealokasiQueue(PrioQueue * Q){
    /* Proses: Mengembalikan memori Q */
    /* I.S. Q pernah dialokasi */
    /* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    /* ALGORITMA */
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueue * Q, infotypeQueue X){
    /* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
    /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
    /* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
            TAIL "maju" dengan mekanisme circular buffer; */
    /* KAMUS */
    int i, next;
    int found = 0;
    infotypeQueue temp;
    /* ALGORITMA */
    if(IsEmptyQueue(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoHead(*Q) = X;
    } else {
        i = Tail(*Q);
        while(i >= Head(*Q) && !found){
            if(Prio(ElmtQueue(*Q, i)) > Prio(X)){
                temp = ElmtQueue(*Q, i);
                if(i == Tail(*Q)){
                    Tail(*Q)++;
                    InfoTail(*Q) = temp;
                } else {
                    ElmtQueue(*Q, i + 1) = temp;
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
                    ElmtQueue(*Q, i+1) = X;
                }
                found = 1;
            }
        }

        if(!found){
            InfoHead(*Q) = X;
        }
    }

}

void FirstEnqueue(PrioQueue *Q, infotypeQueue X){
    /* Menambahkan X ke dalam queue dengan prioritas terbesar */
    Prio(X) = 1;
    Enqueue(Q, X);
}

void Dequeue (PrioQueue * Q, infotypeQueue * X){
    /* Proses: Menghapus X pada Q dengan aturan FIFO */
    /* I.S. Q tidak mungkin kosong */
    /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
            Q mungkin kosong */
    /* ALGORITMA */
    *X = InfoHead(*Q);
    if(Head(*Q) == Tail(*Q)){
        Head(*Q) = NilQueue;
        Tail(*Q) = NilQueue;
    } else {
        if(Head(*Q) == MaxEl(*Q) - 1){
            Head(*Q) = 0;
        } else {
            Head(*Q)++;
        }
    }
}

/* Operasi Tambahan */
void PrintPrioQueue (PrioQueue Q){
    /* Mencetak isi queue Q ke layar */
    /* I.S. Q terdefinisi, mungkin kosong */
    /* F.S. Q tercetak ke layar dengan format:
    <prio-1> <elemen-1>
    ...
    <prio-n> <elemen-n>
    #
    */
   /* KAMUS */
   int i;
   /* ALGORITMA */
   if(!IsEmptyQueue(Q)){
    if(Head(Q) <= Tail(Q)){
        for(i = Head(Q); i <= Tail(Q); i++){
            PrintInfo(InfoQueue(ElmtQueue(Q, i)));
            printf("kesabaran: %d\n", Prio(ElmtQueue(Q, i)));
        }
    } else {
        i = Head(Q);
        while(i <= Tail(Q)){
            PrintInfo(InfoQueue(ElmtQueue(Q, i)));
            printf("kesabaran: %d\n", Prio(ElmtQueue(Q, i)));
            if(i == MaxEl(Q) - 1 && i != Tail(Q)){
                i = 0;
            } else {
                i++;
            }
        }
    }

   }

}