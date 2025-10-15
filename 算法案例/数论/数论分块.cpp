#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    // 求 n/i的和(向下取整)
    ll n,L,R,ans=0;
    cin>>n;
    for(L=1;L<=n;L=R+1){//可证明分块的个数不超过  2*sqrt(n) 个块
        R=n/(n/L);      //分母 n/L 向下取整，变小，则整个答案的值会达到相应范围内的最大
        ans+=(R-L+1)*(n/L);
        cout<<L<<" - "<<R<<":"<<n/R<<endl;
    }
    cout<<ans<<endl;
    return 0;
}