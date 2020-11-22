#include "wahana.h" 
#include <stdio.h>
#include <stdlib.h>


int main(){
    TreeWahanaS T;
    addressWahanaS temptree[10];
    printf("TEST");
    MakeTree(&T);
    PrintTree(T);
    
}
//error : undefined reference Maketree dan PrintTree
//gcc mdriverwahana.c wahana.c ../listlinier/listlinier.c ../jam/jam.c ../mesinkar/mesinkar.c ../mesinkata/mesinkata.c ../point/point.c -o mdriverwahana