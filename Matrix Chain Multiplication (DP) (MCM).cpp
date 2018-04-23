#include <bits/stdc++.h>
using namespace std;

#define MAX 26
#define INF 0x3f3f3f3f

vector<int>matrix;
int dp[MAX][MAX];
int bracket[MAX][MAX];
char c;

void putBracket(int i, int j){
    if(i==j-1){
        printf("%c",c);
        c++;
        return;
    }

    printf("(");

    putBracket(i, bracket[i][j]);
    putBracket(bracket[i][j], j);

    printf(")");

    return;
}

int MCM(int i, int j){
    if(i==j-1)
        return 0;
    if(dp[i][j]!=INF)
        return dp[i][j];

    for(int k=i+1; k<j; k++){
        int value = MCM(i, k) + MCM(k, j) + matrix[i] * matrix[k] * matrix[j];
        if(value < dp[i][j]){
            bracket[i][j] = k;
            dp[i][j] = value;
        }
    }

    return dp[i][j];
}

int main(){
    int n,val;
    scanf("%d",&n);

    for(int i=0; i<=n; i++){
        scanf("%d",&val);
        matrix.push_back(val);
    }

    memset(dp, INF, sizeof dp);

    int op = MCM(0, n);
    printf("%d\n",op);

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            printf("%d ",dp[i][j]);
        }
        puts("");
    }

    c = 'A';
    putBracket(0, n);
}
