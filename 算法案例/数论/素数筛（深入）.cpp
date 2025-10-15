#include<bits/stdc++.h>
using namespace std;
bool isPrime[200000];			//假设都是素数
int prime[100000]; 
int getPrime(int n)			//埃氏筛
{
	int k=0;
	for(int i=2;i<n;i++){		//从2开始筛选 
		if(isPrime[i]==0){
			prime[k++]=i;
			for(int j=1;j*i<=n;j++){
				isPrime[j*i]=true;//不是素数标记去掉 
			}
		}
	}
	return k;
 } 
//埃氏筛优化  外循环不遍历偶数 
#define maxn 20010
int vis[maxn],prime1[maxn];
int Eratosthenes_sieve1(int n){
	int i,j,k;
	k=0;
	memset(vis,0,sizeof(int)*maxn);
	vis[0]=vis[1]=1;
	vis[2]=0;
	prime1[k++]=2;
	for(int i=3;i<=n;i+=2){
		vis[i+1]=1;	//把偶数标记 
		if(vis[i]==0){
			prime1[k++]=i;
			for(j=2;j*i<=n;j++){
				vis[i*j]=1;
			}
		}
	}
	return k;
}
//埃氏筛优化  范围改为【2，sqrt(n)】 
int prime2[maxn];
int Eratosthenes_sieve2(int n){
	if(n<2)return 0;
	int i,j,k;
	k=0;
	memset(vis,0,sizeof(int)*maxn);
	vis[0]=vis[1]=1;
	vis[2]=0;
	for(i=4;i<=n;i+=2)vis[i]=1;
	for(i=3;i*i<=n;i+=2){
		if(vis[i]==0){
			for(j=i;i*j<=n;j++){
				vis[i*j]=1;
			}
		}
	}
	prime2[k++]=2;
	for(i=3;i<=n;i+=2){
		if(vis[i]==0){
			prime2[k++]=i;
		}
	}
	return k;
} 
//欧拉筛 
int prime3[maxn];
int Euler_sieve(int n){
	int i,j,k;
	k=0;
	memset(vis,0,sizeof(int)*maxn);
	for(i=2;i<=n;i++){
		if(vis[i]==0){
			prime3[k++]=i;
		}
		for(j=0;j<k;j++){	//利用每个数的最小的素因子来进行筛除最小的素因子 
			if(i*prime3[j]>n)break;
			vis[i*prime3[j]]=1;
			if(i%prime3[j]==0)break;
		}
	}
	return k;
} 
int main(){
	int len=getPrime(10000);
	int len1=Eratosthenes_sieve1(10000);
	int len2=Eratosthenes_sieve2(10000);
	int t=0;
	int len3=Euler_sieve(10000); 
	for(int i=0;i<len1;i++){
		cout<<prime[i]<<endl;
		if(prime1[i]!=prime3[i])t=1;
	}
	if(t)cout<<"no"<<endl;
	else cout<<"yes"<<endl;
	return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
