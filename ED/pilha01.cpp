//Gerar uma pilha com n elementos inteiros distintos no intervalo de 1 a 2n.
#include "dstack.h"
#include "time.h"

bool existe(TKey k, TStack *s); //Retorna V se K exite na pilha F, caso contrario

int main() {
  TStack s;
  TKey k;
  int i, n;

  do {
    printf("Digite o tamanho da pilha: ");
    scanf("%d", &n);
  } while (n < 0);

  srand(time(0));

  for (i = 1 ; s.depth() < n; i++) {
    k = rand() % (2 * n) + 1;
    printf("%d ", k);
    if (s.depth() == 0)
      s.push(k);
    else {
       if (!existe(k, &s))
         s.push(k);
    }
    s.print(" ");
  }


 return 0;
}

bool existe(TKey k, TStack *s) {
  TStack aux;
  bool existe = true;

  while (!s->empty() && s->top() != k)
     aux.push(s->pop());

  if (s->empty())
    existe = false;

  while (!aux.empty())
    s->push(aux.pop());

  return existe;
}

