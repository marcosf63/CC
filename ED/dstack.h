#ifndef STACK_INCLUDED
#define STACK_INCLUDED
#define padrao " %d"

#include "stdio.h"
#include "stdlib.h"
#include "cell.h"

class TStack {
  private:
    int d;                 // Profundidade da pilha
    TPos start;            // Ponteiro para o topo da pilha
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
  start = NULL;
}

bool TStack::empty() {
  return d == 0;
}

bool TStack::full() {
  TPos tmp = new TCell(0);
  bool cheia;

  cheia = !tmp;
  free(tmp);
  return cheia;
}

TKey TStack::pop() {
  if (!empty()) {
    TPos tmp = start;
    TKey k = top();

    start = tmp->getnext();
    free(tmp);
    d--;
    return k;
  }
}

void TStack::push(TKey k) {
  if (!full()) {
    TPos tmp = new TCell(k);

    tmp->setnext(start);
    start = tmp;
    d++;
  }
}

TKey TStack::top() {
  if (!empty())
    return start->getkey();
}

int TStack::depth() {
  return d;
}

void TStack::print(char *txt) {
  printf("%s", txt);

  if (empty())
    printf(" Vazia!\n");
  else {
    TPos p;

    for (p = start; p; p = p->getnext())
      printf(padrao, p->getkey());

    printf("\n");
  }
}

#endif
