/* 
Empilhar n elementos inteiros, gerados aleatoriamente no intervalo de 1 a 10, e apresentar os dois maiores elementos.
*/
#include "sstack.h"
#include "time.h"

int main() {
  TStack s;
  TKey k, maior1, maior2;
  int i, n;
  
  do {
    printf("Digite o número de elementos da pilha: ");
    scanf("%d", &n);
  } while (n < 0);
  
  srand(time(0));
   
  for (i = 0; i < n; i++) {
    k = rand() % 10 + 1;
    s.push(k);
    if (i == 0) { 
      maior1 = k;
      maior2 = 1;
    }
    else {
      if (k > maior1) {
        maior2 = maior1;
        maior1 = k;
      } else {
          if (k > maior2 && k != maior1)
            maior2 = k;
      }
    }
  //  printf("Maior1 - %d, Maior2 - %d  ", maior1, maior2);
  //  s.print("");
  }

  s.print("");
  printf("Maior1 - %d, Maior2 - %d\n", maior1, maior2);

  return 0;
}
