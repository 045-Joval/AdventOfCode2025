#include <bits/stdc++.h>
using namespace std;

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

    map<string, int> dp;

    dp["you"] = 1;

    for (auto &u : topo)
    {
        for (auto &v : adj[u])
        {
            dp[v] += dp[u];
        }
    }

    cout << dp["out"];
}
