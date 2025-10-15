#include <bits/stdc++.h>
#define GL (k << 1)
#define GR (k << 1 | 1)
#define i64 long long
using namespace std;
template<class T> struct Segt_{
    struct node{
        int pl, pr;
        T w;
        bool lazy;
    };
    vector<T> w;
    vector<node> t;
    Segt_(){}
    void init(vector<int> in){
        int n = in.size() - 1;
        w.resize(n * 4 + 1);
        for (int i = 0; i <= n; i++){
            w[i] = in[i];
        }
        t.resize(n * 4 + 1);
        build(1, n);
    }
    void pushdown(node &p, bool lazy = 1){
        p.w = (p.pr - p.pl + 1) - p.w;
        p.lazy ^= lazy;
    }
    void pushup(node &p, node &pl, node &pr){
        p.w = pl.w + pr.w;
    }
    void pushdown(int k){
        if (t[k].lazy == 0) return;
        pushdown(t[GL]), pushdown(t[GR]);
        t[k].lazy = 0;
    }
    void pushup(int k){
        pushup(t[k], t[GL], t[GR]);
    }
    void build(int pl, int pr, int k = 1){
        if (pl == pr){
            t[k] = {pl, pr, w[pl], 0};
            return ;
        }
        t[k] = {pl, pr};
        int mid = (pl + pr) / 2;
        build(pl, mid, GL);
        build(mid + 1, pr, GR);
        pushup(k);
    }
    void reverse(int pl, int pr, int k = 1){
        if (pl <= t[k].pl && t[k].pr <= pr){
            pushdown(t[k], 1);
            return;
        }
        pushdown(k);
        int mid = (t[k].pl + t[k].pr) / 2;
        if (pl <= mid) reverse(pl, pr, GL);
        if (mid < pr) reverse(pl, pr, GR);
        pushup(k);
    }
    T ask(int L, int R, int k = 1){
        if (L <= t[k].pl && t[k].pr <= R){
            return t[k].w;
        }
        pushdown(k);
        int mid = (t[k].pl + t[k].pr) / 2;
        T ans = 0;
        if (L <= mid) ans += ask(L, R, GL);
        if (mid < R) ans += ask(L, R, GR);
        return ans;
    }
};
/*
5
1 2 3 4 5
对 [1, 3] 区间进行 x = 3 (0011) 的翻转， 则：
1 (0001) -> 2 (0010)
2 (0010) -> 1 (0001)
3 (0011) -> 0 (0000)
*/
signed main(){
    int n;
    cin >> n;
    vector in(20, vector<int>(n + 1));
    Segt_<i64> segt[20];
    for (int i = 1, x; i <= n; i++){
        cin >> x;
        for (int bit = 0; bit < 20; bit++){
            in[bit][i] = x >> bit & 1;
        }
    }
    for (int i = 0; i < 20; i++){
        segt[i].init(in[i]);
    }
    int m, op;
    for (cin >> m; m; m--){
        cin >> op;
        // 操作一：求 [L, R] 区间上的和
        if (op == 1){
            int L, R;
            i64 ans = 0;
            cin >> L >> R;
            for (int i = 0; i < 20; i++){
                ans += segt[i].ask(L, R) * (1LL << i);
            }
            cout << ans << endl;
        }
        // 操作二：对[L, R] 上每一位数字的二进制根据给出的x进行翻转
        else{
            int L, R, val;
            cin >> L >> R >> val;
            for (int i = 0; i < 20; i++){
                if (val >> i & 1){
                    segt[i].reverse(L, R);
                }
            }
        }
    }
}