#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct Node{
	int v;int ls,rs;
}t[N];
void preorder(int p){		//根左右  先序遍历 
	if(p!=0){
		cout<<t[p].v <<" ";
		preorder(t[p].ls );
		preorder(t[p].rs ); 
	}
}
void midorder(int p){		//左根右  中序遍历 
	if(p!=0){
		midorder(t[p].ls );
		cout<<t[p].v <<' ';
		midorder(t[p].rs ); 
	}
}
void postorder(int p){		//左右根  后序遍历 
	if(p!=0){
		postorder(t[p].ls );
		postorder(t[p].rs );
		cout<<t[p].v <<" ";
	}
} 
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int a,b;cin>>a>>b;
		t[i].v =i;
		t[i].ls =a;
		t[i].rs =b;
	}
	preorder(1);cout<<endl;
	midorder(1);cout<<endl;
	postorder(1);cout<<endl;
} 

