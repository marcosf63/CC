#ifndef CELLCNT_H_INCLUDED
#define CELLCNT_H_INCLUDED

typedef class TCellDup *TPos;
typedef int TKey;

class TCellDup {
  private:
    TKey key;             // Chave da célula
    TPos next;            // Apontador para a próxima celula
    TPos prev;
  public:
    TCellDup(TKey k);     // Cria uma nova celula com chave k apontando para NULL
    TKey getkey();        // Retorna o valor da propriedade key
    TPos getnext();       // Retorna o valor da propriedade next
    TPos getprev();       // Retorna o valor da propriedade prev
    void setkey(TKey k);  // Altera o valor da propriedade key para k
    void setnext(TPos p); // Altera o valor da propriedade next para p
    void setprev(TPos p); // Altera o valor da propriedade prev para p
};

TCellDup::TCellDup(TKey k){
  key  = k;
  next = prev = NULL;
}

TKey TCellDup::getkey(){
  return key;
}

TPos TCellDup::getnext(){
  return next;
}

TPos TCellDup::getprev(){
  return prev;
}

void TCellDup::setkey(TKey k){
  key = k;
}

void TCellDup::setnext(TPos p){
  next = p;
}

void TCellDup::setprev(TPos p){
  prev = p;
}

#endif
