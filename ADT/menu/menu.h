#ifndef MENU_H
#define MENU_H

#include "../mesinkata/mesinkata.h"
#include "../matriks/matriks.h"
#include "../jam/jam.h"
#include "../peta/peta.h"
#include "../prioqueue/prioqueue.h"
#include "../graph/graph.h"
#include "../wahana/wahana.h"
#include "../player/player.h"
#include "../graph/graph.h"
#include "../wahana/wahana.h"
#include "../prepare/prepare.h"

void MainMenu();
void MenuJalan(player *p1, Graph G);
void Preparation(player *p1);
void MainPhase(player * p1);
void ListCommand();
#endif