#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1 << 20;  // 支持长度1e6级别的多项式
const int MOD = 998244353; // 常用模数
const int G = 3;           // 原根
const int Gi = 332748118;  // 逆原根：G^(MOD-2) % MOD

class NTT_Convolution {
private:
    // 快速幂取模
    static ll qpow(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    // 位逆序置换
    static void bitReverse(vector<ll>& a, const vector<int>& rev) {
        int n = a.size();
        for (int i = 0; i < n; i++) 
            if (i < rev[i]) swap(a[i], a[rev[i]]);
    }

    // NTT核心变换
    static void ntt(vector<ll>& a, int lim, int type, const vector<int>& rev) {
        bitReverse(a, rev);
        for (int mid = 1; mid < lim; mid <<= 1) {
            ll wn = qpow(type == 1 ? G : Gi, (MOD - 1) / (mid << 1));
            for (int j = 0; j < lim; j += (mid << 1)) {
                ll w = 1;
                for (int k = 0; k < mid; k++, w = w * wn % MOD) {
                    ll x = a[j + k], y = w * a[j + k + mid] % MOD;
                    a[j + k] = (x + y) % MOD;
                    a[j + k + mid] = (x - y + MOD) % MOD;
                }
            }
        }
        if (type == -1) {
            ll inv_lim = qpow(lim, MOD - 2);
            for (int i = 0; i < lim; i++) 
                a[i] = a[i] * inv_lim % MOD;
        }
    }

public:
    // 计算卷积结果 a_i = sum_j b_j * c_{i+j}
    static vector<ll> compute(const vector<ll>& b, const vector<ll>& c) {
        int n = b.size(), m = c.size();
        int lim = 1, l = 0;
        while (lim < n + m) lim <<= 1, l++;

        vector<int> rev(lim);
        for (int i = 0; i < lim; i++)
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));

        vector<ll> fb(lim), fc(lim);
        // 反转数组b并补零
        for (int i = 0; i < n; i++) fb[i] = b[n - 1 - i];
        for (int i = 0; i < m; i++) fc[i] = c[i];

        ntt(fb, lim, 1, rev);  // 正变换
        ntt(fc, lim, 1, rev);
        for (int i = 0; i < lim; i++) fb[i] = fb[i] * fc[i] % MOD;
        ntt(fb, lim, -1, rev); // 逆变换

        // 截取有效部分（a_i对应卷积结果的第n-1到n+m-2项）
        vector<ll> res(m);
        for (int i = 0; i < m; i++) 
            res[i] = fb[n - 1 + i];
        return res;
    }
};

/* 使用示例 */
int main() {
    vector<ll> b = {1, 2, 3};      // 数组b
    vector<ll> c = {4, 5, 6, 7};   // 数组c
    vector<ll> a = NTT_Convolution::compute(b, c);

    for (ll x : a) cout << x << " ";  // 输出：32 38 20 7 
    return 0;
}