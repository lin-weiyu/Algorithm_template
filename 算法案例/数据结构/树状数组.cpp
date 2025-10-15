#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    Fenwick<int> tr(10);
    tr.add(2, 1);
    tr.add(4, 1);
    tr.add(7, 1);
    cout << tr.select(0) << endl;
    cout << tr.sum(1) << endl;
    cout << tr.range(4, 8) << endl;
}