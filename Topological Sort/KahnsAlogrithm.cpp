/*

I am not a huge fan of sorting let alone topo sorting. When I was toposorting using dfs, I thought that it was too trivial. So what was the best thing
that I could have done? Yes, that was to find something not so trivial. So here we have the algo from Oliver Kahn's bro whose first name I don' kno

*/

/*

Algorithm:

1. Find in degree of all the nodes
2. Input all the zero-in-degree node in the queue and run the bfs
3. The topo sorted elements will be in accordance to their movement in the queue, the early they go in the more frontal space they will be occupying.
4. at each front node reduce the in-degree of the adjacent node, if 0 take it into queue



*/

// code

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; // number of the vertices
    cin >> n;
    int m; // number of the edges
    cin >> m;
    vector<vector<int>> graph(n);
    vector<int> in_degree(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ;
        graph[x].push_back(y);
        in_degree[y]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo_sorted;
    while (!q.empty())
    {
        int k = q.size();
        for (int i = 0; i < k; i++)
        {
            int crt_v = q.front();
            topo_sorted.push_back(crt_v);
            q.pop();
            for (int j = 0; j < graph[crt_v].size(); j++)
            {
                if (in_degree[graph[crt_v][j]])
                {
                    in_degree[graph[crt_v][j]]--;
                    if (!in_degree[graph[crt_v][j]])
                    {
                        q.push(graph[crt_v][j]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < topo_sorted.size(); i++)
    {
        cout << topo_sorted[i] << " ";
    }
    cout << endl;
}