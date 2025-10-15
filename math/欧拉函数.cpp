#include <bits/stdc++.h>
using namespace std;
int phik(int n){
    // 求解 n 的欧拉函数值
    int ans = n;
    for (int i = 2; i <= n; i++){
        if (n % i == 0){
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

const int N = 1e5 + 7;
int v[N], prime[N], phi[N];
void euler(int n){
    // 求解 1 - n 区间内每个数的欧拉函数值
    int m = 0;
    for (int i = 2; i <= n; i++){
        if (v[i] == 0){
            v[i] = i;
            prime[++m] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= m; j++){
            if (prime[j] > v[i] || prime[j] > n / i) break;
            v[i * prime[j]] = prime[j];
            phi[i * prime[j]] = phi[i] * (i % prime[j] ? prime[j] - 1 : prime[j]);
        }
    }
}