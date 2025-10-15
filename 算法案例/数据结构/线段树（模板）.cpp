#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
ll a[N];
ll tree[N<<2];
ll tag[N<<2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p){
	tree[p]=tree[ls(p)]+tree[rs(p)];
} 
void build(ll p,ll pl,ll pr){
	tag[p]=0;
	if(pl==pr){
		tree[p]=a[pl];
		return;                                               
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void addtag(ll p,ll pl,ll pr,ll d){
	tag[p]+=d;
	tree[p]+=d*(pr-pl+1);
}
void push_down(ll p,ll pl,ll pr){
	if(tag[p]){
		ll mid=(pl+pr)>>1;
		addtag(ls(p),pl,mid,tag[p]);
		addtag(rs(p),mid+1,pr,tag[p]);
		tag[p]=0;
	}
}
void update(ll L,ll R,ll p,ll pl,ll pr,ll d){
	if(L<=pl&&R>=pr){
		addtag(p,pl,pr,d);
		return;
	}
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1;
	if(L<=mid)update(L,R,ls(p),pl,mid,d);
	if(R>mid)update(L,R,rs(p),mid+1,pr,d);
	push_up(p);
}
ll query(ll L,ll R,ll p,ll pl,ll pr){
	if(pl>=L&&R>=pr)return tree[p];
	push_down(p,pl,pr);
	ll res=0;
	ll mid=(pl+pr)>>1;
	if(L<=mid)res+=query(L,R,ls(p),pl,mid);
	if(R>mid)res+=query(L,R,rs(p),mid+1,pr);
	return res;
}
int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,1,n);
	while(m--){
		ll q,L,R,d;
		scanf("%lld",&q);
		if(q==1){
			scanf("%lld%lld%lld",&L,&R,&d);
			update(L,R,1,1,n,d);
		}
		else{
			scanf("%lld%lld",&L,&R);
			printf("%lld\n",query(L,R,1,1,n));
		}
	}
	return 0;
}
