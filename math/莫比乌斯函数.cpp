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
const int N=1e5+10;
bool vis[N];
int prime[N];
int Mob[N];
void Mobius_sieve(){        //基本跟欧拉函数一致
    int cnt=0;
    vis[1]=1;
    Mob[1]=1;
    for(int i=2;i<=N;i++){
        if(!vis[i]){
            prime[cnt++]=i;
            Mob[i]=-1;
        }
        for(int j=0;j<cnt&&1LL*prime[j]*i<=N;j++){
            vis[prime[j]*i]=1;
            Mob[i*prime[j]]=(i%prime[j]?-Mob[i]:0);
            if(i%prime[j]==0)break;
        }
    }
}
void solve(){
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}