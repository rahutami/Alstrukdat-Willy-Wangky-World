#include <stdio.h>
#include "stackt.h"

void SebelahWahana(){
    int X = X(Player);
    int Y = Y(Player);
    POINT P;
    addressGraph CPeta = FirstGraph(GraphPeta);
    while(ID(CPeta) != MapNum(Player)) CPeta = NextGraph(CPeta);

    if(ElmtMatriks(Peta(CPeta), X-1, Y) == 'W' || ElmtMatriks(Peta(CPeta), X+1, Y) == 'W' || ElmtMatriks(Peta(CPeta), X, Y-1) == 'W' || ElmtMatriks(Peta(CPeta), X, Y+1) == 'W'){
        printf("List wahana yang bisa diupgrade:\n");
    } else {
        printf("Kamu tidak berada di sekitar wahana\n");
    }

    if(ElmtMatriks(Peta(CPeta), X-1, Y) == 'W'){
        P = MakePOINT(X-1, Y);
        PrintKata(NamaWahana(ElmtStatis(SearchWahanaDP(P, WahanaBuilt)))); printf("\n");
    }

    if(ElmtMatriks(Peta(CPeta), X+1, Y) == 'W'){
        P = MakePOINT(X-1, Y);
        PrintKata(NamaWahana(ElmtStatis(SearchWahanaDP(P, WahanaBuilt)))); printf("\n");
    }

    if(ElmtMatriks(Peta(CPeta), X, Y-1) == 'W'){
        P = MakePOINT(X-1, Y);
        PrintKata(NamaWahana(ElmtStatis(SearchWahanaDP(P, WahanaBuilt)))); printf("\n");
    }

    if(ElmtMatriks(Peta(CPeta), X, Y+1) == 'W'){
        P = MakePOINT(X-1, Y);
        PrintKata(NamaWahana(ElmtStatis(SearchWahanaDP(P, WahanaBuilt)))); printf("\n");
    }
}

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
    
    PrintInfoStack(stacktest);
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
    
    POINT Post = MakePOINT(1,1);
    buildWahana(Post, &WahanaBuilt);
    printf("Mau nge-upgrade wahana apa?");
    STARTKATA(); // Ini masih salah :>
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
    // Masih bingung soal lokasi
    /* 
    player *p1;
    addressGraph CPeta = FirstGraph(GraphPeta);
    int x = X(*p1), y = Y(*p1);
    while(ID(CPeta) != MapNum(*p1)){
        CPeta = NextGraph(CPeta);
    }
    ADVKATA();
    if(Elmt(Peta(CPeta), x + 1, y) == 'W' || Elmt(Peta(CPeta), x, y+1) == 'W' || Elmt(Peta(CPeta), x - 1, y) == 'W' || Elmt(Peta(CPeta), x, y - 1) == 'W'){
    {
            
    }
    */ 
    /* CARI */

    printf("\n");
    //addressWahanaS elmtStatisUpgrade = SearchAddress(UpgradeTree,namaWahana);
    addressWahanaD elmtStatisUpgradeD = SearchWahanaD(namaWahana,WahanaBuilt);
    addressWahanaS elmtStatisUpgrade;
    if (elmtStatisUpgradeD != NULL) {
        elmtStatisUpgrade = ElmtStatis(elmtStatisUpgradeD);
        printf("Ketemu, nama wahana: "); printf("\n");
        PrintKata(NamaWahana(elmtStatisUpgrade)); printf("\n");
        printf("Ingin melakukan upgrade apa?\n");
        addressWahanaS addrElmtUpgraded;
        if (Left(elmtStatisUpgrade)== NULL && Right(elmtStatisUpgrade)==NULL) { // Kondisi udah mentok gabisa diupgrade
            printf("Tidak dapat diupgrade.");
        }
        else { // bisa diupgrade
            Kata elmtUpgrade;
            printf("List:\n");
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
                addrElmtUpgraded = Left(elmtStatisUpgrade);
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
                addrElmtUpgraded = Right(elmtStatisUpgrade);
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
                if (IsKataSamaKata(elmtUpgrade,NamaWahana(Left(elmtStatisUpgrade)))) {
                    addrElmtUpgraded = Left(elmtStatisUpgrade);
                }
                if (IsKataSamaKata(elmtUpgrade,NamaWahana(Right(elmtStatisUpgrade)))) {
                    addrElmtUpgraded = Right(elmtStatisUpgrade);
                }
            }
            addressWahanaS parent = elmtStatisUpgrade; // Wahana sebelumnya
            addressWahanaS addrElmtUpgraded = ElmtStatis(SearchWahanaD(elmtUpgrade,WahanaBuilt));
            printf("nanan");
            elmtStatisUpgrade = addrElmtUpgraded; // mengganti elemen statisnya
            // INI BUAT NGETEST
            printf("Upgraded!\n");
            printf("Nama wahana yang baru   : ");PrintKata(NamaWahana(addrElmtUpgraded));printf("\n");
            printf("Deskripsi               : ");PrintKata(DescWahana(addrElmtUpgraded));printf("\n");
            printf("Nama wahana sebelumnya  : ");PrintKata(NamaWahana(parent));printf("\n");
    }
    }
    else { // Gaketemu
        PrintKata(namaWahana);
        printf(" tidak ditemukan pada daftar wahana yang sudah dibangun.\n");
    }
    

     
    
/* 


    */

    return 0;
}
// COMMAND
// gcc -o tes driver_stackt.c stackt.c -lm

// gcc ../maplist/maplist.c stackt.c driver_stackt.c ../mesinkata/mesinkata.c ../mesinkar/mesinkar.c ../wahana/wahana.c ../player/player.c ../jam/jam.c ../point/point.c ../arraydinmap/arraydinmap.c -o yubisayu