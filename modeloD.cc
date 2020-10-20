#include <iostream>
#include <unistd.h>
#include <time.h>
#include "Graph2D.h"

using namespace std;

int main(){
  srand((unsigned)time(NULL)%100*getpid());
  int n;
  int num;
  char a;
  bool prec_arist = false;
  bool prec_nodos = false;
  cout<<"Numero de nodos:"<<endl;
  cin>>n;
  Graph2D rgg;
  rgg.createRGG(n,0.2);
  rgg.print_graph();

  cout<<"Numero de ejecuciones:"<<endl;
  cin>>num;
  cout<<"Precolacion de aristas? (S/N)"<<endl;
  cin>>a;
  prec_arist = (a=='S'||a=='s');
  cout<<"Precolacion de nodos? (S/N)"<<endl;
  cin>>a;
  prec_nodos = (a=='S'||a=='s');

  double q = 0;
  while(q <= 1.01){
    double numTotalCompConnex = 0;
    for(int i = 0; i<num; ++i){
      Graph g;
      g.createNxN(n);
      if (prec_arist) g.precolacio_graf_aresta(q);
      if (prec_nodos) g.precolacio_graf_node(q);
      numTotalCompConnex += (float)g.numCompConnex()/(n*n);
    }
    cout<<"Probabilidad q = "<<q;
    cout<<" "<<numTotalCompConnex/num<<endl;
    q += 0.05;
  }
  return 0;
}
