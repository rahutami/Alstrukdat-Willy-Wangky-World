#include <stdio.h>
#include "menu.h"
#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"
#include "../matriks/matriks.h"
#include "../jam/jam.h"
#include "../peta/peta.h"

MATRIKS Peta1, Peta2, Peta3, Peta4;

void MainMenu(){
    printf("====================================================================\n\n");
    printf("                Welcome to Willy Wangky's World!\n");
    printf("Here, you can make your own amusement park and do so many fun stuff!\n\n");
    printf("====================================================================\n");
    printf("Choose menu: \n1. New Game (new)\n2. Load Game (load)\n3. Exit (exit)\n");
    printf("===================================\n");
    STARTKATA();

    printf("===================================\n");
}

void MenuJalan(player *p1){
    if (IsKataSama("w")){
        w(p1, Peta1);
    }else if (IsKataSama("a")){
        a(p1, Peta1);
    }else if (IsKataSama("s")){
        s(p1, Peta1);
    }else if (IsKataSama("d")){
        d(p1, Peta1);
    }
}

void ListCommand(){
    printf("==========================================================\n");
    printf("New Game: \"new\"\n");
    printf("Load Game: \"load\"\n");
    printf("Berjalan ke atas: \"w\"\n");
    printf("Berjalan ke kiri: \"a\"\n");
    printf("Berjalan ke bawah: \"s\"\n");
    printf("Berjalan ke kanan: \"d\"\n");
    printf("Pergi ke Main Phase tanpa execute (stack): \"main\"\n");
    printf("Pergi ke Main Phase dengan execute (stack): \"execute\"\n");
    printf("Keluar Game: \"exit\"\n");
    printf("==========================================================\n");
}

void Preparation(player *p1){
    do{
        if (!IsKataSama("command")){
            printf("===================================\n");
            printf("        Preparation Phase\n");
            printf("             Day %d\n", Day(*p1));
            printf("===================================\n");
            TulisPETA(Peta1, *p1);
            printf("===================================\n");
            printf("Legend:\n");
            printf("A = Antrian\n");
            printf("P = Player\n");
            printf("W = Wahana\n");
            printf("O = Office\n");
            printf("^, >, v, < = Gerbang\n");
            printf("===================================\n");
            TulisPlayer(*p1);
            printf("Current Time: "); TulisJAM(CJam(*p1)); printf("\n");
            printf("Opening Time: "); TulisJAM(JamBuka); printf("\n");
            printf("Time Remaining: "); TulisTimeRemaining(Durasi(CJam(*p1), JamBuka)); printf("\n");
            // Total aksi yang akan dilakukan:
            // Total waktu yang dibutuhkan:
            // Total uang yang dibutuhkan:
            printf("==========================================================\n");
            printf("Ketikkan \"command\" untuk melihat daftar command yang ada\n");
            printf("==========================================================\n");
        }
        
        printf("Masukkan perintah:\n");

        STARTKATA();
        if (IsKataSama("w") || IsKataSama("a") || IsKataSama("s") || IsKataSama("d")){
           MenuJalan(p1);
        } else if (IsKataSama("command")){
            ListCommand();
        } // nanti tambahin elif aja buat command yang lain
        else if(!(IsKataSama("main") || IsKataSama("exit") || IsKataSama("execute"))){
            printf("==========================================================\n");
            printf("Command tidak tersedia\n");
            printf("==========================================================\n");
            printf("Ketikkan \"command\" untuk melihat daftar command yang ada\n");
            printf("==========================================================\n");
        }
        
    } while (!(IsKataSama("main") || IsKataSama("exit") || IsKataSama("execute")));

}

void MainPhase(player * p1){
    do{
        if (!IsKataSama("command")){
            printf("===================================\n");
            printf("            Main Phase\n");
            printf("             Day %d\n", Day(*p1));
            printf("===================================\n");
            TulisPETA(Peta1, *p1);
            printf("===================================\n");
            printf("Legend:\n");
            printf("A = Antrian\n");
            printf("P = Player\n");
            printf("W = Wahana\n");
            printf("O = Office\n");
            printf("^, >, v, < = Gerbang\n");
            printf("===================================\n");
            TulisPlayer(*p1); //print nama dan uang
            printf("Current Time: "); TulisJAM(CJam(*p1)); printf("\n");
            printf("Closing Time: "); TulisJAM(JamTutup); printf("\n");
            printf("Time Remaining: "); TulisTimeRemaining(Durasi(CJam(*p1), JamTutup)); printf("\n");
            // Antrian
            printf("==========================================================\n");
            printf("Ketikkan \"command\" untuk melihat daftar command yang ada\n");
            printf("==========================================================\n");
        }
        printf("Masukkan perintah:\n");
        
        STARTKATA();
        if (IsKataSama("w") || IsKataSama("a") || IsKataSama("s") || IsKataSama("d")){
           MenuJalan(p1);
        } else if (IsKataSama("command")){
            ListCommand();
        } // nanti tambahin elif aja buat command yang lain 
        else if (!(IsKataSama("prepare") || IsKataSama("exit"))) {
            printf("==========================================================\n");
            printf("Command tidak tersedia\n");
            printf("==========================================================\n");
            printf("Ketikkan \"command\" untuk melihat daftar command yang ada\n");
            printf("==========================================================\n");
        }
        
    } while(!(IsKataSama("prepare") || IsKataSama("exit")));
}