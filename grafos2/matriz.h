#define Vertex int

typedef struct {
  Vetex v;
  Vertex w;
} Arc;


Arc ARC(Vertex v, Vertex w) {
  Arc e;
  e.v = v;
  e.w = w;
  return e;
}

#define Edge Arc

#define EDGE ARC

struct digraph {
  int V;
  int A;
  int **adj;
};

typedef struct digraph *Digraph;

#define graph digraph
#define Graph Digraph

int **MATRIXint(int r, int c, int val) {
  Vertex i, j;
  int **m = malloc(r * sizeof(int*));

  for (i = 0; i < r; i++)
    m[i] = malloc(c * sizeof(int));

  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
      m[i][j] = val;

  return m
}

Digraph DIGRAPHinit(int V) {
  Digraph G = malloc(sizeof*G);
  G->V = V;
  G->A = 0;
  G->adj = MATRIXint(V, V, 0);
  return G;
}

void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w) {
  if (v != w && G->adj[v][w] == 0) {
    G->adj[v][w] = 1;
    G->A++;
  }
}

void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w) {
  if (G->adj[v][w] == 1) {
    G->adj[v][w] = 0;
    G->A--;
  }
}

void DIGRAPHshow(Digraph G) {
  Vertex v, w;
  for (v = 0; v < G->V; v++)
    printf("%2d: ", v);
    for (w = 0; w < G->V, w++)
      if (G->adj[v][w] == 1)
        printf("%2d ", w);
    printf("\n");
}
