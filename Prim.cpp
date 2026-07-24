#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
public: 
    int V;
    vector<vector<pair<int,int>>> l;

    Graph(int val){
        V = val;
        l.resize(val);
    }

    void addEdge(int u,int v,int wt){
        l[u].push_back({v,wt});
        l[v].push_back({u,wt});
    }
};

void buildGraph(Graph &g){
    g.addEdge(0,1,10);
    g.addEdge(1,3,40);
    g.addEdge(0,2,15);
    g.addEdge(0,3,30);
    g.addEdge(2,3,50);
}

int Prim(Graph &g){
    int V = g.V;
    vector<bool> vis(V,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int cost = 0;
    pq.push({0,0});
    vis[0] = true;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(pair<int,int> edge:g.l[u]){
            int v= edge.first;
            int wt = edge.second;
            if(!vis[v]){
                vis[v] = true;
                pq.push({wt,v});
                cost += wt;
                //cout<<v<<endl;
            }
        }
    }
    return cost;
}

int main(){
    Graph g(4);
    buildGraph(g);
    int result = Prim(g);
    cout<<result<<endl;
    return 0;
}