//P3807
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
typedef long long ll;
// mod 为质数时， C(n, m) % mod = C(n / mod, m / mod) * C(n % mod, m % mod) % mod
// 当 mod 不为质数时使用扩展卢卡斯定理

// 快速幂计算 a^b mod p
ll qpow(ll a, ll b, ll p) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

// 预处理阶乘和逆元（需保证 p 是质数）
vector<ll> fac, inv_fac;
void init(int p) {
    fac.resize(p + 1);
    inv_fac.resize(p + 1);
    fac[0] = 1;
    for (int i = 1; i <= p; i++) 
        fac[i] = fac[i - 1] * i % p;
    inv_fac[p - 1] = qpow(fac[p - 1], p - 2, p); // 费马小定理求逆元
    for (int i = p - 2; i >= 0; i--) 
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % p;
}

// 计算组合数 C(n, m) mod p（需 n, m < p）
ll C(ll n, ll m, ll p) {
    if (m > n) return 0;
    return fac[n] * inv_fac[m] % p * inv_fac[n - m] % p;
}

// 卢卡斯定理递归实现
ll lucas(ll n, ll m, ll p) {
    if (m == 0) return 1;
    return C(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}

void solve1() {
    int T;
    cin >> T;
    while (T--) {
        ll n, m, p;
        cin >> n >> m >> p;
        init(p); // 预处理阶乘和逆元
        cout << lucas(n, m, p) << endl; // 示例：计算 C(n+m, m) mod p
    }
}
int main(){

}