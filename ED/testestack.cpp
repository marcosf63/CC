#include "dstack.h"
#include "time.h"

void inverte(TStack *s); //Inverter a pilha
bool existe(TKey k, TStack *s); //Retorna V se K exite na pilha F, caso contrario
void ordena(TStack *s); //Ordena a pilha crescente

int main() {
  TStack s, s2;
  TKey k;
  int i, n = 10;

  srand(time(0));

  for (i = 0; i < n; i++) {
    k = rand() % 10 + 1;
    s.push(k);
    printf("%d ", k);
    s.print(" ");
  }

  printf("pop %d\n", s.pop());
  s.print(" ");

  printf("top %d\n", s.top());
 // s.print(" ");

  printf("A pilha s tah vazia(V ou F)? %s\n", s.empty() ? "V" : "F");
  printf("A pilha s2 tah vazia(V ou F)? %s\n", s2.empty() ? "V" : "F");

  printf("O tamanho da pila eh %d\n", s.depth());
  
  
  s.print("Pilha normal    :");
  inverte(&s);
  s.print("Pilha invertida :");

  int numero = 18;
  printf("O numero %d esta na pilha? %s \n", numero, existe(numero, &s) ? "SIM" : "NAO");

  s.print(" ");

 ordena(&s);
 //inverte(&s);

 s.print("Pilha ordenada: ");
 
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
