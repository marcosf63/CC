#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED
#define padrao " %d"

#include "stdio.h"
#include "stdlib.h"
#include "celldup.h"

#define SIZE_MAX 100

typedef int TKey;

class TDeque{
  private:
    int s;                 //tamanho atual da fila
    TPos l, r;             //esquerda e direita
  public:
    TDeque();              // Construtor
    bool empty();          // Retorna V se a fila estiver vazia; e F, caso contrário
    bool full();           // Retorna V se a fila estiver cheia; e F, caso contrário
    TKey left();           // Retorna o elemento da esquerda da fila
    TKey right();          // Retorna o elemento da direita  da fila
    void enqueuel(TKey k); // Enfileira o elemento k na esquerda da fila
    void enqueuer(TKey k); // Enfileira o elemento k na direita  da fila
    TKey dequeuel();       // Desenfileira elemento da esquerda (retorna o elemento)
    TKey dequeuer();       // Desenfileira elemento da direita  (retorna o elemento)
    int size();            // Retorna o tamanho da fila
    void print(char *txt); // Imprime os elementos da fila precedidos do texto txt
};

TDeque::TDeque(){
  s = 0;
}

bool TDeque::empty(){
  return s == 0;
}

bool TDeque::full(){

}

TKey TDeque::left(){
  return l->getkey();
}

TKey TDeque::right(){
  return r->getkey();
}

void TDeque::enqueuel(TKey k) {

}

void TDeque::enqueuer(TKey k) {
  if (!full()) {
    TPos tmp = new TCellDup(k);

    if (empty())
      l = tmp;
    else {
      tmp->setprev(r);
      r->setnext(tmp);
    }

    r = tmp;
    s++;
  }
}

TKey TDeque::dequeuel() {
  if (!empty()) {
    TPos tmp = l;
    TKey k = tmp->getkey();

    l = tmp->getnext();

    if (l != NULL)
      l->setprev(NULL);
    else
      r = NULL;

    free(tmp);
    s--;
    return k;
  }
}

TKey TDeque::dequeuer() {

}

int TDeque::size() {
  return s;
}

void TDeque::print(char *txt) {
  printf("%s", txt);

  if (empty())
    printf(" Vazia!\n");
  else {
    TPos p;

    for (p = l; p; p = p->getnext())
      printf(padrao, p->getkey());

    printf("\n");
  }
}

#endif
