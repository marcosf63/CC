#include "dstack.h"
#include "time.h"

void inverte(TStack *s); //Inverter a pilha
bool existe(TKey k, TStack *s); //Retorna V se K exite na pilha F, caso contrario
void ordena(TStack *s); //Ordena a pilha crescente

int main() {
  TStack s, aux;
  TKey k;
  int i, n;

  do {
    printf("Digite o tamanho da pilha: ");
    scanf("%d", &n);
  } while (n < 0);
  
  srand(time(0));

  
 while (s.depth() < n) {
    k = rand() % 10 + 1;
    printf("%d", k);
    if (s.depth() == 0)
      s.push(k);
    else {
      while (!s.empty() && k > s.top())
         aux.push(s.pop());
      s.push(k);
      while (!aux.empty())
        s.push(aux.pop());
    }
    s.print(" ");
 }
 
 return 0;
}

void inverte(TStack *s) {
  TStack aux1, aux2;

  while (!s->empty())
    aux1.push(s->pop());

  while (!aux1.empty())
    aux2.push(aux1.pop());

  while (!aux2.empty())
    s->push(aux2.pop());
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

void ordena(TStack *s) {
  TStack aux, aux2;
  int temp;

  while (!s->empty()) {
    temp = s->pop();
    if (aux.depth() == 0)
      aux.push(temp);
    else {
      while (!aux.empty() && temp < aux.top())
        aux2.push(aux.pop());
      aux.push(temp);

      while(!aux2.empty())
        aux.push(aux2.pop());
    }
  }

  while (!aux.empty())
    aux2.push(aux.pop());

  while (!aux2.empty())
    s->push(aux2.pop());

}
