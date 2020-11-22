#include "wahana.h" 
#include <stdio.h>
#include <stdlib.h>

boolean EndKata;
Kata CKata;
char CC;
boolean EOP;

int main(){
    
    TreeWahanaS T;
<<<<<<< Updated upstream
    MakeTree(&T);
    PrintTree(T);

=======
    //addressWahanaS temptree[10];
    //printf("TEST");
    MakeTree(&T);
    PrintTree(T);   
    
>>>>>>> Stashed changes
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