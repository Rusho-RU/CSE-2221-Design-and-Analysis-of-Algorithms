#include <bits/stdc++.h>
using namespace std;

vector<int>data;

int main(){
    data.push_back(-2);
    data.push_back(-3);
    data.push_back(4);
    data.push_back(1);
    data.push_back(5);
    data.push_back(-3);

    int dp[data.size()];
    dp[0] = data[0];
    int ans = dp[0];

    for(int i=1; i<data.size(); i++){
        dp[i] = max(dp[i-1] + data[i], data[i]);
        ans = max(ans, dp[i]);
    }

    cout<<ans<<endl;
}

