#include <stdlib.h>
#include <stdio.h>

class Ponto {
  private:
    int x, y;
  public:
    Ponto();
    void imprimir();
    void setX(int n);
    void setY(int n);
    int getX();
    int getY();
};

class PontoClr: Ponto {
  private:
    int c;
  public:
    PontoClr();
    void setCor(int n);
}

Ponto::Ponto() {
  x = y = 0;
}

void Ponto::setX(int n) {
  x = n;
}

void Ponto::setY(int n) {
  y = n;
}

int Ponto::getX() {
  return x;
}

int Ponto::getY() {
  return y;
}



void Ponto::imprimir() {
  printf("Ponto = (%d, %d)\n", x, y);
}

int main() {

  Ponto p;
  p.imprimir();
  p.setX(10);
  p.setY(5);
  p.imprimir();


  return 0;
}
