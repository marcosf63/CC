#include "matrix.c"



/*Recebe o tamanho da matrix em r e c, inicializa a matrix
com o valor val e devolve uma matrix alocada*/
int **MATRIXinit(int r, int c, int val);


/*Recebe um inteiro V e devolve uma matriz quadrada de ordem
V alocada e inicializada com 0*/
Digraph DIGRAPHinit(int V);


/*Recebe um Digrafo G e dois vértices v e w e devolve o digrafo
com o arco v-w adicionado.*/
void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w);

/*Recebe um Digrafo G e dois vértices v e w e devolve o digrafo
com o arco v-w removido.*/
void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w);


/*Recebe um digrafo G e imprime na tela os vértices do digrafo
e seus vizinhos, caso existam.*/
void DIGRAPHshow(Digraph G);

/* Função DIGRAPHindeg calcula o grau de entrada um vértice v de um digrafo G */
int DIGRAPHindeg(Vertex v, Digraph G);

/* Função DIGRAPHindeg calcula o grau de saida um vértice v de um digrafo G */
int DIGRAPHoutdeg(Vertex v, Digraph G);

/* Teste a consitencia de um digrafo retorna 0 se tiver lacos, do contrario retorna 1 */
int DIGRAPHconsitencia(Digraph G);

/* Funcao que verifica num digrafo G existe caminho entre s e t*/
int DIGRAPHpath(Digraph G, Vertex s, Vertex t);

/* visita todos os vertices que podem ser atigindos a partir de v*/
void pathR(Digraph G, Vertex v);





