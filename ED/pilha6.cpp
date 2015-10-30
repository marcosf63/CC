/*
Proponha um algoritmo em C/C++ que leia um número inteiro e positivo n e gere uma pilha com n elementos inteiros, gerados aleatoriamente no intervalo de 1 a 10. Apresente a pilha e em seguida, remova desta os elementos que estãoem duplicidade, descartando sempre os valores que estão mais distantes do topo.
*/
#include "sstack.h"
#include "time.h"

int main() {
  TStack s, aux;
  TKey k;
  int i, n, d;

  do {
    printf("Digite o tamanho da pilha: ");
    scanf("%d", &n);
  } while (n < 0);
  
  srand(time(0));
  
  for (i = 0; i < n; i++)
    s.push(rand() % 10 + 1);
  
  s.print("Lista gerada: ");
  
  for (i = 0; i < n; i++) {
    k = s.pop();
    aux.push(k);
    while (!s.empty() && k != s.top());
      aux.push(s.pop());
    if (!s.empty()){
      s.pop();
      while (!s.empty())
        aux.push(s.pop());
     }
     
  }
  
  while(!aux.empty())
    s.push(aux.pop());

  return 0;
}
