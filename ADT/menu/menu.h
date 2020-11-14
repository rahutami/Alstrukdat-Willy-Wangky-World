#ifndef MENU_H
#define MENU_H

#include "../prioqueue/prioqueue.h"
#include "../player/player.h"

void MainMenu();
void MenuJalan(player *p1);
void Preparation(player *p1);
void MainPhase(player * p1, PrioQueue * Q);
void ListCommand();
#endif