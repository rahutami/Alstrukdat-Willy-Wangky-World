#include <stdio.h>
#include "stackt.h"

int main() {
    
    Stack stacktest;
    Stack S;
    aksi buang;
    aksi gajadi;
    CreateEmpty(&stacktest);
    player Pemain;
    CreatePlayer(&Pemain);
    /* 
    aksi aksi1, aksi2, aksi3, aksi5;
    aksi1.durasi = 1;
    aksi3.durasi = 3;
    aksi5.durasi = 5;
    aksi2.durasi = 2;

    Push(&stacktest,aksi1);
    Push(&stacktest,aksi3);
    Push(&stacktest,aksi5);
    printf("Stack awal:\n");
    PrintStack(stacktest);

    Push(&stacktest,aksi2);
    printf("Stack, setelah 2 dipush ke stack:\n");
    PrintStack(stacktest);
    printf("Jumlah durasi semua aksi dalam stack: %d \n", SumDurasiStack(stacktest));
    //S=InverseStack(stacktest);
    //PrintStack(&S);

    Undo(&stacktest,&gajadi);
    printf("Setelah di undo (1):\n");
    PrintStack(stacktest);
    Pop(&stacktest,&gajadi);
    printf("Setelah di undo (2):\n");
    PrintStack(stacktest);

    // Ngosongin stack aja tanpa execute
    mainmain(&stacktest,&buang);
    printf("Stack setelah dikosongin:\n");
    PrintStack(stacktest);
    */
    // MULAI MAIN PHASE
    
    //EXECUTE

    /*  blahblah
    if (sum > waktu) {
        printf("error\n");
    }
    else {
        PrintStack(target);
        Stack stacktereksekusi;
        CreateEmpty(&stacktereksekusi);
        int tereksekusi;
        // Eksekusi : pop satu per satu dari target
        while (!IsEmpty(target))
        {
            Pop(&target,&tereksekusi);
            Push(&stacktereksekusi,tereksekusi);
        }
        printf("\n\nStack tereksekusi: \n\n");
        PrintStack(stacktereksekusi);
        printf("\nStack target:\n\n");
        PrintStack(target);
    }
    */
   
    // EXECUTE
    /* Jika jumlah waktu aksi2 di dalam stack melebihi jumlah waktu yang diizinkan, tampilkan pesan error
    Jika waktu cukup:
    pindahkan ke stack lain dengan
    pop dari stack awal,
    lalu push ke stack target.
    terus, eksekusi perintah dengan pop satu per satu dari stack target
    */
    //ListWahanaD listWahana; // Ini buat nanti insertlast (kalo udah)
    addressWahanaS P;
    //TreeWahanaS T;
    MakeTree();
    PrintTree(UpgradeTree);

    Kata namaWahana;
    printf("Inputan kamu adalah: ");
    STARTKATA(); // Ini masih salah :>
    printf("ok");
    CopyKata(CKata,&namaWahana);
    PrintKata(namaWahana);
    /* Nanti dulu deh 
    // CEK TIME REMAINING (?)
    // CEK UANG DAN RESOURCES
    if (UangCukup(&P,250)) {
        // CEK POINT ->
        // Jika kanan kiri atas bawah ada W, oke bisa. Terus cari Wnya. Kalo gaada, gabisa
        if (Next(X(P)= {
            
        }
        else {
            printf("Tidak dapat melakukan command upgrade, karena tidak ada wahana.")
        }
    }
    else {

    }
    */
    /* CARI */
    addressWahanaS elmtStatisUpgrade = ElmtStatis(SearchWahanaD(namaWahana,WahanaBuilt));
    if (elmtStatisUpgrade != NULL) {
        printf("Ketemu, nama wahana: "); printf("\n");
        PrintKata(NamaWahana(elmtStatisUpgrade));
        printf("Ingin melakukan upgrade apa?\n List: \n");
        if (Left(elmtStatisUpgrade)== NULL && Right(elmtStatisUpgrade)==NULL) { // Kondisi udah mentok gabisa diupgrade
            printf("Tidak dapat diupgrade.");
        }
        else { // bisa diupgrade
            if (Left(elmtStatisUpgrade)!=NULL){
                PrintKata(NamaWahana(Left(elmtStatisUpgrade))); printf("\n");
            } 
            if (Right(elmtStatisUpgrade)!=NULL) {
                PrintKata(NamaWahana(Right(elmtStatisUpgrade))); printf("\n");
            }
            Kata elmtUpgrade;
            printf("Mau upgrade kemana: ");
            STARTKATA();
            CopyKata(CKata,&elmtUpgrade);
            // !!! Kalo salah satunya NULL bisa segmentation fault, biar gak segmentationfault gimana yh kondisinya
            while ((!IsKataSamaKata(elmtUpgrade,NamaWahana(Left(elmtStatisUpgrade)))) && (!IsKataSamaKata(elmtUpgrade,NamaWahana(Right(elmtStatisUpgrade))))) {
                printf("Nama wahana yang Anda tulis salah. Mau upgrade kemana: ");
                STARTKATA();
                CopyKata(CKata,&elmtUpgrade);
            }
            // elmtUpgrade = Left atau elmtUpgrade = Right
            // Melakukan upgrade
            addressWahanaS parent = elmtStatisUpgrade; // Kayaknya mau bikin fungsi parent
            addressWahanaS addrElmtUpgraded;
            if (IsKataSamaKata(NamaWahana(Right(elmtStatisUpgrade)),elmtUpgrade)) {
                addrElmtUpgraded = Right(elmtStatisUpgrade);
            }
            if (IsKataSamaKata(NamaWahana(Left(elmtStatisUpgrade)),elmtUpgrade)) {
                addrElmtUpgraded = Left(elmtStatisUpgrade);
            }        
            //elmtStatisUpgrade = addrElmtUpgraded; // mengganti elemen statisnya
            // Harusnya udah berubah nih
            // INI BUAT NGETES
            printf("Upgraded!\n");
            printf("Nama wahana yang baru   : ");PrintKata(NamaWahana(elmtStatisUpgrade));printf("\n");
            printf("Deskripsi               : ");PrintKata(DescWahana(elmtStatisUpgrade));printf("\n");
            printf("Nama wahana sebelumnya  : ");PrintKata(NamaWahana(parent));printf("\n");
            //printf("Posisinya tetep         : ");TulisPOINT(PositionWahana());
        }


        //  MELAKUKAN UPGRADE
    }
    else {
        PrintKata(namaWahana);
        printf(" tidak ditemukan pada tree. ");
    }

    /* BISA PLIS YG INI 
    addressWahanaS elmtStatisUpgrade = SearchAddress(T,namaWahana);
    if (elmtStatisUpgrade != NULL) {
        printf("Ketemu, nama wahana: "); printf("\n");
        PrintKata(NamaWahana(elmtStatisUpgrade));
        printf("Ingin melakukan upgrade apa?\n List: \n");
        if (Left(elmtStatisUpgrade)== NULL && Right(elmtStatisUpgrade)==NULL) { // Kondisi udah mentok gabisa diupgrade
            printf("Tidak dapat diupgrade.");
        }
        else { // bisa diupgrade
            if (Left(elmtStatisUpgrade)!=NULL){
                PrintKata(NamaWahana(Left(elmtStatisUpgrade))); printf("\n");
            } 
            if (Right(elmtStatisUpgrade)!=NULL) {
                PrintKata(NamaWahana(Right(elmtStatisUpgrade))); printf("\n");
            }
            Kata elmtUpgrade;
            printf("Mau upgrade kemana: ");
            STARTKATA();
            CopyKata(CKata,&elmtUpgrade);
            // !!! Kalo salah satunya NULL bisa segmentation fault, biar gak segmentationfault gimana yh kondisinya
            while ((!IsKataSamaKata(elmtUpgrade,NamaWahana(Left(elmtStatisUpgrade)))) && (!IsKataSamaKata(elmtUpgrade,NamaWahana(Right(elmtStatisUpgrade))))) {
                printf("Nama wahana yang Anda tulis salah. Mau upgrade kemana: ");
                STARTKATA();
                CopyKata(CKata,&elmtUpgrade);
            }
            // elmtUpgrade = Left atau elmtUpgrade = Right
            // Melakukan upgrade
            addressWahanaS parent = elmtStatisUpgrade; // Kayaknya mau bikin fungsi parent
            addressWahanaS addrElmtUpgraded = SearchAddress(T,elmtUpgrade);
            elmtStatisUpgrade = addrElmtUpgraded; // mengganti elemen statisnya
            // Harusnya udah berubah nih
            // INI BUAT NGETES
            printf("Upgraded!\n");
            printf("Nama wahana yang baru   : ");PrintKata(NamaWahana(elmtStatisUpgrade));printf("\n");
            printf("Deskripsi               : ");PrintKata(DescWahana(elmtStatisUpgrade));printf("\n");
            printf("Nama wahana sebelumnya  : ");PrintKata(NamaWahana(parent));printf("\n");
            //printf("Posisinya tetep         : ");TulisPOINT(PositionWahana());
        }


        //  MELAKUKAN UPGRADE
    }
    else {
        PrintKata(namaWahana);
        printf(" tidak ditemukan pada tree. ");
    }


    */


    /* WOI KENAPA GAK BISA AAAAAAAAKkk
    printf("\n");
    addressWahanaS elmtStatisUpgrade = SearchAddress(T,namaWahana);
    if (elmtStatisUpgrade != NULL) { // Wahana yang dicari ada
        printf("Ketemu, nama wahana: "); printf("\n");
        PrintKata(NamaWahana(elmtStatisUpgrade));
        printf("Ingin melakukan upgrade apa?\n List: \n");
        if (Left(elmtStatisUpgrade)== NULL && Right(elmtStatisUpgrade)==NULL) { // Kondisi udah mentok gabisa diupgrade
            printf("Tidak dapat diupgrade.");
        }
        else { // bisa diupgrade
         
            Kata elmtUpgrade;
            if (Left(elmtStatisUpgrade)!=NULL && Right(elmtStatisUpgrade)==NULL){ // Cuma bisa upgrade ke left
                PrintKata(NamaWahana(Left(elmtStatisUpgrade))); printf("\n");
                printf("Mau upgrade kemana: ");
                STARTKATA();
                CopyKata(CKata,&elmtUpgrade);
                while ((!IsKataSamaKata(elmtUpgrade,NamaWahana(Left(elmtStatisUpgrade))))) {
                    printf("Nama wahana yang Anda tulis salah. Mau upgrade kemana: ");
                    STARTKATA();
                    CopyKata(CKata,&elmtUpgrade);
                }
            } 
            else if (Left(elmtStatisUpgrade)==NULL && Right(elmtStatisUpgrade)!=NULL){ // Cuma bisa upgrade ke right
                PrintKata(NamaWahana(Right(elmtStatisUpgrade))); printf("\n");
                printf("Mau upgrade kemana: ");
                STARTKATA();
                CopyKata(CKata,&elmtUpgrade);
                while ((!IsKataSamaKata(elmtUpgrade,NamaWahana(Right(elmtStatisUpgrade))))) {
                    printf("Nama wahana yang Anda tulis salah. Mau upgrade kemana: ");
                    STARTKATA();
                    CopyKata(CKata,&elmtUpgrade);
                }
            }
            else { // Bisa diupgrade ke left ataupun right

                PrintKata(NamaWahana(Left(elmtStatisUpgrade))); printf("\n");
                PrintKata(NamaWahana(Right(elmtStatisUpgrade))); printf("\n");
                printf("Mau upgrade kemana: ");
                STARTKATA();
                CopyKata(CKata,&elmtUpgrade);
                while ((!IsKataSamaKata(elmtUpgrade,NamaWahana(Left(elmtStatisUpgrade)))) && (!IsKataSamaKata(elmtUpgrade,NamaWahana(Right(elmtStatisUpgrade))))) {
                    printf("Nama wahana yang Anda tulis salah. Mau upgrade kemana: ");
                    STARTKATA();
                    CopyKata(CKata,&elmtUpgrade);
                }
            }

          
            // !!! Kalo salah satunya NULL bisa segmentation fault, biar gak segmentationfault gimana yh kondisinya GUE MENTOK

            // elmtUpgrade = Left atau elmtUpgrade = Right
            // Melakukan upgrade
            addressWahanaS parent = elmtStatisUpgrade; // Kayaknya mau bikin fungsi parent
            addressWahanaS addrElmtUpgraded = SearchAddress(T,elmtUpgrade);
            elmtStatisUpgrade = addrElmtUpgraded; // mengganti elemen statisnya
            // Harusnya udah berubah nih
            // INI BUAT NGETES
            printf("Upgraded!\n");
            printf("Nama wahana yang baru   : ");PrintKata(NamaWahana(elmtStatisUpgrade));printf("\n");
            printf("Deskripsi               : ");PrintKata(DescWahana(elmtStatisUpgrade));printf("\n");
            printf("Nama wahana sebelumnya  : ");PrintKata(NamaWahana(parent));printf("\n");
            //printf("Posisinya tetep         : ");TulisPOINT(PositionWahana());
        }
    }
    else { // ga ketemu
        PrintKata(namaWahana);
        printf(" tidak ditemukan pada tree. ");
    }
    */    

/* 


    */

    return 0;
}
// COMMAND
// gcc -o tes driver_stackt.c stackt.c -lm

// gcc stackt.c driver_stackt.c ../mesinkata/mesinkata.c ../mesinkar/mesinkar.c ../wahana/wahana.c ../player/player.c ../jam/jam.c ../point/point.c -o tes