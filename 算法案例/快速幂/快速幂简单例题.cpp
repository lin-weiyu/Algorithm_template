#include<bits/stdc++.h>
using namespace std;
//A的B次方的后三位数，B<=10000 
int power1(int a,int n){//快速幂的递归写法 
	int ans;
	if(n==0)ans=1,cout<<a<<" "<<n<<endl;
	else{
		cout<<n<<":"<<ans<<endl; 
		ans=power1(a*a,n/2);//先计算幂的情况，再算奇数幂的情况 
		if(n%2==1)ans*=a;
		cout<<n<<":"<<ans<<endl;
	}
	return ans;
} 
int power2(int a,int n){//快速幂的非递归写法 
	int ans=1;
	while(n){
		if(n%2)ans=ans*a;
		a=a*a;
		n=n/2;
	}
	return ans;
}
int main(){
	return 0;
}
