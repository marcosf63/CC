/* 

*/
#include "dstack.h"
#include "time.h"

int main() {
  TStack s, zero, um;
  TKey k;
  int i, n;
  
  do {
    printf("Digite um numero de elementos da pilha : ");
    scanf("%d", &n);
  } while (n < 0); 
  
  srand(time(0));
  
  for (i = 0; i < n; i++)
    s.push(rand() % 2);

  while (!s.empty()) {
    k = s.pop();
    if (k)
      um.push(k);
    else
      zero.push(k);
  }
 
  while (!um.empty() && !zero.empty()) {
    um.pop();
    zero.pop();
  }

  um.print("");
  zero.print("");
  
  return 0;
}
