#include "sstack.h"
#include "time.h"

bool valida(c1);

int main() {
  TStack s;
  char exp[100];
  int i;
  expressao_valida = true;
  
  i = 0;
  do {
   printf("Digite uma expressao com o valores 1 2 3 4 5 6 7 8 9 0 + -: "); 
   exp[i] = getc(stdin);
   expressao_valida = valida(exp[i]);
   i++;
  } while (exp != "\n");
  
  return 0;
}

bool match (char c1, char c2) {
  return (c1 == '{' && c2 == '}') ||
         (c1 == '[' && c2 == ']') ||
	 (c1 == '(' && c2 == ')');
}
