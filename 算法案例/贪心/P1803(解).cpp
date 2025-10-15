#include<bits/stdc++.h>
using namespace std;
struct data{
	int L,R;
}a[1000005];
bool cmp(data x,data y){return x.R <y.R ;}
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].L >>a[i].R ;
	sort(a,a+n,cmp);
	int ans=0;
	int lastend=-1;
	for(int i=0;i<n;i++){
		if(a[i].L >=lastend){
			ans++;
			lastend=a[i].R ;
		}
	} 
	cout<<ans;
	return 0;
}
