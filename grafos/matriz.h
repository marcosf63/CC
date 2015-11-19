#include "matriz.c"

int **MATRIXint(int r, int c, int val);
Digraph DIGRAPHinit(int V);
void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w);
void DIGRAPHshow(Digraph G);
int DIGRAPHoutdeg(Digraph G, Vertex v);
int DIGRAPHindeg(Digraph G, Vertex v);
int DIGRAPHequal(Digraph G1, Digraph G2);
int DIGRAPHpath(Digraph G, Vertex s, Vertex t);
void pathR(Digraph G, Vertex v);

