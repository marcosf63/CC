#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#define padrao " %d"

#include "stdio.h"
#include "stdlib.h"

#define SIZE_MAX 100

typedef int TKey;

class THeap {
  private:
    int s;                       //tamanho atual da heap
    TKey keys[SIZE_MAX];         //elementos
  public:
    THeap();                     //construtor
    bool empty();                //retorna V ou F caso o heap esateja vazio ou nao
    bool full();                 //retorna V se a heap estiver cheio; e F, caso contrario
    void insert(TKey k);         //insere a chave K no heap
    TKey remove();               //remove e retorna a raiz do heap
    int getpai(int i);           //retorna a posicao do pai de i no vetor
    int getfilhoe(int i);        //retorna a posicao do filho esquerdo
    int getfilhod(int i);        //retorna a posicao do filho direito
    int size();                  //retorna o tamanho
    void print(char *txt);       //imprime os elementos
};

THeap::THeap() {
  s = 0;
}

bool THeap::empty() {
  return s == 0;
}

bool THeap::full() {
  return s == SIZE_MAX;
}

int THeap::size() {
  return s;
}

int THeap::getpai(int i) {
  if (i % 2)
    return i / 2;
  else
    return i / 2 - 1;
}

int THeap::getfilhoe(int i) {
  if (i == 0)
    return 1;
  else
    return i * 2;
}

int THeap::getfilhod(int i) {
  if (i == 0)
    return 2;
  else
    return i * 2 + 1;
}

void THeap::insert(TKey k) {
  TKey aux;
  int j;
  if (!full()) {
    keys[s] = k;
    j = s;
    
    while (j  > 0 && keys[getpai(j)] > keys[j]) {
  
        aux = keys[getpai(j)];
        keys[getpai(j)] = keys[j];
        keys[j] = aux;
	j = getpai(j);
       
    }
    s++;
  }
}

TKey THeap::remove() {
  int j;
  TKey removido = keys[0], aux;
  keys[0] = keys[s - 1]; 
  s--;  
  j = 0;

  while (getfilhoe(j) < s && (keys[getfilhoe(j)] < keys[j] || keys[getfilhod(j)] < keys[j])) {
    if (keys[getfilhoe(j)] < keys[getfilhod(j)]) {
      aux = keys[j];
      keys[j] = keys[getfilhoe(j)];
      keys[getfilhoe(j)] = aux;
      j = getfilhoe(j);
    } else { 
      aux = keys[j];
      keys[j] = keys[getfilhod(j)];
      keys[getfilhod(j)] = aux;
      j = getfilhod(j);
    }
   
  }
  return removido;
}

void THeap::print(char *txt) {
  printf("%s", txt);

  if (empty())
    printf(" Vazio!\n");
  else {
    int i;

    for (i = 0; i < s; i++)
      printf("%d ", keys[i]);

    printf("\n");
  }
}

#endif
