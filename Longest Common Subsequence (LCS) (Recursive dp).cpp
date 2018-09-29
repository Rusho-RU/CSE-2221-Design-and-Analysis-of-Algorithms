#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int dp[MAX][MAX];
string s1,s2,subsequence;

int LCS(int i, int j){
    if(i==s1.size() || j==s2.size())
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s1[i]==s2[j])
        return dp[i][j] = 1+LCS(i+1, j+1);

    return dp[i][j] = max(LCS(i+1, j), LCS(i, j+1));
}

void print(int i, int j){
    if(i==s1.size() || j==s2.size())
        return;

    if(s1[i]==s2[j]){
        subsequence+=s1[i];
        print(i+1, j+1);
    }

    else if(dp[i+1][j] > dp[i][j+1])
        print(i+1, j);

    else
        print(i, j+1);

    return;
}

int main(){
    cin>>s1>>s2;
    memset(dp, -1, sizeof dp);

    int longest = LCS(0,0);
    print(0,0);

    cout<<longest<<endl<<subsequence<<endl;
}
