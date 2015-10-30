#ifndef LISTA_TR_H_INCLUDED
#define LISTA_TR_H_INCLUDED
#define padrao " %d"

#include "stdio.h"
#include "stdlib.h"
#include "cell.h"

class TListTr {
  private:
    int s;                       //tamanho atual da lista
    TPos start;                  //inicio da lista
  public:
    TListTr();                   //construtor
    void access(TKey k);         //acessa a chave k na lista
    void print(char *txt);       //imprime os elementos da lista
};

TListTr::TListTr() {
  s = 0;
  start = new TCell('#');
}

void TListTr::access(TKey k) {
  TPos p, q, tmp;

  p = q = start;

  while (p->getnext() && p->getnext()->getkey() != k) {
    if (p != start)
      q = p;  //q = p->getnext()

    p = p->getnext();
  }

  if (!p->getnext()) { //Elemento não está na lista
    tmp = new TCell(k);
    p->setnext(tmp);
    s++;
  }
  else
    if (p != start){
      tmp = p->getnext();
      p->setnext(tmp->getnext());
      tmp->setnext(p);
      q->setnext(tmp);
    }
}

void TListTr::print(char *txt) {
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
