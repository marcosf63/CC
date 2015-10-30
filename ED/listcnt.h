#ifndef LISTACNT_H_INCLUDED
#define LISTACNT_H_INCLUDED
#define padrao " %d (%d)"

#include "stdio.h"
#include "stdlib.h"
#include "cellcnt.h"

class TListCnt {
  private:
    int s;                       //tamanho atual da lista
    TPos start;                  //inicio da lista
  public:
    TListCnt();                  //construtor
    void access(TKey k);         //acessa a chave k na lista
    void print(char *txt);       //imprime os elementos da lista
};

TListCnt::TListCnt() {
  s = 0;
  start = new TCellCnt('#');
}

void TListCnt::access(TKey k) {
  TPos p = start, tmp;

  while (p->getnext() && p->getnext()->getkey() != k)
    p = p->getnext();

  if (!p->getnext()) { //Elemento não está na lista
    tmp = new TCellCnt(k);
    p->setnext(tmp);
    s++;
  }
  else {
    tmp = p->getnext();
    tmp->setcount(tmp->getcount() + 1);

    if (tmp->getcount() >= p->getcount()) {
      p->setnext(tmp->getnext());
      p = start;

      while (p->getnext() && p->getnext()->getcount() > tmp->getcount())
        p = p->getnext();

      tmp->setnext(p->getnext());
      p->setnext(tmp);
    }
  }
}

void TListCnt::print(char *txt) {
  printf("%s", txt);

  if (s == 0)
    printf(" Vazia!\n");
  else {
    TPos p;

    for (p = start; p->getnext(); p = p->getnext())
      printf(padrao, p->getnext()->getkey(), p->getnext()->getcount());

    printf("\n");
  }
}

#endif
