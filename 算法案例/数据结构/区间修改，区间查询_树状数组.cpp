#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&(-x))
#define ll long long
//P3372 
const int N=1e5+10;
ll tree1[N],tree2[N];
void update(ll t[],ll x,ll d){
	while(x<=N){
		t[x]+=d;
		x+=lowbit(x);
	}
}
ll sum(ll t[],ll x){
	ll ans=0;
	while(x>0){
		ans+=t[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	ll n,m,x,old=0;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		update(tree1,i,x-old);
		update(tree2,i,(i-1)*(x-old));
		old=x;
	}
	ll L,R,d;
	for(int i=0;i<m;i++){
		scanf("%lld",&x);
		if(x==1){
			scanf("%lld %lld %lld",&L,&R,&d);
			update(tree1,L,d);
			update(tree1,R+1,-d);
			update(tree2,L,d*(L-1));
			update(tree2,R+1,-d*R);
		}
		else if(x==2){
			scanf("%lld %lld",&L,&R);//[L,R]==sum(R)-sum(L-1)
			printf("%lld\n",R*sum(tree1,R)-sum(tree2,R)-(L-1)*sum(tree1,L-1)+sum(tree2,L-1));
		}
	}
	return 0;
}
