#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int mygcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
ll gcd(ll a, ll b){ // 卡常gcd
    #define tz __builtin_ctzll
    if (!a || !b) return a | b;
    int t = tz(a | b);
    a >>= tz(a);
    while (b){
        b >>= tz(b);
        if (a > b) swap(a, b);
        b -= a;
    }
    return a << t;
    #undef tz
}