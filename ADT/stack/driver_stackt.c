#include <stdio.h>
#include "stackt.h"

int main() {
    
    Stack stacktest;
    Stack S;
    aksi buang;
    aksi gajadi;
    CreateEmpty(&stacktest);

    aksi aksi1, aksi2, aksi3, aksi5;
    aksi1.durasi = 1;
    aksi3.durasi = 3;
    aksi5.durasi = 5;
    aksi2.durasi = 2;

    Push(&stacktest,aksi1);
    Push(&stacktest,aksi3);
    Push(&stacktest,aksi5);
    printf("Stack awal:\n");
    PrintStack(stacktest);

    Push(&stacktest,aksi2);
    printf("Stack, setelah 2 dipush ke stack:\n");
    PrintStack(stacktest);
    printf("Jumlah durasi semua aksi dalam stack: %d \n", SumDurasiStack(stacktest));
    //S=InverseStack(stacktest);
    //PrintStack(&S);

    Undo(&stacktest,&gajadi);
    printf("Setelah di undo (1):\n");
    PrintStack(stacktest);
    Pop(&stacktest,&gajadi);
    printf("Setelah di undo (2):\n");
    PrintStack(stacktest);

    // Ngosongin stack aja tanpa execute
    mainmain(&stacktest,&buang);
    printf("Stack setelah dikosongin:\n");
    PrintStack(stacktest);
    // MULAI MAIN PHASE
    
    //EXECUTE
    /* 
    if (sum > waktu) {
        printf("error\n");
    }
    else {
        PrintStack(target);
        Stack stacktereksekusi;
        CreateEmpty(&stacktereksekusi);
        int tereksekusi;
        // Eksekusi : pop satu per satu dari target
        while (!IsEmpty(target))
        {
            Pop(&target,&tereksekusi);
            Push(&stacktereksekusi,tereksekusi);
        }
        printf("\n\nStack tereksekusi: \n\n");
        PrintStack(stacktereksekusi);
        printf("\nStack target:\n\n");
        PrintStack(target);
    }
    */
    // EXECUTE
    /* Jika jumlah waktu aksi2 di dalam stack melebihi jumlah waktu yang diizinkan, tampilkan pesan error
    Jika waktu cukup:
    pindahkan ke stack lain dengan
    pop dari stack awal,
    lalu push ke stack target.
    terus, eksekusi perintah dengan pop satu per satu dari stack target
    */
    return 0;
}
// COMMAND
// gcc -o tes driver_stackt.c stackt.c -lm