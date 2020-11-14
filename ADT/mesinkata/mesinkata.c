/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

//  NIM         : 13519192
//  NAMA        : Gayuh Tri Rahutami
//  Tanggal     : 1 Oktober 2020
//  Topik       : Mesin Karakter dan Mesin Kata
//  Deskripsi   : Implementasi Mesin Kata Model Akuisisi Versi I

#include "mesinkata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while ((CC == BLANK) && (CC != MARK)){
        ADV();
    }
}

void STARTKATA()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlank();

    if (CC == MARK){
        EndKata = true;
    }
    else{
        EndKata = false;
        SalinKata();
    }
}
void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();

    if (CC == MARK){
        EndKata = true;
    }else{
        SalinKata();
        IgnoreBlank();
    } 
}
void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i;
    i = 0;
    while ((i < NMax) && (CC != MARK) && (CC != EOL))
    {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i;
}

boolean IsKataSama (const char *command){
    boolean ans = true;
    int i = 0;

    while(command[i] != '\0' && ans){ //ngecek panjang command sekaligus ngecompare command sama CKata
        if(command[i] != CKata.TabKata[i]) ans = false;
        i++;
    }

    if(i != CKata.Length) ans = false;

    return ans;
}

void CopyKata(Kata K1, Kata * K2){
    K2->Length = K1.Length;
    for (int i = 0; i<K1.Length; i++){
        (K2->TabKata)[i] = K1.TabKata[i];
    }
}