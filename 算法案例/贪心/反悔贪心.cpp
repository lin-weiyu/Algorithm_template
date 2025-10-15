#include<bits/stdc++.h>
using namespace std;
#ifdef LWY
#include "debug.h"
#else
#define debug(...) 0
#endif
const int N=3e5+10;//P1484
struct node{
	int id,w;
	node(){
		id=w=0;
	}
	node(int x,int y){
		id=x,w=y;
	}
	bool operator<(const node &x)const{
		return w<x.w;
	}
};
int n,k,a[N],L[N],R[N];
bool vis[N];
std::priority_queue<node>q;
typedef long long ll;
ll ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	debug(100/(100/2),(100/100)/2);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		L[i]=i-1;
		R[i]=i+1;
		q.push(node(i,a[i]));
	}
	for(int i=1;i<=k;i++){
		while(vis[q.top().id])q.pop(),debug(q.top().id);
		node now=q.top();
		if(now.w<0)break;
		q.pop();
		ans+=now.w;
		debug(now.w);
		a[now.id]=now.w=a[L[now.id]]+a[R[now.id]]-a[now.id];
		q.push(now);
		vis[L[now.id]]=vis[R[now.id]]=1;						//相当于把这一整块全部缩为一块，然后不断翻转状态
		L[now.id]=L[L[now.id]],R[now.id]=R[R[now.id]];
		L[R[now.id]]=R[L[now.id]]=now.id;
	}
	cout<<ans<<endl;
	return 0;
}