#include <bits/stdc++.h>
using namespace std;
struct Tree{
    int n;
    vector<vector<int>> ver, val;
    vector<int> lg, dep;
    Tree(int n){
        this -> n = n;
        ver.resize(n + 1);
        val.resize(n + 1, vector<int>(30));
        lg.resize(n + 1);
        dep.resize(n + 1);
        // lg[0] = -1;
        for (int i = 1; i <= n; i++){ // 多 1
            lg[i] = lg[i - 1] + ((1 << lg[i - 1]) == i);
            // lg[i] = lg[i / 2] + 1;
        }
    }
    void add(int x, int y){
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    void dfs(int x, int fa){
        val[x][0] = fa;
        dep[x] = dep[fa] + 1;
        for (int i = 1; i <= lg[dep[x]]; i++){ // ?
            val[x][i] = val[val[x][i - 1]][i - 1];
        }
        for (auto y : ver[x]){
            if (y == fa) continue;
            dfs(y, x);
        }
    }
    int lca(int x, int y){
        if (dep[x] < dep[y]) swap(x, y);
        while (dep[x] > dep[y]){
            x = val[x][lg[dep[x] - dep[y]] - 1];
        }
        if (x == y) return x;
        for (int k  = lg[dep[x]] - 1; k >= 0; k--){
            if (val[x][k] == val[y][k]) continue;
            x = val[x][k];
            y = val[y][k];
        }
        return val[x][0];
    }
    int clac(int x, int y){
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
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
int main(){
    int n, m;
    cin >> n >> m;
    Tree tr(n);
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        tr.add(u, v);
    }
    tr.work();
    int x, y;
    cin >> x >> y;
    cout << tr.lca(x, y);
}