#include "Graph.h"

void Graph::read_graph(){
  int n;
  cin>>n;
  vector<Node> nodes(n);
  for(int i = 0; i<n; ++i) nodes[i].value = i;
  int v, e;
  while(cin>>v && v != -1){
    cin>>e;
    for(int j = 0; j<e; ++j){
      int adj_node;
      cin>>adj_node;
      nodes[v].adj.push_back(adj_node);
      this->edges.insert(make_pair(max(v, adj_node), min(v, adj_node)));
    }
  }
  this->n = n;
  this->nodes = nodes;
}
void Graph::print_graph(){
  cout<<"Nodes: "<<endl;
  for(int i = 0; i < (int)nodes.size(); ++i){
    if (nodes[i].value != -1){
      cout<<nodes[i].value<<"->";
      bool first = true;
      for(auto node : nodes[i].adj){
        if (first) first = false;
        else cout<<" ";
        cout<<node;
      }
      cout<<endl;
    }
  }
  cout<<"Edges: "<<endl;
  for(auto edge: edges){
    cout<<edge.first<<" "<<edge.second<<endl;
  }
}
void Graph::treure_aresta(pair<int, int> edge){
  edges.erase(edge);
  nodes[edge.first].adj.remove(edge.second);
  nodes[edge.second].adj.remove(edge.first);
}
void Graph::treure_node(int node){
  auto it = nodes[node].adj.begin();
  while(it != nodes[node].adj.end()){
    int adj = *it;
    auto edge = make_pair(max(adj, node), min(adj, node));
    edges.erase(edge);
    it = nodes[node].adj.erase(it);
    nodes[adj].adj.remove(node);
  }
  nodes[node].value = -1;
  --n;
}


void Graph::precolacio_graf_aresta( double q){
  for(auto edge : edges){
    int val = rand()%1000;
    if (q*1000 > val){
      treure_aresta(edge);
    }
    
  }
 } 
void Graph::precolacio_graf_node(double q){
  for(int i = 0;i < (int)nodes.size(); ++i){
    if (nodes[i].value != -1){
      int val = rand()%1000;
      if (q*1000 > val){
        treure_node(i);
      }
    }
  }
}


void Graph::DFS(int v, vector<bool> &visited){
  visited[v] = true;
  for(auto adj : nodes[v].adj){
    if (!visited[adj]){
      DFS(adj, visited);
    }
  }
}


int Graph::numCompConnex(){
  int num = 0;
  int n = nodes.size();
  vector<bool> visited(n, false);
  for(int i = 0; i < n; ++i){
    if (!visited[i] && nodes[i].value != -1){
      DFS( i, visited);
      ++num;
    }
  }
  return num;
}

