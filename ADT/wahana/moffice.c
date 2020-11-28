#include "office.h" 
#include "wahana.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    /*POINT P = MakePOINT(1,3);
    POINT X = MakePOINT(1,3);
    if (IsEqPOINT(P,X)) printf ("oke");*/
    POINT P = MakePOINT(1,1);
    office(P);
    return 0;
}
//gcc moffice.c office.c ../wahana/wahana.c ../mesinkar/mesinkar.c ../mesinkata/mesinkata.c ../point/point.c -o moffice