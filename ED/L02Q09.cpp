#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "dlist.h"

using namespace std;

int main() {
  int i , j, contador;
  char palavra[50];
  TList l, cont;
  
  printf("Digite uma palavra: ");
  scanf("%s", &palavra); 

  for (i = 0 ; palavra[i]; i++)
    l.insert(palavra[i], i + 1);

  for (i = 1; i <= l.size(); i++) {
    contador = 1;
    for (j = 1; j <= l.size(); j++)
      if (j != i && l.getkey(j) == l.getkey(i))
        contador++;

    cont.insert(contador, i);
  }

  l.print("");
  cont.print("");

  return 0;
}
