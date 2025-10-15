#include <bits/stdc++.h>

using namespace std;
// 有向图缩点
struct SCC
{
    int n, now, cnt;
    vector<vector<int>> ver;
    vector<int> dfn, low, col, S;

    SCC(int n) : n(n), ver(n + 1), low(n + 1)
    {
        dfn.resize(n + 1, -1);
        col.resize(n + 1, -1);
        now = cnt = 0;
    }

    void add(int x, int y)
    {
        ver[x].push_back(y);
    }
    void tarjan(int x)
    {
        dfn[x] = low[x] = now++;
        S.push_back(x);
        for (auto y : ver[x])
        {
            if (dfn[y] == -1)
            {
                tarjan(y);
                low[x] = min(low[x], low[y]);
            }
            else if (col[y] == -1)
            {
                low[x] = min(low[x], dfn[y]);
            }
        }
        if (dfn[x] == low[x])
        {
            int pre;
            cnt++;
            do{
                pre = S.back();
                col[pre] = cnt;
                S.pop_back();
            }while (pre != x);
        }
    }
    tuple<int, vector<vector<int>>, vector<int>, vector<int>> work()
    {
        for (int i = 1; i <= n; i++)
        {
            if (dfn[i] == -1)
            {
                tarjan(i);
            }
        }

        vector<int> siz(cnt + 1);
        vector<vector<int>> adj(cnt + 1);
        for (int i = 1 ; i <= n; i++)
        {
            siz[col[i]]++;
            for (auto j : ver[i])
            {
                int x = col[i], y = col[j];
                if (x != y)
                {
                    adj[x].push_back(y);
                }
            }
        }
        // 新图的顶点数， 新图的边， 节点属于哪个个SCC， SCC的大小
        // C++17及以上可用 ：auto {} = scc.work();
        // C++11 / 14 可用：result = scc.work(); vector<int> cnt = get<0>(result); vector<vector<int>> adj = get<1>(result); vector<int> col = get<2>(result); vector<int> siz = get<3>(result);
        return {cnt, adj, col, siz};
    }
};