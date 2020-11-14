#include "../boolean/boolean.h"
#include <stdio.h>
#include "stackt.h"

//#define Nil -1
//#define MaxEl 10
/* Nil adalah stack dengan elemen kosong . */

//typedef int infotype;
//typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
//typedef struct { 
 // infotype T[MaxEl]; /* tabel penyimpan elemen */
 // address TOP;  /* alamat TOP: elemen puncak */
//} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
//#define Top(S) (S).TOP
//#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S)=Nil;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return(Top(S)==Nil);
}
boolean IsFull (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return(Top(S)==(MaxEl-1));
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S)++;
    InfoTop(*S)=X;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X=InfoTop(*S);
    Top(*S)--;
}

/* Operasi-operasi lain */
void CopyStack (Stack Sin, Stack *Sout)
/* Membuat salinan Sin */
/* I.S. Sin terdefinisi, Sout sembarang */
/* F.S. Sout berisi salinan Sin yang identik */
{
    Stack Stemp;
    infotype X;
    CreateEmpty(&Stemp);
    CreateEmpty(&Sout);
    while (!IsEmpty(Sin)) {
        Pop(&Sin,&X);
        Push(&Stemp,X);
    }
    while (!IsEmpty(Stemp)) {
        Pop(&Stemp,&X);
        Push(Sout,X);
    }
}

void InverseStack (Stack S) {
    Stack Stemp1;
    Stack Stemp2;
    infotype X;
    CreateEmpty(&Stemp1);
    CreateEmpty(&Stemp2);
    while (!IsEmpty(S)) {
        Pop(&S,&X);
        Push(&Stemp1,X);
    }
    while (!IsEmpty(Stemp1)) {
        Pop(&Stemp1,&X);
        Push(&Stemp2,X);
    }
    while (!IsEmpty(Stemp2)) {
        Pop(&Stemp2,&X);
        Push(&S,X);
    }
}