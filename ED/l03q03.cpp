/* 

*/
#include "dstack.h"

int main() {
  TStack s, aux, aux2;
  char palavra[20];
  int i;
  
  printf("Digite uma palavra: ");
  scanf("%s", &palavra);
   
  for (i = 0; palavra[i]; i++){
    s.push(palavra[i]);
    aux.push(palavra[i]);
  }

  while (!aux.empty())
    aux2.push(aux.pop());

  
  while (!s.empty()) {
    if (s.top() == aux2.top()) {
      aux.push(aux2.pop());
    }
    aux.push(s.pop());
  }
 
  if (aux2.empty())
    printf("Palindromo\n");
  else
    printf("Nao palindromo\n");

  return 0;
}
