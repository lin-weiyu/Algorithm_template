#include<bits/stdc++.h>
using namespace std;
int main(){//蓝桥杯例题 求和 时间1s,空间256MB 
	int n;cin>>n;
	vector<int>a(n+1,0);			//存储初始数据 
	for(int i=0;i<n;i++) cin>>a[i]; 
	vector<long long> sum(n+1,0);	//存储和，每个数据都每前n和 
	for(int i=0;i<n;i++) sum[i]=a[i]+sum[i-1];
	long long s=0;
	for(int i=0;i<n;i++)s+=sum[i]*a[i+1];
	cout<<s<<endl;
	return 0;
} 
