#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define padrao " %d"

#include "stdio.h"
#include "stdlib.h"

#define SIZE_MAX 100

typedef int TKey;

class TStack {
  private:
    int d;                 // Profundidade da pilha
    TKey keys[SIZE_MAX];   // Elementos da pilha
  public:
    TStack();              // Construtor da pilha
    bool empty();          // Retorna V se a pilha estiver vazia; e F, caso contrario
    bool full();           // Retorna V se a pilha estiver cheia; e F, caso contrario
    TKey pop();            // Remove o elemento do topo retornando sua chave
    void push(TKey k);     // Empilha a chave k
    TKey top();            // Retorna a chave do elemento do topo
    int depth();           // Retorna a profundidade da pilha
    void print(char *txt); // Imprime os elementos da pilha precedidos do texto em s
};

TStack::TStack() {
  d = 0;
}

bool TStack::empty() {
  return d == 0;
}

bool TStack::full() {
  return d == SIZE_MAX;
}

TKey TStack::pop() {
  if (!empty())
    return keys[--d];
}

void TStack::push(TKey k) {
  if (!full())
    keys[d++] = k;
}

TKey TStack::top() {
  return keys[d-1];
}

int TStack::depth() {
  return d;
}

void TStack::print(char *txt) {
  printf("%s", txt);

  if (empty())
    printf(" Vazia!\n");
  else {
    int i;

    for (i = d - 1; i >= 0; i--)
      printf(padrao, keys[i]);

    printf("\n");
  }
}

#endif
