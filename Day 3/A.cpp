#include<bits/stdc++.h>
using namespace std;

using ll=long long;

int main(){
    
    string s;
    
    int ans=0;
    
    while(cin>>s) {
        
        int n=s.size(), mx=0;
        
        for(int i=0;i<n;++i) {
            for(int j=i+1;j<n;++j) {
                mx=max(mx,(s[i]-'0')*10+s[j]-'0');
            }
        }
        
        ans+=mx;
    }
    
    cout<<ans;
    
}