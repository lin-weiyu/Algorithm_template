#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100010;
int n;
ll ai[N],mi[N];
ll mul(ll a,ll b,ll m){
    ll res=0;
    while(b>0){
        if(b&1)res=(res+a)%m;
        a=(a+a)%m;
        b>>=1;
    }
    return res;
}
ll extend_gcd(ll a,ll b,ll &x,ll &y){
    if(b==0)return x=1,y=0,a;
    ll d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
ll excrt(){
    ll x,y;
    ll m1=mi[1],a1=ai[1];
    ll ans=0;
    for(int i=2;i<=n;i++){
        ll a2=ai[i],m2=mi[i];
        ll a=m1,b=m2,c=(a2-a1%m2+m2)%m2;
        ll d=extend_gcd(a,b,x,y);
        if(c%d!=0)return -1; 
        x=mul(x,c/d,b/d);
        ans=a1+x*m1;
        m1=m2/d*m1;
        ans=(ans%m1+m1)%m1;
        a1=ans;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>mi[i]>>ai[i];
    }
    cout<<excrt()<<endl;
    return 0;
}