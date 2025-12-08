#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> g;

    string s;

    using pii = pair<int, int>;

    while (cin >> s)
    {
        g.push_back(s);
    }

    queue<pii> q;

    int m = g.size(), n = g[0].size();

    vector<vector<bool>> vis(m, vector<bool>(n));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (g[i][j] == 'S')
            {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    set<pii> st;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (g[x][y] != '^')
        {
            if (x + 1 < m && !vis[x + 1][y])
            {
                q.push({x + 1, y});
                vis[x + 1][y] = true;
            }
        }
        else
        {
            st.insert({x, y});
            if (x + 1 < m)
            {
                if (y - 1 >= 0 && !vis[x + 1][y - 1])
                {
                    q.push({x + 1, y - 1});
                    vis[x + 1][y - 1] = true;
                }
                if (y + 1 < n && !vis[x + 1][y + 1])
                {
                    q.push({x + 1, y + 1});
                    vis[x + 1][y + 1] = true;
                }
            }
        }
    }

    cout << st.size();
}
