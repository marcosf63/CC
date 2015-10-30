#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main() {
  int n1, n2, m = 0, i, j;

    
  printf("Digite o primeiro numero: \n");
  scanf("%d", &n1);
  
  printf("Digite o segundo numero: \n");
  scanf("%d", &n2);
  
  for (i = 0; i < n1; i++)
    m = m + n2;

  printf("%d X %d = %d\n", n1, n2, m);

  return 0;
}
