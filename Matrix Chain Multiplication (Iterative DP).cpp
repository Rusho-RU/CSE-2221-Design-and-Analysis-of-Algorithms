#include <bits/stdc++.h>
using namespace std;

#define MAX 26
#define INF 0x3f3f3f3f

int matrix[MAX];
int dp[MAX][MAX];

int MCM(int n){
    for(int i=1; i<n; i++) dp[i][i] = dp[i][i+1] = 0;

    dp[n][n] = 0;

    for(int i=n; i>=1; i--){
        for(int j=i+2; j<=n; j++){
            dp[i][j] = INF;
            for(int k=i+1; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + matrix[i] * matrix[k] * matrix[j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ",dp[i][j]);
        }
        puts("");
    }

    return dp[1][n];
}

int main(){
    int n,val;
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        scanf("%d",&matrix[i]);
    }

    int optimized = MCM(n);
    printf("%d\n",optimized);
}

