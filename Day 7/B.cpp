#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> g;

    string s;

    using pii = pair<int, int>;
    using ll = long long;

    while (cin >> s)
    {
        g.push_back(s);
    }

    int m = g.size(), n = g[0].size();

    vector<vector<ll>> dp(m, vector<ll>(n));

    for (int i = 0; i < m - 1; ++i)
    {
        for (int j = 0; j < n; ++j)
        {

            if (g[i][j] == 'S')
            {
                dp[i][j] = 1;
            }

            if (g[i][j] == 'S' || g[i][j] == '.')
            {
                dp[i + 1][j] += dp[i][j];
            }
            else
            {
                if (j - 1 >= 0)
                    dp[i + 1][j - 1] += dp[i][j];
                if (j + 1 < n)
                    dp[i + 1][j + 1] += dp[i][j];
            }
        }
    }

    ll ans = accumulate(dp[m - 1].begin(), dp[m - 1].end(), 0ll);

    cout << ans;
}
