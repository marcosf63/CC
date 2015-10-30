#include "dstack.h"

int main() {
  TStack s;
  int i, n, m;
  
  do {
    printf("Digite um numero interio positivo : ");
    scanf("%d", &n);
  } while (n < 0); 
  
  m = n;

  while (n) {
    s.push(n % 2);
    n = n / 2;
  }
  
  printf("O numero %d na base2 eh :", m);
  s.print("");
  return 0;
}
