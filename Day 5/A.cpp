#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<pair<ll, ll>> ranges;

    for (int j = 0; j < n; ++j)
    {
        string s;
        cin >> s;

        ll l = 0, r = 0;

        int i = 0;
        while (s[i] != '-')
        {
            l = l * 10 + s[i] - '0';
            ++i;
        }
        ++i;

        while (i < s.size())
        {
            r = r * 10 + s[i] - '0';
            ++i;
        }

        ranges.push_back({l, r});
    }

    int ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        for (auto &[l, r] : ranges)
        {
            if (l <= x && x <= r)
            {
                ans++;
                break;
            }
        }
    }

    cout << ans;
}
