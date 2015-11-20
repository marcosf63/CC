#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


int main(){

  Digraph G;

  G = DIGRAPHinit(5);

  DIGRAPHinsertA(G, 0, 1);
  DIGRAPHinsertA(G, 0, 2);
  DIGRAPHinsertA(G, 1, 2);
  DIGRAPHinsertA(G, 1, 3);
  DIGRAPHinsertA(G, 1, 4);
  DIGRAPHinsertA(G, 2, 4);
  DIGRAPHinsertA(G, 4, 3);
  
  DIGRAPHshow(G); 
  int existe = DIGRAPHpath(G, 0, 1);
  if (existe)
    printf("EXISTE CAMINHO\n");
  else
    printf("NAO EXISTE CAMINHO\n");

  imprimeCaminhoAoContrario(G, 0, 4);

  return 0;
}
