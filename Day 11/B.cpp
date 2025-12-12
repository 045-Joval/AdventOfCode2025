#include <bits/stdc++.h>
using namespace std;

using ll = long long;

map<string, vector<string>> adj;

vector<string> topo;

void parseIntput(string &s)
{
    string u = s.substr(0, 3);

    for (int i = 5; i + 3 <= s.size(); i += 4)
    {
        adj[u].push_back(s.substr(i, 3));
    }
}

void dfs(string u, set<string> &vis)
{
    vis.insert(u);

    for (auto &v : adj[u])
    {
        if (vis.find(v) != vis.end())
            continue;
        dfs(v, vis);
    }

    topo.push_back(u);
}

ll num_paths(string src, string dst)
{

    map<string, ll> dp;

    dp[src] = 1;

    for (auto &u : topo)
    {
        for (auto &v : adj[u])
        {
            dp[v] += dp[u];
        }
    }

    return dp[dst];

}

int main()
{

    string s;

    while (getline(cin, s, '\n'))
    {

        parseIntput(s);
    }

    set<string> vis;

    for (auto &[u, v] : adj)
    {
        if (vis.find(u) == vis.end())
            dfs(u, vis);
    }

    reverse(topo.begin(), topo.end());

    ll ans1 = num_paths("svr", "dac") * num_paths("dac", "fft") * num_paths("fft", "out");
    ll ans2 = num_paths("svr", "fft") * num_paths("fft", "dac") * num_paths("dac", "out");

    ll ans = ans1 + ans2;

    cout << ans;
    
}
