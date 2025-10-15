#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ll long long
#define id(i) (((i)<=T)?id1[i]:id2[n/(i)])
const int N=1e6;
ll prime[N],id1[N],id2[N],tot;
bool vis[N];
ll g[N],a[N],T,n,m;

void min25(){
    tot=m=0;
    T=sqrt(n+0.5);
    ll i,j;
    for(i=2;i<=T;i++){
        if(!vis[i])prime[++tot]=i;
        for(j=1;j<=tot&&1ll*i*prime[j]<=T;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(i=1;i<=n;i=j+1){
        j=n/(n/i);
        a[++m]=n/i;
        if(a[m]<=T)id1[a[m]]=m;
        else id2[n/a[m]]=m;
        g[m]=3ll*(a[m]-1);
    }
    for(j=1;j<=tot;j++){
        for(i=1;i<=m&&prime[j]*prime[j]<=a[i];i++){
            g[i]-=g[id(a[i]/prime[j])]-3ll*(j-1);
        }
    }
}
ll solve(ll a,ll b){
    if(a<prime[b])return 0;
    ll ans=g[id(a)]-3ll*(b-1);
    for(ll i=b;i<=tot&&1ll*prime[i]*prime[i]<=a;i++){
        for(ll j=1,p=prime[i];p*prime[i]<=a;j++,p*=prime[i]){
            ans+=solve(a/p,i+1)*(2*j+1)+2*(j+1)+1;
        }
    }
    return ans;
}
ll sum(ll x){
    if(x<=0)return 0;
    if(x==1)return 1;
    n=x;
    min25();
    return (solve(x,1)+1+n)/2ll;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll a,b;
    cin>>a>>b;
    cout<<sum(b)-sum(a-1)<<endl;
}