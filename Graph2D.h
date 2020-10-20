#ifndef GRAPH2D_H
#define GRAPH2D_H

#include <iostream>
#include <list>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct Node{
  pair<double,double> pos;
  list<Node*> adj;
  int id;
};

typedef pair<Node*, Node*> Edge;

class Graph2D{
  private:
    int n;
    vector<Node*> nodes;
    set<Edge> edges;
    void DFS(Node* node, vector<bool> &visited);
    void treure_aresta(set<Edge>::iterator &e);
    void treure_node(Node* n);
    double distancia(Node* a, Node* b);
  public:
    void createRGG(int n,double r);
    Graph2D(){}
    void print_graph();
    void read_graph();
    int numCompConnex();
    void precolacio_graf_aresta(double q);
    void precolacio_graf_node(double q);
};

#endif 


