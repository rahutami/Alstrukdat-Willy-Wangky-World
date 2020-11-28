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
MATRIKS Peta1, Peta2, Peta3, Peta4;
JAM JamBuka, JamTutup;
listPlayer LP;
extern Graph GraphPeta;

void NewGame(player *p1){
    
    printf("Enter your name: ");
    STARTKATA();
    printf("\n");
    
    
    CreateJamBukaTutup();
    CreatePlayer(p1);

    loadPeta(&Peta1, &Peta2, &Peta3, &Peta4);
    CreateGraphPeta(Peta1, Peta2, Peta3, Peta4, &GraphPeta);
}

int main(){
    int menu;

    MainMenu();

    if (IsKataSama("new")){
        player p1;
        TreeWahanaS T;
        printf("lala");
        MakeTree(&T);
        printf("lala");

        NewGame(&p1);
        MakeTree(&T);
        
        Preparation(&p1, T);
        while(!IsKataSama("exit")){
            if(IsKataSama("prepare")){
                Day(p1)++;
                CJam(p1) = MakeJAM(21,0);
                Preparation(&p1, T);
            } else if (IsKataSama("main") || IsKataSama("execute")){
                srand(time(NULL));
                CJam(p1) = MakeJAM(9,0);
                MainPhase(&p1, T);
            }
        }
    }

    printf("===================================\n\n");
    printf("          See you soon!\n\n");
    printf("===================================\n");
    return 0;
}

// gcc main.c ADT/wahana/wahana.c ADT/listlinier/listlinier.c ADT/listplayer/listplayer.c ADT/graph/graph.c ADT/jam/jam.c ADT/matriks/matriks.c ADT/menu/menu.c ADT/mesinkar/mesinkar.c ADT/mesinkata/mesinkata.c ADT/peta/peta.c ADT/player/player.c ADT/point/point.c ADT/prioqueue/prioqueue.c ADT/stack/stackt.c -o main