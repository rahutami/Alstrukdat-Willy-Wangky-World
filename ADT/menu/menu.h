#ifndef MENU_H
#define MENU_H

#include "../prioqueue/prioqueue.h"
#include "../player/player.h"
#include "../graph/graph.h"

void MainMenu();
void MenuJalan(player *p1, Graph G);
void Preparation(player *p1);
void MainPhase(player * p1);
void ListCommand();
#endif