#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int IntRead(){
    char ch=getchar();
    register int s=0,w=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<1)+(s<<3)+(ch^48);
        ch=getchar();
    }
    return s*w;
}
inline string StringRead(){
    string str;
    char s=getchar();
    while(s==' '||s=='\n'||s=='\r'){
        s=getchar();
    }
    while(s!=' '&&s!='\n'&&s!='\r'){
        str+=s;
        s=getchar();
    }
    return str;
}
inline double DoubleRead(){
    ll s=0,w=1,k=0,n=0,m=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while((ch>='0'&&ch<='9')||ch=='.'){
        if(ch=='.')n=1;
        else if(n==0){
            s=(s<<1)+(s<<3)+(ch^48);
        }
        else k=(k<<1)+(k<<3)+(ch^48),m++;
        ch=getchar();
    }
    return (pow(0.1,m)*k+s)*w;
}
void Intwrite(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        Intwrite(x/10);
    }
    putchar(x%10+'0');
}
inline void print(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        print(x/10);
    }
    putchar(x%10+'0');
}
int main(){
    register int n;
    n=IntRead();
    Intwrite(n);
    return 0;
}