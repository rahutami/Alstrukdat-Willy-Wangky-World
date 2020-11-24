#include <stdio.h>
#include "stackt.h"

int main() {
    /* 
    Stack stacktest;
    Stack S;
    int buang;
    infotype gajadi;
    CreateEmpty(&stacktest);
    Push(&stacktest,1);
    Push(&stacktest,3);
    Push(&stacktest,5);
    PrintStack(stacktest);
    printf("\nCOBA\n");
    Push(&stacktest,2);
    //Pop(&stacktest,InfoTop(S));
    PrintStack(stacktest);
    //S=InverseStack(stacktest);
    //PrintStack(&S);
    // SUM OF STACK
    int sum=0;
    int waktu=12;
    Stack target;
    CreateEmpty(&target);
    CopyStack(stacktest,&target);
    printf("stack awal:\n\n");
    PrintStack(stacktest);
    */
    /* JUMLAH STACK */
    //SumOfStack(S);
    /* 
    printf("SUM: %d", SumOfStack(stacktest)); udah fix bisa :)
*/    
/* 
    Undo(&stacktest,&gajadi);
    //Pop(&stacktest,&gajadi);
    printf("setelah di undo :\n\n");
    PrintStack(stacktest);

    while (!IsEmpty(stacktest)) {
        sum+= InfoTop(stacktest);
        Pop(&stacktest,&buang);
    }
    printf("\n jumlahnya: \n %d \n",sum) ; 
    */
    // Ngosongin stack aja tanpa execute
    // mainmain(&stacktest,&buang); udah fix bisa :)
    /* 
    while (!IsEmpty(stacktest)) {
        Pop(&stacktest,&buang);
    } 
    */
    //printf("\n\nstack setelah dikosongin\n");
    //PrintStack(stacktest);
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