#include<bits/stdc++.h>//P4213
using namespace std;
typedef long long ll;
const int N=5e6+10;
int prime[N],mu[N];             //莫比乌斯
bool vis[N];            
ll phi[N];                      //欧拉
unordered_map<int,int>summu;    //莫比乌斯前缀和
unordered_map<int,ll>sumphi;    //欧拉前缀和
void init(){                    //提前处理出欧拉和莫比乌斯 O(n)
    int cnt=0;
    vis[0]=vis[1]=1;
    mu[1]=phi[1]=1;
    for(int i=2;i<N;i++){
        if(!vis[i]){
            prime[cnt++]=i;
            mu[i]=-1;
            phi[i]=i-1;
        }
        for(int j=0;j<cnt&&i*prime[j]<N;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]){
                mu[i*prime[j]]=-mu[i];
                phi[i*prime[j]]=phi[i]*phi[prime[j]];
            }
            else{
                mu[i*prime[j]]=0;
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
        }
    }
    for(int i=1;i<N;i++){
        mu[i]+=mu[i-1];
        phi[i]+=phi[i-1];
    }
}
int gsum(int x){
    return x;
}
ll getsmu(int x){               //S(n)=1-sum[2,n](S(n/i))
    if(x<N)return mu[x];
    if(summu[x])return summu[x];
    ll ans=1;
    for(ll l=2,r;l<=x;l=r+1){
        r=x/(x/l);
        ans-=(gsum(r)-gsum(l-1))*getsmu(x/l);
    }
    return summu[x]=ans/gsum(1);
}
ll getsphi(int x){          //S(n)=(n*(n-1)/2)-sum[2,n](S(n/i))
    if(x<N)return phi[x];
    if(sumphi[x])return sumphi[x];
    ll ans=x*((ll)x+1)/2;
    for(ll l=2,r;l<=x;l++){
        r=x/(x/l);          //整除分块
        ans-=(gsum(r)-gsum(l-1))*getsphi(x/l);
    }
    return sumphi[x]=ans/gsum(1);
}
int main(){                 //总复杂度 O(n^(2/3))
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<getsphi(n)<<" "<<getsmu(n)<<endl;
    }
    return 0;
}