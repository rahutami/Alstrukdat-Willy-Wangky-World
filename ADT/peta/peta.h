#ifndef PETA_H
#define PETA_H

#include "../player/player.h" 
#include "../matriks/matriks.h" 
#include "../graph/graph.h" 

void CopyPETA (MATRIKS MIn, MATRIKS * MHsl);
/* Melakukan assignment MHsl  MIn */

void TulisPETA (player Pl, Graph G);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis PETA 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
void MakePETA (char* filename, MATRIKS * P);

void MovePeta(player *P, Graph G, int NewMapID);

void w(player *P, Graph G);

void a(player *P, Graph G);

void s(player *P, Graph G);

void d(player *P, Graph G);

int loadPeta();

void AddWToPeta();
#endif