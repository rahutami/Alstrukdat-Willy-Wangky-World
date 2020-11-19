
#include "wahana.h"
#include <stdio.h>
#include <string.h>

void Details(Kata inputWahana)
/* I.S namaWahana dimasukkan user */
/* F.S Menampilkan detail dari wahana*/
{
    ListWahana L;
    addressWahana P = SearchWahana(inputWahana,L);
    printf("Nama : "); PrintKata(inputWahana); printf("\n");
    printf("Tipe : "); printf("\n");
    printf("Harga : %d\n",PriceWahana(P));
    printf("Lokasi : "); TulisPOINT(PositionWahana(P)); printf("\n");
    printf("Deskripsi : "); PrintKata(DescWahana(P)); printf("\n"); //bedainnya dari baca txt
    printf("Kapasitas : %d\n",CapacityWahana(P));
    printf("Upgrade(s) : "); printf("\n");
    printf("History : "); printf("\n"); //history per wahana
    printf("Durasi : %d\n",TimeWahana(P));
    printf("Ukuran : "); printf("\n");
    printf("Status kerusakan : "); printf("\n");
    printf("Status upgrade : "); printf("\n");
}

void Report(Kata inputWahana)
/* I.S namaWahana dimasukkan user */
/* F.S Menampilkan report dari wahana*/
{
    ListWahana L;
    addressWahana P = SearchWahana(inputWahana,L);
    printf("Berapa kali total dinaiki : %d\n",TotalFreqWahana(P));
    printf("Berapa kali dinaiki hari ini : %d\n",IncomeWahana(P));
    printf("Total penghasilan : %d\n",DailyFreqWahana(P));
}

addressWahana SearchWahana(Kata inputWahana, ListWahana L)
/* I.S namaWahana dimasukkan user */
/* F.S Mengembalikan address dnegan wahana yang sesuai dengan yang dicari*/
{
    //KAMUS LOKAL
    boolean found = false;
    addressWahana P = First(L);
    //ALGORITMA

    while (!found && (P != NilList)){
        if (IsKataSamaKata(inputWahana, NamaWahana(P))){
            found = true;
        } else {
            P = Next(P);
        }
    }
    return P;

}
