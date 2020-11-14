#include <stdio.h>
#include <string.h>
#include "peta.h"
void MakePETA (char* filename, MATRIKS * P)
/* Membentuk sebuah PETA "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori PETA yang dibuat */
/* F.S. PETA M sesuai dengan definisi di atas terbentuk */
{
    FILE* cFile;
    int i;

    cFile = fopen(filename, "r");

    i = 0;
    while(fscanf(cFile, "%s\n", (*P).Mem[i]) > 0){
        i++;
    }

    NBrsEff(*P) = i;
    NKolEff(*P) = strlen((*P).Mem[0]);

    fclose(cFile);
}


void TulisPETA (MATRIKS Pt, player Pl)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis PETA 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

{
    // KAMUS
    int i, j;
    
    // ALGORITMA

    for (i = 0; i < NBrsEff(Pt); i++){
        for (j = 0; j <= NKolEff(Pt); j++){
            if (j == X(Pl) && i == Y(Pl)) printf("P"); //Posisi player
            else if(Elmt(Pt, i, j) >= '1' && Elmt(Pt, i, j) <= '4'){
                if(i == 0) printf("^");
                else if(j == 0) printf("<");
                else if(i == NBrsEff(Pt)-1) printf("V");
                else if(j == NKolEff(Pt)-1) printf(">");
            }
            else printf("%c", Elmt(Pt, i, j)); //Print yang ada di peta
            if(j != NKolEff(Pt)-1) printf(" ");
        }
        if(i != NBrsEff(Pt)) printf("\n");
    }
}

void w(player *P, MATRIKS CPeta){
    int X = X(*P);
    int Y = Y(*P);

    if(Elmt(CPeta, Y-1, X) == '-' || Elmt(CPeta, Y-1, X) == 'O' ) Y(*P)--;
}

void a(player *P, MATRIKS CPeta){
    int X = X(*P);
    int Y = Y(*P);

    if(Elmt(CPeta, Y, X-1) == '-' || Elmt(CPeta, Y, X-1) == 'O') X(*P)--;
}

void s(player *P, MATRIKS CPeta){
    int X = X(*P);
    int Y = Y(*P);
    if(Elmt(CPeta, Y+1, X) == '-' || Elmt(CPeta, Y+1, X) == 'O') Y(*P)++;
}

void d(player *P, MATRIKS CPeta){
    int X = X(*P);
    int Y = Y(*P);

    if(Elmt(CPeta, Y, X+1) == '-' || Elmt(CPeta, Y, X+1) == 'O') X(*P)++;
}

int loadPeta(MATRIKS *Peta1, MATRIKS *Peta2, MATRIKS *Peta3, MATRIKS *Peta4){
    FILE *cFile;
    char* filename;
    char str[MAXCHAR];
    int i;

    // start of peta 1
    
    MakePETA("Peta/Peta_1.txt", Peta1);

    // end of peta 1

    // start of peta 2

    MakePETA("Peta/Peta_2.txt", Peta2);

    // end of peta 2

    // start of peta 3

    MakePETA("Peta/Peta_3.txt", Peta3);

    // end of peta 3

    // start of peta 4

    MakePETA("Peta/Peta_4.txt", Peta4);

    // end of peta 4
}