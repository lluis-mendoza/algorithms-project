#include <iostream>
#include <unistd.h>
#include <time.h>
#include "Graph2D.h"

using namespace std;

int main(){
  srand((unsigned)time(NULL)%100*getpid());
  int n;
  int r;
  int num;
  char a;
  bool prec_arist = false;
  bool prec_nodos = false;
  cout<<"Numero de nodos:"<<endl;
  cin>>n;
  cout<<"Parámetro r:"<<endl;
  cin>>r;
  Graph2D rgg;
  rgg.createRGG(n,r);
  cout<<"Numero de ejecuciones:"<<endl;
  cin>>num;

  double q = 0;
  while(q <= 1.01){
    double numTotalCompConnex = 0;
    for(int i = 0; i<num; ++i){
      Graph g;
      g.createNxN(n);
      g.precolacio_graf_aresta(q);
      numTotalCompConnex += (float)g.numCompConnex()/(n*n);
    }
    cout<<"Probabilidad q = "<<q;
    cout<<" "<<numTotalCompConnex/num<<endl;
    q += 0.05;
  }
  return 0;
}
