/*  NIM     : 13519104
   Nama    : Nabelanita Utami
   Tanggal : 4 November 2020
   Topik praktikum : List linier
   Deskripsi       : Realisasi listlinier.h
*/
 
#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
 
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
   /* Mengirim true jika list kosong */
   return(First(L) == NULL);
}
 
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
   /* I.S. sembarang             */
   /* F.S. Terbentuk list kosong */
   First(*L) = Nil;
}
 
/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
   /* Mengirimkan address hasil alokasi sebuah elemen */
   /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
   /* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
   /* Jika alokasi gagal, mengirimkan Nil */
   /* KAMUS */
   address P;
   /* ALGORITMA */
   P = (ElmtList *) malloc(sizeof(ElmtList));
   if (P!= Nil) {
       Info(P) = X;
       Next(P) = Nil;
    }
    return P;
}
void Dealokasi (address *P){
   /* I.S. P terdefinisi */
   /* F.S. P dikembalikan ke sistem */
   /* Melakukan dealokasi/pengembalian address P */
   free(*P);
}
 
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
   /* Mencari apakah ada elemen list dengan Info(P)= X */
   /* Jika ada, mengirimkan address elemen tersebut. */
   /* Jika tidak ada, mengirimkan Nil */
   /* KAMUS */
   address P = First(L);
   boolean found = false;
   /* ALGORITMA */
   while(!found && (P != Nil)) {
       if (Info(P) == X) {
           found = true;
        } else {
           P = Next(P);
        }
    }
    return P;
}
 
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
   /* I.S. L mungkin kosong */
   /* F.S. Melakukan alokasi sebuah elemen dan */
   /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
   /* KAMUS */
   address P = Alokasi(X);
   /* ALGORITMA */
   if(P != Nil) {
       Next(P) = First(*L);
       First(*L) = P;
    }
}
void InsVLast (List *L, infotype X){
   /* I.S. L mungkin kosong */
   /* F.S. Melakukan alokasi sebuah elemen dan */
   /* menambahkan elemen list di akhir: elemen terakhir yang baru */
   /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
   /* KAMUS */
   address P;
   /* ALGORITMA */
   P = Alokasi(X);
   if(P != Nil) {
       InsertLast(L,P);
    }
}
 
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
   /* I.S. List L tidak kosong  */
   /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
   /*      dan alamat elemen pertama di-dealokasi */
   /* KAMUS */
   address P;
   /* ALGORITMA */
   DelFirst(L, &P);
   *X = Info(P);
   Dealokasi(&P);
}
void DelVLast (List *L, infotype *X){
   /* I.S. list tidak kosong */
   /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
   /*      dan alamat elemen terakhir di-dealokasi */
   /* KAMUS */
   address P;
   /* ALGORITMA */
   DelLast(L, &P);
   *X = Info(P);
   Dealokasi(&P);
}
 
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
   /* I.S. Sembarang, P sudah dialokasi  */
   /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
   /* ALGORITMA */
   Next(P) = First(*L);
   First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec){
   /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
   /*      P sudah dialokasi  */
   /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
   /* ALGORITMA */
   Next(P) = Next(Prec);
   Next(Prec) = P;
}
void InsertLast (List *L, address P){
   /* I.S. Sembarang, P sudah dialokasi  */
   /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
   /* KAMUS */
   address last;
   /* ALGORITMA */
    if(IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        last = First(*L);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        InsertAfter(L, P, last);
    }
}
 
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
   /* I.S. List tidak kosong */
   /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
   /*      Elemen list berkurang satu (mungkin menjadi kosong) */
   /* First element yg baru adalah suksesor elemen pertama yang lama */
   /* ALGORITMA */
   *P = First(*L);
   First(*L) = Next(First(*L));
   Next(*P) = Nil;
}
void DelP (List *L, infotype X){
   /* I.S. Sembarang */
   /* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
   /* Maka P dihapus dari list dan di-dealokasi */
   /* Jika ada lebih dari satu elemen list dengan Info bernilai X */
   /* maka yang dihapus hanya elemen pertama dengan Info = X */
   /* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
   /* List mungkin menjadi kosong karena penghapusan */
   /* KAMUS */
   address P = First(*L), del, prec = Nil;
   boolean found = false;
   /* ALGORITMA */
   while((P != Nil) && (!found)) {
       if (Info(P) == X) {
           found = true;
       } else {
           prec = P;
           P = Next(P);
       }
    }
 
   if(found) {
        if (prec == Nil) {
            DelFirst(L, &del);
        } else {
            DelAfter(L, &del, prec);
        }
        Dealokasi(&del);
    }
}
 
