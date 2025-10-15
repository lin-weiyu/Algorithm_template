#include<bits/stdc++.h>
using namespace std;
//洛谷P1996 
//动态链表（单向链表）   优点：能及时释放空间，缺点： 需要管理空间，容易出错 
struct node{
	int date;
	node *next;
}; 
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	node *head,*p,*now,*prev;
	head=new node;head->date =1;head->next =NULL;
	now=head;
	for(int i=2;i<=n;i++){
		p=new node;p->date =i;p->next =NULL;
		now->next =p;					//把新节点连接在前面的链表上 
		now=p;
	}
	now->next =head;					//循环链表
	now=head,prev=head;
	while((n--)>1){						//最后还保留一个节点，now指向最后节点的地址 
		for(int i=1;i<m;i++){			//循环结束时now在要删除的节点位置 
			prev=now;
			now=now->next ;
		}
		printf("%d ",now->date );
		prev->next=now->next ;
		delete now;						//释放节点
		now=prev->next ; 				//now已经释放，只能用prev->next 
	} 
	printf("%d",now->date ) ;			//去空格 
	delete now;
	return 0;
}
