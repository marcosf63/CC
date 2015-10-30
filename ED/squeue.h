#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "stdio.h"
#include "stdlib.h"

#define SIZE_MAX 100

typedef int TKey;

class TQueue {
  private:
    int s;                // Tamanho da fila
    TKey keys[SIZE_MAX];  // Elementos da fila
  public:
    TQueue();             // Construtor
    bool empty();         // Retorna V se a fila estiver vazia; e F, caso contrário
    bool full();          // Retorna V se a fila estiver cheia; e F, caso contrário
    TKey head();          // Retorna o primeiro elemento do fila
    TKey tail();          // Retorna o último elemento da fila
    void enqueue(TKey k); // Enfileira o elemento k na fila
    TKey dequeue();       // Desenfileira um elemento, retornando-o
    int size();           // Retorna o tamanho da fila
    void print(char *s);
};

TQueue::TQueue() {
  s = 0;
}

bool TQueue::empty() {
  return s == 0;
}

bool TQueue::full() {
  return s == SIZE_MAX;
}

TKey TQueue::head() {

}

TKey TQueue::tail() {

}

void TQueue::enqueue(TKey k) {
  if (!full())
    keys[s++] = k;
}

TKey TQueue::dequeue() {

}

int TQueue::size() {
  return s;
}

void TQueue::print(char *s) {
  printf("%s", s);

  if (empty())
    printf(" Vazia!\n");
  else {
    int i;

    for (i = 0; i < size(); i++)
      printf(" %d", keys[i]);

    printf("\n");
  }
}

#endif
