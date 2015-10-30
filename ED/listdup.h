#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define padrao " %d"

#include "stdio.h"
#include "stdlib.h"
#include "celldup.h"

class TList {
  private:
    int s;                       //tamanho atual da lista
    TPos start;                  //inicio da lista
    TPos getpos(int i);          //retorna a ia. posicao da lista
  public:
    TList();                     //construtor
    bool empty();                //retorna V se a lista estiver vazia; e F, caso contrario
    bool full();                 //retorna V se a lista estiver cheia; e F, caso contrario
    void insert(TKey k, int i);  //insere a chave K na ia. posicao da lista
    void remove(int i);          //apaga o elemento da ia. posicao da lista
    TKey getkey(int i);          //retorna a chave da ia. posicao da lista
    void setkey(int i, TKey k);  //altera a chave da ia. posicao da lista para K
    int  indexof(TKey k);        //retorna a ordem da primeira ocorrencia de K na lista. Se K nao esta na lista, retorna 0
    int  size();                 //retorna o tamanho da lista
    void print(char *txt);       //imprime os elementos da lista
};

TList::TList() {
  s = 0;
  start = new TCellDup('#');
}

TPos TList::getpos(int i) {
  TPos p = start;

  while (i > 1 && p->getnext()) {
    p = p->getnext();
    i--;
  }

  return p;
}

bool TList::empty() {
  return s == 0;
}

bool TList::full() {
  return false;
}

void TList::insert(TKey k, int i) {
  TPos p = getpos(i), tmp = new TCellDup(k);

  if (p->getnext()) {
    tmp->setnext(p->getnext());
    tmp->getnext()->setprev(tmp);
  }

  p->setnext(tmp);
  tmp->setprev(p);
  s++;
}

void TList::remove(int i) {
  TPos p, tmp;

  if (i >= 1 && i <= s) {
    p = getpos(i);
    tmp = p->getnext();
    p->setnext(tmp->getnext());

    if (tmp->getnext())
      tmp->getnext()->setprev(p);

    free(tmp);
    s--;
  }
}

TKey TList::getkey(int i) {
  TPos p = getpos(i);

  return p->getnext()->getkey();
}

void TList::setkey(int i, TKey k) {
  TPos p = getpos(i);

  p->getnext()->setkey(k);
}

int  TList::indexof(TKey k) {
  TPos p;
  int i;

  for (i = 1, p = start; i <= s; i++, p = p->getnext())
    if (p->getnext()->getkey() == k)
      return i;

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
    TPos p;

    for (p = start; p->getnext(); p = p->getnext())
      printf(padrao, p->getnext()->getkey());

    printf("\n");
  }
}

#endif
