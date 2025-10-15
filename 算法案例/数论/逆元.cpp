#include<bits/stdc++.h>
using namespace std;
#define ll long long
//a^(f(m)-1)%m 为 a 在模mod下的逆元
//当m为质数时，f(m)=m-1  费马小定理：m为质数时 逆元为a^(m-2)%m
//f(m)为欧拉函数:为[1,m-1]内与m互质的个数+1,因f(1)=1
ll euler(ll m){
    ll res=m;
    for(int i=2;i*i<=m;i++){
        if(m%i){
            res=res-res/i;
            while(m%i){
                m/=i;
            }
        }
    }
    if(m>1)res=res-res/m;
    return res;
}
ll mod=998244353;
ll powk(ll x,ll n){
    ll res=1;
    while(n){
        if(n)res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res%mod;
}
void solve(){
    ll n,m,ans=0;
    for(int i=1;i<=1e5+3;i++){
        ans+=euler(i);
    }
    cout<<ans<<endl;
    cout<<euler(1e5)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}