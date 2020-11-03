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

int loadPeta(){
    FILE *cFile;
    char* filename;
    char str[MAXCHAR];
    int i;

    // start of peta 1
    
    MakePETA("Peta/Peta_1.txt", &Peta1);

    // end of peta 1

    // start of peta 2

    MakePETA("Peta/Peta_2.txt", &Peta2);

    // end of peta 2

    // start of peta 3

    MakePETA("Peta/Peta_3.txt", &Peta3);

    // end of peta 3

    // start of peta 4

    MakePETA("Peta/Peta_4.txt", &Peta4);

    // end of peta 4
}

int main(){
    int menu;
    printf("====================================================================\n\n");
    printf("                Welcome to Willy Wangky's World!\n");
    printf("Here, you can make your own amusement park and do so many fun stuff!\n\n");
    printf("====================================================================\n");
    printf("Choose menu: \n1. New Game\n2. Load Game\n3. Exit\n");
    printf("====================================================================\n");
    scanf("%d", &menu);

    printf("====================================================================\n");

    if (menu == 1){

        player p1;
        POINT p;
        char charInput;
        char name[20];

        p.X = 1;
        p.Y = 1;

        printf("Enter your name: ");
        scanf("%s", &name);

        CreatePlayer(&p1, p, name);

        printf("====================================================================\n");
        loadPeta();

        TulisPETA(Peta1, p1);

        TulisPlayer(p1);
        printf("====================================================================\n");
        scanf(" %c", &charInput);

        while (charInput != '0'){
            if (charInput == 'w'){
                w(&p1, Peta1);
            }
            else if (charInput == 'a'){
                a(&p1, Peta1);
            }
            else if (charInput == 's'){
                s(&p1, Peta1);
            }
            else if (charInput == 'd'){
                d(&p1, Peta1);
            }

            printf("=========================================\n");
            TulisPETA(Peta1, p1);
            printf("\n=========================================\n");
            TulisPlayer(p1);
            printf("=========================================\n");
            scanf(" %c", &charInput);
        }


    }
    return 0;
}

// gcc main.c ADT/player/player.c ADT/peta/peta.c ADT/point/point.c -o test