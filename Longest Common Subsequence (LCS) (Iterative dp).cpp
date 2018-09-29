#include <bits/stdc++.h>
using namespace std;

string longest;

int LCS(const string& s1, const string& s2){
    int length[s1.size()+1][s2.size()+1];

    for(int i=0; i<=s1.size(); i++)
        length[i][0] = 0;
    for(int i=0; i<=s2.size(); i++)
        length[0][i] = 0;

    for(int i=0; i<s1.size(); i++){
        for(int j=0; j<s2.size(); j++){
            if(s1[i]==s2[j])
                length[i+1][j+1] = length[i][j] + 1;
            else
                length[i+1][j+1] = max(length[i+1][j], length[i][j+1]);
        }
    }

    int i=s1.size(),j=s2.size();

    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            longest+=s1[i-1];
            i--, j--;
        }
        else if(length[i-1][j] > length[i][j-1])
            i--;
        else
            j--;
    }

    reverse(longest.begin(), longest.end());
    return length[s1.size()][s2.size()];
}

int main(){
    string s1,s2;
    cin>>s1>>s2;

    int length = LCS(s1,s2);
    printf("%d\n",length);
    cout<<longest<<endl;
}
