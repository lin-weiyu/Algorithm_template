#include <bits/stdc++.h>
using namespace std;
int n;
std::vector<std::vector<int>> gr;
std::vector<int> colors, vis;

// Depth-first search to color vertices.
bool dfs(int cr)
{
    vis[cr] = true;
    for (int nt : gr[cr])
    {
        if (vis[nt])
        {
            if (colors[cr] == colors[nt])
                return false;
        }
        else
        {
            colors[nt] = colors[cr] ^ 1;
            if (!dfs(nt))
                return false;
        }
    }
    return true;
}

// Check whether the graph GR is bipartite.
// If so, the vector COLORS will store a feasible coloring.
bool check_bipartite()
{
    for (int i = 1; i <= n; ++i)
    {
        // Check connected components one by one.
        if (!vis[i])
        {
            colors[i] = 0;
            if (!dfs(i))
                return false;
        }
    }
    return true;
}