#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <slist.h>

using namespace std;

int main() {
  int i, j, n;
  float soma, media, mediana;
  TKey k;
  TList l;

  do {
    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);
  } while (n < 0 || n > 100);

  soma = 0;
  for (i = 1; i <= n; i++) {
    k = rand() % 10 + 1;
    soma = soma + k;
    l.insert(k, i);
  }
  l.print("Lista gerada: ");

  for (i = 1; i <=  l.size(); i++) {
    k = l.getkey(i);

    for (j = i - 1; i >= 1 && l.getkey(j) > k; j--)
        l.setkey(j + 1, l.getkey(j));
    l.setkey(j + 1, k);
  }

  l.print("Lista ordenada: ");

  //Mediana
  if (l.size() % 2)
    mediana = l.getkey(n / 2 + 1);
  else
    mediana = (l.getkey(n / 2) + l.getkey(n / 2 + 1)) / 2;

  printf("Media   = %.2f\n", soma / n);
  printf("Mediana = %.2f\n", mediana);

  return 0;
}
