#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int r[105];
string GetNewStr(string &str){
    string s="#";
    for(int i=0;str[i];++i){
        (s+=str[i])+='#';
    }
    return s;
}
int main(){
    string str;
    cin>>str;
    str=GetNewStr(str);
    for(int i=0;str[i];++i){
        while(i-r[i]>=0&&str[i-r[i]]==str[i+r[i]])++r[i];
        --r[i];
    }
    for(int i=0;str[i];++i){
        printf("%3c",str[i]);
    }
    printf("\n");
    for(int i=0;str[i];++i){
        printf("%3d",r[i]);
    }
    printf("\n");
    return 0;
}