#include <stdio.h>

int main() {

  FILE *arq;
  char *s, ch;
  int num = 0;

  s = "grafo.txt";

  arq = fopen(s, "r");
  
 while ( (ch = fgetc(arq)) != EOF )
  if(ch == '\n')
    num++;
  
 printf("%d\n", num);

 fclose(arq);

  return 0;
}
