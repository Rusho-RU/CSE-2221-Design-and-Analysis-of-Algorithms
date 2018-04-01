#include <bits/stdc++.h>
using namespace std;

#define NODES 10000

vector<int>adj[NODES];
bool visited[NODES];
int d[NODES], f[NODES], T;

void dfs(int u){
    d[u] = ++T;
    visited[u] = true;

    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];

        if(!visited[v])
            dfs(v);
    }

    f[u] = ++T;
}

int main(){
    int u,v;

    while(scanf("%d%d",&u,&v)==2){
        adj[u].push_back(v);
    }

    memset(visited, false, sizeof visited);
    T=0;

    for(int i=0; i<NODES; i++)
        if(!visited[i])
            dfs(i);

    for(int i=0; i<NODES; i++)
        printf("Discover time and Finishing time of node %d: %d and %d\n",i,d[i],f[i]);
}

