///http://lightoj.com/volume_showproblem.php?problem=1258

#include <bits/stdc++.h>
using namespace std;

string s, newString;
int sz, newSz, pi[2*1000001];

void getNew(){
    newString="@";

    for(int i=0; i<sz; i++)
        newString+='#', newString+=s[i];

    newString+="#$";
    return;
}

int callManacher(){
    int center=0, right=0;

    for(int i=1; i<newSz-1; i++){
        int mirror=center-(i-center);

        pi[i]=right>i ? min(right-i, pi[mirror]) : 0;

        while(newString[i-1-pi[i]] == newString[i+1+pi[i]])
            pi[i]++;
        if(i+pi[i]>right)
            center=i, right=i+pi[i];
    }


    for(int i=1; i<newSz-1; i++)
        if(i+pi[i]==newSz-2)
            return pi[i];
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, Case=0;
    cin>>t;

    while(t--){
        cin>>s;
        sz=s.size();
        getNew();
        newSz=newString.size();

        int ans=sz-(callManacher()-sz);

        cout<<"Case "<<++Case<<": "<<ans<<endl;
    }

    return 0;
}
