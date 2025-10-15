#include <bits/stdc++.h>
using namespace std;
struct Segt
{
    struct node
    {
        int pl, pr, w, lazy;
    };
    vector<int> w;
    vector<node> t;
    Segt() {}
#define GL (k << 1)
#define GR (k << 1 | 1)
    void init(vector<int> in)
    {
        int n = in.size() - 1;
        w.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            w[i] = in[i];
        }
        t.resize(n * 4 + 1);
        auto build = [&](auto self, int pl, int pr, int k = 1)
        {
            if (pl == pr)
            {
                t[k] = {pl, pr, w[pl], 0}; // 如果有赋值为 0 的操作，则懒标记必须要 -1
                return;
            }
            t[k] = {pl, pr};
            int mid = (pl + pr) / 2;
            self(self, pl, mid, GL);
            self(self, mid + 1, pr, GR);
            pushup(k);
        };
        build(build, 1, n);
    }
    void pushdown(node &p, int lazy)
    { /* 【在此更新下递函数】 */
        p.w += (p.pr - p.pl + 1) * lazy;
        p.lazy += lazy;
    }
    void pushdown(int k)
    { // 不需要动
        if (t[k].lazy == 0)
            return;
        pushdown(t[GL], t[k].lazy);
        pushdown(t[GR], t[k].lazy);
        t[k].lazy = 0;
    }
    void pushup(int k)
    {                                                  // 不需要动
        auto pushup = [&](node &p, node &pl, node &pr) { /* 【在此更新上传函数】 */
            p.w = pl.w + pr.w;
        };
        pushup(t[k], t[GL], t[GR]);
    }
    void modify(int pl, int pr, int val, int k = 1)
    {
        if (pl <= t[k].pl && t[k].pr <= pr)
        {
            pushdown(t[k], val);
            return;
        }
        pushdown(k);
        int mid = (t[k].pl + t[k].pr) / 2;
        if (pl <= mid)
            modify(pl, pr, val, GL);
        if (mid < pr)
            modify(pl, pr, val, GR);
        pushup(k);
    }
    int ask(int pl, int pr, int k = 1)
    {
        if (pl <= t[k].pl && t[k].pr <= pr)
        {
            return t[k].w;
        }
        pushdown(k);
        int mid = (t[k].pl + t[k].pr) / 2;
        int ans = 0;
        if (pl <= mid)
            ans += ask(pl, pr, GL);
        if (mid < pr)
            ans += ask(pl, pr, GR);
        return ans;
    }
};
struct HLD
{
    int n, idx;
    vector<vector<int>> ver;
    vector<int> siz, dep;
    vector<int> top, son, parent;
    vector<int> in, id, val;
    Segt segt;
    HLD(int n)
    {
        this->n = n;
        ver.resize(n + 1);
        siz.resize(n + 1);
        dep.resize(n + 1);
        top.resize(n + 1);
        son.resize(n + 1);
        parent.resize(n + 1);
        idx = 0;
        in.resize(n + 1);
        id.resize(n + 1);
        val.resize(n + 1);
    }
    void add(int x, int y)
    { // 建立双向边
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    void dfs1(int x)
    {
        siz[x] = 1;
        dep[x] = dep[parent[x]] + 1;
        for (auto y : ver[x])
        {
            if (y == parent[x])
                continue;
            parent[y] = x;
            dfs1(y);
            siz[x] += siz[y];
            if (siz[y] > siz[son[x]])
            {
                son[x] = y;
            }
        }
    }
    void dfs2(int x, int up)
    {
        id[x] = ++idx;
        val[idx] = in[x]; // 建立编号
        top[x] = up;
        if (son[x])
            dfs2(son[x], up);
        for (auto y : ver[x])
        {
            if (y == parent[x] || y == son[x])
                continue;
            dfs2(y, y);
        }
    }
    void modify(int pl, int pr, int val)
    { // 链上修改
        while (top[pl] != top[pr])
        {
            if (dep[top[pl]] < dep[top[pr]])
            {
                swap(pl, pr);
            }
            segt.modify(id[top[pl]], id[pl], val);
            pl = parent[top[pl]];
        }
        if (dep[pl] > dep[pr])
        {
            swap(pl, pr);
        }
        segt.modify(id[pl], id[pr], val);
    }
    void modify(int root, int val)
    { // 子树修改
        segt.modify(id[root], id[root] + siz[root] - 1, val);
    }
    int ask(int pl, int pr)
    { // 链上查询
        int ans = 0;
        while (top[pl] != top[pr])
        {
            if (dep[top[pl]] < dep[top[pr]])
            {
                swap(pl, pr);
            }
            ans += segt.ask(id[top[pl]], id[pl]);
            pl = parent[top[pl]];
        }
        if (dep[pl] > dep[pr])
        {
            swap(pl, pr);
        }
        return ans + segt.ask(id[pl], id[pr]);
    }
    int ask(int root)
    { // 子树查询
        // 询问从该节点开始往下到该条链尾的值
        return segt.ask(id[root], id[root] + siz[root] - 1);
    }
    void work(auto in, int root = 1)
    { // 在此初始化
        assert(in.size() == n + 1);
        this->in = in;
        dfs1(root);
        dfs2(root, root);
        segt.init(val); // 建立线段树
    }
    void work(int root = 1)
    { // 在此初始化
        dfs1(root);
        dfs2(root, root);
        segt.init(val); // 建立线段树
    }
};
