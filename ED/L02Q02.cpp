#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "slist.h"

using namespace std;

int main() {
  int i, j, k, n;
  TList l;

  do {
    printf("Digite a quantidade de elementos da sequencia: ");
    scanf("%d", &n);
  } while (n < 0 || n > 100);

  l.insert(1, 1);
  l.insert(3, 2);

  for (i = 3; l.size() < n; i++) {
    if (i % 2)
      l.insert(l.getkey(i - 1) - l.getkey(i - 2), i);
    else
      l.insert(l.getkey(i - 2) + 2, i );
  }

  l.print("Lista gerada: ");

  return 0;
}
