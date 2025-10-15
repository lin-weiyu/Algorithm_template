#include<bits/stdc++.h>
using namespace std;
const int N=50000;
int vis[N];
int prime[N];
int phi[N];
int sum[N];
void get_phi(){//O(n)
    phi[1]=1;
    int cnt=0;
    for(int i=2;i<N;i++){
        if(!vis[i]){
            vis[i]=i;               //记录最小质因数
            prime[cnt++]=i;          
            phi[i]=i-1;             //当 n 为素数时  f(n)=n-1
        }
        for(int j=0;j<cnt;j++){
            if(i*prime[j]>N)break;
            vis[i*prime[j]]=prime[j];   //记录最小质因数
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];        //i是prime[j]的k次方，此时k必定为2，因此直接为p*phi[j]
                break;
            }
            phi[i*prime[j]]=phi[i]*phi[prime[j]];       //i 和 prime[j] 互素，则根据积性函数性质计算
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    get_phi();
    sum[1]=1;
    for(int i=2;i<=N;i++){
        sum[i]=sum[i-1]+phi[i];
    }
    int n;
    cin>>n;
    if(n==1)cout<<0<<endl;
    else{
        cout<<2*sum[n-1]+1<<endl;
    }
    return 0;
}
/*
建模：
下面化为最简分数形式后的个数就为答案，因此可以联想到欧拉函数的证明过程，此题为求欧拉函数的前缀和

                    1/5
               1/4  2/5
          1/3  2/4  3/5
     1/2  2/3  3/4  4/5
1/1  2/2  3/3  4/4  5/5

欧拉函数：f(n)不超过n的数中，与 n 互素的数的个数
性质：
若 p 与 q 互素，则有 f(p*q)==f(p)*f(q)  为积性函数
n=f(k1)+f(k2)+f(k3)+....+f(ks)  {任意的 k 都能整除 n }
如：12=f(1)+f(2)+f(3)+f(4)+f(6)+f(12)
*/