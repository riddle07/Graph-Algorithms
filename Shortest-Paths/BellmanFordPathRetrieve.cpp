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
    vector<int> parent(n, -1);
    distance[0] = 0;
    while (true)
    {
        bool flag = false;
        for (auto x : edges)
        {
            if (distance[x[0]] < LLONG_MAX)
            {
                if (distance[x[1]] > distance[x[0]] + x[2])
                {
                    distance[x[1]] = distance[x[0]] + x[2];
                    parent[x[1]] = x[2];
                    flag = true;
                }
            }
        }
        if (!flag)
            break;
    }
    // let say we need to find the path from the source int his case 0 to a node t
    int t;
    int cur = t;
    vector<int> path;
    while (cur != -1)
    {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());
    cout << endl;
}