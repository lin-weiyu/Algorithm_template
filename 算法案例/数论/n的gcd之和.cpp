#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
/*
给定q次询问，gcd(i,n)之和(1<=i<n)
设gcd(n,i)==k,则gcd(n/k,i/k)==1,问题可以转换为n/k有多少个互素的数(即为欧拉函数)
且我们可以找到k(k 就是n的因数)，所以gcd(n,i)==k的情况下的贡献就为 f(n/k)*k:有f(n/k)个答案为k的式子
且gcd(n,i)：也可以看作，在长度为n的置换群中，第i个旋转的循环节的个数
*/

#define ll long long
const int N=1e6+10;
int phi[N],vis[N];
vector<int>prime;
void get_phi(){
    phi[1]=1;
    for(int i=2;i<N;i++){
        if(!vis[i]){
            vis[i]=i;
            prime.push_back(i);
            phi[i]=i-1;
        }
        for(int j=0;j<prime.size();j++){
            if(i*prime[j]>N)break;
            vis[i*prime[j]]=prime[j];
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*phi[prime[j]];//是积性函数：两个互素的p,q,有f(p*q)=f(p)*f(q)
        }
    }
}
void solve(){
    int n;
    ll sum=0;
    cin>>n;
    for(int i=1;i*i<=n;i++){                    //公式为:if(n%k==0)ans+=f(n/k)*k
        if(n%i==0){
            if(n/i!=i){
                sum+=phi[n/i]*i;
                sum+=phi[i]*(n/i);
            }
            else{
                sum+=phi[n/i]*i;
            }
        }
    }
    cout<<sum<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    get_phi();
    while(t--){
        solve();
    }
    return 0;
}