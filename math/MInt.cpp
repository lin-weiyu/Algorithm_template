#include <bits/stdc++.h>
using namespace std;


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
    constexpr MInt(T x): x(norm(x%P)) {} // 出现错误时可删除前置
    constexpr static int norm(int x) {
        return x<0? x+P: x>=P? x-P: x;
    }
    constexpr MInt power(MInt x, MInt k){
        MInt res = 1;
        while (k){
            if (k.x & 1) res = res * x;
            x = x * x;
            k /= 2;
        }
        return res;
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

constexpr int P=1e9+7;
  
using Z=MInt<P>;