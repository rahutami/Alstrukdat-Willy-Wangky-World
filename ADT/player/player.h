#ifndef PLAYER_H
#define PLAYER_H

#include "../point/point.h"
#include "../jam/jam.h"
#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"

#define MaxLength 20

typedef struct {
    Kata Name;
    POINT Position;
    int MapNum;
    JAM CJam;
    int Money;
    int Day;
} player;

extern player Player;

#define Position(P) (P).Position
#define X(P) Absis((P).Position)
#define Y(P) Ordinat((P).Position)
#define MapNum(P) (P).MapNum
#define Money(P) (P).Money
#define CJam(P) (P).CJam
#define Day(P) (P).Day

JAM JamBuka;
JAM JamTutup;

void CreatePlayer(player *P);

void TulisPlayer(player P);

#endif