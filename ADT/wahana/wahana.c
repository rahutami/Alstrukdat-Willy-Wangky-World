
#include "wahana.h"
#include <stdio.h>
#include <stdlib.h>

boolean EndKata;
Kata CKata;
char CC;
boolean EOP;

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
        //printf("Jenis material : ")
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
/* F.S Mengembalikan address dnegan wahana yang sesuai dengan yang dicari,
       apakah dia sudah pernah di build atau belum*/
{
    //KAMUS LOKAL
    boolean found = false;
    addressWahanaD P = First(L);
    //ALGORITMA

    while (!found && (P != NilList)){
        if (IsKataSamaKata(inputWahana, NamaWahana(ElmtStatis(P)))){
            found = true;
            printf("berhasil");
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
    boolean empty = true;
    addressWahanaS temptree[10];
    for (int i = 0; i < 10; i++)
        temptree[i] = AlokNode(i);

    STARTFILE("../../Files/Wahana/wahana.txt");
    //printf("baca file\n");
    int i=0;
    int indexarr=0; //akan bertambah perbaris dan pernode

    while(!EOP){
        empty = false;
        SalinKataFile();
        i++;
        if(CC == EOL){
            if (i == 9){
                JmlBahan(temptree[indexarr]) = convToInt(CKata);
                //printf("bisa 7, %d\n",TimeWahana(temptree[indexarr]));
            }
            ADV(); //pita maju 1 karakter
            i=0;
            //printf("\n");
            indexarr++;
            //printf("[index arr: %d] ",indexarr);
        } else {
            switch (i) {
                case 1:
                    IDWahana(temptree[indexarr]) = convToInt(CKata); 
                    //printf("bisa 1, %d\n",IDWahana(temptree[indexarr]));
                    break;
                case 2:
                    NamaWahana(temptree[indexarr]) = CKata;
                    //printf("bisa 2, "); PrintKata(NamaWahana(temptree[indexarr])); printf("\n");
                    break;
                case 3:
                    TipeWahana(temptree[indexarr]) = CKata;
                    //printf("bisa 3, "); PrintKata(TipeWahana(temptree[indexarr])); printf("\n");
                    break;
                case 4:
                    PriceWahana(temptree[indexarr]) = convToInt(CKata);
                    //printf("bisa 4, %d\n",PriceWahana(temptree[indexarr]));
                    break;
                case 5:
                    DescWahana(temptree[indexarr]) = CKata;
                    //printf("bisa 5, "); PrintKata(DescWahana(temptree[indexarr])); printf("\n");
                    break;
                case 6:
                    CapacityWahana(temptree[indexarr]) = convToInt(CKata);
                    //printf("bisa 6, %d\n",CapacityWahana(temptree[indexarr]));
                    break;
                case 7:
                    TimeWahana(temptree[indexarr]) = convToInt(CKata);
                    //printf("bisa 7, %d\n",TimeWahana(temptree[indexarr]));
                    break;
                case 8:
                    BahanWahana(temptree[indexarr]) = CKata;
                    break;
                case 9:
                    JmlBahan(temptree[indexarr]) = convToInt(CKata);
                    break;
                default:
                    break;
            }
        }
    }  

    if(!empty){
        SubTree(temptree[0], temptree[1], temptree[2]);
        SubTree(temptree[1], temptree[3], temptree[4]);
        SubTree(temptree[3], temptree[7], NilList);
        SubTree(temptree[4], temptree[8], NilList);
        SubTree(temptree[2], temptree[5], temptree[6]);
        SubTree(temptree[5], temptree[9], NilList);
        *T = temptree[0];
    }
}

/* Manajemen Memory */
addressWahanaS AlokNode(int i)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addressWahanaS P;
    P = (ElmtWahanaStatis *)malloc(sizeof(ElmtWahanaStatis));
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
    return (T ==  NilList);
}

boolean IsTreeOneElmt(TreeWahanaS T)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
    if (IsTreeEmpty(T)) return false;
    else {
        if (Left(T) == NilList && Right(T) == NilList){
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
        if (Left(T) != NilList && Right(T) == NilList){
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
        if (Right(T) != NilList && Left(T) == NilList){
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
        if (Left(T) != NilList && Right(T) != NilList){
            return true;
        }
        return false; 
    }
    return false;
}
//ID-WAHANA-TIPE-HARGA-DESKRIPSI-KAPASITAS-DURASI(MENIT)

void PrintTreeNode(addressWahanaS P)
/* Mencetak node tree dengan address P */
{
    
    //int i = 0;
    if (P!= NilList){
        //i++;
        printf("- ");
        PrintKata(NamaWahana(P)); printf("\n");
        PrintTreeNode(Left(P));
        PrintTreeNode(Right(P));
    }
}

void PrintTree(TreeWahanaS T)
/* Mencetak tree dengan PreOrder */
{
    PrintTreeNode(T);
}

void initWahana(TreeWahanaS T)
{
    addressWahanaS Coaster1 = T;
    addressWahanaS Heli2 = Left(T);
    addressWahanaS Water3 = Right(T);
    printf("List:\n");
    printf("  -"); PrintKata(NamaWahana(Coaster1));printf("\n");
    printf("  -"); PrintKata(NamaWahana(Heli2));printf("\n");
    printf("  -"); PrintKata(NamaWahana(Water3));printf("\n");
    STARTKATA();
    //user masukin input wahana mana yang mau di build
    //build di tempat dia berdiri
    //player pindah ke bawah
}

void buildWahana(POINT Pos, ListWahanaD *L)
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
    TreeWahanaS T;
    addressWahanaD P, Prec;
    MakeTree(&T); PrintTree(T);

    printf("Ingin membangun wahana apa?\n");
    STARTKATA(); //printf("oke1");
    //PrintKata(CKata);
    //Menambah elemen pada list linier
    //ListWahanaD L;
    
    //POINT Pos;
    //addressWahanaD P1;
    P = AlokWahana(Pos,CKata,T); 
    
    if (IsEmptyListW(*L)){
        //printf("oke2");
        InsFirstW(L,P); //printf("oke4");
    }
    else{
        Prec = First(*L); 

        while (Next(Prec)!=NilList){
            Prec = Next(Prec);
        }
        InsAfterW(L,P,Prec); //printf("oke3");
    }
    
    /*if (IsEmptyListW(L)){
        InsFirstW(&L,P);
    } else {
        Prec = First(L);
        while (Next(Prec)!=NilList){
            Prec = Next(Prec);
        }
        InsAfterW(&L,P,Prec);
    }
    NamaWahana(ElmtStatis(P)) = CKata;*/

}
boolean IsEmptyListW (ListWahanaD L){
   /* Mengirim true jika list kosong */
   return(First(L) == NilList);
}

addressWahanaD AlokWahana (POINT P, Kata NamaWahana, TreeWahanaS T){
   /* Mengirimkan addressList hasil alokasi sebuah elemen */
   /* Jika alokasi berhasil, maka addressList tidak NilList, dan misalnya */
   /* menghasilkan P, maka InfoList(P)=X, Next(P)=NilList */
   /* Jika alokasi gagal, mengirimkan NilList */
   /* KAMUS */
   addressWahanaD D;
   /* ALGORITMA */
   D = (ElmtWahanaDinamis *) malloc(sizeof(ElmtWahanaDinamis)); 
   if (D!= NilList) {
       PositionWahana(D) = P;
       StatusWahana(D) = true ;
       TotalFreqWahana(D) = 0;
       IncomeWahana(D) = 0;
       DailyFreqWahana(D) = 0;
       NextWahana(D) = NilList;
       ElmtStatis(D) = SearchAddress (T, NamaWahana);
       //printf("OKE2");
    }
    //printf("OKE3");
    return D;
    
}

void InsFirstW (ListWahanaD *L, addressWahanaD D){
   /* I.S. L mungkin kosong */
   /* F.S. Melakukan alokasi sebuah elemen dan */
   /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
   /* KAMUS */
   Next(D) = First(*L);
   First(*L) = D;
}
void InsAfterW (ListWahanaD *L, addressWahanaD P, addressWahanaD Prec){
   /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
   /*      P sudah dialokasi  */
   /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
   /* ALGORITMA */
   Next(P) = Next(Prec);
   Next(Prec) = P;
}
//print wahana yang sudah dibangun
void PrintInfoWD (ListWahanaD L) {
	/* I.S. List mungkin kosong */
	/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
	/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
	/* Jika list kosong : menulis [] */
	/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
	/* KAMUS */
	addressWahanaD P;
	/* ALGORITMA */
	if(IsEmptyListW(L)) {
        printf("()");
    /*}else{
        printf("\nokelagi");
    }*/
    } else { 
        printf("(");
        P = First(L); //printf("oke5");
        //printf("%d", PriceWahana(ElmtStatis(First(L))));
        //PrintKata(NamaWahana(ElmtStatis(P)));
        
        while(P != NilList) {
            PrintKata(NamaWahana(ElmtStatis(P)));
            if(Next(P) != NilList){
                printf(", ");
            }
            P = Next(P);
        }
        printf(")");
    }
}
boolean SearchTree(Kata X, addressWahanaS P)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    if (P==NilList) {
        return false;
    }
    else {
        if (IsKataSamaKata(NamaWahana(P),X)) {
            return true;
        }
        else {
            return (SearchTree(X,Left(P)) || SearchTree(X,Right(P)));
        }
    }
}

addressWahanaS SearchAddress (TreeWahanaS P, Kata NamWahana){
   if(IsTreeEmpty(P)) return NULL;
   else if(IsKataSamaKata(NamaWahana(P), NamWahana)){
      return P;
   }
   else{
      addressWahanaS L = SearchAddress(Left(P), NamWahana);
      addressWahanaS R = SearchAddress(Right(P), NamWahana);
      if(L != NULL) return L;
      else if (R != NULL) return R;
      else return NULL;
   }
}