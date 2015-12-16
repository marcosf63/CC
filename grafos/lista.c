struct digraph { int V;
int A;
link *adj; };

typedef struct digraph *Digraph;

typedef struct node *link; 
struct node {
  Vertex w;
  link next; 
};
￼￼￼

link NEW (Vertex w, link next) { 
link p = malloc(sizeof *p);
p–>w = w;
p–>next = next;
return p; }

#define graph digraph
#define Graph Digraph


Digraph DIGRAPHinit (int V) { Vertex v;
Digraph G = malloc(sizeof *G); G–>V = V;
G–>A = 0;
G–>adj = malloc(V * sizeof(link)); for(v=0;v<V;v++)
G–>adj[v] = NULL; return G;
}

void
DIGRAPHinsertA (Digraph G,Vertex v,Vertex w) {
link p;
if (v == w) return;
for (p = G–>adj[v];p != NULL;p = p–>next)
if (p–>w== w) return; G–>adj[v] = NEW(w,G–>adj[v]); G–>A++;
}
￼￼￼

void DIGRAPHshow (Digraph G) { 
  link p; 
  for(v=0;v<G–>V;v++){
     printf("%2d:", v);
     for (p=G–>adj[v];p!= NULL;p=p–>next)
        printf("%2d", p–>w); 
      printf("\n");
    } 
}


static int lbl[maxV], static Vertex parnt[maxV];

int DIGRAPHpath (Digraph G,Vertex s,Vertex t) {
  Vertex v; 
  for(v=0;v<G–>V;v++) {
     lsl[v] = -1;
     parnt[v] = -1;
  }
  parnt[s] = s;
  pathR(G,s)
  
  if (lbl[t] == -1) return 0;
  else return 1;
}

void pathR (Digraph G, Vertex v) {
  link p;
  lbl[v] = 0;

  for ( p = G->adj[v]; p != NULL; p=p->next)
    if (lbl[p->w] == -1) {
       parnt[p->w] = v;
       parhR(G, p->w)
    }

}


