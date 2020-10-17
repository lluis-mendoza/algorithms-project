#include <iostream>
#include <time.h>
#include "Graph.h"

using namespace std;

int main(int argc, char** argv){
   srand(time(NULL));
    
    Graph g;
    //g.read_graph();
    g.createNxN(3);
    //g.print_graph();
    cout<<"Num connex components = "<<g.numCompConnex()<<endl;
    double q;
    cin>>q;
    cout<<endl;
    cout<<"Q = "<<q<<endl;
    cout<<endl;
    g.precolacio_graf_aresta(q);
    g.precolacio_graf_node(q);
    //g.print_graph();
    cout<<"Num connex components = "<<g.numCompConnex()<<endl;
    return 0;
}
