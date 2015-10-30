#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "slist.h"

using namespace std;

int main() {
  int i, n, aux;
  TList l;

  do {
    printf("Digite a quantidade de elementos da lista: ");
    scanf("%d", &n);
  } while (n < 0 || n > 100);

  srand(time(0));

  for (i = 1; l.size() < n; i++)
    l.insert(rand() % 10 + 1, i);

  l.print("Lista gerada: ");

  for (i = 1; i <= n / 2; i++) {
    aux = l.getkey(i);
    l.setkey(i, l.getkey(n - i + 1));
    l.setkey(n - i + 1, aux);
  }

  l.print("Lista invertida: ");



  return 0;
}
