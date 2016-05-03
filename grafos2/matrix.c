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

#define Edge Arc;
#define EDGE ARC;

struct digraph{
  int V;
  int A;
  int **adj;
};

typedef struct digraph *Digraph;


#define graph digraph
#define Graph Digraph

int **MATRIXinit(int r, int c, int val){
  Vertex i, j;
  int **m = malloc(r * sizeof(int *));
  for(i = 0; i < r; i++)
    m[i] = malloc(c * sizeof(int));
  for(i = 0; i < r; i++)
    for(j = 0; j < c; j++)
      m[i][j] = val;
  return m;
}


Digraph DIGRAPHinit(int V){
  Digraph G = malloc(sizeof *G);
  G->V = V;
  G->A = 0;
  G->adj = MATRIXinit(V, V, 0);
  return G;
}

void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w){
  if(v != w && G->adj[v][w] ==0){
    G->adj[v][w] = 1;
    G->A++;
  }
}

void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w){
  if(G->adj[v][w] ==1){
    G->adj[v][w] = 0;
    G->A--;
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

int DIGRAPHindeg(Vertex v, Digraph G) {
  int g = 0;
  Vertex w;

  for (w = 0; w < G->V; w++)
    if (G->adj[w][v] == 1)
      g++;

  return g;
}

int DIGRAPHoutdeg(Vertex v, Digraph G) {
  int g = 0;
  Vertex w;

  for (w = 0; w < G->V; w++)
    if (G->adj[v][w] == 1)
      g++;

  return g;
}

int DIGRAPHconsitencia(Digraph G) {
  Vertex v, w;
  for (v = 0; v < G->V; v++)
    for (w = 0; w < G->V; w++)
      if (v == w && G->adj[v][w] == 1)
        return 0;

  return 1;
}

#define maxV 10000

static int lbl[maxV];

void pathR(Digraph G, Vertex v) {
  Vertex w;
  lbl[v] = 0;
  for (w = 0; w < G->V; w++)
    if (G->adj[v][w] == 1 && lbl[w] == -1)
      pathR(G, w);
}


int DIGRAPHpath(Digraph G, Vertex s, Vertex t) {
  Vertex v;
  for (v = 0; v < G->V; v++)
    lbl[v] = -1;
  pathR(G, s);
  if (lbl[t] == -1) return 0;
  else return 1;
}

void DIGRAPdestroy(Digraph G) {
  Vertex v;
  for (v = 0; v < G->V; v++)
    free(G->adj[v]);
  free(G->adj);
  free(G);
}










