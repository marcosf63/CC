/*
Utilizando os TADs Pilha e/ou fila, proponha um algoritmo em C/C++ que leia um número inteiro positivo n. Em seguida; gere um numero m, com digitos de n, mas dispostos de forma crescente, com exceção do digito 0 que deve sempre aparecer despois de qualquer dígito diferente dele.

Ex.: n = 10502 m = 12500
*/
#include "dstack.h"
#include "math.h"

int main() {
  TStack s, aux, aux2;
  TKey k;
  int n, m, i;

  do {
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);
  } while (n < 0);
  
  printf("Dado numero %d ", n);
  //inserir o numero numa pila

  while (n) {
    k = n % 10;
    if (s.empty() && k != 0)
      s.push(k);
    else {
      if (k == 0)
        aux2.push(k);
      else {
        while (!s.empty() && k < s.top())
	  aux.push(s.pop());
	s.push(k);
	while (!aux.empty())
	  s.push(aux.pop());
      }
    }
    n /= 10;
  }
  
  while(!aux2.empty())
    s.push(aux2.pop());
  
  i = m = 0;
  while (!s.empty()){
    k = s.pop();
    m  = m + k * pow(10,i);
    i++;
  }

  printf(", teremos o numero %d\n", m);

  return 0;
}

