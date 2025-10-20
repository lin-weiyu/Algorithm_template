#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 1 << 20;  // 支持长度1e6级别的多项式
const int MOD = 998244353, G = 3, Gi = 332748118;  // 模数、原根及其逆元

class NTT_Solver {
private:
    vector<int> rev;

    ll qpow(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void ntt(vector<ll>& a, int lim, int type) {
        for (int i = 0; i < lim; ++i)
            if (i < rev[i]) swap(a[i], a[rev[i]]);

        for (int mid = 1; mid < lim; mid <<= 1) {
            ll wn = qpow(type == 1 ? G : Gi, (MOD - 1) / (mid << 1));
            for (int j = 0; j < lim; j += (mid << 1)) {
                ll w = 1;
                for (int k = 0; k < mid; ++k, w = w * wn % MOD) {
                    ll x = a[j + k], y = w * a[j + k + mid] % MOD;
                    a[j + k] = (x + y) % MOD;
                    a[j + k + mid] = (x - y + MOD) % MOD;
                }
            }
        }

        if (type == -1) {
            ll inv_lim = qpow(lim, MOD - 2);
            for (int i = 0; i < lim; ++i) 
                a[i] = a[i] * inv_lim % MOD;
        }
    }

public:
    vector<ll> solve(const vector<ll>& b, const vector<ll>& c) {
        int n = b.size(), m = c.size();
        int lim = 1, l = 0;
        while (lim < n + m) lim <<= 1, l++;

        rev.resize(lim);
        for (int i = 0; i < lim; ++i)
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));

        vector<ll> fb(lim), fc(lim);
        // 反转数组b并补零
        for (int i = 0; i < n; ++i) fb[i] = b[n - 1 - i];
        for (int i = 0; i < m; ++i) fc[i] = c[i];

        ntt(fb, lim, 1);  // 正变换
        ntt(fc, lim, 1);
        for (int i = 0; i < lim; ++i) fb[i] = fb[i] * fc[i] % MOD;
        ntt(fb, lim, -1);  // 逆变换

        // 截取有效部分（a_i对应卷积结果的第n-1到n+m-2项）
        vector<ll> a(m);
        for (int i = 0; i < m; ++i) 
            a[i] = fb[n - 1 + i];
        return a;
    }
};

/* 使用示例 */
int main() {
    vector<ll> b = {1, 2, 3};      // 数组b
    vector<ll> c = {4, 5, 6, 7};   // 数组c
    NTT_Solver solver;
    vector<ll> a = solver.solve(b, c);

    for (ll x : a) cout << x << " ";  // 输出结果：32 38 20 7 
    return 0;
}