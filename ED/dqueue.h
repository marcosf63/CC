#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "stdio.h"
#include "stdlib.h"
#include "cell.h"

class TQueue {
  private:
    int s;                // Tamanho da fila
    TPos h, t;            // Cabeça e Cauda da fila
  public:
    TQueue();             // Construtor
    bool empty();         // Retorna V se a fila estiver vazia; e F, caso contrário
    bool full();          // Retorna V se a fila estiver cheia; e F, caso contrário
    TKey head();          // Retorna o 1º elemento do fila
    TKey tail();          // Retorna o último elemento da fila
    void enqueue(TKey k); // Enfileira o elemento k na fila
    TKey dequeue();       // Desenfileira um elemento (retorna o elemento)
    int size();           // Retorna o tamanho da fila
    void print(char *s);
};

TQueue::TQueue() {

}

bool TQueue::empty() {

}

bool TQueue::full() {

}

TKey TQueue::head() {

}

TKey TQueue::tail() {

}

void TQueue::enqueue(TKey k) {

}

TKey TQueue::dequeue() {

}

int TQueue::size() {
  return s;
}

void TQueue::print(char *s) {
  printf("%s", s);

  if(empty())
    printf("vazia!\n");
  else {
    TPos p;

    for (p = h; p; p = p->getnext())
      printf(" %d", p->getkey());

    printf("\n");
  }
}

#endif
