#include<bits/stdc++.h>
using namespace std;
int a[150]={1,1};
int main(){		//���ﲻ���ÿ��������Ĺ�ʽ�������ö��壬��Ϊȡģ���� 
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			a[i]+=a[j]*a[i-j-1];
		}
	}
	cout<<a[n]%100;
	return 0;
}

/*  dp�ⷨ 
int n,f[505][505];
int main(){
	scanf("%d",&n);
	f[1][1]=1;
	for (int i=2;i<=n+n;i++)
		for (int j=(i+1)>>1;j<=i;j++)
			f[i][j]=(f[i-1][j]+f[i-1][j-1])%100;
	printf("%d",f[n+n][n]);
	return 0;
}
*/
