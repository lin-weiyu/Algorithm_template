#include <bits/stdc++.h>
using namespace std;
int x, y;
int exgcd(int a, int b, int &x, int &y){
    // 求解 a * x + b * y == __gcd(a, b)的任意一组解
    if (b == 0){
        x = 1, y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int temp = y;
    y = x - (a / b) * y;
    x = temp;
    return r; // 得到a b 的最大公因数
}
int getInv(int a, int mod){
    // 求 a 在 mod 下的逆元, 不存在逆元返回 -1
    int x, y, d = exgcd(a, mod, x, y);
    return d == 1 ? (x % mod + mod) % mod : -1;
}


const int N = 1e6 + 10;
const int P = 998244353;
vector<int> inv(N);
void get_inv(int n){
    inv[1] = 1;
    for (int i = 2; i <= n; i++){
        inv[i] = (P - P / i) * inv[P % i] % P;
    }
}

auto clac = [&](int a, int b, int c){
    // 求解 a * x + b * y == c 的解
    int u = 1, v = 1;
    if (a < 0){
        a = -a;
        u = -1;
    }
    if (b < 0){
        b = -b;
        v = -1;
    }
    int x, y, d = exgcd(a, b, x, y), ans;
    if (c % d != 0){
        // 无整数解
        return -1;
    }
    a /= d, b /= d, c /= d;
    x *= c, y *= c; // 得到可行解
    ans = (x % b + b - 1) % b + 1;
    auto [A, B] = pair{u * ans, v * (c - ans * a) / b}; // x 为最小正整数解，特解
    ans = (y % a + a - 1) % a + 1;
    auto [C, D] = pair{u * (c - ans * b) / a, v * ans}; // y 为最小正整数解，特解
    int num = (C - A) / b + 1; // x y 均为正整数的解的组数
    return A;
};