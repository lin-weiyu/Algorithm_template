#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct data{
	ll L,R;
}a[100005];
bool cmp(data x,data y){return x.L <y.L ;}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].L >>a[i].R ;
	sort(a,a+n,cmp);
	ll lastend=-1,ans=0;
	for(int i=0;i<n;i++){
		if(a[i].R >=lastend){
			ans+=a[i].R -max(lastend,a[i].L )+1;
			lastend=a[i].R +1;
		}
	} 
	cout<<ans;
	return 0;
}
