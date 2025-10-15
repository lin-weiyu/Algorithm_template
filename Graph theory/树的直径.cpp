#include <bits/stdc++.h>
using namespace std;
struct Tree{
    int n;
    vector<vector<int>> ver;
    Tree(int n){
        this -> n = n;
        ver.resize(n + 1);
    }
    void add(int x, int y){
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    int getlen(int root){// 获取 x 所在树的直径
        map<int, int> dep; // map 用于优化输入为森林时的深度计算
        function<void(int, int)> dfs = [&](int x, int fa) -> void{
            for (auto y : ver[x]){
                if (y == fa) continue;
                dep[y] = dep[x] + 1;
                dfs(y, x);
            }
            if (dep[x] > dep[root]){
                root = x;
            }
        };
        dfs(root, 0);
        int st = root;
        dep.clear();
        dfs(root, 0);
        int ed = root;
        return dep[root];
    }
};