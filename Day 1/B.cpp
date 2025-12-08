#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    string s;

    int ans = 0, pos = 50;

    while (cin >> s)
    {
        char dir = s[0];
        int d = stoi(s.substr(1));

        int diff = (dir == 'L' ? -1 : 1);

        while (d--)
        {
            pos += diff;
            if ((pos + 100) % 100 == 0)
                ans++;
        }
    }

    cout << ans;
}