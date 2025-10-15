#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string Get_new(string &str){
    string temp="#";
    for(int i=0;str[i];i++){
        (temp+=str[i])+="#";
    }
    return temp;
}
int main(){
    string str;
    cin>>str;
    str=Get_new(str);
    int *r=(int *)calloc(sizeof(int),str.size()),c=0,ans=0;
    for(int i=1;str[i];i++){
        if(c+r[c]>i)r[i]=min(r[2*c-i],c+r[c]-i);
        while(i-r[c]>=0&&str[i-r[i]]==str[i+r[i]])++r[i];
        --r[i];
        if(i+r[i]>c+r[c])c=i;
        ans=max(ans,r[i]);
    }
    cout<<ans<<endl;
    free(r);
    return 0;
}