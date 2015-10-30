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
    void remove();               //remove a raiz do heap
    TKey getpai(int i);          //retorna a chave da ia. posicao da lista
    TKey getfilhoe(int i);  //altera a chave da ia. posicao da lista para K
    TKey getfilhod(int i);     //ia de K na lista. Se K nao esta na lista, retorna 0
    int  size();                 //retorna o tamanho da lista
    void print(char *txt);       //imprime os elementos da lista
};

THeap::Heap() {
  s = 0;
}

bool TList::empty() {
  return s == 0;
}

bool TList::full() {
  return s == SIZE_MAX;
}

void TList::insert(TKey k) {
  int aux;
  if (!full()) {
    k[s] = k;
    j = s;
    while (getpai(s) < k && j!= 0){
      //troca o pai pelo filho
    }    
  
    s++;
  }
}

void TList::remove(int i) {
  if (i >= 1 && i <= s) {
    int j;

    for (j = i - 1; j < s - 1; j++)
      keys[j] = keys[j+1];

    s--;
  }
}

TKey TList::getkey(int i) {
  return keys[i-1];
}

void TList::setkey(int i, TKey k) {
  if (i >= 1 && i <= s)
    keys[i-1] = k;
}

int  TList::indexof(TKey k) {
  int i;

  for (i = 0; i < s; i++)
    if (keys[i] == k)
      return i + 1;

  return 0;
}

int  TList::size() {
  return s;
}

void TList::print(char *txt) {
  printf("%s", txt);

  if (empty())
    printf(" Vazia!\n");
  else {
    int i;

    for (i = 0; i < s; i++)
      printf(padrao, keys[i]);

    printf("\n");
  }
}

#endif
