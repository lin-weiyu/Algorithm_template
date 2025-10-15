#include<bits/stdc++.h>
using namespace std;
const int N=1000,mod=1e9+7;
struct matrix{int m[N][N];};
matrix operator*(const matrix &a,const matrix &b){
    matrix c;
    memset(c.m,0,sizeof(c.m));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
            }
        }
    }
    return c;
}
matrix pow_matrix(matrix a,int n){
    matrix ans;
    memset(ans.m,0,sizeof(ans.m));
    for(int i=0;i<N;i++)ans.m[i][i]=1;
    while(n){
        if(n&1)ans=ans*a;
        a=a*a;                          //不能用*=，因为*被重载
        n>>=1;
    }
    return ans;
}
int main(){
    return 0;
}