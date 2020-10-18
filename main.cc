#include <iostream>
#include <unistd.h>
#include <time.h>
#include "Graph.h"

using namespace std;

int main(int argc, char** argv){
  srand((unsigned)time(NULL)%100*getpid());
  if (argc < 3){
    cout<<"Usage: n q"<<endl;
    return -1;
  }
  int n = atoi(argv[1]);
  double q = stod(argv[2]);

  Graph g;
  g.createNxN(n);
  int ant = g.numCompConnex();
  g.precolacio_graf_aresta(q);
  g.precolacio_graf_node(q);
  int act = g.numCompConnex();

  cout<<(ant!=act)<<endl;
  return 0;
}
