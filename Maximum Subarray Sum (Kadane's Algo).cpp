#include <bits/stdc++.h>
using namespace std;

vector<int>data;

int Kadane(){
    int max_so_far = INT_MIN, max_ending_here = 0;
    int start = 0, stop = 0, now = 0;

    for(int i=0; i<data.size(); i++){
        max_ending_here += data[i];
        if(max_so_far < max_ending_here){
            max_so_far = max_ending_here;
            start = now;
            stop = i;
        }

        if(max_ending_here < 0){
            max_ending_here = 0;
            now = i+1;
        }
    }

    printf("%d to %d\n",start, stop);

    return max_so_far;
}

int main(){
    int n;
    scanf("%d",&n);
    int val;

    for(int i=0; i<n; i++){
        scanf("%d",&val);
        data.push_back(val);
    }

    printf("%d\n",Kadane());
}
