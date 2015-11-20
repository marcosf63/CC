#include <stdio.h>
#include "matriz.h"

Digraph DIGRAPHconstruct(char *nomeDoAarquivo);//ler um arquivo gráfico e constroi um digrafo

int main() {

  Digraph G;
  
  G = DIGRAPHconstruct("grafo.txt");

  DIGRAPHshow(G);  

 
  return 0;
}

Digraph DIGRAPHconstruct (char *nomeDoArquivo) {
  FILE *arq;
  Digraph G;
  int V;
  Vertex v, w;
  char ch;
  int i, numeroLinhas = 4;

  arq = fopen(nomeDoArquivo, "r");
  printf("%s\n", nomeDoArquivo);  
  if ( arq != NULL) printf("ok\n");
 
  printf("numero de linhas %d", numeroLinhas);

  G = DIGRAPHinit(3);
  DIGRAPHinsertA(G, 0, 1);
  DIGRAPHinsertA(G, 1, 2);
  DIGRAPHinsertA(G, 2, 0);


  
   
  fclose(arq);  
  return G;
} 


