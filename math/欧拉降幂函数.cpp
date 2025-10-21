#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;

// 计算欧拉函数φ(m) [质因数分解法]
ll euler_phi(ll m) {
    ll res = m;
    for (ll i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            res = res / i * (i - 1);  // φ(m) = m * Π(1 - 1/p)
            while (m % i == 0) m /= i;
        }
    }
    if (m > 1) res = res / m * (m - 1);  // 处理剩余的质因数
    return res;
}

// 快速幂取模
ll qpow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;  // 防止a过大
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// 欧拉降幂核心函数：计算 a^b mod m（b为整数）
ll euler_pow(ll a, ll b, ll m) {
    if (m == 1) return 0;  // 任何数模1为0
    ll phi_m = euler_phi(m);
    // 扩展欧拉定理：若a与m不互质且b≥φ(m)，则指数需加φ(m)
    if (b >= phi_m && __gcd(a, m) != 1) {
        b = b % phi_m + phi_m;
    } else {
        b %= phi_m;  // 否则直接取模
    }
    return qpow(a, b, m);
}

/* 使用示例 */
int main() {
    ll a = 2, b = 1000, m = 10007;
    cout << euler_pow(a, b, m) << endl;  // 输出 2^1000 mod 10007
    return 0;
}