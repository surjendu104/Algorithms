#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n;cin>>n;
    string s;
    cin>>s;

    int i=0,j;
    for(j=0;j<s.size();j++){
        if(s[j]=='W')n--;
        if(n<0 && s[i++]=='W')n++;
    }
    cout<<j-i<<endl;
}


int main(){
    solve();
}