#include <iostream>
#include <vector>
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

    T range(int L, int R)
    {
        return sum(R) - sum(L - 1);
    }

    int select(const T &k) // 小于等于 k 的最大位置
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
signed main()
{
    Fenwick<int> tr(10);
    tr.add(5, 2);
    tr.add(7, 2);
    cout << tr.select(3) << endl;
    return 0;
}