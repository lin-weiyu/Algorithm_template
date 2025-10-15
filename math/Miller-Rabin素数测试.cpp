#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mul(int a, int b, int m)
{
    int r = a * b - m * (int)(1.L / m * a * b);
    return r - m * (r >= m) + m * (r < 0);
}
int mypow(int a, int b, int m)
{
    int res = 1 % m;
    for (; b; b >>= 1, a = mul(a, a, m))
    {
        if (b & 1)
        {
            res = mul(res, a, m);
        }
    }
    return res;
}
int B[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
bool MR(int n)
{
    if (n <= 1)
        return 0;
    for (int p : B)
    {
        if (n == p)
            return 1;
        if (n % p == 0)
            return 0;
    }
    int m = (n - 1) >> __builtin_ctz(n - 1);
    for (int p : B)
    {
        int t = m, a = mypow(p, m, n);
        while (t != n - 1 && a != 1 && a != n - 1)
        {
            a = mul(a, a, n);
            t *= 2;
        }
        if (a != n - 1 && t % 2 == 0)
            return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    auto t1 =clock();
    ll L, R;
    cin >> L >> R;
    for (ll i = i; i <= R; i++){
        bool k = MR(i);
    }
    auto t2 = clock();
    cout << t2 - t1 << endl;
}