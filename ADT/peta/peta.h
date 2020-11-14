#ifndef PETA_H
#define PETA_H

#include "../player/player.h" 
#include "../matriks/matriks.h" 

void CopyPETA (MATRIKS MIn, MATRIKS * MHsl);
/* Melakukan assignment MHsl  MIn */

void TulisPETA (MATRIKS Pt, player Pl);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis PETA 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

void w(player *P, MATRIKS CPeta);

void a(player *P, MATRIKS CPeta);

void s(player *P, MATRIKS CPeta);

void d(player *P, MATRIKS CPeta);

int loadPeta();

#endif