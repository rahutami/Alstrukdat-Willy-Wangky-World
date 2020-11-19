/* File : wahana.h */

#ifndef WAHANA_H
#define WAHANA_H

#include "../listlinier/listlinier.h"
#include "../boolean/boolean.h"
#include "../point/point.h"
#include "../jam/jam.h"
#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"

typedef struct tElmtWahana *addressWahana;
typedef struct tElmtWahana {
    int IDWahana;
    Kata NameWahana;
    // Tipe
    int PriceWahana;
    POINT PositionWahana;
    Kata DescWahana;
    int CapacityWahana;
    //upgrade
    int TimeWahana; //dalam menit
    //ukuran 
    boolean StatusWahana;
    //boolean BuildWahana; //apakah wahana sudah pernah di build sebelumnya
    //next action : upgrade atau build
	addressWahana next;
    int TotalFreqWahana;
    int IncomeWahana;
    int DailyFreqWahana;
} ElmtWahana;

typedef struct {
	addressWahana First;
} ListWahana;

#define NextWahana(W) (W)->next
#define FirstWahana(L) ((L).First)

#define IDWahana(W) (W)->IDWahana
#define NamaWahana(W) (W)->NameWahana
#define PriceWahana(W) (W)->PriceWahana
#define PositionWahana(W) (W)->PositionWahana
#define DescWahana(W) (W)->DescWahana
#define CapacityWahana(W) (W)->CapacityWahana
#define TimeWahana(W) (W)->TimeWahana
#define StatusWahana(W) (W)->StatusWahana

#define TotalFreqWahana(W) (W)->TotalFreqWahana
#define IncomeWahana(W) (W)->IncomeWahana
#define DailyFreqWahana(W) (W)->DailyFreqWahana

void Details(Kata namaWahana);
/* I.S namaWahana dimasukkan user */
/* F.S Menampilkan detail dari wahana*/

void Report(Kata namaWahana);
/* I.S namaWahana dimasukkan user */
/* F.S Menampilkan report dari wahana*/

addressWahana SearchWahana(Kata namaWahana, ListWahana L);
/* I.S namaWahana dimasukkan user */
/* F.S Mengembalikan address dnegan wahana yang sesuai dengan yang dicari*/

#endif