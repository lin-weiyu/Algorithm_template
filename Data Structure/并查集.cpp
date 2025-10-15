#include <bits/stdc++.h>
using namespace std;
struct DSU{
    vector<int> fa, p, e, f;
    DSU(int n){
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        p.resize(n + 1);
        e.resize(n + 1);
        f.resize(n + 1);
    }
    int get(int x){
        while (x != fa[x]){
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool merge(int x, int y){
        if (x == y) f[get(x)] = 1; // 存在自环
        x = get(x), y = get(y);
        e[x]++;
        if (x == y) return false;
        if (x < y) swap(x, y); // 编号小的合并到编号大的上
        fa[y] = x;
        f[x] |= f[y], p[x] += p[y], e[x] += e[y];
        return true;
    }
    bool same(int x, int y){
        return get(x) == get(y);
    }
    bool F(int x){ // 判断连通块内是否存在自环
        return f[get(x)];
    }
    int size(int x){ // 输出连通块中点的数量
        return p[get(x)]; 
    }
    int E(int x){ // 输出连通块中边的数量
        return e[get(x)];
    }
};