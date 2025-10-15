#include<bits/stdc++.h>
#ifdef LWY
#include "debug.h"
#else
#define debug(...) 0
#endif
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ll long long
#define endl '\n'
const ll mod1=1e9+7,mod2=998244353;
//不开long long 见祖宗！！！！
ll BSGS(ll a,ll b,ll m){    //解决  a^x%m==b%m 的求解，a,b要为已知，a和m互质
    //设t=sqrt(m)-1,x=A*t-B,且可以化为 (a^m)^A==b*(a^B)
    std::unordered_map<ll,ll>hs;
    ll cur=1,t=sqrt(m)+1;
    for(ll B=1;B<=t;B++){
        cur=cur*a%m;
        hs[b*cur%m]=B;
    }
    ll now=cur;
    for(int A=1;A<=t;A++){
        auto it=hs.find(now);
        if(it!=hs.end()){
            return A*t-it->second;
        }
        now=now*cur%m;
    }
    return -1;
}
ll exBSGS(ll a,ll b,ll m){  //当 a 和 m 不互质的情况
    a%=m;
    b%=m;
    if(b==1||m==1)return 0;
    ll d=__gcd(a,m);
    if(b%d!=0)return -1;
    ll k=a/d;
    b/=d;
    m/=d;
    unordered_map<ll,ll>hs;
    ll cur=1,t=sqrt(m)+1;
    for(ll B=1;B<=t;B++){
        cur=cur*a%m;
        hs[b*cur%m]=B;
    }
    ll now=k*cur%m;
    for(int A=1;A<=t;A++){
        auto it=hs.find(now);
        if(it!=hs.end()){
            return A*t-it->second+1;
        }
        now=now*cur%m;
    }
    return -1;
}
void solve(){
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}