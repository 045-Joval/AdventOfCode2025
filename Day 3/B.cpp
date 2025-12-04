#include<bits/stdc++.h>
using namespace std;

using ll=long long;

int main(){
    
    string s;
    
    ll ans=0;
    
    while(cin>>s) {
        
        string stk;
        
        int n=s.size();
        
        for(int i=0;i<n;++i) {
            while(!stk.empty() && stk.back()<s[i] && stk.size()+n-i-1>=12) stk.pop_back();
            stk.push_back(s[i]);
        }
        
        while(stk.size()>12) stk.pop_back();
        
        ans+=stoll(stk);
    }
    
    cout<<ans;
    
}