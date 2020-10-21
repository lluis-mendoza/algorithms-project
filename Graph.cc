#include "Graph.h"

void Graph::createNxN(int n){
  vector<Node*> nodes(n*n);
  for(int i = 0; i< n*n; ++i){
    nodes[i] = new Node;
    nodes[i]->value = i;
    
  }
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if (j > 0){
        nodes[i*n+j]->adj.push_back(nodes[i*n+(j-1)]);
        this->edges.insert(make_pair(nodes[i*n+j], nodes[i*n+(j-1)]));
      }
      if (j < n-1){
        nodes[i*n+j]->adj.push_back(nodes[i*n+(j+1)]);
      }
      if (i > 0){
        nodes[i*n+j]->adj.push_back(nodes[(i-1)*n+j]);
        this->edges.insert(make_pair(nodes[i*n+j], nodes[(i-1)*n+j]));
      }
      if (i < n-1){
        nodes[i*n+j]->adj.push_back(nodes[(i+1)*n+j]);
      }
    }
  }
  this->n = n*n;
  this->nodes = nodes;
}

void Graph::createRGG(int n, double r){
  vector<Node*> nodes(n);
  vector<Pos> pos(n);
  for(int i = 0; i< n; ++i){
    nodes[i] = new Node;
    nodes[i]->value = i;
    pos[i] = make_pair((rand()%1000)/1000.0, (rand()%1000)/1000.0);
  }

  for(int i=0; i < n; ++i){
      for(int j=i+1; j < n; ++j){
          if(distancia(pos[i],pos[j]) < r){
              this->edges.insert(make_pair(nodes[i], nodes[j]));
              nodes[i]->adj.push_back(nodes[j]);
              nodes[j]->adj.push_back(nodes[i]);
          }
      }
  }
  this->n = n;
  this->nodes = nodes;
}
double Graph::distancia(Pos a, Pos b){
  double deltaX = a.first - b.first;
  double deltaY = a.second - b.second;
  return sqrt((deltaX*deltaX) + (deltaY*deltaY));
}

void Graph::read_graph(){
  int n;
  cin>>n;
  vector<Node*> nodes(n);
  for(int i = 0; i<n; ++i) nodes[i]->value = i;
  int v, e;
  while(cin>>v && v != -1){
    cin>>e;
    for(int j = 0; j<e; ++j){
      int adj_node;
      cin>>adj_node;
      nodes[v]->adj.push_back(nodes[adj_node]);
      this->edges.insert(make_pair(nodes[max(v, adj_node)], nodes[min(v, adj_node)]));
    }
  }
  this->n = n;
  this->nodes = nodes;
}

void Graph::print_graph(){
  cout<<"Nodes: "<<endl;
  for(int i = 0; i < (int)nodes.size(); ++i){
    if (nodes[i]->value != -1){
      cout<<nodes[i]->value<<"->";
      bool first = true;
      for(auto node : nodes[i]->adj){
        if (first) first = false;
        else cout<<" ";
        cout<<node->value;
      }
      cout<<endl;
    }
  }
  cout<<"Edges: "<<endl;
  for(auto edge: edges){
    cout<<edge.first->value<<" "<<edge.second->value<<endl;
  }
}

void Graph::treure_aresta(set<Edge>::iterator &e){
  auto edge = *e;
  if (edges.find(edge) != edges.end()){
    e = edges.erase(e);
    auto it = find(edge.first->adj.begin(), edge.first->adj.end(), edge.second);
    if (it != edge.first->adj.end()) edge.first->adj.erase(it);
    auto it2 = find(edge.second->adj.begin(), edge.second->adj.end(), edge.first);
    if (it2 != edge.second->adj.end()) edge.second->adj.erase(it2);
  }
}

void Graph::treure_node(Node* node){
  auto it = node->adj.begin();
  while(it != node->adj.end()){
    Node* adj = *it;
    auto edge = make_pair(nodes[max(adj->value, node->value)],
nodes[min(adj->value, node->value)]);
    edges.erase(edge);
    it = node->adj.erase(it);
    nodes[adj->value]->adj.remove(node);
  }
  node->value = -1;
  --n;
}

void Graph::precolacio_graf_aresta( double q){
  for(auto edge= edges.begin(); edge != edges.end(); ){
    int val = rand()%1000;
    if (q*1000 > val){
      treure_aresta(edge);
    }
    else ++edge;
  }
}

void Graph::precolacio_graf_node(double q){
  for(int i = 0;i < (int)nodes.size(); ++i){
    Node* node = nodes[i];
    if (node->value != -1){
      int val = rand()%1000;
      if (q*1000 > val){
        treure_node(node);
      }
    }
  }
}

void Graph::DFS(Node* v, vector<bool> &visited){
  visited[v->value] = true;
  for(auto adj : v->adj){
    if (!visited[adj->value]){
      DFS(adj, visited);
    }
  }
}

int Graph::numCompConnex(){
  int num = 0;
  int n = nodes.size();
  vector<bool> visited(n, false);
  for(int i = 0; i < n; ++i){
    if (!visited[i] && nodes[i]->value != -1){
      DFS( nodes[i], visited);
      ++num;
    }
  }
  return num;
}
