#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y, z));
        graph[y].push_back(make_pair(x, z));
    }
    vector<int> key(n, INT_MAX);
    key[0] = 0;
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);
    bool ok = false;
    while (!ok)
    {
        int crt_min = INT_MAX;
        int crt_node;
        for (int i = 0; i < n; i++)
        {
            if (key[i] < crt_min && mst[i] == false)
            {
                crt_min = key[i];
                crt_node = i;
            }
        }
        mst[crt_node] = true;
        for (auto x : graph[crt_node])
        {
            if (!mst[x.first] && key[x.first] > x.second)
            {
                parent[x.first] = crt_node;
                key[x.first] = x.second;
            }
        }
        int count = 0;
        for (auto x : mst)
        {
            count += (x);
        }
        if (count == n)
        {
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << i << " " << parent[i] << endl;
    }
    return 0;
}