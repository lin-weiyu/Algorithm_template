#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

// 扩展欧几里得求逆元
void exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) { x = 1; y = 0; return; }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

// 求逆元（适用于模数非质数）
ll inv(ll a, ll p) {
    ll x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}

// 计算 n! 中除去质因子 p 后的部分 mod pk
ll fac(ll n, ll p, ll pk) {
    if (!n) return 1;
    ll ans = 1;
    // 循环节部分（每 pk 个数模 pk 结果相同）
    for (ll i = 1; i <= pk; i++) 
        if (i % p) ans = ans * i % pk;
    ans = qpow(ans, n / pk, pk);
    // 剩余部分
    for (ll i = n / pk * pk + 1; i <= n; i++)
        if (i % p) ans = ans * (i % pk) % pk;
    return ans * fac(n / p, p, pk) % pk; // 递归处理 p 的倍数
}

// 计算 C(n, m) mod p^k（p 是质数）
ll C_pk(ll n, ll m, ll p, ll pk) {
    if (m > n) return 0;
    // 计算质因子 p 的指数
    ll cnt = 0;
    for (ll i = n; i; i /= p) cnt += i / p;
    for (ll i = m; i; i /= p) cnt -= i / p;
    for (ll i = n - m; i; i /= p) cnt -= i / p;
    // 计算组合数模 p^k
    ll a = fac(n, p, pk), b = fac(m, p, pk), c = fac(n - m, p, pk);
    return qpow(p, cnt, pk) * a % pk * inv(b, pk) % pk * inv(c, pk) % pk;
}

// 中国剩余定理合并同余方程
ll CRT(const vector<ll> &a, const vector<ll> &m, ll p) {
    ll ans = 0, M = 1;
    for (ll mi : m) M *= mi;
    for (int i = 0; i < a.size(); i++) {
        ll Mi = M / m[i];
        ans = (ans + a[i] * Mi % p * inv(Mi, m[i]) % p) % p;
    }
    return ans;
}

// 扩展卢卡斯定理主函数
ll exLucas(ll n, ll m, ll p) {
    vector<ll> a, m_factors;
    ll tmp = p;
    // 质因数分解 p
    for (ll i = 2; i * i <= tmp; i++) {
        if (tmp % i == 0) {
            ll pk = 1;
            while (tmp % i == 0) tmp /= i, pk *= i;
            m_factors.push_back(pk);
            a.push_back(C_pk(n, m, i, pk));
        }
    }
    if (tmp > 1) {
        m_factors.push_back(tmp);
        a.push_back(C_pk(n, m, tmp, tmp));
    }
    // 中国剩余定理合并
    return CRT(a, m_factors, p);
}

int main() {
    ll n, m, p;
    cin >> n >> m >> p;
    cout << exLucas(n, m, p) << endl;
    return 0;
}