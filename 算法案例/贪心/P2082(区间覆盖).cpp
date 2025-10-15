#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	long long s=0,L=0;
	for(int i=1;i<n;i++){
		if(a[i]>b[i-1]){
			s+=b[i-1]-a[L]+1;
			L=i;
		}
	} 
	s+=b[n-1]-a[L]+1;
	cout<<s<<endl;
	return 0;
}
