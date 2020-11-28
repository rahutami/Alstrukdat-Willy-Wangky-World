#include <stdio.h>
#include "menu.h"


Graph GraphPeta;
MATRIKS Peta1, Peta2, Peta3, Peta4;

void MainMenu(){
    printf("====================================================================\n\n");
    printf("                Welcome to Willy Wangky's World!\n");
    printf("Here, you can make your own amusement park and do so many fun stuff!\n\n");
    printf("====================================================================\n");
    printf("Choose menu: \nNew Game (new)\nLoad Game (load)\nExit (exit)\n");
    printf("===================================\n");
    STARTKATA();

    printf("===================================\n");
}

void MenuJalan(player *p1, Graph G){
    CJam(*p1) = NextMenit(CJam(*p1));
    if (IsKataSama("w")){
        w(p1, G);
    }else if (IsKataSama("a")){
        a(p1, G);
    }else if (IsKataSama("s")){
        s(p1, G);
    }else if (IsKataSama("d")){
        d(p1, G);
    }
}

void ListCommand(){
    printf("================================================================\n");
    printf("New Game: \"new\"\n");
    printf("Load Game: \"load\"\n");
    printf("Berjalan ke atas: \"w\"\n");
    printf("Berjalan ke kiri: \"a\"\n");
    printf("Berjalan ke bawah: \"s\"\n");
    printf("Berjalan ke kanan: \"d\"\n");
    printf("Bangun wahana: \"build\"\n");
    printf("Upgrade wahana: \"upgrade\"\n");
    printf("Beli item: \"buy\"\n");
    printf("Undo: \"undo\"\n");
    printf("Pergi ke Main Phase tanpa execute (stack): \"main\"\n");
    printf("Pergi ke Main Phase dengan execute (stack): \"execute\"\n");
    printf("Melayani pelanggan saat main phase: \"main\"\n");
    printf("Melayani pengunjung: \"serve <nama wahana>\"\n");
    printf("   Hanya bisa digunakan ketika pemain berada di sebelah antrian\n");
    printf("Memperbaiki wahana: \"repair\"\n");
    printf("   Hanya bisa digunakan ketika pemain berada di sebelah wahana\n");
    printf("Melihat detail wahana: \"detail\"\n");
    printf("   Hanya bisa digunakan ketika pemain berada di sebelah wahana\n");
    printf("Masuk office: \"office\"\n");
    printf("   Hanya bisa digunakan ketika pemain berada di atas office\n");
    printf("Pergi ke Preparation Phase: \"prepare\"\n");
    printf("Keluar Game: \"exit\"\n");
    printf("================================================================\n");
}

void Preparation(player *p1, TreeWahanaS T){
    do{
        if (!IsKataSama("command")){
            printf("===================================\n");
            printf("        Preparation Phase\n");
            printf("             Day %d\n", Day(*p1));
            printf("===================================\n");
            TulisPETA(*p1, GraphPeta);
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
            printf("Time Remaining:"); TulisTimeRemaining(Durasi(CJam(*p1), JamBuka)); 
            printf("\n");
            // Total aksi yang akan dilakukan:
            // Total waktu yang dibutuhkan:
            // Total uang yang dibutuhkan:
            printf("==========================================================\n");
            printf("Ketikkan \"command\" untuk melihat daftar command yang ada\n");
            printf("==========================================================\n");
            printf("\n");
        }
        
        printf("Masukkan perintah: ");

        STARTKATA();

        if (IsKataSama("w") || IsKataSama("a") || IsKataSama("s") || IsKataSama("d")){
           MenuJalan(p1, GraphPeta);
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

void MainPhase(player * p1, TreeWahanaS T){
    PrioQueue Q;
    listPlayer LP;
    List del;
    boolean enter = false;

    CreateEmptyQueue(&Q, 5);
    CreateEmptyLP(&LP);
    RandomizeQueue(&Q);


    do{
        if(!IsEmptyLP(LP)){
            ReduceTime(&LP);
            for(int i = 0; i < CountCompleted(LP); i++) {
                DelCompleted(&LP, &del);
                FirstEnqueue(&Q, del);
            }
        }
        
        if(enter){
            ReducePatience(&Q);
        }
        
        enter = true;

        AngryCustomer(&Q);
        
        if (!IsKataSama("command")){
            printf("===================================\n");
            printf("            Main Phase\n");
            printf("             Day %d\n", Day(*p1));
            printf("===================================\n");
            TulisPETA(*p1, GraphPeta);
            printf("===================================\n");
            printf("Legend:\n");
            printf("A = Antrian\n");
            printf("P = Player\n");
            printf("W = Wahana\n");
            printf("O = Office\n");
            printf("^, >, v, < = Gerbang\n");
            printf("===================================\n");
            printf("\n");
            TulisPlayer(*p1); //print nama dan uang
            printf("Current Time: "); TulisJAM(CJam(*p1)); printf("\n");
            printf("Closing Time: "); TulisJAM(JamTutup); printf("\n");
            printf("Time Remaining:"); TulisTimeRemaining(Durasi(CJam(*p1), JamTutup)); 
            printf("\n");
            printf("\n");
            if(!IsEmptyQueue(Q)){
                printf("Antrian [%d/5] :\n", NbElmtQueue(Q));
                PrintPrioQueue(Q);
            } else {
                printf("Antrian kosong\n");
            }
            printf("\n");
            printf("==========================================================\n");
            printf("Ketikkan \"command\" untuk melihat daftar command yang ada\n");
            printf("==========================================================\n");
            printf("\n");
        }
        printf("Masukkan perintah: ");
        
        STARTKATA();
        if (IsKataSama("w") || IsKataSama("a") || IsKataSama("s") || IsKataSama("d")){
           MenuJalan(p1, GraphPeta);
        } else if (IsKataSama("command")){
            ListCommand();
        } else if (IsKataSama("serve")) {
            addressGraph CPeta = FirstGraph(GraphPeta);
            int x = X(*p1), y = Y(*p1);
            while(ID(CPeta) != MapNum(*p1)){
                CPeta = NextGraph(CPeta);
            }
            ADVKATA();
            if(Elmt(Peta(CPeta), x + 1, y) == 'A' || Elmt(Peta(CPeta), x, y+1) == 'A' || Elmt(Peta(CPeta), x - 1, y) == 'A' || Elmt(Peta(CPeta), x, y - 1) == 'A'){
                Serve(p1, CKata, &Q, &LP, LW);
            } else {
                printf("Silahkan pergi ke sebelah antrian untuk menggunakan command ini \n\n");
            }

        }// nanti tambahin elif aja buat command yang lain 
        // else if (!(IsKataSama("prepare") || IsKataSama("exit"))) {
        //     printf("==========================================================\n");
        //     printf("Command tidak tersedia\n");
        //     printf("==========================================================\n");
        //     printf("Ketikkan \"command\" untuk melihat daftar command yang ada\n");
        //     printf("==========================================================\n");
        // } 
        else if (!(IsKataSama("prepare") || IsKataSama("exit"))) {
            printf("==========================================================\n");
            printf("Command tidak tersedia\n");
            printf("==========================================================\n");
            printf("Ketikkan \"command\" untuk melihat daftar command yang ada\n");
            printf("==========================================================\n");
        } 
        
    } while(!(IsKataSama("prepare") || IsKataSama("exit")));
}