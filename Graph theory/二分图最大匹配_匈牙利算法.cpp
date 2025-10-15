#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

// sqrt(n)*m/10  ~  nlog(n)
// 最小点覆盖问题是指，在一张无向图中选择最少的顶点，满足每条边至少有一个端点被选。
// 二分图中，最小点覆盖中的顶点数量等于最大匹配中的边数量
// 最小点覆盖与最大独立集的大小之和等于顶点数目。
struct BipartiteGraph
{
    int n1, n2;                      // number of vertices in X and Y, resp.
    std::vector<std::vector<int>> g; // edges from X to Y
    std::vector<int> ma, mb;         // matches from X to Y and from Y to X, resp. 匹配从X到Y和从Y到X
    std::vector<int> dist;           // distance from unsaturated vertices in X.   到X中不饱和顶点的距离

    BipartiteGraph(int n1, int n2)
        : n1(n1), n2(n2), g(n1), ma(n1, -1), mb(n2, -1) {}
    // 添加一条从X中的u 到Y中的v的边
    // Add an edge from u in X to v in Y.
    void add_edge(int u, int v) { g[u].emplace_back(v); }

    // Build the level graph.
    // 构建层级图
    bool bfs()
    {
        dist.assign(n1, -1);
        std::queue<int> q;
        for (int u = 0; u < n1; ++u)
        {
            if (ma[u] == -1)
            {
                dist[u] = 0;
                q.emplace(u);
            }
        }
        // 为所有可到达的顶点构建层级图。
        // Build the level graph for all reachable vertices.
        bool succ = false;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : g[u])
            {
                if (mb[v] == -1)
                {
                    succ = true;
                }
                else if (dist[mb[v]] == -1)
                {
                    dist[mb[v]] = dist[u] + 1;
                    q.emplace(mb[v]);
                }
            }
        }
        return succ;
    }
    // 找到一个从u开始的增广路径
    // Find an augmenting path starting at u.
    bool dfs(int u)
    {
        for (int v : g[u])
        {
            if (mb[v] == -1 || (dist[mb[v]] == dist[u] + 1 && dfs(mb[v])))
            {
                ma[u] = v;
                mb[v] = u;
                return true;
            }
        }
        // 将此点标记为访问一次后不可达
        dist[u] = -1; // Mark this point as inreachable after one visit. 
        return false;
    }

    // Hopcroft-Karp maximum matching algorithm.
    std::vector<std::pair<int, int>> hopcroft_karp_maximum_matching()
    {
        // Build the level graph and then find a blocking flow.
        // 构建层级图，然后找出一条阻塞流
        while (bfs())
        {
            for (int u = 0; u < n1; ++u)
            {
                if (ma[u] == -1)
                {
                    dfs(u);
                }
            }
        }
        // 收集成功的配对
        std::vector<std::pair<int, int>> matches;
        matches.reserve(n1);
        for (int u = 0; u < n1; ++u)
        {
            if (ma[u] != -1)
            {
                matches.emplace_back(u, ma[u]);
            }
        }
        return matches;
    }
};

/*
input:
4 4 7
0 0
1 0
1 1
2 1
2 2
3 2
3 3

左边的点: 0, 1, 2, 3
右边的点: 0, 1, 2, 3

output:
4
0 0
1 1
2 2
3 3

*/


int main()
{
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int n1, n2, m;
    std::cin >> n1 >> n2 >> m;
    BipartiteGraph gr(n1, n2);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        gr.add_edge(u, v);
    }
    auto res = gr.hopcroft_karp_maximum_matching();
    std::cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i)
    {
        std::cout << res[i].first << ' ' << res[i].second << '\n';
    }
    return 0;
}