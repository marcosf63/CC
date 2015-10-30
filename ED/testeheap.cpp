#include "sheap.h"
#include "time.h"


int main () {
  int i, k;
  THeapMin h;

  //insere valores
  h.insert(2);
  h.insert(3);
  h.insert(5);
  h.insert(4);
  h.insert(6);
  h.insert(7);
  h.print(" ");
  getchar();
  h.insert(1);
  h.print(" ");
  getchar();
  h.remove();
  h.print(" ");
  //h.remove();
  //h.print(" ");
  return 0;
}
