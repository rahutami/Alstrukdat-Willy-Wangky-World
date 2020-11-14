// /* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

// #ifndef MATRIKS_H
// #define MATRIKS_H

#include <stdio.h>
#include "matriks.h"
#include <string.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    // ALGORITMA
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}
/* *** Selektor *** */
// #define NBrsEff(M) (M).NBrsEff
// #define NKolEff(M) (M).NKolEff
// #define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    // ALGORITMA
    return (i>=BrsMin && i<=BrsMax && j>=KolMin && j<=KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    // ALGORITMA
    return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    // ALGORITMA
    return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    // ALGORITMA
    return BrsMin + NBrsEff(M) - 1;
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    // ALGORITMA
    return KolMin + NKolEff(M) - 1;
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    // ALGORITMA
    return(i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M) && j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    // ALGORITMA
    return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    // KAMUS
    int i,j;

    // ALGORITMA
    NBrsEff(*MHsl) = NBrsEff(MIn);
    NKolEff(*MHsl) = NKolEff(MIn);

    for (i=GetFirstIdxBrs(MIn); i<=GetLastIdxBrs(MIn); i++){
        for (j=GetFirstIdxKol(MIn); j<=GetLastIdxKol(MIn); j++){
            Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
        }
    }
}
/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    // KAMUS
    int i, j;

    // ALGORITMA
    MakeMATRIKS(NB, NK, M);
    
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
        for (j = GetFirstIdxKol(*M); j <=GetLastIdxKol(*M); j++){
            scanf("%d", &Elmt(*M, i, j));
        }
    }
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    // KAMUS
    int i, j;
    
    // ALGORITMA
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for (j = GetFirstIdxKol(M); j <=GetLastIdxKol(M); j++){
            printf("%d", Elmt(M, i, j));
            if(j != GetLastIdxKol(M)) printf(" ");
        }
        if(i != GetLastIdxBrs(M)) printf("\n");
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
{
    // KAMUS
    int i, j;
    
    // ALGORITMA
    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
        for (j = GetFirstIdxKol(M1); j <=GetLastIdxKol(M1); j++){
            Elmt(M1, i, j) += Elmt(M2, i, j);
        }
    }

    return M1;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
{
    // KAMUS
    int i, j;
    
    // ALGORITMA
    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
        for (j = GetFirstIdxKol(M1); j <=GetLastIdxKol(M1); j++){
            Elmt(M1, i, j) -= Elmt(M2, i, j);
        }
    }

    return M1;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    // KAMUS
    MATRIKS MResult;
    int i,j, k;

    // ALGORITMA
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &MResult);
    for (i=GetFirstIdxBrs(MResult); i<=GetLastIdxBrs(MResult); i++){
        for (j=GetFirstIdxKol(MResult); j<=GetLastIdxKol(MResult); j++){
            Elmt(MResult, i, j) = 0;
            for (k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++)
            {
                Elmt(MResult, i, j) += Elmt(M1, i, k) * Elmt(M2, k, j);
            }
            
        }
    }
    
    return MResult;
}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    // KAMUS
    int i, j;
    
    // ALGORITMA
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for (j = GetFirstIdxKol(M); j <=GetLastIdxKol(M); j++){
            Elmt(M, i, j) *= X;
        }
    }

    return M;
}
void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
    // KAMUS
    int i, j;
    
    // ALGORITMA
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
        for (j = GetFirstIdxKol(*M); j <=GetLastIdxKol(*M); j++){
            Elmt(*M, i, j) *= K;
        }
    }
}
/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    // ALGORITMA
    return NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2);
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    // ALGORITMA
    return NKolEff(M) * NBrsEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{   
    // ALGORITMA
    return NBrsEff(M) == NKolEff(M);
}
boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
    // KAMUS
    int i,j;
    boolean ans;

    // ALGORITMA
    if(!IsBujurSangkar(M)) return false;
    
    ans = true;

    i = GetFirstIdxBrs(M);

    while(ans && i<=GetLastIdxBrs(M)){
        j = GetFirstIdxKol(M);
        while (ans && j<=GetLastIdxKol(M))
        {
            if(Elmt(M, i, j) != Elmt(M, j, i)) ans = false;
            j++;
        }
        i++;
    }
    
    return ans;
}
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
{
    // KAMUS
    int i,j;
    boolean ans;

    // ALGORITMA
    if(!IsBujurSangkar(M)) return false;
    
    ans = true;

    i = GetFirstIdxBrs(M);

    while(ans && i<=GetLastIdxBrs(M)){
        j = GetFirstIdxKol(M);
        while (ans && j<=GetLastIdxKol(M))
        {
            if (i==j && Elmt(M, i, j) != 1) ans = false;
            else if (i!=j && Elmt(M,i,j) != 0) ans = false; 
            j++;
        }
        i++;
    }
    
    return ans;
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
{
        // KAMUS
    int i,j;
    int nonZeroEl;
    int maxNonZeroEl;

    // ALGORITMA
    if(!IsBujurSangkar(M)) return false;
    
    nonZeroEl = 0;
    maxNonZeroEl = NBElmt(M)/20;
    i = GetFirstIdxBrs(M);

    while(nonZeroEl <= maxNonZeroEl && i<=GetLastIdxBrs(M)){
        j = GetFirstIdxKol(M);
        while (nonZeroEl <= maxNonZeroEl && j<GetLastIdxKol(M))
        {
            if(Elmt(M,i,j) != 0) nonZeroEl++;
            j++;
        }
        i++;
    }
    
    return nonZeroEl <= maxNonZeroEl;
}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    // ALGORITMA
    return KaliKons(M, -1);
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
    // KAMUS
    float sum;
    float posOrNeg;
    int n;
    int countKol;
    int countBar;


    if(NBrsEff(M) == 2) sum = Elmt(M,0,0) * Elmt(M,1,1) - Elmt(M,0,1) * Elmt(M,1,0);

    else{
        n = NKolEff(M);
        sum = 0;
        for (int i=0; i<n; i++){
            MATRIKS tempM;
            MakeMATRIKS(n-1, n-1, &tempM);
            countBar = 0;

            for (int j = 1; j<n; j++){
                countKol = 0;
                for (int k = 0; k<n; k++){
                    if(k!=i){
                        Elmt(tempM, countBar, countKol) = Elmt(M, j, k);
                        countKol++;
                    }
                }
                countBar++;
            }
            if (i%2==0) posOrNeg = 1;
            else posOrNeg = -1;
            sum += posOrNeg * Elmt(M, 0, i) * Determinan(tempM);
        }
    }
    return  sum;
}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    // ALGORITMA
    PKaliKons(M, -1);

}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    // KAMUS
    ElType temp;
    int i,j;

    // ALGORITMA
    for (i=GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M); i++){
        for (j = GetFirstIdxKol(*M); j<=GetLastIdxKol(*M); j++){
            if(j>i){
                temp = Elmt(*M,i,j);
                Elmt(*M,i,j) = Elmt(*M,j,i);
                Elmt(*M,j,i) = temp;
            }
        }
    }
}

