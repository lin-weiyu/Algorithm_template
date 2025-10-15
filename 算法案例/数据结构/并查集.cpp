#include<bits/stdc++.h> 
using namespace std;
int bin[1002];
int Set[2001],N; 
int findx(int x){
	int r=x;
	while(bin[r]!=x){
		r=bin[r];
	}
	return r;
}

int find1(int x){//O(1)
	return Set[x];
}
void Merge1(int a,int b){//O(N)
	int i=min(a,b);
	int j=max(a,b);
	for(int k=1;k<=N;k++){
		if(Set[k]==j)
			Set[k]=i;
	}
}

int find3(int x){//带路径压缩的查找优化操作 
	if(Set[x]!=x){
		Set[x]=find3(Set[x]);
	}
	return Set[x];
}
int find2(int x){//O(N)
	int r=x;
	while(Set[r]!=r)
		r=Set[r];
	return r;
}
void Merge2(int a,int b){//O(1)
	Set[a]=b;
}

void merge(int x,int y){
	int fx,fy;
	fx=findx(x);
	fy=findx(y);
	if(fx!=fy)
		bin[fx]=fy;
}
int main(){
	int n,m,i,x,y,count;
	while(scanf("%d",&n),n){
		for(i=1;i<=n;i++){
			bin[i]=i;
		}
		for(scanf("%d",&m);m>0;m--){
			scanf("%d %d",&x,&y);
			merge(x,y);
		}
		for(count=-1,i=1;i<=n;i++)
			if(bin[i]==i)count++;
		printf("%d\n",count);
	}
	return 0;
}
