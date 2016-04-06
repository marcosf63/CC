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
