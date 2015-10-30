#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#define SIZE_MAX 127

typedef int TNode;
typedef int TKey;

class THeapMin {
  int s;
  TKey nodes[SIZE_MAX];

  public:
    THeapMin();                    // Construtor do heap binario
    bool  empty();                 // Retorna V se o heap estiver vazio; e F, caso contrario
    bool  full();                  // Retorna V se o heap estiver cheio; e F, caso contrario
    int   size();                  // Retorna a qtd. de nós do heap
    TKey  getkey(TNode n);         // Retorna a chave do no n
    void  setkey(TNode n, TKey k); // Altera o valor da chave do no n para k
    TNode getnode(int i);          // Retorna o iº no do heap
    void  insert(TKey k);          // Insere um nó com chave k no heap
    TKey  remove();                // Remove um nó do heap, retornando sua chave
    void  print(char *txt);        // Imprime os elementos do heap por níveis
  private:
    void  heapup(TNode n);         // Sobe o nó no heap o máximo possível
    void  heapdown(TNode n);       // Desce o nó no heap o máximo possível
    TNode parent(TNode n);         // Retorna o nó pai de n, ou -1 caso n seja a raiz
    TNode leftchild(TNode n);      // Retorna o filho esquerdo do nó n
    TNode rightchild(TNode n);     // Retorna o filho direito do nó n
};

THeapMin::THeapMin() {
  s = 0;
}

bool THeapMin::empty() {
  return s == 0;
}

bool THeapMin::full() {
  return s == SIZE_MAX;
}

int  THeapMin::size() {
  return s;
}

TKey THeapMin::getkey(TNode n) {
  return nodes[n];
}

void THeapMin::setkey(TNode n, TKey k) {
  TNode p = parent(n);

  nodes[n] = k;

  if (p != -1 && nodes[p] > nodes[n])
    heapup(n);
  else
    heapdown(n);
}

TNode THeapMin::getnode(int i) {
  return i - 1;
}

void THeapMin::insert(TKey k) {
  if (!full()) {
    nodes[s] = k;
    heapup(s);
    s++;
  }
}

TKey THeapMin::remove() {
  if (!empty()) {
    TKey k = nodes[0];

    nodes[0] = nodes[--s];

    if (!empty())
      heapdown(0);

    return k;
  }
}

void THeapMin::print(char *txt) {
  printf("%s:", txt);

  if (empty())
    printf("Vazia!\n");
  else {
    int i, n = 0, min, max;

    printf("\n");

    while (true) {
      min = (int) pow(2, n) - 1;

      if (min < s) {
        max = 2 * min;

        if (max >= s)
          max = s - 1;

        printf("Nivel %d:", n);

        for (i = min; i <= max; i++)
          printf(" %d", nodes[i]);

        printf("\n");
        n++;
      }
      else
        break;
    }
  }
}

void THeapMin::heapup(TNode n) {
  TNode p = parent(n);
  TKey k;

  while (p != -1 && nodes[p] > nodes[n]) {
    k = nodes[p];
    nodes[p] = nodes[n];
    nodes[n] = k;
    n = p;
    p = parent(n);
  }
}

void THeapMin::heapdown(TNode n) {
  TNode fe, fd, fm;
  TKey k;

  fe = leftchild(n);

  while (fe != -1) {
    fd = rightchild(n);

    if (fd == -1)
      fm = fe;
    else
      fm = (nodes[fe] < nodes[fd])? fe: fd;

    if (nodes[n] > nodes[fm]) {
      k = nodes[fm];
      nodes[fm] = nodes[n];
      nodes[n] = k;
    }

    n = fm;
    fe = leftchild(n);
  }
}

TNode THeapMin::parent(TNode n) {
  return n? (n - 1) / 2: -1;
}

TNode THeapMin::leftchild(TNode n) {
  int filho = 2 * n + 1;

  return filho < s? filho: -1;
}

TNode THeapMin::rightchild(TNode n) {
  int filho = 2 * n + 2;

  return filho < s? filho: -1;
}

#endif
