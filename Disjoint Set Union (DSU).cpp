#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

int Parent[MAX];

int Find(int x){
    if(x==Parent[x])
        return x;
    return Parent[x] = Find(Parent[x]);
}

void Union(int u, int v){
    int x = Find(u);
    int y = Find(v);

    if(x!=y)
        Parent[x] = y;
    return;
}

void reset(){
    for(int i=0; i<MAX; i++)
        Parent[i] = i;
}

int main(){
    int u, v;
    reset();

    while(scanf("%d%d",&u,&v)==2){
        Union(u,v);
    }

    int cnt=0;

    for(int i=0; i<MAX; i++)
        if(Parent[i]==i)
            cnt++;

    printf("There are %d disjoint sets.\n",cnt);

    return 0;
}
