#include<bits/stdc++.h>
using namespace std;

using ll=long long;

int main(){
    string s;

    int ans=0, pos=50;

    while(cin>>s) {
        char dir=s[0];
        int d=stoi(s.substr(1));
        
        if(dir=='L') {
            pos=(pos-d+100)%100;
        }else{
            pos=(pos+d)%100;
        }

        if(pos==0)ans++;
    }

    cout<<ans;
}