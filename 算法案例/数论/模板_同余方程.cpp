#include<bits/stdc++.h>
#ifdef LWY
#include "debug.h"
#else
#define debug(...) 0
#endif
using namespace std;
#define ll long long
#define endl '\n'
const ll mod1=1e9+7,mod2=998244353;
int ex_gcd(ll a,ll b,ll &x,ll &y){
    if(b==0)return x=1,y=0,a;
    int d=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
void solve(){
    ll a,b,x,y;
    cin>>a>>b;
    int d=ex_gcd(a,b,x,y);
    if(d!=1)cout<<-1<<endl;
    else cout<<(x%b+b)%b<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}