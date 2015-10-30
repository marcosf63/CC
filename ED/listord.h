#ifndef LISTA_ORD_H_INCLUDED
#define LISTA_ORD_H_INCLUDED
#define padrao " %d"

#include "stdio.h"
#include "stdlib.h"
#include "cell.h"

class TListOrd {
  private:
    int s;                       //tamanho atual da lista
    TPos start;                  //inicio da lista
  public:
    TListOrd();                  //construtor
    void access(TKey k);         //acessa a chave k na lista
    void print(char *txt);       //imprime os elementos da lista
};

TListOrd::TListOrd() {
  s = 0;
  start = new TCell('#');
}

void TListOrd::access(TKey k) {
  TPos tmp, p;

  p = start;

  while (p->getnext() && p->getnext()->getkey() < k)
    p = p->getnext();

  if (!p->getnext() || p->getnext()->getkey() > k) {
    tmp = new TCell(k);
    tmp->setnext(p->getnext());
    p->setnext(tmp);
    s++;
  }
}

void TListOrd::print(char *txt) {
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
