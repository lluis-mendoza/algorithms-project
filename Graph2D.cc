#include "Graph2D.h"
#include <cmath>

void Graph2D::createRGG(int n, double r){
  vector<Node*> nodes(n);
  cout << n << endl;
  for(int i = 0; i< n; ++i){
    nodes[i] = new Node;
    nodes[i]->id = i;
    nodes[i]->pos = make_pair((rand()%1000)/1000.0, (rand()%1000)/1000.0);
  }

  for(int i=0; i < n; ++i){
      for(int j=i+1; j < n; ++j){
          cout << distancia(nodes[i],nodes[j]) << endl;
          if(distancia(nodes[i],nodes[j]) < r){
              this->edges.insert(make_pair(nodes[i], nodes[j]));
              nodes[i]->adj.push_back(nodes[j]);
              nodes[j]->adj.push_back(nodes[i]);
          }else{
              cout << "Too far";
          }
          cout << endl;
      }
  }
  this->n = n;
  this->nodes = nodes;
}

void Graph2D::print_graph(){
  cout<<"Nodes: "<<(int)nodes.size() <<endl;
  for(int i = 0; i < (int)nodes.size(); ++i){
    if (nodes[i]->id != -1){
      cout<<'(' << nodes[i]->pos.first << ',' << nodes[i]->pos.second << ')'<<"->";
      bool first = true;
      for(auto node : nodes[i]->adj){
        if (first) first = false;
        else cout<<" ";
        cout<<'(' << node->pos.first << ',' << node->pos.second << ')';
      }
      cout<<endl;
    }
  }
  cout<<"Edges: "<<endl;
  for(auto edge: edges){
    cout<<edge.first->id<<" "<<edge.second->id<<endl;
  }
}

void Graph2D::treure_aresta(set<Edge>::iterator &e){
  auto edge = *e;
  if (edges.find(edge) != edges.end()){
    e = edges.erase(e);
    auto it = find(edge.first->adj.begin(), edge.first->adj.end(), edge.second);
    if (it != edge.first->adj.end()) edge.first->adj.erase(it);
    auto it2 = find(edge.second->adj.begin(), edge.second->adj.end(), edge.first);
    if (it2 != edge.second->adj.end()) edge.second->adj.erase(it2);
  }
}

void Graph2D::treure_node(Node* node){
  auto it = node->adj.begin();
  while(it != node->adj.end()){
    Node* adj = *it;
    auto edge = make_pair(nodes[max(adj->id, node->id)],
nodes[min(adj->id, node->id)]);
    edges.erase(edge);
    it = node->adj.erase(it);
    nodes[adj->id]->adj.remove(node);
  }
  node->id = -1;
  --n;
}

void Graph2D::precolacio_graf_aresta( double q){
  for(auto edge= edges.begin(); edge != edges.end(); ){
    int val = rand()%1000;
    if (q*1000 > val){
      treure_aresta(edge);
    }
    else ++edge;
  }
}

void Graph2D::precolacio_graf_node(double q){
  for(int i = 0;i < (int)nodes.size(); ++i){
    Node* node = nodes[i];
    if (node->id != -1){
      int val = rand()%1000;
      if (q*1000 > val){
        treure_node(node);
      }
    }
  }
}

void Graph2D::DFS(Node* v, vector<bool> &visited){
  visited[v->id] = true;
  for(auto adj : v->adj){
    if (!visited[adj->id]){
      DFS(adj, visited);
    }
  }
}

int Graph2D::numCompConnex(){
  int num = 0;
  int n = nodes.size();
  vector<bool> visited(n, false);
  for(int i = 0; i < n; ++i){
    if (!visited[i] && nodes[i]->id != -1){
      DFS( nodes[i], visited);
      ++num;
    }
  }
  return num;
}

double Graph2D::distancia(Node* a, Node* b){
    const double deltaX = b->pos.first - a->pos.first;
    const double deltaY = b->pos.second - a->pos.second;
    return sqrt((deltaX * deltaX) + (deltaY * deltaY));
}