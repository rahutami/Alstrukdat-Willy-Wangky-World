/* file : buy.h
merupakan bagian preparation phase
yang menampilkan commad BUY
*/

#include "buy.h"
#include <stdio.h>

void CommmandBuy()
// melakukan semua perintah yang ada didalam Command Buy
{
	Map File_Buy;
	CreateEmptyMap (&File_Buy);
	STARTKATAFILE("../../Files/material.txt");
	int count = 0;
	SalinKataFile();
	while( ! EndKata){
		Kata keyKata;
		int val;
		if (count % 2 == 0 ){
			CopyKata (CKata, &keyKata);
			//PrintKata(keyKata);
			
		} else{
			val = convToInt (CKata);
			Insert (&File_Buy, keyKata, val);
		}
		count ++;
		//printf("%i\n", count );
		ADVKATAFILE();
	}

	address P;
	P = First(File_Buy);
	while (P != Nil){
		//for (int i=0; i< Key(P).Length ;i++) {
		//		printf("%c", Key(P).TabKata[i] );
		//	}
		PrintKata(Key(P));
		printf("\n" );
		printf("%i\n", Val(P) );
		P = Next(P);
	}

}