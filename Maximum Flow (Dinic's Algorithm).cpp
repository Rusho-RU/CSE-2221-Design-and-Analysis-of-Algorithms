#include <bits/stdc++.h>
using namespace std;

#define MAX 150
#define INF 0x3f3f3f3f

vector<int>adj[MAX];
int cap[MAX][MAX], flow[MAX][MAX];
int level[MAX];
int start[MAX];

bool hasPath(int source, int sink){
    memset(level, 0, sizeof level);
    queue<int>q;
    q.push(source);
    level[source] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(cap[u][v] > flow[u][v] || flow[u][v] > 0 && !level[v]){
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    return level[sink];
}

int dfs(int u, int sink, int bottleneck){
    if(u==sink)
        return bottleneck;

    for(; start[u]<adj[u].size(); start[u]++){
        int v = adj[u][start[u]];
        if(cap[u][v] > flow[u][v] && level[v]==level[u]+1){
            int value = dfs(v, sink, min(cap[u][v], bottleneck));
            flow[u][v]+=value;
            flow[v][u]-=value;
            if(value)
                return value;
        }
    }

    return 0;
}

int maxFlow(int source, int sink){
    int max_flow = 0;

    while(hasPath(source, sink)){
        memset(start, 0, sizeof start);
        max_flow+=dfs(source, sink, INF);
    }

    return max_flow;
}

void reset(int n){
    for(int i=0; i<n; i++){
        adj[i].clear();
        for(int j=0; j<n; j++){
            cap[i][j] = 0;
            flow[i][j] = 0;
        }
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

            cap[u][v]+=c;
            cap[v][u]+=c;
        }

        source--, sink--;

        int max_flow = maxFlow(source, sink);
        printf("Case %d: %d\n",++Case,max_flow);
        reset(n);
    }

    return 0;
}
