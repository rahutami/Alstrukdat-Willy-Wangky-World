#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ADT/boolean/boolean.h"
#include "ADT/mesinkar/mesinkar.h"
#include "ADT/point/point.h"
#include "ADT/player/player.h"


#define MAXCHAR 100
char CC;
boolean EOP;
MATRIKS Peta1, Peta2, Peta3, Peta4;

void Preparation(){
}

void MainPhase(){

}

int MainMenu(){
    int menu;
    printf("====================================================================\n\n");
    printf("                Welcome to Willy Wangky's World!\n");
    printf("Here, you can make your own amusement park and do so many fun stuff!\n\n");
    printf("====================================================================\n");
    printf("Choose menu: \n1. New Game\n2. Load Game\n3. Exit\n");
    printf("====================================================================\n");
    scanf("%d", &menu);

    printf("====================================================================\n");
    return menu;
}

void MenuJalan(player *p1, char charInput){
    if (charInput == 'w'){
                w(p1, Peta1);
            }
            else if (charInput == 'a'){
                a(p1, Peta1);
            }
            else if (charInput == 's'){
                s(p1, Peta1);
            }
            else if (charInput == 'd'){
                d(p1, Peta1);
            }

            printf("=========================================\n");
            TulisPETA(Peta1, *p1);
            printf("\n=========================================\n");
            TulisPlayer(*p1);
            printf("=========================================\n");
            scanf(" %c", &charInput);
}

void NewGame(player *p1){
    POINT p;
    char name[20];

    p.X = 1;
    p.Y = 1;

    printf("Enter your name: ");
    scanf("%s", &name);

    CreatePlayer(&p1, p, name);

    printf("====================================================================\n");
    loadPeta();

    TulisPETA(Peta1, p1);

    TulisPlayer(*p1);
    printf("====================================================================\n");

}

int main(){
    int menu;
    
    menu = MainMenu();

    if (menu == 1){
        player p1;
        char charInput;
        
        NewGame(&p1);

        while (charInput != '0'){
            MenuJalan(&p1, charInput);
            scanf(" %c", &charInput);
        }


    }
    return 0;
}

// gcc main.c ADT/player/player.c ADT/peta/peta.c ADT/point/point.c -o test