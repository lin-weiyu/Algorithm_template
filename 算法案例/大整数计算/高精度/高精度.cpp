#include<bits/stdc++.h>
using namespace std;
const int Mod=10000;
int k[85],n,m;
struct node{
	int a[505]={0},len=0;
	node(string s=""){
		int x=0,k=1;
		for(int i=s.size()-1;i>=0;i--){
			x=x+(s[i]-'0')*k;
			k*=10;
			if(x>Mod){
				a[++len]=x%Mod;
				x/=Mod;
				k=10;
			}
		}
		if(x)a[++len]=x;
	}
	void print(){
		printf("%d",a[len]);
		for(int i=len-1;i>0;i--){
			if(a[i]==0){
				printf("0000");
				continue;
			}
			for(int j=10;j*a[i]<Mod;j*=10){
				printf("0");
			}
			printf("%d",a[i]);
		}
	}
}f[85][85],Base[85],ans;
node operator+(const node &x,const node &y){
	node c;
	c.len=max(x.len ,y.len);
	int k=0;
	for(int i=1;i<=c.len ;i++){
		c.a[i]=x.a[i]+y.a[i]+k;
		k=c.a[i]/Mod;
		c.a[i]%=Mod;
	}
	if(k>0)c.a[++c.len]=k;
	return c;
}
node operator*(const node &x,const int &y){
	node c;
	c.len=x.len;
	int k=0;
	for(int i=1;i<=c.len;i++){
		c.a[i]=x.a[i]*y+k;
		k=c.a[i]/Mod;
		c.a[i]%=Mod;
	}
	while(k>0){
		c.a[++c.len]=k%Mod;
		k/=Mod;
	}
	return c;
} 
void Basetwo(){
	Base[0].a[1]=1,Base[0].len=1;
	for(int i=1;i<=m+2;i++){
		Base[i]=Base[i-1]*2;
	}
}
node max(const node &x,const node &y){
	if(x.len<y.len)return y;
	else if(x.len >y.len )return x;
	else{
		for(int i=x.len;i>0;i--){
			if(x.a[i]<y.a[i])return y;
			else if(x.a[i]>y.a[i]) return x;
		}
		return x;
	}
}
int main(){
	cin>>n>>m;
	Basetwo();
	for(int h=1;h<=n;h++){
		memset(f,0,sizeof(f));
		for(int j=1;j<=m;j++){
			cin>>k[j];
		}
		for(int i=1;i<=m;i++){
			for(int j=m;j>=i;j--){
				f[i][j]=max(f[i][j],f[i-1][j]+Base[m+i-j-1]*k[i-1]);
				f[i][j]=max(f[i][j],f[i][j+1]+Base[m+i-j-1]*k[j+1]);
			}
		}
		node Max;
		for(int i=1;i<=m;i++){
			Max=max(Max,f[i][i]+Base[m]*k[i]);
		}
		ans=ans+Max;
	}
	ans.print();
	return 0;
}
