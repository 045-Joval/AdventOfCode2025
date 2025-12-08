#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;

int main()
{
    int n;
    cin >> n;

    vector<pair<ll, ll>> ranges, merged;

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

    sort(ranges.begin(), ranges.end());

    pll prev = ranges[0];
    for (int i = 1; i < ranges.size(); ++i)
    {
        pll cur = ranges[i];

        if (cur.first <= prev.second)
        {
            prev.second = max(prev.second, cur.second);
        }
        else
        {
            merged.push_back(prev);
            prev = cur;
        }
    }
    merged.push_back(prev);

    ll ans = 0;

    for (auto &[l, r] : merged)
    {
        ans += r - l + 1;
    }

    cout << ans;
}
