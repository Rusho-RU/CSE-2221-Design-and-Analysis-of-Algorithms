///Based on lightoj-1153

#include <bits/stdc++.h>
using namespace std;

#define MAX 150

vector<int>adj[MAX];
int rGraph[MAX][MAX];
int parent[MAX];

bool bfs(int source, int sink, int n){
    bool visited[n];
    memset(visited, false, sizeof visited);

    queue<int>q;
    q.push(source);
    visited[source] = true;

    while(!q.empty()){
        int from = q.front();
        q.pop();

        for(int i=0; i<adj[from].size(); i++){
            int to = adj[from][i];

            if(!visited[to] && rGraph[from][to]>0){
                visited[to] = true;
                parent[to] = from;
                q.push(to);
            }
        }
    }

    return visited[sink];
}

int FordFulkerson(int source, int sink, int n){
    int max_flow = 0;

    while(bfs(source, sink, n)){
        int flow = INT_MAX;

        for(int to = sink; to!=source; to = parent[to]){
            int from = parent[to];
            flow = min(flow, rGraph[from][to]);
        }

        for(int to = sink; to!=source; to = parent[to]){
            int from = parent[to];
            rGraph[from][to]-=flow;
            rGraph[to][from]+=flow;
        }

        max_flow += flow;
    }

    return max_flow;
}

void reset(int n){
    for(int i=0; i<n; i++){
        adj[i].clear();
        for(int j=0; j<n; j++)
            rGraph[i][j] = 0;
    }
}

int main(){
    int t, Case=0;
    scanf("%d",&t);

    while(t--){
        int n,m,source, sink;
        scanf("%d%d%d%d",&n,&source,&sink,&m);

        for(int i=0; i<m; i++){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            u--, v--;

            adj[u].push_back(v);
            adj[v].push_back(u);

            rGraph[u][v]+=c;
            rGraph[v][u]+=c;
        }

        source--, sink--;

        int flow = FordFulkerson(source, sink, n);
        printf("Case %d: %d\n",++Case,flow);
        reset(n);
    }

    return 0;
}
