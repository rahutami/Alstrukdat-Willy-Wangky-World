#include "player.h"
#include <stdio.h>
#include <string.h>

void CreatePlayer(player *P, POINT post, char* name){
    strcpy((*P).name, name);
    (*P).position.X = post.X;
    (*P).position.Y = post.Y;
    MapNum(*P) = 1;
}

void TulisPlayer(player P){
    printf("Nama player: %s\nPosisi Player: (%.0f,%.0f)\n", P.name, X(P), Y(P));
}

void movePeta(player *P){

}
