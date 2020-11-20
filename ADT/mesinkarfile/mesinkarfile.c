/* File: mesinkarfile.c */
/* Implementasi Mesin Karakter */

#include "mesinkarfile.h"
#include <stdio.h>

/* ****** variabel Global ketika include "masinkar.h" */
char CC;
boolean EOP;
char * Name_File; // bias di deklararikan di luar file ini dengan cara Name_file = "blabla.txt"

static FILE * pita;
static int retval;

void STARTFILE() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	pita = fopen(Name_File,"r");
	ADVFILE();
}

void ADVFILE() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
		  Jika  CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(pita,"%c",&CC);
	EOP = (CC == MARK);
	if (EOP) {
       fclose(pita);
 	}
}