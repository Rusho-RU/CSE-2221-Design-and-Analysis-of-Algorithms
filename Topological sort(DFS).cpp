#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

vector<int>adj[MAX];
int Time;
vector<pair<int, int> >topsort;
int d[MAX], f[MAX];

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

void dfs(int s){
    d[s] = ++Time;

    for(int i=0; i<adj[s].size(); i++){
        int x = adj[s][i];
        if(d[x]==-1)
            dfs(x);
    }

    f[s] = ++Time;
    topsort.push_back(make_pair(s, f[s]));

    return;
}

int main(){
    int numOfActivity;
    scanf("%d",&numOfActivity);
    Time = 0;
    int relation;
    scanf("%d",&relation);

    while(relation--){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
    }

    memset(d, -1, sizeof d);

    for(int i=0; i<numOfActivity; i++)
        if(d[i]==-1)
            dfs(i);

    sort(topsort.begin(), topsort.end(), cmp);

    for(int i=0; i<numOfActivity; i++)
        printf("%d ",topsort[i].first);
}
