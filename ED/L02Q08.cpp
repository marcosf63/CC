#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dlist.h"

int main() {
  int i, j, n, contador, maior;
  TList l, c, lista_final; //Lista c para guardar o numero de ocorrencias na lista

  do {
    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);
  } while (n < 0);

  srand(time(0));

  for (i = 1; i <= n; i++) {
    l.insert(rand() % 10, i);
  }

  maior = 1;
  for (i = 1; i <= n; i++) {
    contador = 1;
    for (j = 1; j <= n; j ++) {
      if (j != i && l.getkey(j) == l.getkey(i))
        contador++;
    }
    c.insert(contador, i);
    if (contador > maior)
      maior = contador;
  }

  l.print("Lista                :");
  c.print("Numero de ocorrencias:");

  for (i = j = 1; i <= n; i++)
    if (c.getkey(i) == maior && !lista_final.indexof(l.getkey(i))){
      lista_final.insert(l.getkey(i), j);
      j++;
    }

  lista_final.print("Elementos que mais se repetem: "); // Imprime os elementos que mais se repetem

  return 0;
}
