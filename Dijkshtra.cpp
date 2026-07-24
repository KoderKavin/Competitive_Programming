#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph{
public: 
    int V;
    vector<vector<pair<int,int>>> l;

    Graph (int V){
        V = V;
        l.resize(V);
    }

    void addEdge(int u,int v,int wt){
        l[u].push_back({v,wt});
    }
};

void buildGraph(Graph &g){
    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,7);
    g.addEdge(2,4,3);
    g.addEdge(3,5,1);
    g.addEdge(4,3,2);
    g.addEdge(4,5,5);
}

vector<int> dijkshtra(Graph &g, int src, int V){
    vector<int> dist(V,INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // dist[u], u
    pq.push({src,dist[src]});
    while(!pq.empty()){ 
        int u = pq.top().second;
        for(pair<int,int> edge:g.l[u]){
            int v = edge.first;
            int wt = edge.second;
            dist[v] = min(dist[v],dist[u]+ wt);
            pq.push({dist[v],v});
        }
        pq.pop();
    }

    return dist;
}

int main(){
    int V = 6;
    Graph g(6);
    buildGraph(g);
    vector<int> output = dijkshtra(g,0,V);
    for(int val:output){
        cout<<val<<" ";
    }
    return 0;
}