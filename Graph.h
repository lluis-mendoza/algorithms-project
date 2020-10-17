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
  list<int> adj;
};

class Graph{
  private:
    int n;
    vector<Node> nodes;
    set<pair<int, int> > edges;
    void DFS(int node, vector<bool> &visited);
  public:  
    Graph(){}
    void print_graph();
    void read_graph();
    void createNxN(int n);
    void treure_aresta(pair<int, int> edge);
    void treure_node(int node);
    int numCompConnex();
    void precolacio_graf_aresta(double q);
    void precolacio_graf_node(double q);
};

#endif 


