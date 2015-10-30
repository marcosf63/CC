// Ler um número natural e n e gerar uma string correspondente a representação de n em binário
#include "dstack.h"

int main() {
  TStack s;
  int n, i, m;


  do {
    printf("Digite um numero natural: ");
    scanf("%d", &n);
  } while (n < 0);

  m = n;

  while (n) {
    s.push(n % 2);
    n = n / 2;
  }

  char str[s.depth()];
  str[s.depth()] = '\0';
  printf("%d\n", str[5]);
  s.print(" ");
  for (i = 0; str[i]; i++)
    str[i] = '0' + s.pop();

  printf("O numero %d  em binario eh %s ", m, str);

  return 0;
}
