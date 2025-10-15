#include<bits/stdc++.h>
using namespace std;
//单向静态链表（结构体数组）
const int N=105;
struct node{
	int id,nextid;
	//int date;							    	需要时可加 
}nodes[N]; 
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	nodes[0].nextid =1;
	for(int i=1;i<=n;i++){nodes[i].id =i;nodes[i].nextid =i+1;}
	nodes[n].nextid =1;						//循环链表 
	int now=1,prev=1;
	while((n--)>1){							//最后的now是最后节点的地址 
		for(int i=1;i<m;i++){
			prev=now;
			now=nodes[now].nextid ;
		}
		printf("%d ",nodes[now].id );
		nodes[prev].nextid =nodes[now].nextid ;
		now=nodes[now].nextid ;
	}
	printf("%d",nodes[now].nextid );		//最后节点的地址和节点的数值相等 
	return 0;
}
