#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> v;
	
	string s;
	
	while(cin>>s){
	    v.push_back(s);
	}
	
	int m=v.size(), n=v[0].size(), ans=0;
	
	bool flag=true;
	
	while(flag){
	    flag=false;
	    
	    for(int i=0;i<m;++i){
    	    for(int j=0;j<n;++j) {
    	        if(v[i][j]=='.')continue;
    	        
    	        int cnt=0;
    	        
    	        for(int di=-1;di<=1;++di){
                    for(int dj=-1;dj<=1;dj++){
                        if(di==0&&dj==0)continue;
    	                int i_=i+di;
    	                int j_=j+dj;
    	                
    	                if(i_>=0&&i_<m&&j_>=0&&j_<n&&v[i_][j_]=='@')cnt++;
    	            }
    	        }
    	        
    	        if(cnt<4){
        	        ans++;
    	            v[i][j]='.';
    	            flag=true;
    	        } 
    	    }
    	}
	}
	
	cout<<ans;

}
