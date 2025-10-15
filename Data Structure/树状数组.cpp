#include <bits/stdc++.h>
using namespace std;
template <class T>
struct Fenwick
{
    int n;
    vector<T> t;
    Fenwick(T n) : n(n) { t.assign(n + 1, T{}); }       
    void add(int x, const T &v)           
    {
        for (int i = x; i <= n; i += i & -i)
        {
            t[i] += v;
        }
    }
    T sum(int x)
    {
        assert(x >= 0);
        int res = 0;
        for (int i = x; i; i -= i & -i)
        {
            res += t[i];
        }
        return res;
    }
    T range(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
    int select(const T &k)                  
    {
        int x = 0;
        T cur{};
        for (int i = 1 << __lg(n); i; i /= 2)
        {
            if (x + i <= n && cur + t[x + i] <= k)
            {
                x += i;
                cur += t[x];
            }
        }
        return x;
    }
};

template<class T> struct BIT{
    int n;
    vector<T> w, chk;
    BIT(int n, auto &in) : n(n), w(n + 1), chk(in){
        // 预处理填值
        for (int i = 1; i <= n; i++){
            add(i, in[i]);
        }
    }
    void add(int x, T v){
        for (; x <= n; x += x & -x){
            w[x] += v;
        }
    }
    T ask(int x){
        // 前缀和查询
        T ans = 0;
        for (; x; x -= x & -x){
            ans += w[x];
        }
        return ans;
    }
    T ask(int l, int r){
        // 差分实现区间和查询
        return ask(r) - ask(l - 1);
    }
    int get(){
        // 统计逆序对的个数
        vector<array<int, 2>> alls;
        for (int i = 1; i <= n; i++){
            alls.push_back({chk[i], i});
        }
        sort(alls.begin(), alls.end());
        int ans = 0;
        for (auto [val, idx] : alls){
            ans += ask(idx + 1, n);
            add(idx, 1);
        }
        return ans;
    }
};