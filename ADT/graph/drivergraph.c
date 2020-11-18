#include "graph.h"


int main(){
    Graph G;
    MATRIKS Peta1, Peta2, Peta3, Peta4;
    loadPeta(&Peta1, &Peta2, &Peta3, &Peta4);
    CreateGraphPeta(Peta1, Peta2, Peta3, Peta4, &G);
    PrintGraph(G);
    PrintPetaGraph(G);
}

// gcc drivergraph.c graph.c ../matriks/matriks.c ../peta/peta.c ../linkgraph/linkgraph.c -o test