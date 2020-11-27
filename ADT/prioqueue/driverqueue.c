#include "../listlinier/listlinier.h"
#include "../listplayer/listplayer.h"
#include "../mesinkata/mesinkata.h"
#include "../wahana/wahana.h"
#include "../player/player.h"
#include <stdio.h>

int main() {
    player P;
    PrioQueue Q;
    listPlayer LP;
    TreeWahanaS T;
    CreateEmptyQueue(&Q, 5);
    CreateEmptyLP(&LP);
    RandomizeQueue(&Q);

    printf("Enter your name: ");
    STARTKATA();
    printf("\n");
    CreatePlayer(&P);

    STARTKATA();
    do {
        if (IsKataSama('serve')){
            ADV();
            Serve(&P,CKata,&Q,&LP,T);
        }
    } while (IsKataSama('exit'));



    return 0;
}