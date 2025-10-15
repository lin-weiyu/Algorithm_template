#include<bits/stdc++.h>
using namespace std;
struct nod{
	int st,en;
}nodes[1000010];
bool cmp(nod x,nod y){return x.en <y.en ;}
int main(){
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++)cin>>nodes[i].st >>nodes[i].en ;
	sort(nodes,nodes+n,cmp);
	int s=0,t=0;
	for(int i=0;i<n;i++){
		if(nodes[i].st >=t){
			s++;t=nodes[i].en;
		}
	}
	cout<<s;
	return 0;
}
