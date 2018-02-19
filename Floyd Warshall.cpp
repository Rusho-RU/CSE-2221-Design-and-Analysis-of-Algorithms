#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define INF 0x3f3f3f3f

int adj[MAX][MAX];

void FloydWarshall(int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            if(i==k)
                continue;
            for(int j=0; j<n; j++){
                if(j==k || j==i)
                    continue;
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",adj[i][j]);
        }
        puts("");
    }

    return;
}

int main(){
    int node, edge;
    scanf("%d%d",&node,&edge);

    memset(adj, INF, sizeof adj);

    while(edge--){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        adj[u][v] = c;
    }

    FloydWarshall(node);
    return 0;
}
