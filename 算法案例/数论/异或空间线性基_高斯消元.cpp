//hdu 3949
#include<bits/stdc++.h>
using namespace std;
#define N 10100
#define endl '\n'
typedef long long ll;
int n;
bool zero;
ll a[N];
void Gauss(){                           //高斯消元,构造线性基(需离线读取所有数)
    int i,k=1;
    ll j=(ll)1<<62;
    for(;j;j>>=1){
        for(i=k;i<=n;i++){
            if(a[i]&j)break;
        }
        if(i>n)continue;    
        swap(a[i],a[k]);
        for(i=1;i<=n;i++){
            if(i!=k&&a[i]&j)a[i]^=a[k];
        }
        k++;
    }
    k--;
    if(k!=n)zero=true;
    else zero=false;
    n=k;
}
ll Query(ll k){
    ll ans=0;
    if(zero)k--;
    if(!k)return 0;
    for(int i=n;i;i--){
        if(k&1)ans^=a[i];
        k>>=1;
    }
    if(k)return -1;
    return ans;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    Gauss();
    int q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        cout<<Query(k)<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T,cnt=0;
    cin>>T;
    while(T--){
        cout<<"Case # "<<(++cnt)<<":"<<endl;
        solve();
    }
    return 0;
}