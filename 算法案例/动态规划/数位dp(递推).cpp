#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=15;
ll ten[N],dp[N];
ll cnta[N],cntb[N];
int num[N];
void init(){
    ten[0]=1;
    for(int i=1;i<=N;i++){
        dp[i]=i*ten[i-1];//
        ten[i]=10*ten[i-1];
    }
}
void solve(ll x,ll *cnt){
    int len=0;
    while(x){
        num[++len]=x%10;
        x=x/10;
    }
    for(int i=len;i>=1;i--){//统计0000-XXXX的位数个数（补前导0）
        for(int j=0;j<=9;j++)cnt[j]+=dp[i-1]*num[i];//统计退一位的满情况
        for(int j=0;j<num[i];j++)cnt[j]+=ten[i-1];//统计当前位数上的个数
        ll num2=0;
        for(int j=i-1;j>=1;j--)num2=num2*10+num[j];//单独统计当前位当前值的个数，特判最高位
        cnt[num[i]]+=num2+1;
        cnt[0]-=ten[i-1];//去除前导0
    }
}
int main(){
    init();
    ll a,b;
    cin>>a>>b;
    solve(a-1,cnta);//要减一
    solve(b,cntb);
    for(int i=0;i<=9;i++)cout<<cntb[i]-cnta[i]<<" ";
    return 0;
}