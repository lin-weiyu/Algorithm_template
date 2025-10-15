#include<bits/stdc++.h>
using namespace std;
const int N=1000;
char *p1,*p2,buf[N];
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,N,stdin),p1==p2)?EOF:*p1++)
#define LL long long
LL read(){
    LL x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57){//把字符比较转为数字比较
        if(ch=='-')f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57){
        x=(x<<1)+(x<<3)+(ch^48),ch=nc();
    }
    return x*f;
}
char obuf[N],*p3=obuf;
#define putchar(x) (p3-obuf<N)?(*p3++=x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x)
inline void write(LL x){
    if(!x){
        putchar('0');
        return;
    }
    LL len=0,k1=x,c[40];
    if(k1<0)k1=-k1,putchar('-');
    while(k1)c[len++]=k1%10^48,k1/=10;
    while(len--)putchar(c[len]);
}
int main(){

    fwrite(obuf,p3-obuf,1,stdout);
    fflush(stdout);//专门清空显示器缓冲区
    /*清空输入缓冲区：
    1：getcahr() 使用getchar()读取完缓冲区内容则会清空
    2：scanf("%*[^$\n]");scanf("%*c");第一个会丢弃[]中的字符遇到\n停止,此时还有一个\n,所有使用第二次
    #:fflush(inout);适用部分新GCC和旧VC
    */
    return 0;
}
