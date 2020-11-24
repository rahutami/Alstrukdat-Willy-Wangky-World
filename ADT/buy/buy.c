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
			
		} else{
			val = convToInt (CKata);
			Insert (&File_Buy, keyKata, val);
		}
		if (CC == EOL){
			ADV();
		}
		count ++;
		ADVKATAFILE();
	}
	printf("%s\n%s\n", "Ingin membeli apa?","List:" );
	address P;
	P = First(File_Buy);
	while (P != Nil){
		printf("  -- ");
		PrintKata(Key(P));
		printf(" <$%i>", Val(P) );
		printf("\n" );
		P = Next(P);
	}
	printf("\n%s\n%s\n%s\n%s","Masukkan Perintah:","<jumlah> <material>","<enter untuk keluar>","-> ");
	STARTKATA();
	Kata InputEnter;
	InputEnter.Length = 1;
	InputEnter.TabKata[1] = '\n';
	if (!IsKataSama("Cancel")){
		int val;
		val = convToInt(CKata);
		ADVKATA();
		val = val * SearcVal(&File_Buy,CKata);
		printf("%i\n",val); // cuma check
		//<nama item> <jumlah item>
	}else{
		printf("Anda Keluar dari buy");//coba
	}

}