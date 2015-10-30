#include "sstack.h"
#include "time.h"

int main() {
  TStack s, aux;
  TKey k;
  int i, n;
  
  do {
    printf("Digite o número de elementos da pilha: ");
    scanf("%d", &n);
  } while (n < 0);
  
  srand(time(0));
   
  for (i = 0; i < n; i++) {
    k = rand() % 10 + 1;

    while (!s.empty() && k > s.top())
      aux.push(s.pop());

    s.push(k);

    while (!aux.empty())
      s.push(aux.pop());
  }

  s.print("");
  
  return 0;
}
