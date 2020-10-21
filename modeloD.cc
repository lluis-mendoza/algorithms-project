#include <iostream>
#include <unistd.h>
#include <time.h>
#include "Graph.h"

using namespace std;

int main(){
  srand((unsigned)time(NULL)%100*getpid());
  int n;
  int num;
  double r;
  cout<<"Numero de nodos:"<<endl;
  cin>>n;
  cout<<"Numero de ejecuciones:"<<endl;
  cin>>num;
  cout<<"Parametro r:"<<endl;
  cin>>r;

  double q = 0;
  while(q <= 1.01){
    double numTotalCompConnex = 0;
    for(int i = 0; i<num; ++i){
      Graph g;
      g.createRGG(n, r);
      g.precolacio_graf_aresta(q);
      numTotalCompConnex += (float)g.numCompConnex()/(n*n);
    }
    cout<<"Probabilidad q = "<<q;
    cout<<" "<<numTotalCompConnex/num<<endl;
    q += 0.05;
  }
  return 0;
}
