#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;
  
int main() {
int **m, i, j, o, l, c;// o = ordem,  l = linhas, c = colunas
int movimento;
printf("Digite a ordem da matriz: ");
scanf("%d", &o);
printf("\n");

m = (int **)calloc(o, sizeof(int *));

for (i = 0; i < o; i++)
  m[i] = (int*)calloc(o, sizeof(int));

//Imprime a matriz
for (i = 0; i < o; i++){
  for (j = 0; j < o; j++)
    printf("%d ", m[i][j]);
  printf("\n");
}

printf("Digite uma posicao da matriz: \n");
printf("Linha -> ");
scanf("%d", &l);
printf("\n");
printf("Coluna -> ");
scanf("%d", &c);
printf("\n");

l--;
c--;

m[l][c] = 1;

//Imprime a matriz
for (i = 0; i < o; i++){
  for (j = 0; j < o; j++)
    printf("%d ", m[i][j]);
  printf("\n");
}

printf("Digite para onde quer mover o UM: \n");
printf("Para cima, digite 1 \n");
printf("Para baixo, digite 2 \n");
printf("Para direita, digite 3 \n");
printf("Para cima, esquerda 4:  \n");
scanf("%d", &movimento);


if (movimento == 1) {
  if (l == 0)
    printf("Movimento Invalido\n");
  else{
    m[l][c] = 0;
    m[l - 1][c] = 1;
  }
}

if (movimento == 2) {
  if (l == o - 1)
    printf("Movimento Invalido\n");
  else{
    m[l][c] = 0;
    m[l + 1][c] = 1;
  }
}

if (movimento == 3) {
  if (c == o - 1)
    printf("Movimento Invalido\n");
  else{
    m[l][c] = 0;
    m[l][c + 1] = 1;
  }
}

if (movimento == 4) {
  if (c == 0)
    printf("Movimento Invalido\n");
  else{
    m[l][c] = 0;
    m[l][c - 1] = 1;
  }
}

printf("\n");

//Imprime a matriz
for (i = 0; i < o; i++){
  for (j = 0; j < o; j++)
    printf("%d ", m[i][j]);
  printf("\n");
}

return 0;
}
