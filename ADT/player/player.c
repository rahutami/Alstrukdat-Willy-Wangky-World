#include "player.h"
#include <stdio.h>
#include <string.h>

boolean EndKata;
Kata CKata;

void CreatePlayer(player *P){
    CopyKata(CKata, &(P->Name));
    
    (*P).position.X = 1;
    (*P).position.Y = 1;
    MapNum(*P) = 1;
    Money(*P) = 1000;
}

void TulisPlayer(player P){
    printf("Nama player: ");
    for (int i = 0; i < (P.Name).Length; i++){
        printf("%c", P.Name.TabKata[i]);
    }
    printf("\n");
    printf("Posisi Player: (%.0f,%.0f)\n", X(P), Y(P));
    printf("Money: %d\n", Money(P));
}

void movePeta(player *P){

}
