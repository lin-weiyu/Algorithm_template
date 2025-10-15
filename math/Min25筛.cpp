#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace min25{
    // 求解 1 - n 的质数的和，n 最大为1e10
    const int N = 1e6 + 10;
    int prime[N], id1[N], id2[N], flag[N], ncnt, m;
    ll g[N], sum[N], a[N], T;
    ll n, mod;
    inline ll ps(ll n, ll k){
        ll r = 1;
        for (; k; k >>= 1){
            if (k & 1){
                r = r * n % mod;
            }
            n = n * n % mod;
        }
        return r;
    }
    void finit(){
        // 最开始清 0 
        memset(g, 0, sizeof(g));
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
        memset(prime, 0, sizeof(prime));
        memset(id1, 0, sizeof(id1));
        memset(id2, 0, sizeof(id2));
        memset(flag, 0, sizeof(flag));
        ncnt = m = 0;
    }
    int ID(ll x){
        return x <= T ? id1[x] : id2[n / x];
    }
    ll calc(ll x){
        return x * (x + 1) / 2 - 1;
    }
    ll init(ll x){
        T = sqrt(x + 0.5);
        for (int i = 2; i <= T; i++){
            if (!flag[i]) prime[++ncnt] = i, sum[ncnt] = sum[ncnt - 1] + i;
            for (int j = 1; j <= ncnt && i * prime[j] <= T; j++){
                flag[i * prime[j]] = 1;
                if (i % prime[j] == 0) break;
            }
        }
        for (ll L = 1; L <= x; L = x / (x / L) + 1){
            a[++m] = x / L;
            if (a[m] <= T) id1[a[m]] = m;
            else id2[x / a[m]] = m;
            g[m] = calc(a[m]);
        }
        for (int i = 1; i <= ncnt; i++){
            for (int j = 1; j <= m && (ll) prime[i] * prime[i] <= a[j]; j++){
                g[j] = g[j] - (ll) prime[i] * (g[ID(a[j] / prime[i])] - sum[i - 1]);
            }
        }
    }
    ll solve(ll x){
        if (x <= 1) return x;
        return n = x, init(n), g[ID(n)];
    }
}

using namespace min25;

int main(){
    int tt;
    cin >> tt;
    while (tt--){
        finit();
        cin >> n >> mod;
        // cout << n << " " << mod << endl;
        // ll ans = (n + 3) % mod * n % mod * ps(2, mod - 2) % mod + solve(n + 1) - 4;
        // ans = (ans + mod) % mod;
        cout << solve(n) << endl;
    }
}