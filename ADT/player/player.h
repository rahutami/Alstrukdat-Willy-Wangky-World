#ifndef PLAYER_H
#define PLAYER_H

#include "../point/point.h"
#include "../jam/jam.h"
#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"

#define MaxLength 20

typedef struct {
    Kata Name;
    POINT position;
    int MapNum;
    JAM CJam;
    int money;
    int Day;
} player;

#define X(P) Absis((P).position)
#define Y(P) Ordinat((P).position)
#define MapNum(P) (P).MapNum
#define Money(P) (P).money
#define CJam(P) (P).CJam
#define Day(P) (P).Day

JAM JamBuka;
JAM JamTutup;

void CreatePlayer(player *P);

void TulisPlayer(player P);

void movePeta(player *P);

#endif