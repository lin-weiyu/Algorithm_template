#include<bits/stdc++.h>
using namespace std;
__int128 read(){
    char arr[30];
    __int128 res=0;
    scanf("%s",arr);
    for(int i=0;i<strlen(arr);i++){
        res*=10;
        res+=arr[i]-'0';
    }
    return res;
}
void print(__int128 num){
    if(num>9){
        print(num/10);
    }
    putchar(num%10+'0');
}
int main(){
    //范围在2^127(1e38)左右，只支持四则运算，不支持cin输入等,其它无区别
    //但int128只在GCC4.6以上的64位版本中支持
    __int128 n;
    n=read();
    print(n);
    return 0;
}