/* File: mesinkatafile.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include "mesinkatafile.h"

boolean EndKataFile;
Kata CKataFile;

void IgnoreBlankFile()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while ((CC == BLANK) && (CC != MARK)){
        ADVFILE();
    }
}

void STARTKATAFile()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    STARTFILE();
    IgnoreBlankFile();

    if (CC == MARK){
        EndKataFile = true;
    }
    else{
        EndKataFile = false;
        SalinKataFile();
    }
}
void ADVKATAFile()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlankFile();

    if (CC == MARK){
        EndKata = true;
    }else{
        SalinKataFile();
        IgnoreBlankFile();
    } 
}
void SalinKataFile()
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
        CKataFile.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKataFile.Length = i;
}

boolean IsKataSamaFile (const char *command){
    /* Membandingkan CKata dengan string

    */
    boolean ans = true;
    int i = 0;

    while(command[i] != '\0' && ans){ //ngecek panjang command sekaligus ngecompare command sama CKata
        if(command[i] != CKataFile.TabKata[i]) ans = false;
        i++;
    }

    if(i != CKataFile.Length) ans = false;

    return ans;
}

boolean IsKataSamaKataFile (Kata K1, Kata K2){
    /* Membandingkan kata dengan kata

    */
    boolean ans = true;
    int i = 0;

    if(K1.Length == K2.Length){
        while(ans && i < K1.Length){
            if(K1.TabKata[i] != K2.TabKata[i]) ans = false;
            i++;
        }
    } else {
        ans = false;
    }

    return ans;
}

void CopyKataFile(Kata K1, Kata * K2){
    K2->Length = K1.Length;
    for (int i = 0; i<K1.Length; i++){
        (K2->TabKata)[i] = K1.TabKata[i];
    }
}
