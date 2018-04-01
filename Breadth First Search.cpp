#include <bits/stdc++.h>
using namespace std;

#define NODES 10000

vector<int>adj[NODES];
bool visited[NODES];
int level[NODES];

void bfs(int root){
    queue<int>q;
    q.push(root);
    visited[root] = true;
    level[root] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(!visited[v]){
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    return;
}

int main(){
    int u,v;

    while(scanf("%d%d",&u,&v)==2){
        adj[u].push_back(v);
    }

    memset(visited, false, sizeof visited);

    for(int i=0; i<NODES; i++)
        if(!visited[i])
            bfs(i);

    for(int i=0; i<NODES; i++)
        printf("Level of node %d: %d\n",i,level[i]);
}
