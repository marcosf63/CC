#define Vertex int

typedef struct{

  Vertex v;
  Vertex w;
} Arc;

Arc ARC(Vertex v, Vertex w){
  Arc e;

  e.v = v;
  e.w = w;

  return e;
}

#define Edge Arc

#define EDGE ARC

struct digraph{
  int V;
  int A;
  int **adj;
};

typedef struct digraph *Digraph;

#define graph digraph
#define Graph Digraph

int **MATRIXint(int r, int c, int val){
  Vertex i, j;
  int **m = malloc(r * sizeof(int*));
  for (i = 0; i < r; i++)
    m[i] = malloc(c * sizeof(int));
  for(i = 0; i < r; i++)
    for(j = 0; j < c; j++)
      m[i][j] = val;
  return m;
}

Digraph DIGRAPHinit(int V){
  Digraph G = malloc(sizeof*G);
  G->V = V;
  G->A = 0;
  G->adj = MATRIXint(V, V, 0);
  return G;
}

void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w){
  if (v != w && G->adj[v][w] == 0){
    G->adj[v][w] = 1;
    G-> A++;
  }
}

void DIGRAPHshow(Digraph G){
  Vertex v, w;
  for(v = 0; v < G->V; v++){
    printf("%2d:", v);
    for(w = 0; w < G->V; w++)
      if (G->adj[v][w] == 1)
        printf("%2d", w);
    printf("\n");
  }
}


/*A função recebe um Digrafo G e um vértice v e devolve o grau de saída
do vértice v no inteiro grau*/
int DIGRAPHoutdeg(Digraph G, Vertex v){
  Vertex w;
  int grau = 0;

  for(w = 0; w < G->V; w++)
    if (G->adj[v][w] == 1)
      grau++;
  return grau;
}



  

/*A função recebe um Digrafo G e um vértice v e devolve o grau de saída
do vértice v no inteiro grau*/
int DIGRAPHindeg(Digraph G, Vertex v){
  Vertex w;
  int grau = 0;

  for(w = 0; w < G->V; w++)
    if (G->adj[w][v] == 1)
      grau++;
  return grau;
}


int DIGRAPHequal(Digraph G1, Digraph G2){
  Vertex v, w;

  if (G1->V != G2->V)

    return 0;

  if (G1->A != G2->A)
    return 0;

  for(v = 0; v < G1->V; v++)
    for(w = 0; w < G1->V; w++)
      if (G1->adj[v][w] != G2->adj[v][w])
        return 0;

  return 1;
}

//Funcao retorna size(tamanho do caminho) se existe caminho de s a t e caso contrário retorna 0
#define maxV 10000

static int lbl[maxV];
static int size = 0;

int DIGRAPHpath(Digraph G, Vertex s, Vertex t) {
  Vertex v;
  
  for (v = 0; v < G->V; v++)
    lbl[v] = -1;

  pathR(G,s);

  if (lbl[t] == -1) return 0;

  return size;

}

void pathR(Digraph G, Vertex v) {
  Vertex w;
  lbl[v] = 0;
  for (w = 0; w < G->V; w++)
    if(G->adj[v][w] == 1)
      if (lbl[w] == -1) {
        size++;
        pathR(G, w);   
      } else 
         size--;
}

