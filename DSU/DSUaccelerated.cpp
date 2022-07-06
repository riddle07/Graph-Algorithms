/*

Here we do two things: 1. Path compression


suppose we have a set in represented in form of tree

                   1
                   |
                   2
                  / \
                 3   4

                 Now we alread know parent of all (3,2 4) is 1,,,,,then y not already join them to 1 to reduce complexity of find operation
                 That's what we are going to do

                 So end result will be like

                 1
               / | \
              2  3  4

                     2. Merge by rank

                     Now this is a simple thing that while merging two sets we will keep parent of the set with a greater size.
    Time Complexity: O(alpha(n)) -> amortized time complextity almost O(1) for 1 query
    alpha(n) -> inverse Ackerman funtion

    Note: without path compression: the time complexity will be O(log(n)) per query
*/

#include <bits/stdc++.h>
#define N_max (int)1e5 + 10

using namespace std;

int parent[N_max];
int Size[N_max];
void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void Union(int v, int u)
{
    v = find(v);
    u = find(u);
    if (u != v)
    {
        if (Size[u] > Size[v])
            swap(u, v);
        parent[u] = v;
        Size[v] += Size[u];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
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