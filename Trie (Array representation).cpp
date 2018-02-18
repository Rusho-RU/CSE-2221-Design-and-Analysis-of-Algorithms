///Based on a problem, UVa 11362-Phone List (Using Array Trie)

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001

bool possible;

struct node{
    int next[10];
    bool endword;

    node(){
        memset(next, 0, sizeof next);
        endword = false;
    }
};

vector<node>data;

void init(string s){
    int now = 0;

    for(int i=0; i<s.size(); i++){
        int x = s[i] - '0';

        if(!data[now].next[x]){
            data[now].next[x] = data.size();
            data.push_back(node());
        }

        else if(data[data[now].next[x]].endword || i==s.size()){
            possible = false;
            return;
        }

        now = data[now].next[x];
    }

    data[now].endword = true;

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        string s;

        possible = true;
        data.push_back(node());

        while(n--){
            cin>>s;
            if(possible)
                init(s);
        }

        if(possible)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}

