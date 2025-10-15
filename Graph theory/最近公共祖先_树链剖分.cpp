#include <bits/stdc++.h>
using namespace std;
struct HLD {
    int n, idx;
    vector<vector<int>> ver;
    vector<int> siz, dep;
    vector<int> top, son, parent;

    HLD(int n){
        this -> n = n;
        ver.resize(n + 1);
        siz.resize(n + 1);
        dep.resize(n + 1);
        top.resize(n + 1);
        son.resize(n + 1);
        parent.resize(n + 1);
    }
    void add(int x, int y){
        // 建双向边
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    void dfs1(int x){
        // 计算每个节点的父节点，深度和重儿子节点
        siz[x] = 1;
        dep[x] = dep[parent[x]] + 1;
        for (auto y : ver[x]){
            if (y == parent[x]) continue;
            parent[y] = x;
            dfs1(y);
            siz[x] += siz[y];
            if (siz[y] > siz[son[x]]){
                son[x] = y;
            }
        }
    }
    void dfs2(int x, int up){
        // 处理出每个节点到重链的链头
        top[x] = up;
        if (son[x]) dfs2(son[x], up);
        for (auto y : ver[x]){
            if (y == parent[x] || y == son[x]) continue;
            dfs2(y, y);
        }
    }
    int lca(int x, int y){
        while (top[x] != top[y]){
            if (dep[top[x]] > dep[top[y]]){
                x = parent[top[x]];
            }
            else{
                y = parent[top[y]];
            }
        }
        return dep[x] < dep[y] ? x : y;
    }
    int calc(int x, int y){
        // 查询两点间的距离
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    }
    void work(int root = 1){
        // 在此初始化
        dfs1(root);
        dfs2(root, root);
    }
};