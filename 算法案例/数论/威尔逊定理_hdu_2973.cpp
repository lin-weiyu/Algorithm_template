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
const int N=3e6+50;
int prime[N],vis[N],len,sumk[N];
void get_prime(){
    for(int i=2;i<N;i++){
        if(!vis[i]){
            vis[i]=i;
            prime[len++]=i;
        }
        for(int j=0;j<len;j++){
            if(i*prime[j]>N)break;
            vis[i*prime[j]]=prime[j];
            if(i%prime[j]==0){
                break;
            }
        }
    }
    for(int i=1;i<=1e6;i++){
        if(vis[3*i+7]==3*i+7){
            sumk[3*i+7]=1;
        }
    }
    for(int i=1;i<N;i++){
        sumk[i]+=sumk[i-1];
    }
}
void solve(){
    int n;
    cin>>n;
    cout<<sumk[3*n+7]-sumk[9]<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    get_prime();
    cin>>t;
    while(t--)solve();
    return 0;
}
/*
若p 为素数，则有  
((p-1)!+1)%p==0
(p-1)!%p==p-1
(p-1)!=pq-1,q为正整数
当n为合数时，除了4为，(n-1)!中必有两个数的积为n，因此 (n-1)!%n==0
当n为素数时，(n-1)!%n==n-1
*/