void DelLast (List *L, address *P){
	/* I.S. List tidak kosong */
	/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
	/*      Elemen list berkurang satu (mungkin menjadi kosong) */
	/* Last element baru adalah predesesor elemen terakhir yg lama, */
	/* jika ada */
	/* KAMUS */
	address last = First(*L), precLast = Nil;
	/* KAMUS */
    while(Next(last) != Nil) {
        precLast = last;
        last = Next(last);
    }

    if(precLast == Nil) {
        DelFirst(L, P);
    } else {
        DelAfter(L, P, precLast);
    }

}
void DelAfter (List *L, address *Pdel, address Prec) {
	/* I.S. List tidak kosong. Prec adalah anggota list  */
	/* F.S. Menghapus Next(Prec): */
	/*      Pdel adalah alamat elemen list yang dihapus  */
	/* KAMUS */
	address P = First(*L);
	boolean found = false;
	/* ALGORITMA  */
	while((P != Nil) && (!found)) {
        if (P == Prec) {
            found = true;
        } else {
            P = Next(P);
        }
    }

    *Pdel = Next(P);
    Next(P) = Next(Next(P));
    Next(*Pdel) = Nil;
}
 
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
	/* I.S. List mungkin kosong */
	/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
	/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
	/* Jika list kosong : menulis [] */
	/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
	/* KAMUS */
	address P;
	/* ALGORITMA */
	if(IsEmpty(L)) {
        printf("[]\n");
    } else { 
        P = First(L);
        printf("[%d", Info(P));
        P = Next(P);
        while(P != Nil) {
            printf(",%d", Info(P));
            P = Next(P);
        }
        printf("]\n");
    }
}
int NbElmt (List L) {
	/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
	/* KAMUS */
	address P;
	int count = 0;
	/* ALGORITMA */
	if(IsEmpty(L)){
		return 0;
	} else {
		P = First(L);
		while(P != Nil){
			count++;
			P = Next(P);
		}
		return count;
	}
}
 
/*** Prekondisi untuk Min: List tidak kosong ***/
infotype Min (List L) {
	/* Mengirimkan nilai Info(P) yang minimum */
	/* KAMUS */
    address P = Next(First(L));
	infotype minimum = Info(First(L));
	/* ALGORITMA */
    while(P != Nil) {
        if(minimum > Info(P)) {
            minimum = Info(P);
        }
        P = Next(P);
    }
    return minimum;
}
 
/*** Prekondisi untuk Max: List tidak kosong ***/
infotype Max (List L) {
	/* Mengirimkan nilai Info(P) yang maksimum */
	/* KAMUS */
	address P = Next(First(L));
	infotype maximum = Info(First(L));
	/* ALGORITMA */
	while (P != Nil) {
        if(maximum < Info(P)) {
            maximum = Info(P);
        }
        P = Next(P);
    }
    return maximum;
}
 
/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3) {
	/* I.S. L1 dan L2 sembarang */
	/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
	/* Konkatenasi dua buah list : L1 dan L2    */
	/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
	/* dan L1 serta L2 menjadi list kosong.*/
	/* Tidak ada alokasi/dealokasi pada prosedur ini */
	/* KAMUS */
	address P;
	/* ALGORITMA */
    if(IsEmpty(*L1)) {
        First(*L3) = First(*L2);
        First(*L2) = Nil;
    } else if(IsEmpty(*L2)) {
        First(*L3) = First(*L1);
        First(*L1) = Nil;
    } else if(IsEmpty(*L1) && IsEmpty(*L2)) {
		First(*L3) = Nil;
	} else {
        First(*L3) = First(*L1);
        P = First(*L3);
        while(Next(P) != Nil){
            P = Next(P);
        }
        Next(P) = First(*L2);

        First(*L1) = Nil;
        First(*L2) = Nil;
	}
}