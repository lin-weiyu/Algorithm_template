#include<bits/stdc++.h>
using namespace std;
//���P1540 queue���д��� 
int Hash[1003]={0};		//�ù�ϣ����ڴ�����û�е��� 
queue<int>mem;			//�ö���ģ���ڴ� 
int main(){
	int n,m;
	scanf("%d %d",&m,&n);
	int cnt=0;			//��ʵ�Ĵ��� 
	while(n--){
		int en;scanf("%d",&en);			//�����Ӣ�ĵ��� 
		if(!Hash[en]){					//����ڴ���û�д洢 
			++cnt;					
			mem.push(en);
			Hash[en]=1;					//��¼�ڴ������������ 
			while(mem.size()>m){		//�ڴ���ʱ 
				Hash[mem.front()]=0;	//���ڴ���ȥ�� 
				mem.pop();				//�Ӷ�ͷȥ�� 
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
