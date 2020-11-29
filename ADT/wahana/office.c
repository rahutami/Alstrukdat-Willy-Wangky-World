/*office*/
#include "office.h" 
#include "wahana.h"
#include <stdio.h>
#include <stdlib.h>


void Inoffice(){//contoh 
    
    Kata Cdetails, Crep, Cexit;

    //Pembentuk kata Details
    Cdetails.Length = 7;
    Cdetails.TabKata[0] = 'D';
    Cdetails.TabKata[1] = 'e';
    Cdetails.TabKata[2] = 't';
    Cdetails.TabKata[3] = 'a';
    Cdetails.TabKata[4] = 'i';
    Cdetails.TabKata[5] = 'l';
    Cdetails.TabKata[6] = 's';

    //Pembentuk kata Report
    Crep.Length = 6;
    Crep.TabKata[0] = 'R';
    Crep.TabKata[1] = 'e';
    Crep.TabKata[2] = 'p';
    Crep.TabKata[3] = 'o';
    Crep.TabKata[4] = 'r';
    Crep.TabKata[5] = 't';

    //Pembentuk kata Exit
    Cexit.Length = 4;
    Cexit.TabKata[0] = 'E';
    Cexit.TabKata[1] = 'x';
    Cexit.TabKata[2] = 'i';
    Cexit.TabKata[3] = 't';

    printf("\nMasukkan perintah (Details / Report / Exit): \n");
    STARTKATA();
    boolean finish = false;

    while (!finish){
        if (IsKataSamaKata(Cdetails,CKata)){
            MakeTree(); //udah ada di main
            printf("\nDaftar Wahana: \n");
            PrintTree(UpgradeTree);
            details(); finish = true;
        }     
        else if (IsKataSamaKata(Crep,CKata)){
            MakeTree(); //udah ada di main
            printf("\nDaftar Wahana: \n");
            PrintTree(UpgradeTree);
            report();
            finish = true;
        }
        else if (IsKataSamaKata(Cexit, CKata))
            finish = true;
        else
        {
            printf("Input yang dimasukkan salah!\n"); printf("Masukkan kembali input : ");
            STARTKATA();
        }
    }
}

void PrintHistory(Kata Wahana, addressWahanaS T){
    if(IsKataSamaKata(Wahana, NamaWahana(T))){
        PrintKata(NamaWahana(T));
    }
    else if(SearchTree(Wahana, Right(T))){
        PrintKata(NamaWahana(T)); printf("->");
        PrintHistory(Wahana, Right(T));
    }else if(SearchTree(Wahana, Left(T))){
        PrintKata(NamaWahana(T)); printf("->");
        PrintHistory(Wahana, Left(T));
    }
}

void PrintElmtS (addressWahanaS P, TreeWahanaS T){
    
    addressWahanaD D = SearchWahanaD (NamaWahana(P),WahanaBuilt);
    printf("\n----------Details Wahana----------\n");
    printf("Nama : "); PrintKata(NamaWahana(P)); printf("\n");

    printf("Lokasi : "); 
    if (D!=NilList){
        TulisPOINT(PositionWahana(D));//nampilin dari addressD
    } else printf("-");
    printf("\n");
    
    printf("Upgrade(s) : ["); 
    if (Left(P)!= NilList){
        PrintKata(NamaWahana(Left(P))); printf(", ");
    } else printf("");
    if (Right(P)!=NilList){
        PrintKata(NamaWahana(Right(P)));
    } else printf("");
    printf("]\n");

    //PrintKata(NamaWahana(Left(P))); printf(", "); PrintKata(NamaWahana(Right(P))); printf("]\n"); 
    printf("History : "); PrintHistory(NamaWahana(P),P); printf("\n");
    
    printf("Status : ");
    if (D == NilList) printf("-");
    else
        if (StatusWahana(D)){
            printf("berfungsi");
        } else printf("rusak");
    printf("\n\n");
}

void details(){
    printf("\nPilih wahana yang ingin ditampilkan Details-nya: \n");
    STARTKATA();

    addressWahanaS P = SearchAddress (UpgradeTree, CKata);

   // boolean foundD = false;
    while (P == NilList){//P == NilList){
        printf("Input yang dimasukkan salah!\n"); 
        printf("Masukkan kembali input : ");
        STARTKATA(); //PrintKata(CKata);
        
        P = SearchAddress (UpgradeTree, CKata);
    } 
    
    PrintElmtS(P,UpgradeTree);

}

void report()
/* I.S namaWahana dimasukkan user */
/* F.S Menampilkan report dari wahana*/
{
    First(WahanaBuilt) = NilList;
    
    printf("\nPilih wahana yang ingin ditampilkan Report-nya: \n");
    STARTKATA();

    boolean found = SearchTree(CKata, UpgradeTree);
    //printf("oke\n");

    while(!found){
        printf("Input yang dimasukkan salah!\n"); 
        printf("Masukkan kembali input : ");
        STARTKATA(); 
        found = SearchTree(CKata, UpgradeTree);
    }
    
    addressWahanaD P = SearchWahanaD (CKata,WahanaBuilt);
    printf("\n----------Report Wahana----------\n");
    printf("Berapa kali total dinaiki : ");
    if (P!=NilList) printf("%d",TotalFreqWahana(P));
    else printf("-\n");

    printf("Berapa kali dinaiki hari ini : ");
    if (P!=NilList) printf("%d",IncomeWahana(P));
    else printf("-\n");

    printf("Total penghasilan : ");
    if (P!=NilList) printf("%d",DailyFreqWahana(P));
    else printf("-");
    printf("\n\n");
}