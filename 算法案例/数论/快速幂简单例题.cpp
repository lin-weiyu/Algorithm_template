#include<bits/stdc++.h>
using namespace std;
//A��B�η��ĺ���λ����B<=10000 
int power1(int a,int n){//�����ݵĵݹ�д�� 
	int ans;
	if(n==0)ans=1,cout<<a<<" "<<n<<endl;
	else{
		cout<<n<<":"<<ans<<endl; 
		ans=power1(a*a,n/2);//�ȼ����ݵ���������������ݵ���� 
		if(n%2==1)ans*=a;
		cout<<n<<":"<<ans<<endl;
	}
	return ans;
} 
int power2(int a,int n){//�����ݵķǵݹ�д�� 
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
