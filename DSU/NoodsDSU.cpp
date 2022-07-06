/*

This is a noob method with no kind of optimization like path compression or merging by sort.

Time Complexity: O(n) for each call on find()

*/

#include <bits/stdc++.h>
#define N_max (int)1e5 + 10

using namespace std;

int parent[N_max];

void make(int v)
{
    // Just inittialize the nodes to self which is the condition for the grand-parent(or the end boss(or the root))
    parent[v] = v;
}

int find(int v)
{
    if (v == parent[v]) // recursive function to call for the parent of node
        return v;
    return find(parent[v]);
}

void Union(int v, int u)
{
    v = parent[v]; // find parent and add them
    u = parent[u];
    if (u != v)
    {
        parent[u] = v;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        make(i);
    }
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            Union(i, graph[i][j]);
        }
    }
}