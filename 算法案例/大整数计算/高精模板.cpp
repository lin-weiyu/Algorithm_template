#include<bits/stdc++.h>
using namespace std;
const int mod=10000;
struct node{
    int a[300]={0},len=0;
    node(string k=""){
        int x=0;
        int h=1;
        for(int i=k.size()-1;i>=0;i--){
            x=x+(k[i]-'0')*h;
            h*=10;
            if(x>mod){
                a[++len]=x%mod;
                x/=mod;
                h=10;
            }
        }
        if(x)a[++len]=x;
    }
    void print(){
        printf("%d",a[len]);
        for(int i=len-1;i>0;i--){
            if(a[i]==0){
                printf("0000");
                continue;
            }
            for(int j=10;j*a[i]<mod;i*=10){
                printf("0");
            }
            printf("%d",a[i]);
        }
    }
}dp[50][50],ans;
node operator +(const node &x,const node &y){
    int k=0;
    node c;
    c.len=max(x.len,y.len);
    for(int i=1;i<=c.len;i++){
        c.a[i]=x.a[i]+y.a[i]+k;
        k=c.a[i]/mod;
        c.a[i]%=mod;
    }
    if(k)c.a[++c.len]=k;
    return c;
}
node operator *(const node &x,const node &y){
    long long k=0;
    node c;
    for(int i=1;i<=x.len;i++){
        for(int j=1;j<=y.len;j++){
            c.a[i+j-1]+=x.a[i]+y.a[j]+k;
            k=c.a[i+j-1]/mod;
            c.a[i+j-1]%=mod;
            c.len=max(c.len,i+j-1);
        }
        while(k){
            c.a[++c.len]=k%mod;
            k/=mod;
        }
    }
    return c;
}
node max(const node &x,const node &y){
    if(x.len<y.len)return y;
    else if(x.len>y.len)return x;
    else{
        for(int i=x.len;i>0;i--){
            if(x.a[i]>y.a[i])return x;
            else if(x.a[i]<y.a[i])return y;
        }
        return x;
    }
}
string s;
int main(){
    int n,k;
    cin>>n>>k; 
    cin>>s;
    for(int i=1;i<=n;i++){
        string a(s,0,i);
        node x(a);
        dp[1][i]=x;

    }
    for(int i=2;i<=k+1;i++){
        for(int h=i;h<=n;h++){
            for(int j=i;j<=h;j++){
                string a(s,j-1,h-j+1);
                node x(a);
                dp[i][h]=max(dp[i][h],dp[i-1][j-1]*x);
            }
        }
    }
    for(int i=1;i<=k+1;i++){
        for(int j=1;j<=n;j++)dp[i][j].print(),cout<<" ";
        cout<<endl;
    }
    cout<<endl;
    dp[k+1][n-1].print();
    cout<<endl;
    dp[k+1][n].print();
    return 0;
}