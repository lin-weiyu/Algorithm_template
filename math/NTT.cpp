#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1 << 20;  // 支持长度1e6级别的多项式
const int MOD = 998244353; // 常用模数
const int G = 3;           // 原根
const int Gi = 332748118;  // 逆原根：G^(MOD-2) % MOD

class NTT {
private:
    // 快速幂取模
    ll qpow(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    // NTT核心变换
    void ntt(vector<ll>& a, int lim, int type) {
        // 蝴蝶变换
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
    }

public:
    vector<int> rev;

    // 计算多项式乘法
    vector<ll> multiply(const vector<ll>& a, const vector<ll>& b) {
        int n = a.size(), m = b.size();
        int lim = 1, l = 0;
        while (lim <= n + m) lim <<= 1, l++;
        rev.resize(lim);

        // 初始化蝴蝶变换索引
        for (int i = 0; i < lim; ++i)
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));

        vector<ll> fa(lim), fb(lim);
        copy(a.begin(), a.end(), fa.begin());
        copy(b.begin(), b.end(), fb.begin());

        ntt(fa, lim, 1);  // 正变换
        ntt(fb, lim, 1);
        for (int i = 0; i < lim; ++i) 
            fa[i] = fa[i] * fb[i] % MOD;
        ntt(fa, lim, -1); // 逆变换

        // 归一化并截取有效长度
        ll inv_lim = qpow(lim, MOD - 2);
        vector<ll> res(n + m - 1);
        for (int i = 0; i < n + m - 1; ++i) 
            res[i] = fa[i] * inv_lim % MOD;
        return res;
    }
};

/* 使用示例 */
int main() {
    vector<ll> a = {1, 2, 3};       // 多项式1的系数
    vector<ll> b = {4, 5, 6, 7};    // 多项式2的系数
    NTT ntt_solver;
    vector<ll> c = ntt_solver.multiply(a, b);

    for (ll x : c) cout << x << " "; // 输出卷积结果：4 13 28 34 32 21
    return 0;
}