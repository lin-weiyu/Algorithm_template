#include<bits/stdc++.h>
using namespace std;
struct node{
	double x;
	double y;
	double c;	
}nodes[210];
bool cmp(node x,node y){
	return(x.c>y.c);
}
int main(){
	int n;
	double s=0,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>nodes[i].x >>nodes[i].y ;
		nodes[i].c=nodes[i].y/nodes[i].x;
	}	
	sort(nodes,nodes+n,cmp);
	for(int i=0;i<n;i++){
		if(nodes[i].x<=m){
			s+=nodes[i].y;
			m-=nodes[i].x;
		}
		else{
			s+=nodes[i].c*m;
			break;
		}
	}
	printf("%.2lf",s);
	return 0;
}
