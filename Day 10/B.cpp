#include <bits/stdc++.h>
using namespace std;

vector<string> lights;
vector<vector<vector<int>>> switches;

void parseInput(string &s)
{

    string light;

    int i = 1;

    while (s[i] != ']')
    {
        light.push_back(s[i]);
        ++i;
    }

    lights.push_back(light);

    i += 2;

    int num;

    vector<vector<int>> switches1;

    while (s[i] != '{')
    {
        i++;

        vector<int> v;

        while (s[i] != ' ')
        {
            num = 0;
            while (s[i] != ',' && s[i] != ')')
            {
                num = num * 10 + s[i] - '0';
                ++i;
            }
            v.push_back(num);
            ++i;
        }

        switches1.push_back(v);
        i++;
    }

    switches.push_back(switches1);
}

int ans;

void check(int i, int xr, int cnt, vector<int> &nums, int target)
{
    if (xr == target)
    {
        ans = min(ans, cnt);
        return;
    }
    if (i == nums.size())
        return;

    check(i + 1, xr, cnt, nums, target);
    check(i + 1, xr ^ nums[i], cnt + 1, nums, target);
}

int main()
{

    string s;

    while (getline(cin, s, '\n'))
    {
        parseInput(s);
    }

    int fans = 0;

    for (int i = 0; i < lights.size(); ++i)
    {
        int target = 0;
        for (int j = 0; j < lights[i].size(); ++j)
        {
            if (lights[i][j] == '#')
                target |= (1 << j);
        }

        vector<int> nums;

        for (auto &v : switches[i])
        {
            int num = 0;
            for (int &x : v)
            {
                num |= (1 << x);
            }
            nums.push_back(num);
        }

        ans = 2e9;

        check(0, 0, 0, nums, target);

        fans += ans;
    }

    cout << fans;
}
