/* file : buy.c
merupakan bagian preparation phase
yang menampilkan commad BUY
*/

#include "prepare.h"
#include <stdio.h>

void ProsedureBuild(POINT Pos, ListWahanaD *L)
/* Menambahkan  status build kedalam stack dan list wahana */

/*Command ini digunakan untuk membuat wahana baru di petak di mana
pemain sedang berdiri.
1. Setelah meminta command ini, program akan menampilkan
wahana dasar yang mungkin dibuat (hasil load file eksternal).
2. Setelah pemain memilih wahana dasar yang ingin dibuat.
3. Jika resource untuk membangun wahana tidak mencukupi, maka
akan ditampilkan pesan error.
4. Setelah itu, perintah eksekusi ini akan dimasukkan ke dalam
stack*/
{
    //Menampilkan wahana dasar (ada 10, diambil dari tree wahana)
    addressWahanaD P, Prec;
    printf("\nIngin membangun wahana apa?\n-> ");
    STARTKATA(); 
    if (!IsKataSama (""))
    {
         if(SearchTree(CKata,UpgradeTree))
         {
            //masukkin ke list  wahana
            P = AlokWahana(Pos, CKata); 
            if (IsEmptyListW(*L))
            {
                 InsFirstW(L,P);
            }
            else{
                
                Prec = First(*L); 

                while (Next(Prec)!=NilList){
                    Prec = Next(Prec);
                }
                InsAfterW(L, P, Prec);
            }
            // Masukkin ke stack

            addressWahanaS P = SearchAddress (UpgradeTree, CKata);
            Kata command;
            command.TabKata[0]='B';
            command.TabKata[1]='u';
            command.TabKata[2]='i';
            command.TabKata[3]='l';
            command.TabKata[4]='d';
            command.TabKata[5]='\n';
            command.Length = 5;
            
            aksi X;
            X.commandStack = command;
            X.durasi = 60;
            X.PointWahana = Position(Player);
            X.NamaBahan = BahanWahana(P);
            X.JumlahBahan = JmlBahan(P); 
            X.uang = PriceWahana(P);
            Push (&stackExecute, X); //Variabel globla stackExecute
            //PrintInfoStack(stackExecute); // buat test
            
        }
        else
        {
            printf("%s\n","Wahana tidak ada dalam list wahana" );
        }   
    }
    else
	{
		printf("%s\n","Masukkan Anda enter" );
	}
}

void CommmandBuild()
/* Menampikkan kelayar list wahana kemudian meminta inputan dan memangil fungsi prosedurBuild*/
/* UNTUK MAIN PROGRAM */

/*Command ini digunakan untuk membuat wahana baru di petak di mana
pemain sedang berdiri.
1. Setelah meminta command ini, program akan menampilkan
wahana dasar yang mungkin dibuat (hasil load file eksternal).
2. Setelah pemain memilih wahana dasar yang ingin dibuat.
3. Jika resource untuk membangun wahana tidak mencukupi, maka
akan ditampilkan pesan error.
4. Setelah itu, perintah eksekusi ini akan dimasukkan ke dalam
stack*/
{
     //CreateEmpty (&stackExecute); // coba // buat test di deklarai di main awal
     First(WahanaBuilt) = NilList;
     MakeTree();
     printf("Daftar Wahana: \n");
     PrintTree(UpgradeTree);
     POINT P = Position(Player);
     ProsedureBuild(P,&WahanaBuilt);
     //printf("\n");
     //PrintInfoWD(WahanaBuilt);
     
     
     
}

void UndoBuild() {
    // Tambahin uang
    // Tambahin bahan -> cek inventory pake PrintIsiTab
    // Delete di list wahana built -> Cek list WahanaBuilt
    // Pop
}

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


