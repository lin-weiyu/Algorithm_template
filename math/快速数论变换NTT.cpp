#include <bits/stdc++.h>
#define LL long long
using namespace std;

template <int T>
struct MInt {
    int x;
    MInt() : x(0) {}
    MInt(int y) : x(y % T) { if (x < 0) x += T; }
    MInt operator+(const MInt &y) const { return MInt((x + y.x) % T); }
    MInt operator-(const MInt &y) const { return MInt((x - y.x + T) % T); }
    MInt operator*(const MInt &y) const { return MInt(1LL * x * y.x % T); }
    MInt& operator+=(const MInt &y) { x = (x + y.x) % T; return *this; }
    MInt& operator-=(const MInt &y) { x = (x - y.x + T) % T; return *this; }
    MInt& operator*=(const MInt &y) { x = 1LL * x * y.x % T; return *this; }
    bool operator==(const MInt &y) const { return x == y.x; }
    bool operator!=(const MInt &y) const { return x != y.x; }
    friend ostream& operator<<(ostream &os, const MInt &m) { return os << m.x; }
};
constexpr int mod=1e9+7;
  
using Z=MInt<mod>;
// mod  一定要满足 mod = len * k + 1; len 为 2 的次幂长度  一定要注意模数的选取！！！
// ntt 从 0 - n 的位置依次存放权值从小到大的
struct Polynomial
{
    vector<Z> z;
    vector<int> r;
    Polynomial(vector<int> &a)
    {
        int n = a.size();
        z.resize(n);
        r.resize(n);
        for (int i = 0; i < n; i++)
        {
            z[i] = a[i];
            r[i] = (i & 1) * (n / 2) + r[i / 2] / 2;
        }
        ntt(z, n, 1);
    }
    LL power(LL a, int b)
    {
        LL res = 1;
        for (; b; b /= 2, a = a * a % mod)
        {
            if (b % 2)
            {
                res = res * a % mod;
            }
        }
        return res;
    }
    void ntt(vector<Z> &a, int n, int opt)
    {
        for (int i = 0; i < n; i++)
        {
            if (r[i] < i)
            {
                swap(a[i], a[r[i]]);
            }
        }
        for (int k = 2; k <= n; k *= 2)
        {
            Z gn = power(3, (mod - 1) / k);
            for (int i = 0; i < n; i += k)
            {
                Z g = 1;
                for (int j = 0; j < k / 2; j++, g *= gn)
                {
                    Z t = a[i + j + k / 2] * g;
                    a[i + j + k / 2] = a[i + j] - t;
                    a[i + j] = a[i + j] + t;
                }
            }
        }
        if (opt == -1)
        {
            reverse(a.begin() + 1, a.end());
            Z inv = power(n, mod - 2);
            for (int i = 0; i < n; i++)
            {
                a[i] *= inv;
            }
        }
    }
};
/*输入：
5
0 1
10 10
10 11
101 101
110 110
*/

/*输出：进制为 sqrt(-2)时
0
100
110
1
10110100
*/

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    int len = 1;
    while (len < n * 2 || len < m * 2) len <<= 1;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++){
        a[i] = s1[i] - '0';
    }
    for (int i = 0; i < m; i++){
        b[i] = s2[i] - '0';
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    a.resize(len);
    b.resize(len);
    Polynomial f1(a), f2(b);
    for (int i = 0; i < len; i++){
        f1.z[i] = f1.z[i] * f2.z[i];
    }
    f1.ntt(f1.z, len, -1);
    len = n + m - 1;
    vector<int> ans(len + 100);
    for (int i = 0; i < len; i++){
        // cout << f1.z[i].x << " ";
        ans[i] = f1.z[i].x;
    }
    // cout << endl;
    for (int i = 0; i <= len; i++){
        // cout << ans[i] << " ";
        if (i == ans.size()) break;
        if (ans[i] > 1){
            ans[i + 2] -= ans[i] / 2;
            ans[i] %= 2;
            len = max(len, i + 2);
        }
        if(ans[i] < 0){
            ans[i + 2] += -ans[i] / 2;
            ans[i] %= 2;
            if (ans[i] < 0){
                ans[i] = 1;
                ans[i + 2]++;
            }
            len = max(len, i + 2);
        }
    }
    // cout << endl;
    while (ans[len] == 0) len--;
    len = max(len, 0);
    for (int i = len; i >= 0; i--) cout << ans[i];
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}