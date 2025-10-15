#include<bits/stdc++.h>
using namespace std;
//洛谷P1540 queue队列代码 
int Hash[1003]={0};		//用哈希检查内存中有没有单词 
queue<int>mem;			//用队列模拟内存 
int main(){
	int n,m;
	scanf("%d %d",&m,&n);
	int cnt=0;			//查词典的次数 
	while(n--){
		int en;scanf("%d",&en);			//输入的英文单词 
		if(!Hash[en]){					//如果内存中没有存储 
			++cnt;					
			mem.push(en);
			Hash[en]=1;					//记录内存中有这个单词 
			while(mem.size()>m){		//内存满时 
				Hash[mem.front()]=0;	//从内存中去掉 
				mem.pop();				//从对头去掉 
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
