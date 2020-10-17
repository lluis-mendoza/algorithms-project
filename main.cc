#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stdlib.h>
#include <set>
#include <utility>
#include <time.h>

using namespace std;

struct Node{
  int value;
  list<int> adj;
};
struct Graph{
  int n;
  vector<Node> nodes;
  set<pair<int, int> > edges;
};

Graph read_graph(){
  Graph g;
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
      g.edges.insert(make_pair(max(v, adj_node), min(v, adj_node)));
    }
  }
  g.n = n;
  g.nodes = nodes;
  return g;
}
void print_graph(const Graph &g){
  cout<<"Nodes: "<<endl;
  for(int i = 0; i < (int)g.nodes.size(); ++i){
    if (g.nodes[i].value != -1){
      cout<<g.nodes[i].value<<"->";
      bool first = true;
      for(auto node : g.nodes[i].adj){
        if (first) first = false;
        else cout<<" ";
        cout<<node;
      }
      cout<<endl;
    }
  }
  cout<<"Edges: "<<endl;
  for(auto edge: g.edges){
    cout<<edge.first<<" "<<edge.second<<endl;
  }
}

void treure_aresta(Graph &g, pair<int, int> edge){
  g.edges.erase(edge);
  g.nodes[edge.first].adj.remove(edge.second);
  g.nodes[edge.second].adj.remove(edge.first);
}
void treure_node(Graph &g, int node){
  auto it = g.nodes[node].adj.begin();
  while(it != g.nodes[node].adj.end()){
    int adj = *it;
    auto edge = make_pair(max(adj, node), min(adj, node));
    g.edges.erase(edge);
    it = g.nodes[node].adj.erase(it);
    g.nodes[adj].adj.remove(node);
  }
  g.nodes[node].value = -1;
  --g.n;
}

void precolacio_graf(Graph &g, double q, bool nodos, bool aristas){
  if (aristas){
    for(auto edge : g.edges){
      int val = rand()%1000;
      if (q*1000 > val){
        treure_aresta(g, edge);
      }
      
    }
  }
  if (nodos){
    for(int i = 0;i < (int)g.nodes.size(); ++i){
      if (g.nodes[i].value != -1){
        int val = rand()%1000;
        if (q*1000 > val){
          treure_node(g, i);
        }
      }
    }
  }
}

int main(int argc, char** argv){
   srand(time(NULL));
    
    Graph g = read_graph();
    print_graph(g);
    double q;
    cin>>q;
    cout<<endl;
    cout<<"Q = "<<q<<endl;
    cout<<endl;
    precolacio_graf(g, q,true,true);
    print_graph(g);
    return 0;
}
