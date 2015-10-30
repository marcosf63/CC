#ifndef CELLCNT_H_INCLUDED
#define CELLCNT_H_INCLUDED

typedef class TCellCnt *TPos;
typedef int TKey;

class TCellCnt {
  private:
    TKey key;              // Chave da célula
    int  count;            // Contador
    TPos next;             // Apontador para a próxima celula
  public:
    TCellCnt(TKey k);      // Cria uma nova celula com chave k, contador 1 e apontando para NULL
    TKey getkey();         // Retorna o valor da propriedade key
    TPos getnext();        // Retorna o valor da propriedade next
    int  getcount();       // Retorna o valor da propriedade count
    void setkey(TKey k);   // Altera o valor da propriedade key para k
    void setnext(TPos p);  // Altera o valor da propriedade next para p
    void setcount(int n);  // Altera o valor da propriedade count para n
};

TCellCnt::TCellCnt(TKey k){
  key   = k;
  next  = NULL;
  count = 1;
}

TKey TCellCnt::getkey(){
  return key;
}

TPos TCellCnt::getnext(){
  return next;
}

int  TCellCnt::getcount(){
  return count;
}

void TCellCnt::setkey(TKey k){
  key = k;
}

void TCellCnt::setnext(TPos p){
  next = p;
}

void TCellCnt::setcount(int n){
  count = n;
}

#endif
