#include<stdio.h>
#include<stdlib.h>
#include "matrix.h"

int main(){
  Digraph G1; //, G2;
  Vertex v, w;
  int qtdA;

  system("clear");
  G1 = DIGRAPHinit(6);
  //G2 = DIGRAPHinit(3);

  printf("Digite a quantidade de Arcos G1: ");
  scanf("%d", &qtdA);

  int i;
  for(i = 0; i < qtdA; i++){
    printf("Digite o arco  %d/%d v-w: ", i+1, qtdA);
    scanf("%d-%d", &v, &w);
    DIGRAPHinsertA(G1, v, w);
  }
  printf("Digrafo G1\n");
  DIGRAPHshow(G1);


  /*printf("Digite a quantidade de Arcos G2: ");
  scanf("%d", &qtdA);

  
  for(i = 0; i < qtdA; i++){
    printf("Digite o arco  %d/%d v-w: ", i+1, qtdA);
    scanf("%d-%d", &v, &w);
    DIGRAPHinsertA(G2, v, w);
  }
  printf("Digrafo G2\n");
  DIGRAPHshow(G2);*/
/*
  printf("Remover o arco v-w: ");
  scanf("%d-%d", &v, &w);
  DIGRAPHremoveA(G, v, w);

  DIGRAPHshow(G);*/
/*
  int g0 = DIGRAPHindeg(0, G);
  int g1 = DIGRAPHindeg(1, G);
  int g2 = DIGRAPHindeg(2, G);

  printf("O grau de entrada de 0 eh: %d\n", g0);
  printf("O grau de entrada de 1 eh: %d\n", g1);
  printf("O grau de entrada de 2 eh: %d\n", g2);

  g0 = DIGRAPHoutdeg(0, G);
  g1 = DIGRAPHoutdeg(1, G);
  g2 = DIGRAPHoutdeg(2, G);

  printf("O grau de saida de 0 eh: %d\n", g0);
  printf("O grau de saida de 1 eh: %d\n", g1);
  printf("O grau de saida de 2 eh: %d\n", g2);*/

  /*if (DIGRAPHconsitencia(G1))
    printf("OK\n");
  else
    printf("NOK\n");

  if(DIGRAPHconsitencia(G2))
    printf("OK\n");
  else
    printf("NOK\n");
*/
  
  if (DIGRAPHpath(G1, 0, 1))
    printf("Existe caminho entre 0 e 1\n");
  else
    printf("Nao existe caminho entre 0 e 1\n");

  if (DIGRAPHpath(G1, 2, 3))
    printf("Existe caminho entre 2 e 3\n");
  else
    printf("Nao existe caminho entre 2 e 3\n");

  return 0;
}


