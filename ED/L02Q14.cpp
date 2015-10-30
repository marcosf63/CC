#include <stdlib.h>
#include <stdio.h>
#include "dlist.h"

int main() {
  int n, i, j;
  TList l;
  bool  pan = true;
  do {
   printf("Digite um numero: ");
   scanf("%d", &n);
  } while (n < 0);
  
  i = 1;
  while (n) {
    l.insert(n % 10, i);
    n = n / 10;
    i++;
  }
 
  for (i = 2; i <= l.size(); i++) {
   for (j = i - 1; j > 0; j--)
     if (l.getkey(i) == l.getkey(j))
       pan = false;
  }

  
  if (pan)
    printf("Pandigita\n");
  else
    printf("Nao pandigital\n");

  return 0;
}
