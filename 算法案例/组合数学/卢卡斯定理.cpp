//P3807
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
typedef long long ll;
ll fac[N];
ll fastPow(ll a,ll n,ll m){
    ll ans=1;
    a%=m;
    while(n){
        if(n&1){
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        n>>=1;
    }
    return ans;
}
ll inverse(ll a,int m){
    return fastPow(fac[a],m-2,m);
}
ll C(ll n,ll r,int m){
    if(r>n)return 0;
    return ((fac[n]*inverse(r,m))%m*inverse(n-r,m)%m);
}
ll Lucas(ll n,ll r,int m){
    if(r==0)return 1;
    return C(n%m,r%m,m)*Lucas(n/m,r/m,m)%m;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int a,b,m;
        cin>>a>>b>>m;
        fac[0]=1;
        for(int i=1;i<=m;i++){
            fac[i]=(fac[i-1]*i)%m;
        }
        cout<<Lucas(a+b,a,m)<<endl;
    }
    return 0;
}