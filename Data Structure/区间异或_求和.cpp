#include <bits/stdc++.h>
using namespace std;
#define GL (k << 1)
#define GR (k << 1 | 1)
#define i64 long long
const int N = 30;
struct Segt
{ // #define GL (k << 1) // #define GR (k << 1 | 1)
    struct node
    {
        int l, r;
        int w[N], lazy; // 注意这里为了方便计算，w 只需要存位
    };
    vector<int> base;
    vector<node> t;
    Segt(vector<int> in) : base(in)
    {
        int n = in.size() - 1;
        t.resize(n * 4 + 1);
        auto build = [&](auto self, int l, int r, int k = 1)
        {
            t[k] = {l, r}; // 前置赋值
            if (l == r)
            {
                for (int i = 0; i < N; i++)
                {
                    t[k].w[i] = base[l] >> i & 1;
                }
                return;
            }
            int mid = (l + r) / 2;
            self(self, l, mid, GL);
            self(self, mid + 1, r, GR);
            pushup(k);
        };
        build(build, 1, n);
    }
    void pushdown(node &p, int lazy)
    { /* 【在此更新下递函数】 */
        int len = p.r - p.l + 1;
        for (int i = 0; i < N; i++)
        {
            if (lazy >> i & 1)
            { // 即 p.w = (p.r - p.l + 1) - p.w;
                p.w[i] = len - p.w[i];
            }
        }
        p.lazy ^= lazy;
    }
    void pushdown(int k)
    { // 【不需要动】
        if (t[k].lazy == 0)
            return;
        pushdown(t[GL], t[k].lazy);
        pushdown(t[GR], t[k].lazy);
        t[k].lazy = 0;
    }
    void pushup(int k)
    {
        auto pushup = [&](node &p, node &l, node &r) { /* 【在此更新上传函数】 */
            for (int i = 0; i < N; i++)
            {
                p.w[i] = l.w[i] + r.w[i]; // 即 p.w = l.w + r.w;
            }
        };
        pushup(t[k], t[GL], t[GR]);
    }
    void modify(int l, int r, int val, int k = 1)
    { // 区间修改 对区间[L, R]内的每个数都异或上 val
        if (l <= t[k].l && t[k].r <= r)
        {
            pushdown(t[k], val);
            return;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        if (l <= mid)
            modify(l, r, val, GL);
        if (mid < r)
            modify(l, r, val, GR);
        pushup(k);
    }
    i64 ask(int l, int r, int k = 1)
    { // 区间求和
        if (l <= t[k].l && t[k].r <= r)
        {
            i64 ans = 0;
            for (int i = 0; i < N; i++)
            {
                ans += t[k].w[i] * (1LL << i);
            }
            return ans;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        i64 ans = 0;
        if (l <= mid)
            ans += ask(l, r, GL);
        if (mid < r)
            ans += ask(l, r, GR);
        return ans;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Segt tr(a);
    int q;
    cin >> q;
    for (int qk = 1; qk <= q; qk++)
    {
        int op, L, R, x;
        cin >> op;
        if (op == 1)
        {
            cin >> L >> R;
            cout << tr.ask(L, R) << endl;
        }
        else
        {
            cin >> L >> R >> x;
            tr.modify(L, R, x);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}