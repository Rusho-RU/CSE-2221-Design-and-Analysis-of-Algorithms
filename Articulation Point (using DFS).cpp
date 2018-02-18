#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

vector<int>adj[MAX];
int d[MAX], low[MAX], t, parent[MAX];
bool visited[MAX], articulation_point[MAX];

void reset(int n){
    for(int i=0; i<n; i++){
        visited[i] = false;
        articulation_point[i] = false;
        parent[i] = -1;
        adj[i].clear();
    }

    t = 0;
}

void dfs(int u){
    low[u] = d[u] = ++t;
    visited[u] = true;
    int child = 0;

    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];

        if(v == parent[u])
            continue;

        if(visited[v])
            low[u] = min(low[u], d[v]);

        else{
            child++;
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);

            if(parent[u]!=-1 && d[u] <= low[v])
                articulation_point[u] = true;
        }
    }

    if(parent[u] == -1 && child > 1)
        articulation_point[u] = true;
    ++t;
}

int main(){
    int n, e;

    scanf("%d%d",&n,&e);

    reset(n);

    for(int i=0; i<e; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);

    for(int i=0; i<n; i++)
        if(articulation_point[i])
            printf("%d\n",i+1);

    return 0;

}
