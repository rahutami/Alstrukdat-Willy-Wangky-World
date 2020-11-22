
#include "wahana.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void Details(Kata inputWahana, ListWahanaD L)
/* I.S namaWahana dimasukkan user */
/* F.S Menampilkan detail dari wahana*/
{
    addressWahanaD P = SearchWahanaD (inputWahana,L);
    if (P!=NilList){
        printf("Nama : "); PrintKata(inputWahana); printf("\n");
        printf("Tipe : "); printf("\n");
        printf("Harga : %d\n",PriceWahana(ElmtStatis(P)));
        printf("Lokasi : "); TulisPOINT(PositionWahana(P)); printf("\n");
        printf("Deskripsi : "); PrintKata(DescWahana(ElmtStatis(P))); printf("\n"); 
        printf("Kapasitas : %d\n",CapacityWahana(ElmtStatis(P)));
        printf("Upgrade(s) : "); printf("\n");
        printf("History : "); printf("\n"); //history per wahana
        printf("Durasi : %d\n",TimeWahana(ElmtStatis(P)));
        printf("Ukuran : "); printf("\n");
        printf("Status kerusakan : "); printf("\n");
        printf("Status build : "); printf("\n");//sudah dibuild ato belom, jadi tau next actionnya upgrade ato build
    } else {
        printf("Wahana tidak ditemukan!");
    }
    
}

void Report(Kata inputWahana, ListWahanaD L)
/* I.S namaWahana dimasukkan user */
/* F.S Menampilkan report dari wahana*/
{
    addressWahanaD P = SearchWahanaD (inputWahana,L);
    printf("Berapa kali total dinaiki : %d\n",TotalFreqWahana(P));
    printf("Berapa kali dinaiki hari ini : %d\n",IncomeWahana(P));
    printf("Total penghasilan : %d\n",DailyFreqWahana(P));
}

addressWahanaD SearchWahanaD (Kata inputWahana, ListWahanaD L)
/* I.S namaWahana dimasukkan user */
/* F.S Mengembalikan address dnegan wahana yang sesuai dengan yang dicari*/
{
    //KAMUS LOKAL
    boolean found = false;
    addressWahanaD P = First(L);
    //ALGORITMA

    while (!found && (P != NilList)){
        if (IsKataSamaKata(inputWahana, NamaWahana(ElmtStatis(P)))){
            found = true;
        } else {
            P = Next(P);
        }
    }
    return P;    
}

void SubTree(addressWahanaS parent, addressWahanaS l, addressWahanaS r){
    Left(parent) = l;
    Right(parent) = r;
}

void MakeTree(TreeWahanaS *T)
/* I.S P adalah tree kosong */
/* F.S P adalah tree berisi ElmtWahanaStatis yang diambil dari file txt */
{
    boolean EndKata;
    Kata CKata;
    char CC;
    boolean EOP;

    addressWahanaS temptree[10];
    for (int i = 0; i < 10; i++)
        temptree[i] = AlokNode(i);

    STARTFILE("../../Files/Wahana/wahana.txt");
    int i=0;
    int indexarr=0; //akan bertambah perbaris dan pernode

    while(!EOP){
        SalinKataFile();
        i++;
        if(CC == EOL){
            ADV(); //pita maju 1 karakter
            i=0;
            printf("\n");
            indexarr++;
        } else {
            switch (i) {
                case 1:
                    IDWahana(temptree[indexarr]) = convToInt(CKata); 
                    break;
                case 2:
                    NamaWahana(temptree[indexarr]) = CKata;
                    break;
                case 3:
                    TipeWahana(temptree[indexarr]) = CKata;
                    break;
                case 4:
                    PriceWahana(temptree[indexarr]) = convToInt(CKata);
                    break;
                case 5:
                    DescWahana(temptree[indexarr]) = CKata;
                    break;
                case 6:
                    CapacityWahana(temptree[indexarr]) = convToInt(CKata);
                    break;
                case 7:
                    TimeWahana(temptree[indexarr]) = convToInt(CKata);
                    break;
                default:
                    break;
            }
        }
    }  

    SubTree(temptree[0], temptree[1], temptree[2]);
    SubTree(temptree[1], temptree[3], temptree[4]);
    SubTree(temptree[3], temptree[7], NilList);
    SubTree(temptree[4], temptree[8], NilList);
    SubTree(temptree[2], temptree[5], temptree[6]);
    SubTree(temptree[5], temptree[9], NilList);
    Root(*T) = temptree[0];
}

/* Manajemen Memory */
addressWahanaS AlokNode(int i)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addressWahanaS P;
    P = (addressWahanaS)malloc(sizeof(ElmtWahanaStatis));
    if (P != NilList){
        Left(P) = NilList;
        Right(P) = NilList;
    }
    return P;
}

void DealokNode(addressWahanaS *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
    free(*P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(TreeWahanaS T)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
    return (Root(T) ==  NilList);
}

boolean IsTreeOneElmt(TreeWahanaS T)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
    if (IsTreeEmpty(T)) return false;
    else {
        if (Left(Root(T)) == NilList && Right(Root(T)) == NilList){
            return true;
        } 
        else{
            return false;
        }     
    }
}

boolean IsUnerLeft(TreeWahanaS T)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
    if (!IsTreeEmpty(T)) {
        if (Left(Root(T)) != NilList && Right(Root(T)) == NilList){
            return true;
        }    
        return false;
    }
    return false;
}

boolean IsUnerRight(TreeWahanaS T)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
    if (!IsTreeEmpty(T)){
        if (Right(Root(T)) != NilList && Left(Root(T)) == NilList){
            return true;    
        }

        return false;
    }
    return false;
}

boolean IsBiner(TreeWahanaS T)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
    if (!IsTreeEmpty(T)) {
        if (Left(Root(T)) != NilList && Right(Root(T)) != NilList){
            return true;
        }
        return false; 
    }
    return false;
}
//ID-WAHANA-TIPE-HARGA-DESKRIPSI-KAPASITAS-DURASI(MENIT)

void PrintTreeNode(addressWahanaS P){
    if (P!= NilList){
        PrintKata(NamaWahana(P));
        PrintTreeNode(Left(P));
        PrintTreeNode(Right(P));
    }
}

void PrintTree(TreeWahanaS T){
    PrintTreeNode(Root(T));
}