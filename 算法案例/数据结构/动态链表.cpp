#include<bits/stdc++.h>
using namespace std;
//���P1996 
//��̬������������   �ŵ㣺�ܼ�ʱ�ͷſռ䣬ȱ�㣺 ��Ҫ����ռ䣬���׳��� 
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
		now->next =p;					//���½ڵ�������ǰ��������� 
		now=p;
	}
	now->next =head;					//ѭ������
	now=head,prev=head;
	while((n--)>1){						//��󻹱���һ���ڵ㣬nowָ�����ڵ�ĵ�ַ 
		for(int i=1;i<m;i++){			//ѭ������ʱnow��Ҫɾ���Ľڵ�λ�� 
			prev=now;
			now=now->next ;
		}
		printf("%d ",now->date );
		prev->next=now->next ;
		delete now;						//�ͷŽڵ�
		now=prev->next ; 				//now�Ѿ��ͷţ�ֻ����prev->next 
	} 
	printf("%d",now->date ) ;			//ȥ�ո� 
	delete now;
	return 0;
}
