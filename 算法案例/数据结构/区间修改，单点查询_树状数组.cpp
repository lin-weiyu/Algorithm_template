#include<bits/stdc++.h>
using namespace std;
const int N=1000;
#define lowbit(x) ((x)&(-x))
int tree[N];
void update(int x,int d){
	while(x<=N){
		tree[x]+=d;
		x+=lowbit(x);
	}
}
int sum(int x){
	int ans=0;
	while(x>0){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(tree,0,sizeof(tree));
		for(int i=1;i<=n;i++){
			int L,R;
			scanf("%d %d",&L,&R);
			update(L,1);//�൱�ڰѵ�ǰ��ֵ��ɢ��ǰ�����ӽڵ��� ��ʹ�õ�ǰλ�õ�sum���� 
			update(R+1,-1);
		}
		for(int i=1;i<=n;i++){
			if(i!=n)printf("%d",sum(i));
			else printf("%d\n",sum(i));
		}
	}
	return 0;
}
