#include<bits/stdc++.h>
using namespace std;
//����̬�����ṹ�����飩
const int N=105;
struct node{
	int id,nextid;
	//int date;							    	��Ҫʱ�ɼ� 
}nodes[N]; 
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	nodes[0].nextid =1;
	for(int i=1;i<=n;i++){nodes[i].id =i;nodes[i].nextid =i+1;}
	nodes[n].nextid =1;						//ѭ������ 
	int now=1,prev=1;
	while((n--)>1){							//����now�����ڵ�ĵ�ַ 
		for(int i=1;i<m;i++){
			prev=now;
			now=nodes[now].nextid ;
		}
		printf("%d ",nodes[now].id );
		nodes[prev].nextid =nodes[now].nextid ;
		now=nodes[now].nextid ;
	}
	printf("%d",nodes[now].nextid );		//���ڵ�ĵ�ַ�ͽڵ����ֵ��� 
	return 0;
}
