#include <bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
using ll=long long;

int main() {
	string s;
	
	vector<pii> pts;
	
	while(cin>>s) {
	    int x=0, y=0;
	    
	    int i=0;
	    
	    while(s[i]!=',') {
	        x=x*10+s[i]-'0';
	        ++i;
	    }
	    ++i;
	    while(i<s.size()) {
	        y=y*10+s[i]-'0';
	        ++i;
	    }
	    
	    pts.push_back({x,y});
	}
	
	int n=pts.size();
	
    ll ans=0;
    
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            ll l=1ll+abs(pts[i].first-pts[j].first);
            ll r=1ll+abs(pts[i].second-pts[j].second);
        	ans=max(ans,l*r);
        }
    }
    
    cout<<ans;
}
