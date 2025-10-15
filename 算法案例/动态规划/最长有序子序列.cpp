#include<bits/stdc++.h>
using namespace std;
int a[10000],b[10000];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	b[0]=1; 
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j])b[i]=max(b[i],b[j]+1),ans=max(b[i],ans);
		}
	}
	cout<<ans<<endl;
	return 0;
} 
