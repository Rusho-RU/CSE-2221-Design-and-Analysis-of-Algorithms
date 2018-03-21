///Based on lightoj-1153

#include <bits/stdc++.h>
using namespace std;

#define MAX 150

vector<int>adj[MAX];
int rGraph[MAX][MAX];
int parent[MAX];

bool hasPath(int s, int to){
    bool visited[MAX];
    memset(visited, false, sizeof visited);

    queue<int>q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        s = q.front();
        q.pop();

        for(int i=0; i<adj[s].size(); i++){
            int d = adj[s][i];

            if(!visited[d] && rGraph[s][d]>0){
                visited[d] = true;
                parent[d] = s;
                q.push(d);
            }
        }
    }

    return visited[to];
}

int maxFlow(int source, int sink){
    int max_flow = 0;

    while(hasPath(source, sink)){
        int flow = INT_MAX;

        for(int v=sink; v!=source; v=parent[v]){
            int u = parent[v];
            flow = min(flow, rGraph[u][v]);
        }

        for(int v=sink; v!=source; v=parent[v]){
            int u = parent[v];
            rGraph[u][v] -= flow;
            rGraph[v][u] += flow;
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

        int flow = maxFlow(source, sink);
        printf("Case %d: %d\n",++Case,flow);
        reset(n);
    }

    return 0;
}

