#include <bits/stdc++.h>
using namespace std;
vector<int> rev;
template <int T>
struct MInt {
    int x;
    MInt() : x(0) {}
    MInt(int y) : x(y % T) { if (x < 0) x += T; }
    MInt operator+(const MInt &y) const { return MInt((x + y.x) % T); }
    MInt operator-(const MInt &y) const { return MInt((x - y.x + T) % T); }
    MInt operator*(const MInt &y) const { return MInt(1LL * x * y.x % T); }
    MInt& operator+=(const MInt &y) { x = (x + y.x) % T; return *this; }
    MInt& operator-=(const MInt &y) { x = (x - y.x + T) % T; return *this; }
    MInt& operator*=(const MInt &y) { x = 1LL * x * y.x % T; return *this; }
    bool operator==(const MInt &y) const { return x == y.x; }
    bool operator!=(const MInt &y) const { return x != y.x; }
    friend ostream& operator<<(ostream &os, const MInt &m) { return os << m.x; }
};

template<int P>
struct MInt {
    int x;
    constexpr MInt(): x(0) {}
    template<class T>
    constexpr MInt(T x): x(norm(x%P)) {}
    constexpr static int norm(int x) {
        return x<0? x+P: x>=P? x-P: x;
    }
    constexpr MInt inv() const{
        int a=x, b=P, u=1, v=0;
        while(b) {
            int t = a/b;
            swap((a-=t*b), b);
            swap((u-=t*v), v);
        }
        return u;
    }
    constexpr MInt operator-() const{
        return MInt()-*this;
    }
    constexpr MInt& operator+=(const MInt& a) {
        x=norm(x+a.x);
        return *this;
    }
    constexpr MInt& operator-=(const MInt& a) {
        x=norm(x-a.x);
        return *this;
    }
    constexpr MInt& operator*=(const MInt& a) {
        x=1ll*x*a.x%P;
        return *this;
    }
    constexpr MInt& operator/=(const MInt& a) {
        return *this*=a.inv();
    }
    constexpr friend MInt operator+(MInt l,const MInt& r) {
        return l+=r;
    }
    constexpr friend MInt operator-(MInt l,const MInt& r) {
        return l-=r;
    }
    constexpr friend MInt operator*(MInt l,const MInt& r) {
        return l*=r;
    }
    constexpr friend MInt operator/(MInt l,const MInt& r) {
        return l/=r;
    }
    constexpr explicit operator bool()const {
        return x!=0;
    }
    constexpr bool operator!()const {
        return x==0;
    }
    friend ostream& operator<<(ostream& os,const MInt& a) {
        return os<<a.x;
    }
    string find_Fraction()const {
        for(int i=1; i<=1000000; ++i) {
            if((*this*i).x<=100) {
                return to_string((*this*i).x) + "/" + to_string(i);
            }
        }
        return "not find.";
    }
};

template <int P>
vector<MInt<P>> roots{0, 1};
template <int P>
constexpr MInt<P> findPrimitiveRoot()
{
    MInt<P> i = 2;
    int k = __builtin_ctz(P - 1);
    while (true)
    {
        if (power(i, (P - 1) / 2) != 1)
        {
            break;
        }
        i += 1;
    }
    return power(i, (P - 1) >> k);
}
template <int P>constexpr MInt<P> primitiveRoot = findPrimitiveRoot<P>();
template<> MInt<998244353> primitiveRoot<998244353> {31};
template <int P>
constexpr void dft(vector<MInt<P>> &a)
{ // 离散傅里叶变换
    int n = a.size();
    if (int(rev.size()) != n)
    {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; i++)
        {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (rev[i] < i)
        {
            swap(a[i], a[rev[i]]);
        }
    }
    if (roots<P>.size() < n)
    {
        int k = __builtin_ctz(roots<P>.size());
        roots<P>.resize(n);
        while ((1 << k) < n)
        {
            auto e = power(primitiveRoot<P>, 1 << (__builtin_ctz(P - 1) - k - 1));
            for (int i = 1 << (k - 1); i < (1 << k); i++)
            {
                roots<P>[2 * i] = roots<P>[i];
                roots<P>[2 * i + 1] = roots<P>[i] * e;
            }
            k++;
        }
    }
    for (int k = 1; k < n; k *= 2)
    {
        for (int i = 0; i < n; i += 2 * k)
        {
            for (int j = 0; j < k; j++)
            {
                MInt<P> u = a[i + j];
                MInt<P> v = a[i + j + k] * roots<P>[k + j];
                a[i + j] = u + v;
                a[i + j + k] = u - v;
            }
        }
    }
}
template <int P>
constexpr void idft(vector<MInt<P>> &a)
{ // 逆变换
    int n = a.size();
    reverse(a.begin() + 1, a.end());
    dft(a);
    MInt<P> inv = (1 - P) / n;
    for (int i = 0; i < n; i++)
    {
        a[i] *= inv;
    }
}