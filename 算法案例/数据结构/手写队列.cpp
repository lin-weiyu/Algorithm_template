#include<bits/stdc++.h>
using namespace std;
//P1540 ��дѭ������
#define N 1003
int Hash[N];
struct myqueue{
	int data[N];
	/*��̬���䣺int *data;  */
	int head,rear;					//rearָ���β�ĺ�һ��λ�� 
	bool init(){					//�Զ��г�ʼ�� 
		/*��̬���䣺
		Q.data=(*int)malloc(N*sizeof(int));
		if(!Q.data) return false;  */ 
		head=rear=0;
		return 0;
	} 
	int size(){return (rear-head+N)%N;}
	bool empty(){					//�ж϶����Ƿ�Ϊ�� 
		if(size()==0) return true;
		else          return false;
	}
	bool push(int e){
		if((rear+1)%N==head)return false;		//��������+1����Ϊ��rear==headΪ������Ϊ�ղ���ì�ܵ������ 
		data[rear]=e;
		rear=(rear+1)%N;
		return true; 
	} 
	bool pop(int &e){			//&e ����e 
		if(head==rear)return false;
		e=data[head];
		head=(head+1)%N;
		return true;
	}
	int front(){return data[head];
	}
}Q;
int main(){
	Q.init() ;					//��ʼ������ 
	int n,m;
	scanf("%d %d",&m,&n);
	int cnt=0;
	while(n--){
		int en;
		scanf("%d",&en);
		if(!Hash[en]){
			cnt++;
			Q.push(en);
			Hash[en]=1;
			while(Q.size()>m){
				int tmp;Q.pop(tmp);
				Hash[tmp]=0;
			} 
		}
	}
	printf("%d\n",cnt);
	return 0;
} 
