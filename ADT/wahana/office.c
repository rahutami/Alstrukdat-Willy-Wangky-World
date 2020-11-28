/*office*/
#include "office.h" 
#include "wahana.h"
#include <stdio.h>
#include <stdlib.h>

boolean EndKata;
Kata CKata;
char CC;
boolean EOP;


void Inoffice(POINT P){
    POINT Office = MakePOINT(1,1); //contoh 
    
    Kata Coffice, Cdetails, Crep, Cexit;

    //Pembentuk kata office
    Coffice.Length = 6;
    Coffice.TabKata[0] = 'o';
    Coffice.TabKata[1] = 'f';
    Coffice.TabKata[2] = 'f';
    Coffice.TabKata[3] = 'i';
    Coffice.TabKata[4] = 'c';
    Coffice.TabKata[5] = 'e';

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

    STARTKATA();
    do
    {
        if (IsKataSamaKata(Cdetails, CKata)){
            details();
        }else if (IsKataSamaKata(Crep, CKata)){
            ListWahanaD L1;
            Report(CKata,L1);
        }else if (!IsKataSamaKata(Cexit,CKata)){
            printf("Input yang dimasukkan salah!");
            STARTKATA();
        }
    } while (!IsKataSamaKata(Cexit,CKata));
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
    
    ListWahanaD L;
    addressWahanaD D = SearchWahanaD (NamaWahana(P),L);

    printf("Nama :"); PrintKata(NamaWahana(P)); printf("\n");

    printf("Lokasi : "); TulisPOINT(PositionWahana(D)); printf("\n");//nampilin dari addressD
    
    printf("Upgrade(s) : ["); 
    if (Left(P)!= NilList){
        PrintKata(NamaWahana(Left(P))); printf(", ");
    } else printf("");
    if (Right(P)!=NilList){
        PrintKata(NamaWahana(Left(P)));
    } else printf("");
    printf("]");

    //PrintKata(NamaWahana(Left(P))); printf(", "); PrintKata(NamaWahana(Right(P))); printf("]\n"); 
    printf("History : "); PrintHistory(NamaWahana(P),P); printf("\n");
    
    printf("Status : ");
    if (StatusWahana(D)){
        printf("berfungsi");
    } else printf("rusak");

}

void details(){

    First(WahanaBuilt) = NilList;

    MakeTree(); //udah ada di main
    printf("Daftar Wahana: \n");
    PrintTree(UpgradeTree);
    
    printf("Pilih wahana yang ingin ditampilkan Details-nya: \n");
    STARTKATA();
    addressWahanaS P = SearchAddress (UpgradeTree, CKata); printf("okeee\n");
    PrintElmtS(P,UpgradeTree);
}

