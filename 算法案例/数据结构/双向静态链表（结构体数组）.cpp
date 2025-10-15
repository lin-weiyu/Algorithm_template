#include<bits/stdc++.h>
using namespace std;
//双向静态链表（结构体数组）
const int N=105;
struct node{
	int id;
	//int date;
	int preid,nextid;
}nodes[N];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	nodes[0].nextid =1;
	for(int i=1;i<n;i++){
		nodes[i].id =i;
		nodes[i].nextid =i+1;
		nodes[i].preid =i-1;
	}
	nodes[n].nextid =1;						//形成循环 
	nodes[1].preid =n;
	int now=1;
	while((n--)>1){
		for(int i=1;i<m;i++){now=nodes[i].nextid ;}
		printf("%d ",nodes[now].id );
		int prev=nodes[now].preid ,next=nodes[now].nextid ;		
		nodes[prev].nextid =nodes[now].preid ;
		nodes[next].preid =nodes[now].nextid ;
		now=next;
	}
	printf("%d",nodes[now].nextid );		//nextid==id==preid
	return 0; 
} 
