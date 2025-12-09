#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll dist(vector<int> &x, vector<int> &y)
{
    return 1ll * (x[0] - y[0]) * (x[0] - y[0]) + 1ll * (x[1] - y[1]) * (x[1] - y[1]) + 1ll * (x[2] - y[2]) * (x[2] - y[2]);
}

class DSU
{
public:
    vector<int> par,
        sz;

    DSU(int n)
    {
        par.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x)
    {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }

    bool join(int x, int y)
    {
        int px = find(x), py = find(y);

        if (px == py)
            return false;

        if (sz[px] > sz[py])
            swap(px, py);

        par[px] = py;
        sz[py] += sz[px];
        return true;
    }
};

int main()
{
    vector<vector<int>> points;

    string s;

    while (cin >> s)
    {
        vector<int> pts;

        string pt;

        int x = 0, i = 0;
        while (i < s.size())
        {
            if (s[i] == ',')
            {
                pts.push_back(x);
                x = 0;
            }
            else
            {

                x = x * 10 + s[i] - '0';
            }
            ++i;
        }

        pts.push_back(x);

        points.push_back(pts);
    }

    int n = points.size();

    DSU dsu(n);

    vector<vector<ll>> edges;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            edges.push_back({dist(points[i], points[j]),
                             i,
                             j});
        }
    }

    sort(edges.begin(), edges.end());

    int con = 0;

    for (int i = 0; i < 1000; ++i)
    {
        auto e = edges[i];
        int x = e[1];
        int y = e[2];
        if (dsu.join(x, y))
        {
            con++;
        }
    }

    using pii = pair<int, int>;

    set<pii> st;
    map<int, vector<int>> mp;

    for (int i = 0; i < n; ++i)
    {
        int p = dsu.find(i);
        mp[p].push_back(i);
        st.insert({-dsu.sz[p],
                   p});
        if (st.size() > 3)
        {
            st.erase(prev(st.end()));
        }
    }

    ll ans = 1;

    for (auto &it : st)
    {
        ans *= -it.first;
    }

    cout << ans;
}