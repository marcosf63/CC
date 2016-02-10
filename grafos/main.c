#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


int main(){

  Digraph G;
  Vertex v, w;
  


  G = DIGRAPHinit(6);

  DIGRAPHinsertA(G, 0, 2);
  DIGRAPHinsertA(G, 0, 4);
  DIGRAPHinsertA(G, 0, 3);
  DIGRAPHinsertA(G, 2, 4);
  DIGRAPHinsertA(G, 2, 1);
  DIGRAPHinsertA(G, 3, 5);
  DIGRAPHinsertA(G, 4, 1);
  DIGRAPHinsertA(G, 4, 5);
  DIGRAPHinsertA(G, 5, 1);
  DIGRAPHinsertA(G, 0, 2);

  DIGRAPHshow(G);

  imprimeCaminhoAoContrario(G, 0, 5);
  
  return 0;
}
