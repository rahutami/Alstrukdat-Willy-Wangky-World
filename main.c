#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ADT/boolean/boolean.h"
#include "ADT/mesinkar/mesinkar.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/point/point.h"
#include "ADT/player/player.h"
#include "ADT/matriks/matriks.h"


#define MAXCHAR 100
char CC;
Kata CKata;
boolean EOP;
MATRIKS Peta1, Peta2, Peta3, Peta4;

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

void Preparation(player *p1){
    do{
        printf("===================================\n");
        printf("        Preparation Phase\n");
        printf("             Day X\n");
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
        printf("===================================\n");
        
        STARTKATA();
        if (IsKataSama("w") || IsKataSama("a") || IsKataSama("s") || IsKataSama("d")){
           MenuJalan(p1);
        }  
        
    } while (!(IsKataSama("main") || IsKataSama("exit") || IsKataSama("execute")));

}

void MainPhase(){

}

void MainMenu(){
    int menu;
    printf("====================================================================\n\n");
    printf("                Welcome to Willy Wangky's World!\n");
    printf("Here, you can make your own amusement park and do so many fun stuff!\n\n");
    printf("====================================================================\n");
    printf("Choose menu: \n1. New Game (new)\n2. Load Game (load)\n3. Exit (exit)\n");
    printf("===================================\n");
    STARTKATA();

    printf("===================================\n");
}

void NewGame(player *p1){
    POINT p;

    p.X = 1;
    p.Y = 1;

    printf("Enter your name: \n");
    STARTKATA();
    
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

    }
    return 0;
}

// gcc main.c ADT/player/player.c ADT/matriks/matriks.c ADT/point/point.c ADT/mesinkar/mesinkar.c ADT/mesinkata/mesinkata.c -o test