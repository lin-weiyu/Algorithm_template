#include<bits/stdc++.h>
using namespace std;
//欧拉函数降幂(A^(B))%C==(A^(B%f(C)+f(C)))%C   
//f(C)为欧拉函数：为[1,(C-1)]的质数个数+1（因为包括1），f(1)=1,f(2)=1,f(3)=2....
#define ll long long
ll euler(ll x){
	ll res=1;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			x/=i;
			res*=(i-1);
			while(x%i==0){
				x/=i;
				res*=i;
			}
		}
	}
	if(x>1)res*=(x-1);
	return res;
}
ll euler2(ll x){//第二种求法，相当于不断减去
	ll res=x;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			res=res-res/i;
			while(x%i==0){
				x/=i;
			}
		}
	}
	if(x>1)res=res-res/x;
	return res;
}
int main(){
    return 0;
}