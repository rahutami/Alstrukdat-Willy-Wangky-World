// driverbuy.c

#include "buy.h"
#include <stdio.h>
int main(){
	CommmandBuyArray();
}
// rubah data STARTKATAFILE("Files/material.txt"); menjadi STARTKATAFILE("../../Files/material.txt"); pada BacaIsiMaterial di "../arraydinmap/arraydinmap.c"
//
// gcc -o driverbuy driverbuy.c buy.c ../mesinkar/mesinkar.c ../mesinkata/mesinkata.c ../arraydinmap/arraydinmap.c ../point/point.c ../stack/stackt.c ../jam/jam.c