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
const int N=3e6+10;
ll ans[N];
void solve(){
    ll n,p;
    cin>>n>>p;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]=(p-p/i)*ans[p%i]%p;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}