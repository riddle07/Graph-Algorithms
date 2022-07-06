#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> dp(n, vector<long long>(n, LLONG_MAX));
    vector<vector<int>> next(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        dp[x][y] = z;
        dp[y][x] = z;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] != 0 && dp[i][j] != LLONG_MAX)
            {
                next[i][j] = j;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][k] < LLONG_MAX && dp[k][j] < LLONG_MAX)
                {
                    if (dp[i][j] > dp[i][k] + dp[k][j])
                    {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }
}