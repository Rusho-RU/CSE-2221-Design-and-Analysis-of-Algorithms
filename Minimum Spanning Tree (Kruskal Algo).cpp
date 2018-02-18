#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

struct Edge{
    int u,v,cost;

    Edge(int a, int b, int c) : u(a), v(b), cost(c){}

    bool operator<(const Edge& a)const{
        return cost<a.cost;
    }
};

vector<Edge>edge;
vector<Edge>path;
int parent[MAX];

void reset(){
    for(int i=0; i<MAX; i++)
        parent[i] = i;
}

int Find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int u, int v){
    int x = Find(u), y = Find(v);

    if(x!=y){
        parent[x] = y;
        return false;
    }

    return true;
}

int MST(){
    int cost = 0;

    sort(edge.begin(), edge.end());

    for(int i=0; i<edge.size(); i++){
        int u = edge[i].u, v = edge[i].v;

        if(!Union(u, v)){
            cost += edge[i].cost;
            path.push_back(edge[i]);
        }
    }

    return cost;
}

int main(){
    int u,v,c;

    reset();

    while(scanf("%d%d%d",&u,&v,&c)==3){
        edge.push_back(Edge(u, v, c));
    }

    int minCost = MST();
    printf("%d\n",minCost);

    for(int i=0; i<path.size(); i++)
        printf("%d %d\n",path[i].u, path[i].v);

    return 0;
}
