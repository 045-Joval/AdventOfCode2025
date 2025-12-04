#include<bits/stdc++.h>
using namespace std;

using ll=long long;

int main(){
    vector<vector<int>> factors(20);
    
    for(int i=2;i<20;++i) {
        for(int j=1;j<i;++j) {
            if(i%j==0)
                factors[i].push_back(j);
        }
    }
    
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
            
            for(int sz:factors[n]) {
                string tmp;
                
                for(int i=0;i<n/sz;++i) tmp+=t.substr(0,sz);
                
                if(tmp==t) {ans+=x;break;}
            }
        }
    }
    
    cout<<ans;
}