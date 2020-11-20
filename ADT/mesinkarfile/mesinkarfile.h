/* File: mesinkarfile.h */
/* Definisi Mesin Karakter baca file */

#ifndef __MESIN_KARFILE_H_
#define __MESIN_KARFILE_H_

#include "../boolean/boolean.h"

#define MARK '.'
/* State Mesin */
extern char CC;
extern boolean EOP;
extern char * Name_File;

void STARTFILE();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */

void ADVFILE();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */

#endif