#include<bits/stdc++.h>
using namespace std;
int main(){//���ű����� ��� ʱ��1s,�ռ�256MB 
	int n;cin>>n;
	vector<int>a(n+1,0);			//�洢��ʼ���� 
	for(int i=0;i<n;i++) cin>>a[i]; 
	vector<long long> sum(n+1,0);	//�洢�ͣ�ÿ�����ݶ�ÿǰn�� 
	for(int i=0;i<n;i++) sum[i]=a[i]+sum[i-1];
	long long s=0;
	for(int i=0;i<n;i++)s+=sum[i]*a[i+1];
	cout<<s<<endl;
	return 0;
} 
