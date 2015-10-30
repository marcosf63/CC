/* Utilizando apenas o TAD Fila, proponha um algoritmo em C/C++ que leia um número inteiro n
e enfileire os n primeiros elementos da sequencia de Fibonacci, onde cada termo (com
exceção dos dois primeiros que possuem valor igual a 1) é determinado pela soma dos dois
termos anteriores. */

#include "sstack.h"

int main() {
  TStack s, fib;
  TKey k;
  int i, n, anterior1, anterior2;

  do {
    printf("Digite o tamanho o tamanho da sequencia de fibonacci: ");
    scanf("%d", &n);
  } while (n < 0);
  
  s.push(1);
  s.push(1);
  
  for (i = 2; i < n; i++) {
    anterior1 = s.pop();
    anterior2 = s.pop();
    k = anterior1 + anterior2;
    s.push(anterior2);
    s.push(anterior1);
    s.push(k);
  }

  while (!s.empty())
    fib.push(s.pop());

  fib.print(" ");

  return 0;
}
