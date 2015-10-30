#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED
#define padrao " %d"

#include "stdio.h"
#include "stdlib.h"

#define SIZE_MAX 100

typedef int TKey;

class TDeque{
  private:
    int s;                 //tamanho atual da fila
    TKey keys[SIZE_MAX];   //elementos
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
  return s == SIZE_MAX;
}

TKey TDeque::left(){
  return keys[0];
}

TKey TDeque::right(){
  return keys[s-1];
}

void TDeque::enqueuel(TKey k) {
  if (!full()) {
    int i;

    for (i = s; i > 0; i--)
      keys[i] = keys[i-1];

    keys[0] = k;
    s++;
  }
}

void TDeque::enqueuer(TKey k) {
  if (!full())
    keys[s++] = k;
}

TKey TDeque::dequeuel() {
  if (!empty()) {
    int i;
    TKey k = left();

    for (i = 0; i < s - 1; i++)
      keys[i] = keys[i+1];

    s--;
    return k;
  }
}

TKey TDeque::dequeuer() {
  if (!empty())
    return keys[--s];
}

int TDeque::size() {
  return s;
}

void TDeque::print(char *txt) {
  printf("%s", txt);

  if(empty())
    printf("vazia!\n");
  else {
    int i;

    for (i = 0; i < size(); i++)
      printf(padrao, keys[i]);

    printf("\n");
  }
}

#endif
