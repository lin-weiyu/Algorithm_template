#include <bits/stdc++.h>
#define LL long long
using namespace std;

template <int P>
struct MInt
{
    int x;
    constexpr MInt() : x(0) {}
    template <class T>
    MInt(T x) : x(norm(x % P)) {}
    constexpr static int norm(int x)
    {
        return x < 0 ? x + P : x >= P ? x - P
                                      : x;
    }
    constexpr MInt power(MInt x, MInt k)
    {
        MInt res = 1;
        while (k)
        {
            if (k.x & 1)
                res = res * x;
            x = x * x;
            k /= 2;
        }
        return res;
    }
    constexpr MInt inv() const
    {
        int a = x, b = P, u = 1, v = 0;
        while (b)
        {
            int t = a / b;
            swap((a -= t * b), b);
            swap((u -= t * v), v);
        }
        return u;
    }
    constexpr MInt operator-() const
    {
        return MInt() - *this;
    }
    constexpr MInt &operator+=(const MInt &a)
    {
        x = norm(x + a.x);
        return *this;
    }
    constexpr MInt &operator-=(const MInt &a)
    {
        x = norm(x - a.x);
        return *this;
    }
    constexpr MInt &operator*=(const MInt &a)
    {
        x = 1ll * x * a.x % P;
        return *this;
    }
    constexpr MInt &operator/=(const MInt &a)
    {
        return *this *= a.inv();
    }
    constexpr friend MInt operator+(MInt l, const MInt &r)
    {
        return l += r;
    }
    constexpr friend MInt operator-(MInt l, const MInt &r)
    {
        return l -= r;
    }
    constexpr friend MInt operator*(MInt l, const MInt &r)
    {
        return l *= r;
    }
    constexpr friend MInt operator/(MInt l, const MInt &r)
    {
        return l /= r;
    }
    constexpr explicit operator bool() const
    {
        return x != 0;
    }
    constexpr bool operator!() const
    {
        return x == 0;
    }
    friend ostream &operator<<(ostream &os, const MInt &a)
    {
        return os << a.x;
    }
    string find_Fraction() const
    {
        for (int i = 1; i <= 1000000; ++i)
        {
            if ((*this * i).x <= 100)
            {
                return to_string((*this * i).x) + "/" + to_string(i);
            }
        }
        return "not find.";
    }
};

constexpr int mod = 1e9 + 7;

using Z = MInt<mod>;
struct Lagrange
{
    int n;
    vector<Z> x, y, fac, invfac;
    Lagrange(int n)
    {
        this->n = n;
        x.resize(n + 3);
        y.resize(n + 3);
        fac.resize(n + 3);
        invfac.resize(n + 3);
        init(n);
    }
    void init(int n)
    {
        iota(x.begin(), x.end(), 0);
        for (int i = 1; i <= n + 2; i++)
        {
            Z t;
            y[i] = y[i - 1] + t.power(i, n);
        }
        fac[0] = 1;
        for (int i = 1; i <= n + 2; i++)
        {
            fac[i] = fac[i - 1] * i;
        }
        invfac[n + 2] = fac[n + 2].inv();
        for (int i = n + 1; i >= 0; i--)
        {
            invfac[i] = invfac[i + 1] * (i + 1);
        }
    }
    Z solve(LL k)
    {
        if (k <= n + 2)
        {
            return y[k];
        }
        vector<Z> sub(n + 3);
        for (int i = 1; i <= n + 2; i++)
        {
            sub[i] = k - x[i];
        }
        vector<Z> mul(n + 3);
        mul[0] = 1;
        for (int i = 1; i <= n + 2; i++)
        {
            mul[i] = mul[i - 1] * sub[i];
        }
        Z ans = 0;
        for (int i = 1; i <= n + 2; i++)
        {
            ans = ans + y[i] * mul[n + 2] * sub[i].inv() * pow(-1, n + 2 - i) * invfac[i - 1] * invfac[n + 2 - i];
        }
        return ans;
    }
};
