void DIGRAPHlisttomatrix (Digraph G) {
  Digraph G;
  link p;

  DIGRAPHinit(G->V);

  for(v=0;v<G–>V;v++){
     for (p=G–>adj[v];p!= NULL;p=p–>next)
        DIGRAPHinsertA(v, p–>w); 
  } 
}