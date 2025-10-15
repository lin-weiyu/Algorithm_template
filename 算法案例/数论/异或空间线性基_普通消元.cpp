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
const int M=63;
ll p[M];
bool zero;
void Insert(ll x){
    for(int i=M;i>=0;i--){
        if(x>>i==1){
            if(p[i]==0){
                p[i]=x;
                return;
            }
        } 
        else x^=p[i];
    }
    zero=true;
}
ll qmax(){
    ll ans=0;
    for(int i=M;i>=0;i--){
        ans=max(ans,ans^p[i]);
    }
    return ans;
}
void solve(){
    ll x,n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        Insert(x);
    }
    cout<<qmax()<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}