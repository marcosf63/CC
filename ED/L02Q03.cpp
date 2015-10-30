#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <dlist.h>

using namespace std;

int main() {
  int i, menor, maior, n;
  float media, soma;
  TList l;

  do {
    printf("Digite a quantidade de elementos da lista: ");
    scanf("%d", &n);
  } while (n < 0 || n > 100);

  srand(time(0));

  soma = 0;
  for (i = 1; l.size() < n; i++) {
    l.insert(rand() % 10 + 1, i);
    if (i == 1) {
      menor = l.getkey(i);
      maior = l.getkey(i);
    } else {
        menor = l.getkey(i) < menor ? l.getkey(i) : menor;
        maior = l.getkey(i) > maior ? l.getkey(i) : maior;
    }
    soma = soma + l.getkey(i);
  }

  l.print("Lista gerada: ");
  printf("Maior = %d, Menor = %d, Media = %0.2f \n", maior, menor, soma / n);


  return 0;
}
