#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "ADT/boolean/boolean.h"
#include "ADT/mesinkar/mesinkar.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/point/point.h"
#include "ADT/player/player.h"
#include "ADT/prioqueue/prioqueue.h"
#include "ADT/matriks/matriks.h"
#include "ADT/jam/jam.h"
#include "ADT/menu/menu.h"
#include "ADT/peta/peta.h"
#include "ADT/graph/graph.h"
#include "ADT/listlinier/listlinier.h"
#include "ADT/listplayer/listplayer.h"
#include "ADT/wahana/wahana.h"

#define MAXCHAR 100
char CC;
Kata CKata;
boolean EOP;

void NewGame(){
    //Mengambil nama player dan Create player
    printf("===================================\n");
    printf("Enter your name: \n");
    STARTKATA();
    CreatePlayer(&Player);

    //Membuat tree upgrade wahana
    MakeTree();

    //Membuat jam buka dan jam tutup
    CreateJamBukaTutup();

    //Membuat stack aksi kosong
    CreateEmpty(&stackExecute);

    //Membuat peta
    loadPeta();
    CreateGraphPeta();

    //Membuat list wahana terbangun kosong    
    First(WahanaBuilt) = NULL;
}

int main(){
    MainMenu();

    do{
        if (IsKataSama("new")){ //Input new bakal masuk ke game

            NewGame();

            Preparation(&Player);
            while(!IsKataSama("exit")){
                if(IsKataSama("prepare")){
                    Day(Player)++;
                    CJam(Player) = MakeJAM(21,0);
                    Preparation(&Player);
                } else if (IsKataSama("main") || IsKataSama("execute")){
                    srand(time(NULL));
                    CJam(Player) = MakeJAM(9,0);
                    MainPhase(&Player);
                }
            }
        } else if(!IsKataSama("exit")) {// Input selain nwe atau exit bakal loop dan minta input lagi
            printf("===================================\n");
            printf("Command tidak tersedia\n");
            printf("Choose menu: \nNew Game (new)\nExit (exit)\n");\
            printf("===================================\n");
            STARTKATA();
        }
    } while(!IsKataSama("exit")); //Input exit bakal keluar
    

    printf("===================================\n\n");
    printf("          See you soon!\n\n");
    printf("===================================\n");
    return 0;
}

// gcc bukanmain.c ADT/buy/buy.c ADT/arraydinmap/arraydinmap.c ADT/build/build.c ADT/wahana/wahana.c ADT/listlinier/listlinier.c ADT/listplayer/listplayer.c ADT/graph/graph.c ADT/jam/jam.c ADT/matriks/matriks.c ADT/menu/menu.c ADT/mesinkar/mesinkar.c ADT/mesinkata/mesinkata.c ADT/peta/peta.c ADT/player/player.c ADT/point/point.c ADT/prioqueue/prioqueue.c ADT/stack/stackt.c -o test