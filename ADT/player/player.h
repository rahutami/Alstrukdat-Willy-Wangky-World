#ifndef PLAYER_H
#define PLAYER_H

#include "../matriks/matriks.h"
#include "../point/point.h"

#define MaxLength 20

typedef struct {
    char name[MaxLength];
    POINT position;
    int MapNum;
} player;

#define X(P) Absis((P).position)
#define Y(P) Ordinat((P).position)
#define MapNum(P) (P).MapNum

void CreatePlayer(player *P, POINT post, char* name);

void TulisPlayer(player P);

void movePeta(player *P);

#endif