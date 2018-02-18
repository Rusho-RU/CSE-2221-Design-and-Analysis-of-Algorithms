#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 10

long long factorial[MAX], inverse_factorial[MAX];

long long BigMOD(long long a, long long b){
    if(b==0)
        return 1;

    if(b&1)
        return a * BigMOD(a, b-1) % MOD;

    long long temp = BigMOD(a, b/2);
    return temp * temp % MOD;
}

long long bitwise_BigMod(long long a, long long b){
    long long ans=1,hold=a%MOD;
    while(b){
        if(b & 1) ans=(ans*hold)%MOD;
        hold=(hold*hold)%MOD;
        b>>=1;
    }
    return ans;
}

long long bigmod_using_extended_euclid(long long n, long long m){
    long long hold,x=0,y=1;
    while(n>1){
        long long q=n/m;
        hold=m;
        m=n%m;
        n=hold;
        hold=x;
        x=y-q*x;
        y=hold;
    }
    if(y<0) y+=MOD;
    return y;
}

void calculate(){
    factorial[0] = inverse_factorial[0] = 1;

    for(int i=1; i<MAX; i++){
        factorial[i] = factorial[i-1] * i % MOD;
        inverse_factorial[i] = inverse_factorial[i-1] * BigMOD(i, MOD-2) % MOD;
    }
}

void calculate_using_extended_euclid(){
    factorial[0] = inverse_factorial[0] = 1;

    for(int i=1; i<MAX; i++){
        factorial[i] = factorial[i-1] * i % MOD;
        inverse_factorial[i] = inverse_factorial[i-1] * bigmod_using_extended_euclid(i, MOD) % MOD;
    }
}

int main(){
    calculate();
}
