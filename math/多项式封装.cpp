#include <bits/stdc++.h>
using namespace std;
template<int P = 998244353> 
struct Poly : public vector<MInt<P>>{
    using Value = MInt<P>;
    Poly() : vector<Value>(){}
    explicit constexpr Poly(int n) : vector<Value>(n){}
    constexpr Poly(const initializer_list<Value> &a) : vector<Value>(a){}
    
};