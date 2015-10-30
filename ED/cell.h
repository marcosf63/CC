#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

typedef class TCell *TPos;
typedef int TKey;

class TCell {
  private:
    TKey key;             // Chave da célula
    TPos next;            // Apontador para a próxima celula
  public:
    TCell();              // Cria uma nova celula
    TCell(TKey k);        // Cria uma nova celula com chave k apontando para NULL
    TKey getkey();        // Retorna o valor da propriedade key
    TPos getnext();       // Retorna o valor da propriedade next
    void setkey(TKey k);  // Altera o valor da propriedade key para k
    void setnext(TPos p); // Altera o valor da propriedade next para p
};

TCell::TCell(){
  next = NULL;
}

TCell::TCell(TKey k){
  key  = k;
  next = NULL;
}

TKey TCell::getkey(){
  return key;
}

TPos TCell::getnext(){
  return next;
}

void TCell::setkey(TKey k){
  key = k;
}

void TCell::setnext(TPos p){
  next = p;
}

#endif
