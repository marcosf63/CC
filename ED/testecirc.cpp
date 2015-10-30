#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <listcirc.h>

using namespace std;

int main() {
  int i = 1;
  TList l;

  for (i = 1; i <= 10; i++)
    l.insert(i, i);

  l.print("");

  printf("%d",l.getkey(11));


  return 0;
}
