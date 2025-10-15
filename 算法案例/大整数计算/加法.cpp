#include<bits/stdc++.h>
using namespace std;
char x[505],y[505];
int a[500],b[500],c[500];
int* add(char s1[],char s2[]){
	int len_a=strlen(s1);
	int len_b=strlen(s2);
	for(int i=len_a-1;i>=0;i--){
		a[i]=s1[len_a-i-1]-'0';
	}
	for(int i=len_b-1;i>=0;i--){
		b[i]=s2[len_b-i-1]-'0';
	}
	int max=(len_a>=len_b)?len_a:len_b;
	for(int i=0;i<max;i++){
		c[i]+=a[i]+b[i];
		c[i+1]=c[i]/10;
		c[i]%=10; 
	} 
	for(int i=max;i>=0;i--){
		if(i==max&&c[i]==0)continue;
		printf("%d",c[i]); 
	}
	return c;
}
int main(){
	cin>>x>>y;
	int *k;
	k=add(x,y);
	cout<<endl;
	cout<<*(k)<<endl;
	return 0;
}
