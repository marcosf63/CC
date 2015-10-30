#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <slist.h>

using namespace std;

int main() {
  int i, n;
  TList ln, ld;

  do {
    printf("Digite o nivel das Fracoes de Farey: ");
    scanf("%d", &n);
  } while (n < 0 || n > 100);

  ln.insert(0, 1);
  ln.insert(1, 2);
  ld.insert(1, 1);
  ld.insert(1, 2);





  return 0;
}
