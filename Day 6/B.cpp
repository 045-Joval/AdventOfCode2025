#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main() {
    vector<string>lines;
    
    string s;
    
    while(getline(cin,s)) {
        
        lines.push_back(s);
        
    }
    
    string ops;
    
    for(char c:lines.back()) {
        if(c=='+'||c=='*')
            ops.push_back(c);
    }
    
    vector<vector<int>> v(10000);
    
    int n=lines.size()-1;
    
    int idx=0;
    
    for(int j=0;j<lines[0].size();++j){
        int num=0; char op='$';
        for(int i=0;i<=n;++i) {
            
            if(isdigit(lines[i][j])) num=num*10+lines[i][j]-'0';
            else op=lines[i][j];
            
        }
        
        if(num==0) {
            idx++;
            continue;
        }
        
        v[idx].push_back(num);
    }
    
    ll fans=0;
    
    for(int i=0;i<ops.size();++i) {
        ll ans;
        
        if(ops[i]=='+') {
        
            ans=0;
            
            for(auto &x:v[i]) ans+=x;
            
            
        }else{
            
            ans=1;
            
            for(auto &x:v[i]) ans*=x;
            
        }
        
        fans+=ans;
        
    }
    
    cout<<fans;
    
}
