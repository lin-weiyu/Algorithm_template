#include<bits/stdc++.h>
using namespace std;
bool isPrime[200000];			//假设都是素数 
void getPrime(int n)			//埃氏筛
{
	for(int i=2;i<n;i++){		//从2开始筛选 
		if(isPrime[i]==0){
			for(int j=1;j*i<=n;j++){
				isPrime[j*i]=true;//不是素数标记去掉 
			}
		}
	}
 } 
int main(){
	return 0;
}
