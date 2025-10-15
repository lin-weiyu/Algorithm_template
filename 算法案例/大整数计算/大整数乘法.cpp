#include<bits/stdc++.h>
using namespace std;
int na[1005],nb[1005],nc[1000005];
string mul(string a,string b){
	if(a=="0"||b=="0")return "0";
	int lena=a.size(),lenb=b.size();
	for(int i=0;i<lena;i++)na[lena-i]=a[i]-'0';
	for(int i=0;i<lenb;i++)nb[lenb-i]=b[i]-'0';
	for(int i=1;i<=lena;i++){
		for(int j=1;j<=lenb;j++){
			nc[i+j-1]+=na[i]*nb[j];
		}
	}
	for(int i=1;i<=lena+lenb;i++)nc[i+1]+=nc[i]/10,nc[i]%=10;	//处理进位问题 
	string ans;
	if(nc[lena+lenb])ans+=nc[lena+lenb]+'0';	//+'0'== +48 转为字符数字 
	for(int i=lena+lenb-1;i>=1;i--)ans+=nc[i]+'0';// 位数为[lena+lenb-1,lena+lenb]之间 
	return ans;
}
int main(){
	string a,b;
	cin>>a>>b;
	cout<<mul(a,b);
	return 0;
}
