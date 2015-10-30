#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "slist.h"
using namespace std;
  
int main() {
  int i, j, k, n, aux;
  TList l;

  do {
    printf("Digite a quantidade de elementos da lista: ");
    scanf("%d", &n);
  } while (n < 0);

  srand(time(NULL));

  for (i = 1; i <= n; i++)
    l.insert(rand() % 10 + 1, i);

  l.print("Lista: ");

  for(i = 1; i <= n - 1; i++) {
    j = i + 1;
    
    for (k = j + 1; k <= n; k++)
      if (l.getkey(k) < l.getkey(j))
        j = k;
      
      if (l.getkey(j) < l.getkey(i)) {
        aux = l.getkey(i);
	l.setkey(i, l.getkey(j));
	l.setkey(j, aux);
      }
  }
  
  l.print("lista ordenada: ");
  return 0;
}
