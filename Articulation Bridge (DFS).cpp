#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

vector<int>adj[MAX];
int d[MAX], low[MAX], t, parent[MAX];
bool visited[MAX];
vector<pair<int, int> >bridges;

void reset(int n){
    for(int i=0; i<n; i++){
        visited[i] = false;
        parent[i] = -1;
        adj[i].clear();
    }

    t = 0;
    bridges.clear();
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
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);

            if(d[u] < low[v])
                bridges.push_back(make_pair(u, v));
        }
    }

    ++t;
}

int main(){
    int n, e;

    scanf("%d%d",&n,&e);

    reset(n);

    for(int i=0; i<e; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);

    for(int i=0; i<bridges.size(); i++)
        printf("%d %d\n",bridges[i].first+1, bridges[i].second+1);

    return 0;

}
