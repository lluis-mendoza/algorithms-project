#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct Node{
  int value;
  list<Node*> adj;
};

typedef pair<Node*, Node*> Edge;

class Graph{
  private:
    int n;
    vector<Node*> nodes;
    set<Edge> edges;
    void DFS(Node* node, vector<bool> &visited);
    void treure_aresta(set<Edge>::iterator &e);
    void treure_node(Node* n);
  public:  
    Graph(){}
    void print_graph();
    void read_graph();
    void createNxN(int n);
    int numCompConnex();
    void precolacio_graf_aresta(double q);
    void precolacio_graf_node(double q);
};

#endif 


