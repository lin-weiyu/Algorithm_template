#include<bits/stdc++.h>
using namespace std;
struct gold{
	double w,v,p;
}a[105];
bool cmp(gold a,gold b){return a.p>b.p;}
int main(){
	int n,c;cin>>n>>c;
	for(int i=0;i<n;i++){
		cin>>a[i].w >>a[i].v ;
		a[i].p =a[i].v /a[i].w ;
	}
	sort(a,a+n,cmp);
	double sum=0.0;
	for(int i=0;i<n;i++){
		if(c>=a[i].w ){
			c-=a[i].w ;
			sum+=a[i].v;
		}
		else{
			sum+=c*a[i].p;
			break;
		}
	}
	printf("%.2lf",sum);
	return 0;
}
