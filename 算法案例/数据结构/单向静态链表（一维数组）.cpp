#include<bits/stdc++.h>
using namespace std;
//����̬����һά���� ��
//nodes[i]�е� i ���ǽڵ��ֵ��nodes[i]��ֵ����һ�ڵ�ĵ�ַ
int nodes[150];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)nodes[i]=i+1;
	nodes[n]=1;
	int now=1,prev=1;
	while((n--)>1){
		for(int i=1;i<m;i++){prev=now;now=nodes[now];
		}
		printf("%d ",now);
		nodes[prev]=nodes[now];
		now=nodes[now];
	}
	printf("%d",now);
	return 0;
}
