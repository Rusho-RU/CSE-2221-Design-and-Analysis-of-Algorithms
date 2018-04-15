#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
#define INF 0x3f3f3f3f

struct cmp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.second < b.second;
    }
};

void dijkstra(int source, const vector<int>graph[], int cost[][MAX], int data[], int n){
    for(int i=0; i<=n; i++)
        data[i] = INF;
    data[source] = 0;

    priority_queue< pair<int, int>, vector<pair<int, int> >, cmp >pq;
    pq.push(make_pair(source, 0));

    while(!pq.empty()){
        int u = pq.top().first;
        int c = pq.top().second;
        pq.pop();

        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u][i];

            if(c+cost[u][v] < data[v]){
                data[v] = c+cost[u][v];
                pq.push(make_pair(v, data[v]));
            }
        }
    }

    return;
}
