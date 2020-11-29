#include "build.h"
#include <stdio.h>
int main(){
	CommmandBuild();
}
// untuk menjalankan driver rubah fileSTARTFILE("./Files/Wahana/wahana.txt"); menjadi  STARTFILE("../../Files/Wahana/wahana.txt"); pada MakeTree() di "../wahana/wahana.c"
//gcc driverbuild.c build.c  ../listlinier/listlinier.c ../jam/jam.c ../mesinkar/mesinkar.c ../mesinkata/mesinkata.c ../point/point.c ../wahana/wahana.c ../stack/stackt.c  ../player/player.c -o test