/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
    // KAMUS
    int sum=0;
    int j;
    // ALGORITMA
    for (j=0; j<NKolEff(M); j++){
        sum += Elmt(M, i, j);
    }

    return sum*1.0/NKolEff(M);
}
float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
    // KAMUS
    int sum=0;
    int i;
    // ALGORITMA
    for (i=0; i<NBrsEff(M); i++){
        sum += Elmt(M, i, j);
    }

    return sum*1.0/NBrsEff(M);
}
void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
    // KAMUS
    int j;
    // ALGORITMA
    *max = Elmt(M, i, 0); *min = Elmt(M, i, 0);

    for (j=0; j<NKolEff(M); j++){
        if(Elmt(M,i,j) > *max) *max = Elmt(M,i,j);
        if(Elmt(M,i,j) < *min) *min = Elmt(M,i,j);
    }
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
    // KAMUS
    int i;
    // ALGORITMA
    *max = Elmt(M, 0, j); *min = Elmt(M, 0, j);

    for (i=0; i<NBrsEff(M); i++){
        if(Elmt(M,i,j) > *max) *max = Elmt(M,i,j);
        if(Elmt(M,i,j) < *min) *min = Elmt(M,i,j);
    }
}
int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
    // KAMUS
    int j;
    int countX = 0;
    // ALGORITMA

    for (j=0; j<NKolEff(M); j++){
        if (Elmt(M,i,j) == X) countX++;
    }

    return countX;
}
int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
        // KAMUS
    int i;
    int countX = 0;
    // ALGORITMA

    for (i=0; i<NBrsEff(M); i++){
        if (Elmt(M,i,j) == X) countX++;
    }

    return countX;
}