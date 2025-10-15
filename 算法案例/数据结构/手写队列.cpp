#include<bits/stdc++.h>
using namespace std;
//P1540 手写循环队列
#define N 1003
int Hash[N];
struct myqueue{
	int data[N];
	/*动态分配：int *data;  */
	int head,rear;					//rear指向队尾的后一个位置 
	bool init(){					//对队列初始化 
		/*动态分配：
		Q.data=(*int)malloc(N*sizeof(int));
		if(!Q.data) return false;  */ 
		head=rear=0;
		return 0;
	} 
	int size(){return (rear-head+N)%N;}
	bool empty(){					//判断队列是否为空 
		if(size()==0) return true;
		else          return false;
	}
	bool push(int e){
		if((rear+1)%N==head)return false;		//队列满，+1是因为与rear==head为满或者为空产生矛盾的情况错开 
		data[rear]=e;
		rear=(rear+1)%N;
		return true; 
	} 
	bool pop(int &e){			//&e 引用e 
		if(head==rear)return false;
		e=data[head];
		head=(head+1)%N;
		return true;
	}
	int front(){return data[head];
	}
}Q;
int main(){
	Q.init() ;					//初始化队列 
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
