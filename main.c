#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ADT/boolean/boolean.h"
#include "ADT/mesinkar/mesinkar.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/point/point.h"
#include "ADT/player/player.h"
#include "ADT/matriks/matriks.h"
#include "ADT/jam/jam.h"
#include "ADT/menu/menu.h"
#include "ADT/peta/peta.h"

#define MAXCHAR 100
char CC;
Kata CKata;
boolean EOP;
MATRIKS Peta1, Peta2, Peta3, Peta4;
JAM JamBuka;
JAM JamTutup;

void NewGame(player *p1){
    printf("Enter your name: \n");
    STARTKATA();
    
    
    CreateJamBukaTutup();
    CreatePlayer(p1);

    loadPeta(&Peta1, &Peta2, &Peta3, &Peta4);
}

int main(){
    int menu;

    MainMenu();

    if (IsKataSama("new")){
        player p1;
        
        NewGame(&p1);
        
        Preparation(&p1);
        while(!IsKataSama("exit")){
            if(IsKataSama("prepare")){
                Day(p1)++;
                CJam(p1) = MakeJAM(21,0,0);
                Preparation(&p1);
            }
            else if (IsKataSama("main") || IsKataSama("execute")){
                CJam(p1) = MakeJAM(9,0,0);
                MainPhase(&p1);
            }
        }
    }

    printf("===================================\n\n");
    printf("          See you soon!\n\n");
    printf("===================================\n");
    return 0;
}

// gcc main.c ADT/peta/peta.c ADT/menu/menu.c ADT/jam/jam.c ADT/player/player.c ADT/matriks/matriks.c ADT/point/point.c ADT/mesinkar/mesinkar.c ADT/mesinkata/mesinkata.c -o main