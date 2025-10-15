#include<bits/stdc++.h>
using namespace std;
int c[1000000];
int add(string a,string b){
	int lena=a.size()-1,lenb=b.size()-1,t=0,k=0;
	while(lena>=0&&lenb>=0){
		int x=(int)a[lena]-48,y=(int)b[lenb]-48;
		c[t++]=((x+y)+k)%10;
		k=(x+y+k)/10;
		lena--;lenb--;
	}
	while((lena)>=0){
		c[t++]=((int)a[lena]-48+k)%10;k=((int)a[lena]-48+k)/10;lena--;
	}
	while((lenb)>=0){
		c[t++]=((int)b[lenb]-48+k)%10;k=((int)b[lenb]-48+k)/10;lenb--;
	}
	if(k!=0)c[t++]=k;
	return t;
}
int main()
{
	string a,b;
	cin>>a>>b;
	int n=add(a,b);
	for(int i=n-1;i>=0;i--)cout<<c[i];
	return 0;
}
