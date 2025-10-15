#include<bits/stdc++.h>
using namespace std;
int na[1005],nb[1005];
string sub(string a,string b){
	if(a==b)return "0";
	bool neg=0;
	if(a.size()<b.size()||a.size()==b.size()&&a<b)	//当a长度小于b，或长度相等a小于b时 
		swap(a,b),neg=1;							//交换位置，为负数 
	int lena=a.size(),lenb=b.size();
	for(int i=0;i<lena;i++)
		na[lena-1-i]=a[i]-'0';
	for(int i=0;i<lenb;i++)
		nb[lenb-i-1]=b[i]-'0';
	int lmax=lena;									//此时a为最长 
	for(int i=0;i<lmax;i++){
		na[i]-=nb[i];
		if(na[i]<0){								//借位 
			na[i]+=10;
			na[i+1]--;
		}
	}
	while(!na[--lmax]&&lmax>0);						//找到从最高位开始不为0的位置 
	lmax++;
	string ans;
	for(int i=lmax-1;i>=0;i--)ans+=na[i]+'0';
	if(neg)ans='-'+ans;								//是否为负数 
	return ans;
} 
int main(){
	string a,b;
	cin>>a>>b;
	cout<<sub(a,b);
	return 0;
}
