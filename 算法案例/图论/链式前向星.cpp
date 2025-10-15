#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=2e6+5;
int head[N],cnt;
struct {
	int from,to,next;
	int w;
}edge[M];
void init(){
	for(int i=0;i<N;i++)head[i]=-1;
	for(int i=0;i<M;i++)edge[i].next=-1;
	cnt=0;
}
void addedge(int u,int v,int w){
	edge[cnt].from=u;
	edge[cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];//把上一个节点的位置给next
	head[u]=cnt++;//head[u]指向当前边所在的位置
}
int main(){
	init();
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	} 
	for(int i=0;i<n;i++)printf("h[%d] = %d",i,head[i]);
	printf("\n");
	for(int i=0;i<m;i++)printf("e[%d] = %d",i,edge[i].to);
	printf("\n");
	for(int i=0;i<m;i++)printf("e[%d].next = %d",i,edge[i].next);
	printf("\n");
	for(int i=head[2];~i;i=edge[i].next)printf("%d",edge[i].to);
	return 0;
}