void upgradeWahana() {
    int X = X(Player);
    int Y = Y(Player);
    POINT P;
    addressGraph CPeta = FirstGraph(GraphPeta);
    while(ID(CPeta) != MapNum(Player)) CPeta = NextGraph(CPeta);
    if (ElmtMatriks(Peta(CPeta), Y-1, X) == 'W' || ElmtMatriks(Peta(CPeta), Y+1, X) == 'W' || ElmtMatriks(Peta(CPeta), Y, X-1) == 'W' || ElmtMatriks(Peta(CPeta), Y, X+1) == 'W'){
        printf("\nList wahana yang bisa diupgrade:\n");

        if(ElmtMatriks(Peta(CPeta), Y-1, X) == 'W'){
            P = MakePOINT(X,Y-1);
            PrintKata(NamaWahana(ElmtStatis(SearchWahanaDP(P, WahanaBuilt)))); printf("\n");
        }

        if(ElmtMatriks(Peta(CPeta), Y+1, X) == 'W'){
            P = MakePOINT(X, Y+1);
            PrintKata(NamaWahana(ElmtStatis(SearchWahanaDP(P, WahanaBuilt)))); printf("\n");
        }

        if(ElmtMatriks(Peta(CPeta), Y, X-1) == 'W'){
            P = MakePOINT(X-1,Y);
            PrintKata(NamaWahana(ElmtStatis(SearchWahanaDP(P, WahanaBuilt)))); printf("\n");
        }

        if(ElmtMatriks(Peta(CPeta), Y, X+1) == 'W'){
            P = MakePOINT(X+1, Y);
            PrintKata(NamaWahana(ElmtStatis(SearchWahanaDP(P, WahanaBuilt)))); printf("\n");
        }

        printf("\nPilih wahana yang ingin diupgrade: ");
        STARTKATA(); printf("\n");
        addressWahanaS elmtStatisUpgrade = ElmtStatis(SearchWahanaD(CKata, WahanaBuilt));
        addressWahanaS addrPrevWahana = elmtStatisUpgrade; // address wahana sebelumnya
        //addressWahanaD elmtStatisUpgradeD = SearchWahanaD(namaWahana,WahanaBuilt);
        //addressWahanaS elmtStatisUpgrade;
        /* 
        if (elmtStatisUpgradeD != NULL) {
            elmtStatisUpgrade = ElmtStatis(elmtStatisUpgradeD);
            printf("Ketemu, nama wahana: "); printf("\n");
            PrintKata(NamaWahana(elmtStatisUpgrade)); printf("\n");
            printf("Ingin melakukan upgrade apa?\n"); */
            
            addressWahanaS addrElmtUpgraded; // address wahana setelah upgrade
            if (Left(elmtStatisUpgrade)== NULL && Right(elmtStatisUpgrade)==NULL) { // Kondisi udah mentok gabisa diupgrade
                printf("Tidak dapat diupgrade.");
            }
            else { // bisa diupgrade
                // Kalo bisa diupgrade, tampilin list terus cek resource dan uang
                Kata elmtUpgrade;
                printf("List:\n");
                if (Left(elmtStatisUpgrade)!=NULL && Right(elmtStatisUpgrade)==NULL){ // Cuma bisa upgrade ke left
                    PrintKata(NamaWahana(Left(elmtStatisUpgrade))); printf("\n");
                    // cek resource DAN UPGRADE COST (BELOM)
                    if (BahanCukup(&Player,BahanWahana(Left(elmtStatisUpgrade)),JmlBahan(Left(elmtStatisUpgrade)))) {
                        // Bisa upgrade
                        /* Kode mau upgrade kemana */
                        printf("\nMau upgrade kemana: ");
                        STARTKATA();
                        printf("\n");
                        CopyKata(CKata,&elmtUpgrade);
                        while ((!IsKataSamaKata(elmtUpgrade,NamaWahana(Left(elmtStatisUpgrade))))) {
                            printf("Nama wahana yang Anda tulis salah. Mau upgrade kemana: ");
                            STARTKATA();
                            CopyKata(CKata,&elmtUpgrade);
                        }
                        addrElmtUpgraded = Left(elmtStatisUpgrade);
                        /* Kode mau upgrade kemana */
                        elmtStatisUpgrade = addrElmtUpgraded; // mengganti elemen statisnya
                                                    PrintUpgraded(addrPrevWahana,elmtStatisUpgrade);
                                                            UpgradeStack(); // Buat nge push ke stack

                    }
                    else {
                        printf("\nBahan atau uang yang kamu miliki tidak cukup untuk melakukan upgrade.\n");
                    }
                } 
                else if (Left(elmtStatisUpgrade)==NULL && Right(elmtStatisUpgrade)!=NULL){ // Cuma bisa upgrade ke right
                    PrintKata(NamaWahana(Right(elmtStatisUpgrade))); printf("\n");
                    if (BahanCukup(&Player,BahanWahana(Right(elmtStatisUpgrade)),JmlBahan(Right(elmtStatisUpgrade)))) {
                        // Bisa upgrade
                        /* Kode mau upgrade kemana */
                        printf("Mau upgrade kemana: ");
                        STARTKATA();
                        CopyKata(CKata,&elmtUpgrade);
                        while ((!IsKataSamaKata(elmtUpgrade,NamaWahana(Right(elmtStatisUpgrade))))) {
                            printf("Nama wahana yang Anda tulis salah. Mau upgrade kemana: ");
                            STARTKATA();
                            CopyKata(CKata,&elmtUpgrade);
                        }
                        addrElmtUpgraded = Right(elmtStatisUpgrade);
                        elmtStatisUpgrade = addrElmtUpgraded; // mengganti elemen statisnya
                        /* Kode mau upgrade kemana */
                                                    PrintUpgraded(addrPrevWahana,elmtStatisUpgrade);
                            UpgradeStack(); // Buat nge push ke stack
                    }
                    else {
                        printf("Bahan atau uang yang kamu miliki tidak cukup untuk melakukan upgrade.\n");
                    }
                }
                else { // Bisa diupgrade ke left ataupun right
                    PrintKata(NamaWahana(Left(elmtStatisUpgrade))); printf("\n");
                    PrintKata(NamaWahana(Right(elmtStatisUpgrade))); printf("\n");
                    printf("Mau upgrade kemana: ");
                    STARTKATA();
                    CopyKata(CKata,&elmtUpgrade);
                    while ((!IsKataSamaKata(elmtUpgrade,NamaWahana(Left(elmtStatisUpgrade)))) && (!IsKataSamaKata(elmtUpgrade,NamaWahana(Right(elmtStatisUpgrade))))) {
                        printf("Nama wahana yang Anda tulis salah. Mau upgrade kemana: ");
                        STARTKATA();
                        CopyKata(CKata,&elmtUpgrade);
                    }
                    if (IsKataSamaKata(elmtUpgrade,NamaWahana(Left(elmtStatisUpgrade)))) {
                        // CEK RESOURCE KIRI
                        if (BahanCukup(&Player,BahanWahana(Left(elmtStatisUpgrade)),JmlBahan(Left(elmtStatisUpgrade)))) {
                            // Bisa upgrade
                            /* Kode mau upgrade kemana */
                            printf("Mau upgrade kemana: ");
                            STARTKATA();
                            CopyKata(CKata,&elmtUpgrade);
                            while ((!IsKataSamaKata(elmtUpgrade,NamaWahana(Left(elmtStatisUpgrade))))) {
                                printf("Nama wahana yang Anda tulis salah. Mau upgrade kemana: ");
                                STARTKATA();
                                CopyKata(CKata,&elmtUpgrade);
                            }
                            addrElmtUpgraded = Left(elmtStatisUpgrade);
                            /* Kode mau upgrade kemana */
                            elmtStatisUpgrade = addrElmtUpgraded; // mengganti elemen statisnya
                            PrintUpgraded(addrPrevWahana,elmtStatisUpgrade);
                            UpgradeStack(); // Buat nge push ke stack
                            }
                        else {
                            printf("Bahan atau uang yang kamu miliki tidak cukup untuk melakukan upgrade.\n");
                        }
                    }
                    if (IsKataSamaKata(elmtUpgrade,NamaWahana(Right(elmtStatisUpgrade)))) {
                        if (BahanCukup(&Player,BahanWahana(Left(elmtStatisUpgrade)),JmlBahan(Left(elmtStatisUpgrade)))) {
                            // Bisa upgrade
                            /* Kode mau upgrade kemana */
                            printf("Mau upgrade kemana: ");
                            STARTKATA();
                            CopyKata(CKata,&elmtUpgrade);
                            while ((!IsKataSamaKata(elmtUpgrade,NamaWahana(Left(elmtStatisUpgrade))))) {
                                printf("Nama wahana yang Anda tulis salah. Mau upgrade kemana: ");
                                STARTKATA();
                                CopyKata(CKata,&elmtUpgrade);
                            }
                            addrElmtUpgraded = Left(elmtStatisUpgrade);
                            elmtStatisUpgrade = addrElmtUpgraded; // mengganti elemen statisnya
                            /* Kode mau upgrade kemana */
                            PrintUpgraded(addrPrevWahana,elmtStatisUpgrade);
                            UpgradeStack(); // Buat nge push ke stack
                            }
                        else { // gabisa upgrade
                            printf("Bahan atau uang yang kamu miliki tidak cukup untuk melakukan upgrade.\n");
                        }
                    }
                }
                //addressWahanaS addrElmtUpgraded = ElmtStatis(SearchWahanaD(elmtUpgrade,WahanaBuilt));
                //elmtStatisUpgrade = addrElmtUpgraded; // mengganti elemen statisnya
        }

        // Memasukkan perintah ke stack ONLY IF berhasil upgrade (uang dan resources cukup!)


    } else { // Tidak bisa upgrade, karena tidak di sekitar wahana
        printf("Kamu tidak berada di sekitar wahana\n");
    }
}