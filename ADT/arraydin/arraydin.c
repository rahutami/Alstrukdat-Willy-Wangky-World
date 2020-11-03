#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "arraydin.h"

/* ********** SELEKTOR ********** */
// #define Neff(T) (T).Neff
// #define TI(T) (T).TI
// #define Elmt(T, i) (T).TI[(i)]
// #define MaxEl(T) (T).MaxEl

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
{

    // Kamus

    // ALGORITMA
    MaxEl(*T) = maxel;
    Neff(*T) = 0;
    TI(*T) = (int *) malloc(maxel * sizeof(ElType));
}

void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    MaxEl(*T) = 0;
    Neff(*T) = 0;
    free(TI(*T));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    return Neff(T);
}

int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return MaxEl(T);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return Neff(T)-1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return i >= 0 && i < MaxEl(T);
}

boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return i >= GetFirstIdx(T) && i <= GetLastIdx(T);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return Neff(T) == 0;
}

/* *** Test tabel penuh *** */
boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return Neff(T) == MaxEl(T);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    // Kamus
    int N;
    int i;

    // Algoritma
    do{
        scanf("%d", &N);
    } while (N<0 || N>MaxEl(*T));

    Neff(*T) = N;

    for (i=IdxMin; i<IdxMin+N; i++){
        scanf("%d", &Elmt(*T,i));
    }

}

void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    // Kamus Lokal
    int i;
    // Algoritma
    printf("[");
    if(!IsEmpty(T)){
        for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++){
            printf("%d",Elmt(T,i));
            if(i!=GetLastIdx(T)) printf(",");
        }
    }

    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    // Kamus Lokal
    TabInt TSum;
    int i;

    // Algoritma
    MakeEmpty(&TSum, MaxEl(T1));
    Neff(TSum) = Neff(T1);

    if(plus){
        if (NbElmt(T1)>NbElmt(T2)){
            for (i=GetFirstIdx(T1); i<=GetLastIdx(T1); i++){
                if(i<Neff(T2)) Elmt(TSum, i) = Elmt(T1, i) + Elmt(T2, i);
                else Elmt(TSum,i) = Elmt(T1,i);
            }
        } else {
            for (i=GetFirstIdx(T2); i<=GetLastIdx(T2); i++){
                if(i<Neff(T1)) Elmt(TSum, i) = Elmt(T1, i) + Elmt(T2, i);
                else Elmt(TSum,i) = Elmt(T2,i);
            }
        }
    } else {
        if (NbElmt(T1)>NbElmt(T2)){
            for (i=GetFirstIdx(T1); i<=GetLastIdx(T1); i++){
                if(i<Neff(T2)) Elmt(TSum, i) = Elmt(T1, i) - Elmt(T2, i);
                else Elmt(TSum,i) = Elmt(T1,i);
            }
        } else {
            for (i=GetFirstIdx(T2); i<=GetLastIdx(T2); i++){
                if(i<Neff(T1)) Elmt(TSum, i) = Elmt(T1, i) - Elmt(T2, i);
                else Elmt(TSum,i) = Elmt(T2,i);
            }
        }
    }
    return TSum;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{
    // Kamus Lokal
    boolean ans;
    int i;

    // Algoritma
    if (NbElmt(T1) != NbElmt(T2)) return false;
    
    // else
    ans = true;
    i = GetFirstIdx(T1);

    while (i<=GetLastIdx(T1) && ans){
        if(Elmt(T1,i) != Elmt(T2,i)) ans=false;
        i++;
    }
    
    return ans;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
    // Kamus Lokal
    int ans;
    int i;

    // Algoritma
    if(NbElmt(T) == 0) return IdxUndef;

    // else
    ans = IdxUndef;
    i = GetFirstIdx(T)-1;

    do{
        i++;
        if(Elmt(T,i) == X){
            ans = i;
        }
    } while (i<=GetLastIdx(T) && Elmt(T,i) != X);
    
    return ans;
}

boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
    // Kamus Lokal
    boolean ans;
    int i;

    // Algoritma
    ans=false;
    i=GetFirstIdx(T)-1;

    do{
        i++;
        if(Elmt(T,i) == X){
            ans = true;
        }
    } while (i<=GetLastIdx(T) && Elmt(T,i) != X);

    return ans;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    // Kamus Lokal
    int i = GetFirstIdx(T);

    // Algoritma
    *Max = Elmt(T,i);
    *Min = Elmt(T,i);

    for (i = GetFirstIdx(T); i<=GetLastIdx(T); i++){
        if(Elmt(T,i) > *Max) *Max = Elmt(T,i);
        if(Elmt(T,i) < *Min) *Min = Elmt(T,i);
    }

}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{
    // Kamus
    int i;

    // Algoritma
    MakeEmpty(Tout, MaxEl(Tin));
    for (i=0; i< Neff(Tin); i++){
        Elmt(*Tout, i) = Elmt(Tin, i);
        Neff(*Tout)++;
    }
}

ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
    // Kamus Lokal
    ElType sum = 0;
    int i;
    
    // Algoritma
    if(!IsEmpty(T)){
        for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++){
            sum+=Elmt(T,i);
        }
    }
    return sum;
}

int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
    // Kamus Lokal
    int count = 0;
    int i;

    // Algoritma
    if(IsEmpty(T)) return count;

    // else
    for (i = GetFirstIdx(T); i<=GetLastIdx(T); i++){
        if(Elmt(T,i)==X) count++;
    }

    return count;
}

boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{   
    // Kamus Lokal
    boolean ans;
    int i;

    // Algoritma
    ans = true;
    i=GetFirstIdx(T);
    while(ans && i<=GetLastIdx(T)){
        if(Elmt(T,i)%2==1) ans = false;
        i++;
    }
    return ans;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
    // Kamus Lokal
    int i;
    int j;
    int max, min;

    // Algoritma
    if(NbElmt(*T) != 0){
        if(asc){
                for (i=GetFirstIdx(*T)+1; i<=GetLastIdx(*T); i++){
                    j = i-1;
                    min = Elmt(*T,i);
                    
                    while(j>=0 && Elmt(*T,j)>min){
                        Elmt(*T,j+1) = Elmt(*T, j);
                        j--;
                    }
                    Elmt(*T, j+1) = min;
                }
            } else {
                for (i=GetFirstIdx(*T)+1; i<=GetLastIdx(*T); i++){
                    j = i-1;
                    max = Elmt(*T,i);
                    
                    while(j>=0 && Elmt(*T,j)<max){
                        Elmt(*T,j+1) = Elmt(*T, j);
                        j--;
                    }
                    Elmt(*T, j+1) = max;
                }
        }
    }
    
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

{
    // Algoritma
    if(IsEmpty(*T)) Elmt(*T, IdxMin) = X;
    else{
        Elmt(*T, Neff(*T)) = X;
    }

    Neff(*T)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    // Algoritma
    *X = Elmt(*T, GetLastIdx(*T));
    Neff(*T)--;

}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
    // Kamus
    int i;

    MaxEl(*T) += num;
    int * temp = (int *) malloc(MaxEl(*T) * sizeof(int));
    for (i=IdxMin; i<Neff(*T); i++){
        temp[i] = Elmt(*T,i);
    }

    free(TI(*T));

    TI(*T) = (int *) malloc(MaxEl(*T) * sizeof(int)); 
    
    for (i=IdxMin; i<Neff(*T); i++){
        Elmt(*T,i) = temp[i];
    }

    free(temp);
}

void ShrinkTab(TabInt *T, int num)
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
{
    // Kamus
    int i;

    MaxEl(*T) -= num;
    int * temp = (int *) malloc(MaxEl(*T) * sizeof(int));
    for (i=IdxMin; i<MaxEl(*T); i++){
        temp[i] = Elmt(*T,i);
    }

    free(TI(*T));
    
    TI(*T) = (int *) malloc(MaxEl(*T) * sizeof(int)); 
    
    if (Neff(*T) > MaxElement(*T)) Neff(*T) = MaxElement(*T);
    
    for (i=IdxMin; i<Neff(*T); i++){
        Elmt(*T,i) = temp[i];
    }

    free(temp);
}

void CompactTab(TabInt *T)
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
{
    ShrinkTab(T, MaxEl(*T) - Neff(*T));
}