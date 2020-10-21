#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

struct Node{
  int value;
  list<Node*> adj;
};

typedef pair<Node*, Node*> Edge;
typedef pair<double, double> Pos;

class Graph{
  private:
    int n;
    vector<Node*> nodes;
    set<Edge> edges;
    void DFS(Node* node, vector<bool> &visited);
    void treure_aresta(set<Edge>::iterator &e);
    void treure_node(Node* n);
    double distancia(Pos a, Pos b);
  public:  
    Graph(){}
    void print_graph();
    void read_graph();
    void createNxN(int n);
    void createRGG(int n, double r);
    int numCompConnex();
    void precolacio_graf_aresta(double q);
    void precolacio_graf_node(double q);
};

#endif 


