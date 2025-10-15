//P1516
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll extend_gcd(ll a,ll b,ll &x,ll &y){//依据为: 翡蜀定理
    if(b==0){x=1,y=0;return a;}
    ll d=extend_gcd(b,a%b,y,x);     //注意是y , x 不是  x,y 。因此与下一行形成一个当前的特解
    y-=a/b*x;                       //x1=y2,y1=x2-a/b*y2
    return d;
}
int main(){
    ll n,m,x,y,L;
    cin>>x>>y>>m>>n>>L;
    ll a=n-m,c=x-y;
    if(a<0){a=-a;c=-c;}
    ll d=extend_gcd(a,L,x,y);
    if(c%d!=0)cout<<"impossible";
    else cout<<((x*(c/d))%(L/d)+(L/d))%(L/d);
    return 0;
}