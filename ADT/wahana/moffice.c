#include "office.h" 
#include <stdio.h>
#include <stdlib.h>

int main(){
    /*POINT P = MakePOINT(1,3);
    POINT X = MakePOINT(1,3);
    if (IsEqPOINT(P,X)) printf ("oke");*/
    
    Kata Coffice;
    //Pembentuk kata office
    Coffice.Length = 6;
    Coffice.TabKata[0] = 'o';
    Coffice.TabKata[1] = 'f';
    Coffice.TabKata[2] = 'f';
    Coffice.TabKata[3] = 'i';
    Coffice.TabKata[4] = 'c';
    Coffice.TabKata[5] = 'e';
    
    POINT Office = MakePOINT(1,1); //point office
    POINT P = MakePOINT(1,1); //point pemain

    if (IsEqPOINT(P,Office)){
    printf("Masukkan Perintah (Masukkan 'office' untuk mengakses office): \n");
    STARTKATA();
    
    boolean masuk = false;
    
    while(!masuk){
        if (IsKataSamaKata(Coffice, CKata)){
            Inoffice(P); masuk = true;
        }
        else{
            printf("Input yang dimasukkan salah!\n"); printf("Masukkan kembali input : ");
            STARTKATA();
        }
    }
}
    return 0;
}
//gcc moffice.c office.c ../arraydin/arraydin.c ../player/player.c ../matriks/matriks.c ../peta/peta.c ../wahana/wahana.c ../mesinkar/mesinkar.c ../jam/jam.c ../mesinkata/mesinkata.c ../point/point.c -o moffice
//gcc moffice.c office.c ../point/point.c ../mesinkar/mesinkar.c ../mesinkata/mesinkata.c ../wahana/wahana.c -o moffice