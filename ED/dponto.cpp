//Distancia entre dois potos

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct {
  int x, y;
} Ponto;

int main() {
  Ponto p1, p2;
  float d;

  printf("Digite P1: \n");
  scanf(" (%d,%d)", &p1.x, &p1.y);
  printf("Digite P2: \n");
  scanf(" (%d,%d)", &p2.x, &p2.y);
  
  d = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

  printf("A distancia eh %f\n", d);
  

  return 0;
}
