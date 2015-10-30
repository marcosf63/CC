#include "sstack.h"
#include "time.h"

bool match(char c1, char c2);

int main() {
  TStack s, aux, aux2;
  char exp[100];
  int i;
  
  printf("Digite uma expressao com {, }, (, ), [, ]: ");
  scanf("%[][{}()]s", &exp);

  for (i = 0; exp[i]; i++)
    aux.push(exp[i]);

  while (!aux.empty())
    printf("%c", aux.pop());
  
  for (i = 0; exp[i]; i++) {
    if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
      s.push(exp[i]);
    else
      if (match(s.top(), exp[i]))
        s.pop();
      else
        break;
  }

  if (s.empty() && !exp[i])
    printf("Expressao balanceada\n");
  else
    printf("Expressao nao balanceada\n");
 
 return 0;
}

bool match (char c1, char c2) {
  return (c1 == '{' && c2 == '}') ||
         (c1 == '[' && c2 == ']') ||
	 (c1 == '(' && c2 == ')');
}
