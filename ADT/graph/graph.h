/* File: graph.h */
/* ADT graph dengan representasi multilist */

#ifndef GRAPH_H
#define GRAPH_H

#include "../boolean/boolean.h"
#include "../linkgraph/linkgraph.h"
#include "../matriks/matriks.h"

// Maksimum simpul dari graph = maks bangunan
#define N  600
typedef int infoTypeLink;
typedef struct tElmtgraph *addressGraph;
typedef struct tElmtgraph {
	int ID;
	MATRIKS Peta;
	ListLink link;
	addressGraph next;
} ElmtGraph;
typedef struct {
	addressGraph First;
} Graph;

#define ID(P) (P)->ID
#define Peta(P) (P)->Peta
#define NextGraph(P) (P)->next
#define Link(P) 	 (P)->link
#define FirstGraph(G) ((G).First)

void CreateEmptyGraph(Graph *G);
/* I.S. sembarang             */
/* F.S. Terbentuk graph kosong */

boolean IsGraphEmpty(Graph G);
/* Mengirimkan true jika graph kosong */

addressGraph AlokasiGraph(int id, MATRIKS peta);
/* Mengirimkan addressGraph hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressGraph tidak nil, dan misalnya */
/* menghasilkan P, maka InfoGraph(P)=X, NextGraph(P)=NULL, dan Link(P) berisi list kosong */
/* Jika alokasi gagal, mengirimkan NULL */

void InsGraphLast(Graph * G, addressGraph P);

void PrintGraph(Graph G);
/* I.S. Graph mungkin kosong */
/* F.S. Jika Graph tidak kosong, isi info Graph dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Graph kosong : menulis [] */


void AddLink(Graph *G, infoTypeLink n, infoTypeLink p);
/* I. S. Graph G terdefinisi, n dan p pasti tidak lebih dari jumlah building
   F. S. Link dari elemen n bertambah dengan p, dan sebaliknya (soalnya bolak balik)
   contoh :
   1 2->3
   2 1
   3 1
   Add(&G, 2, 3) 
   1 2->3
   2 1->3
   3 1->3 */

void PrintLink(Graph G, infoTypeLink X);

boolean IsLinked(Graph G, infoTypeLink n, infoTypeLink p);
/* Mengembalikan true jika pada link n ada p */

addressGraph SearchGraph(Graph G, infoTypeLink X);

void CreateGraphPeta(MATRIKS Peta1, MATRIKS Peta2, MATRIKS Peta3, MATRIKS Peta4, Graph * G);

void PrintPetaGraph(Graph G);

void MakeLink(addressGraph * P);
#endif
