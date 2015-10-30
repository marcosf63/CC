#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <slist.h>

using namespace std;
int main() {
  int i, j, n;
  TList l;

  do {
    printf("Digite a quantidade de elementos da lista: ");
    scanf("%d", &n);
  } while (n < 0 || n > 100);

  srand(time(0));

  for (i = 1; l.size() < n; i++)
    l.insert(rand() % 10 + 1, i);

  l.print("Lista gerada: ");

  for (i = 2; i < n; i++) {
    for (j = 1; j < i ; j++ )
      if (l.getkey(j) == l.getkey(i))
         break;
    if (j != i)
      l.remove(i);
  }

  l.print("Lista sem repetidos: ");

  return 0;
}
