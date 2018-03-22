#include <bits/stdc++.h>
using namespace std;

#define MAX 150
#define INF 0x3f3f3f3f

vector<int>adj[MAX];
int cap[MAX][MAX], flow[MAX][MAX];
int level[MAX], startFrom[MAX];

bool bfs(int source, int sink, int n){
    for(int i=0; i<n; i++)
        level[i] = -1;

    queue<int>q;
    q.push(source);
    level[source] = 1;

    while(!q.empty()){
        int from = q.front();
        q.pop();

        for(int i=0; i<adj[from].size(); i++){
            int to = adj[from][i];

            if(level[to]==-1 && cap[from][to] > flow[from][to]){
                level[to] = level[from] + 1;
                if(to==sink)
                    return true;
                q.push(to);
            }
        }
    }

    return false;
}

int dfs(int from, int sink, int bottleneck){
    if(from==sink)
        return bottleneck;

    for(; startFrom[from]<adj[from].size(); startFrom[from]++){
        int to = adj[from][startFrom[from]];

        if(cap[from][to] > flow[from][to] && level[to] == level[from] + 1){
            int value = dfs(to, sink, min(bottleneck, cap[from][to]-flow[from][to]));
            if(value){
                flow[from][to]+=value;
                flow[to][from]-=value;
                return value;
            }
        }
    }

    return 0;
}

int Dinics(int source, int sink, int n){
    int max_flow = 0;

    while(bfs(source, sink, n)){
        for(int i=0; i<n; i++)
            startFrom[i] = 0;
        while(int f = dfs(source,sink,INT_MAX))
            max_flow+=f;
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

        int max_flow = Dinics(source, sink, n);
        printf("Case %d: %d\n",++Case,max_flow);
        reset(n);
    }

    return 0;
}
