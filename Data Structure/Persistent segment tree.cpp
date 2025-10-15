#include <iostream>
#include <vector>
using namespace std;

struct PresidentTree
{
    struct node
    {
        int l, r;
        int cnt;
    };
    int cntNodes{}, n{};
    vector<int> root;
    vector<node> tr;

    PresidentTree(int n)
    {
        cntNodes = 0;
        this->n = n;
        root.resize(n << 7 | 1, 0);
        tr.resize(n << 7 | 1);
        build(root[0], 1, n);
    }

    void build(int &u, int l, int r)
    {                   // 建空树
        u = ++cntNodes; // 动态开点
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(tr[u].l, l, mid);
        build(tr[u].r, mid + 1, r);
    }

    void modify(int &u, int v, int l, int r, int x)
    {
        u = ++cntNodes;
        tr[u] = tr[v];
        tr[u].cnt++;
        if (l == r)
            return;
        int mid = (l + r) / 2;
        if (x <= mid)
            modify(tr[u].l, tr[v].l, l, mid, x);
        else
            modify(tr[u].r, tr[v].r, mid + 1, r, x);
    }

    void modify(int cur, int pre, int x)
    {
        modify(root[cur], root[pre], 1, n, x);
    }

    int kth(int u, int v, int l, int r, int k)
    {
        if (l == r)
            return l;
        int res = tr[tr[v].l].cnt - tr[tr[u].l].cnt;
        int mid = (l + r) / 2;
        if (k <= res)
            return kth(tr[u].l, tr[v].l, l, mid, k);
        else
            return kth(tr[u].r, tr[v].r, mid + 1, r, k - res);
    }

    int kth(int l, int r, int k) // 区间[L, R] 内第 k 大的数是多少
    {
        if (l > r)
            return 0;
        return kth(root[l - 1], root[r], 1, n, k);
    }

    int ask(int u, int v, int l, int r, int k)
    {
        if (l == r)
            return tr[v].cnt - tr[u].cnt;
        int mid = (l + r) / 2;
        int ans = 0;
        if (k <= mid)
            ans += ask(tr[u].l, tr[v].l, l, mid, k);
        else
        {
            ans += tr[tr[v].l].cnt - tr[tr[u].l].cnt;
            ans += ask(tr[u].r, tr[v].r, mid + 1, r, k);
        }
        return ans;
    }

    int ask(int l, int r, int k) // 区间[L, R] 内比 k 小的数有几个
    {
        if (l > r)
            return 0;
        return ask(root[l - 1], root[r], 1, n, k);
    }
};