/* file : buy.h
merupakan bagian preparation phase
yang menampilkan commad BUY
*/

#include "buy.h"
#include <stdio.h>

void CommmandBuyArray()
/* melakukan semua perintah yang ada didalam Command Buy
menampilkan daftar bahan kemudian menerima inputan dan mengatusr senua case 
input salah atau benar kemudian masukin ke stack */
{
	//CreateEmpty (&stackExecute); // coba // buat test
	Tab File_material;
	BacaIsiMaterial(&File_material);
	TulisIsiTabMaterial(File_material);
	printf("\n%s\n%s\n%s\n%s","Masukkan Perintah:","<jumlah> <material>","<enter untuk keluar>","-> ");
	STARTKATA();
	while (!IsKataSama (""))
	{
		player PTes; // TEST
		CreatePlayer(&PTes); // TEST
		int val;
		int Nbahan;
		Nbahan = convToInt(CKata);
		ADVKATA();
		PrintKata(CKata);
		if (SearchK(File_material, CKata) && !IsKataSama (""))
		{
			val = Nbahan * SearchVal(File_material, CKata);
			//printf("%i\n",val);
			AddAsLastEl(&Tab(PTes),CKata,Nbahan);  // TEST
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
		printf("\n%s\n%s\n%s\n%s","Masukkan Perintah:","<jumlah> <material>","<enter untuk keluar>","-> ");
		STARTKATA();	
	}
	// else
	// {
		printf("Anda keluar dari menu buy\n");
	// }

}

void UndoBuy () {
// Uang ditambah
// Inventory berkurang (delete dari arraydinmap) -> belom bikin fungsinya. Cek inventory pake print Isi
// Pop

}