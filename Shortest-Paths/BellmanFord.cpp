#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({x, y, z});
    }
    vector<long long> distance(n, LLONG_MAX);
    distance[0] = 0;
    while (true)
    {
        bool flag = false;
        for (auto x : edges)
        {
            if (distance[x[0]] < LLONG_MAX) // only if the edges are negative
            {
                if (distance[x[1]] > distance[x[0]] + x[2])
                {
                    distance[x[1]] = distance[x[0]] + x[2];
                    flag = true;
                }
            }
        }
        if (!flag)
            break;
    }
    for (auto x : distance)
    {
        cout << x << " ";
    }
    cout << endl;
}