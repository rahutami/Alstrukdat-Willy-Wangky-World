/* file : buy.h
merupakan bagian preparation phase
yang menampilkan commad BUY
*/

#include "buy.h"
#include <stdio.h>

void CommmandBuyArray()
{
	//CreateEmpty (&stackExecute); // coba // buat test
	Tab File_material;
	BacaIsi(&File_material);
	TulisIsiTab(File_material);
	printf("\n%s\n%s\n%s\n%s","Masukkan Perintah:","<jumlah> <material>","<enter untuk keluar>","-> ");
	STARTKATA();
	if (!IsKataSama (""))
	{
		int val;
		int Nbahan;
		Nbahan = convToInt(CKata);
		ADVKATA();
		PrintKata(CKata);
		if (SearchK(File_material, CKata) && !IsKataSama (""))
		{
			val = Nbahan * SearchVal(File_material, CKata);
			//printf("%i\n",val);
			Kata command;
			command.TabKata[0]='B';
			command.TabKata[1]='u';
			command.TabKata[2]='y';
			command.TabKata[3]='\n';
			command.Length = 3;

			POINT P = MakePOINT(0,0);

			aksi X;
			X.commandStack = command;
			X.durasi = 5;
			X.PointWahana = P;
			X.NamaBahan = CKata;
			X.JumlahBahan = Nbahan;
			X.uang = val;

			Push (&stackExecute, X); //Variabel globla stackExecute
			//PrintInfoStack(stackExecute); // buat test
		}
		else
		{
			printf("%s\n","Material tidak ada di list" );
		}	
	}else
	{
		printf("%s\n","Masukkana Anda enter" );
	}

}