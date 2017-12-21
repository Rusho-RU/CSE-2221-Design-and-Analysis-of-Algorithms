#include <bits/stdc++.h>
using namespace std;

vector<int>data;

int crossingMax(int l, int m, int r){
    int sum = 0, leftSum = INT_MIN, rightSum = INT_MIN;

    for(int i=m; i>=l; i--)
        leftSum = max(leftSum, sum+=data[i]);

    sum=0;
    for(int i=m+1; i<=r; i++)
        rightSum  =max(rightSum, sum+=data[i]);

    return leftSum + rightSum;
}

int findMax(int left, int right){
    if(left == right)
        return data[left];

    int mid = (left + right)/2;

    return max(max(findMax(left, mid), findMax(mid+1, right)), crossingMax(left, mid, right));
}

int main(){
    data.push_back(2);
    data.push_back(3);
    data.push_back(4);
    data.push_back(5);
    data.push_back(7);

    int ans = findMax(0,data.size()-1);
    cout<<ans<<endl;
}
