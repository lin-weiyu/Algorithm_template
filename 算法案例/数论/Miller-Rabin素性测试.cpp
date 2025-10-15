#include<bits/stdc++.h>
using namespace std;

//hdu 2138
#define ll long long
ll fast_pow(ll x,ll y,int m){
    ll res=1;
    x%=m;
    while(y){
        if(y&1)res=res*x%m;
        x=x*x%m;
        y>>=1;
    }
    return res;
}
bool witness(ll a,ll n){        //是合数则返回true，素数则返回false
    ll u=n-1;
    int t=0;
    while(u&1==0)u=u>>=1,t++;
    ll x1,x2;
    x1=fast_pow(a,u,n);
    for(int i=1;i<=t;i++){
        x2=fast_pow(x1,2,n);
        if(x2==1&&x1!=-1&&x1!=n-1){
            return true;
        }
        x1=x2;
    }
    if(x1!=1)return true;
    return false;
}
bool miller_rabin(ll n,int s){//对 n 进行 s 次测试  费马小定理+二次探测定理
    if(n<2)return false;
    if(n==2)return true;
    if(n%2==0)return false;
    for(int i=0;i<s&&i<n;i++){
        ll a=rand()%(n-1)+1;
        if(witness(a,n))return false;
    }
    return true;
}
int t;
void solve(){
    int cnt=0;
    ll n;
    for(int i=0;i<t;i++){
        cin>>n;
        int s=50;
        cnt+=miller_rabin(n,s);
    }
    cout<<cnt<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    while(cin>>t){
        solve();
    }
    return 0;
}