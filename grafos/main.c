#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


int main(){

  Digraph G, G1, G2;
  Vertex v, w;
  int qtdv, qtda, i;

  printf("Qtd de Vértices: ");
  scanf("%d", &qtdv);
  G = DIGRAPHinit(qtdv);

  printf("Qtd de Arcos: ");
  scanf("%d", &qtda);

  for (i = 0; i < qtda; i++){
    printf("Entre com v-w %d: ", i+1);
    scanf("%d-%d", &v, &w);
    DIGRAPHinsertA(G, v, w);
  }

  DIGRAPHshow(G);


  printf("(Grau de saída) Digite um vértice: ");
  scanf("%d", &v);
  printf("O gradu do vértice %d: %d\n", v, DIGRAPHoutdeg(G, v));

  printf("(Grau de entrada) Digite um vértice: ");
  scanf("%d", &v);
  printf("O gradu do vértice %d: %d\n", v, DIGRAPHindeg(G, v));


  G1 = DIGRAPHinit(3);
  G2 = DIGRAPHinit(3);

  DIGRAPHinsertA(G1, 0, 1);
  DIGRAPHinsertA(G1, 0, 2);
  DIGRAPHinsertA(G1, 2, 0);

  DIGRAPHinsertA(G2, 0, 1);
  DIGRAPHinsertA(G2, 0, 2);
  DIGRAPHinsertA(G2, 2, 1);

  if (DIGRAPHequal(G1, G2))
    printf("IGUAIS\n");
  else
    printf("DIFERENTES\n");

  return 0;
}
