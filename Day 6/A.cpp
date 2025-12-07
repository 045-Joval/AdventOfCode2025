#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main() {
    vector<string>lines;
    
    int idx=0;
    
    string s;
    
    while(getline(cin,s)) {
        
        lines.push_back(s);
        
    }
    
    vector<vector<int>> v(lines.size()-1);
    
    for(int i=0;i<lines.size()-1;++i) {
        stringstream ss(lines[i]);
        
        int x;
        
        while(ss>>x) {
            v[i].push_back(x);
        }
    }
    
    string ops;
    
    for(char c:lines.back()) {
        if(c=='+'||c=='*')
            ops.push_back(c);
    }
    
    ll fans=0;
    
    for(int i=0;i<ops.size();++i) {
        ll ans;
        
        if(ops[i]=='+') {
        
            ans=0;
            
            for(int j=0;j<v.size();++j) {
                ans+=v[j][i];
            }
            
        }else{
            
            ans=1;
            
            for(int j=0;j<v.size();++j) {
                ans*=v[j][i];
            }
            
        }
        
        fans+=ans;
    }
    
    cout<<fans;
    
}
