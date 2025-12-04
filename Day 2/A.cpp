#include<bits/stdc++.h>
using namespace std;

using ll=long long;

int main(){
    string q;
    cin>>q;
    
    stringstream ss1(q);
    
    string s;
    
    ll ans=0;
    
    while(getline(ss1,s,',')) {
        ll l=0, r=0;
        int i=0;
        
        while(s[i]!='-') {
            l=l*10+s[i]-'0';
            ++i;
        }
        
        ++i;
        
        while(i<s.size()) {
            r=r*10+s[i]-'0';
            ++i;
        }
        
        for(ll x=l;x<=r;++x) {
            string t=to_string(x);
            
            int n=t.size();
            
            if(n%2)continue;
            
            string a=t.substr(0,n/2);
            string b=t.substr(n/2);
            
            if(a==b) ans+=x;
        }
    }
    
    cout<<ans;
}