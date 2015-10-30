#include "squeue.h"
#include "time.h"

bool existe_na_fila(TKey k, TQueue *q);

int main() {
  TQueue q, aux;
  TKey k;
  int i, n;
  
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);

  q.print("");
  
  if (existe_na_fila(2, &q))
    printf("OK\n");
  else
    printf("NOK\n");

  q.print("");

  return 0;
}

bool existe_na_fila(TKey k, TQueue *q) {
  TQueue aux;
  bool existe = true; 
  
  q->dequeue();
  q->dequeue();
  q->dequeue();

  q->print("");
  return existe;
}
