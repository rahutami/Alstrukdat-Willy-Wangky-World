#include "wahana.h" 
#include <stdio.h>
#include <stdlib.h>

boolean EndKata;
Kata CKata;
char CC;
boolean EOP;

int main(){
    
    First(WahanaBuilt) = NilList;
    //TreeWahanaS T;
    MakeTree(&UpgradeTree);
    printf("Daftar Wahana: \n");
    PrintTree(UpgradeTree);
    //STARTKATA();
    //addressWahanaD P = SearchWahanaD(CKata,L);
    POINT P = MakePOINT(1,1);
    buildWahana(P,&WahanaBuilt);
    PrintInfoWD(WahanaBuilt);
    STARTKATA();
    PrintHistory(CKata, UpgradeTree);
    return 0;
    
}
/*Print PreOrder
[A]Coaster
[B]Helicap
[C]Jungle
[D]Stars
[E]Shotgun
[F]Dancingking
[G]Watersplash
[H]Marinebay
[I]Rush
[J]Liftup

     A
  B     G
C  E   H  J
D  F   I
*/
//gcc mdriverwahana.c wahana.c ../listlinier/listlinier.c ../jam/jam.c ../mesinkar/mesinkar.c ../mesinkata/mesinkata.c ../point/point.c -o mdriverwahana