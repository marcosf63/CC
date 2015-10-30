#ifndef LISTA_MF_H_INCLUDED
#define LISTA_MF_H_INCLUDED
#define padrao " %d"

#include "stdio.h"
#include "stdlib.h"
#include "cell.h"

class TListMF {
  private:
    int s;                       //tamanho atual da lista
    TPos start;                  //inicio da lista
  public:
    TListMF();                   //construtor
    void access(TKey k);         //acessa a chave k na lista
    void print(char *txt);       //imprime os elementos da lista
};

TListMF::TListMF() {
  s = 0;
  start = new TCell('#');
}

void TListMF::access(TKey k) {
  TPos tmp, p, q;

  p = start;

  while (p->getnext() && p->getnext()->getkey() != k)
    p = p->getnext();

  if (!p->getnext()) {
    tmp = new TCell(k);
    p->setnext(tmp);
    s++;
  }
  else
    if (p != start) {
      q = p->getnext();
      p->setnext(q->getnext());
      q->setnext(start->getnext());
      start->setnext(q);
    }
}

void TListMF::print(char *txt) {
  printf("%s", txt);

  if (s == 0)
    printf(" Vazia!\n");
  else {
    TPos p;

    for (p = start; p->getnext(); p = p->getnext())
      printf(padrao, p->getnext()->getkey());

    printf("\n");
  }
}

#endif
