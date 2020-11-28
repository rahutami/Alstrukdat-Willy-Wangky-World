#include "../boolean/boolean.h"
#include <stdio.h>
#include "arraydinmap.h"

int main() {
    Tab T;
    Kata Tami;
    //MakeEmptyDin(&T,10);

    //AddAsLastEl(&T,Tami,3);
   // AddAsLastEl(&T,Abel,5);
   // AddAsLastEl(&T,Adila,7);
    printf("Baca isi\n");
    BacaIsi(&T);
    printf("Tulis isi\n");
    TulisIsiTab(T);
    return 0;
}
// gcc arraydinmap.c driver_arraydinmap.c ../mesinkata/mesinkata.c ../mesinkar/mesinkar.c -o tes