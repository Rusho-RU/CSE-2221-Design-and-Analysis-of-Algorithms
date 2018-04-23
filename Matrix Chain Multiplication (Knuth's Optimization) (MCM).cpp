///Based on UVa - 10304

#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX 260

int sum[MAX], dp[MAX][MAX], pos[MAX][MAX], data[MAX];

int main(){
    int n;

    while(scanf("%d",&n)==1){
        sum[0] = 0;

        for(int i=1; i<=n; i++){
            scanf("%d",&data[i]);
            sum[i] = sum[i-1] + data[i];
        }

        memset(dp, 0, sizeof dp);

        for(int i=n; i>=1; i--){
            pos[i][i]=i;
            for(int j=i+1; j<=n; j++){
                dp[i][j] = INF;
                for(int k=pos[i][j-1]; k<=pos[i+1][j]; k++){
                    int cost = dp[i][k-1] + dp[k+1][j] + sum[j] - sum[i-1] - data[k];
                    if(cost < dp[i][j])
                        dp[i][j] = cost, pos[i][j] = k;
                }
            }
        }

        printf("%d\n",dp[1][n]);
    }

    return 0;
}

