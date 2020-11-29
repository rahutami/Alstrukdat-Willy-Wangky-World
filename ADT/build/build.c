/* file : buy.c
merupakan bagian preparation phase
yang menampilkan commad BUY
*/

#include "build.h"
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