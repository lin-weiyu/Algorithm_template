#include <bits/stdc++.h>
using namespace std;
struct Tree{
    int n;
    vector<vector<int>> val, Max;
    vector<vector<pair<int, int>>> ver;
    vector<int> lg, dep;
    Tree(int n){
        this -> n = n;
        ver.resize(n + 1);
        val.resize(n + 1, vector<int>(30));
        Max.resize(n + 1, vector<int>(30));
        lg.resize(n + 1);
        dep.resize(n + 1);
        for (int i = 1; i <= n; i++){
            lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
        }
    }
    void add(int x, int y, int w){
        ver[x].push_back({y, w});
        ver[y].push_back({x, w});
    }
    void dfs(int x, int fa){
        val[x][0] = fa;
        dep[x] = dep[fa] + 1;
        for (int i = 1; i <= lg[dep[x]]; i++){
            val[x][i] = val[val[x][i - 1]][i - 1];
            Max[x][i] = max(Max[x][i - 1], Max[val[x][i - 1]][i - 1]);
        }
        for (auto [y, w] : ver[x]){
            if (y == fa) continue;
            Max[y][0] = w;
            dfs(y, x);
        }
    }
    int lca(int x, int y){
        if (dep[x] < dep[y]) swap(x, y);
        while (dep[x] > dep[y]){
            x = val[x][lg[dep[x] - dep[y]] - 1];
        }
        if (x == y) return x;
        for (int k = lg[dep[x]] - 1; k >= 0; k--){
            if (val[x][k] == val[y][k]) continue;
            x = val[x][k];
            y = val[y][k];
        }
        return val[x][0];
    }
    int clac(int x, int y){
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    }
    int query(int x, int y){
        // 查询 x - y 路径上的最大边权
        auto get = [&](int x, int y) -> int{
            int ans = 0;
            if (x == y) return ans;
            for (int i = lg[dep[x]]; i >= 0; i--){
                if (dep[val[x][i]] > dep[y]){
                    ans = max(ans, Max[x][i]);
                    x = val[x][i];
                }
            }
            ans = max(ans, Max[x][0]);
            return ans;
        };
        int fa = lca(x, y);
        return max(get(x, fa), get(y, fa));
    }
    int intersection(int x, int y, int X, int Y){ 
        // 计算路径 x - y 与路径 X - Y 两条路径的交点数
        vector<int> t = {lca(x, X), lca(x, Y), lca(y, X), lca(y, Y)};
        sort(t.begin(), t.end());
        int r = lca(x, y), R = lca(X, Y);
        if (dep[t[0]] < min(dep[r], dep[R]) || dep[t[2]] < max(dep[r], dep[R])){
            return 0;
        }
        return 1 + clac(t[2], t[3]);
    }
    void work(int root = 1){
        dfs(root, 0);
    }
};