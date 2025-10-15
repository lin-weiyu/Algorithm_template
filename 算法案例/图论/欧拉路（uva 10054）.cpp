#include<bits/stdc++.h>
using namespace std;
const int N=55;
int degree[N];
int G[N][N];
void euler(int u){
	for(int v=1;v<=50;v++){
		if(G[u][v]){
			G[u][v]--;
			G[v][u]--;
			euler(v);
			cout<<v<<" "<<u<<endl;
		}
	}
}
int main(){
	int t;
	cin>>t;
	int cnt=0;
	while(t--){
		cnt++;
		if(cnt!=1)cout<<endl;
		cout<<"Case#"<<cnt<<endl;
		memset(degree,0,sizeof(degree));
		memset(G,0,sizeof(G));
		int n;
		cin>>n;
		int color;
		for(int i=0;i<n;i++){
			int u,v;
			cin>>u>>v;
			color=u;
			degree[u]++;
			degree[v]++;
			G[u][v]++;
			G[v][u]++;
		}
		int ok=1;
		for(int i=0;i<=50;i++){
			if(degree[i]%2){
				cout<<"some beads may be lost"<<endl;
				ok=0;
				break;
			}
		}
		if(ok){
			euler(color);
		}
	}
	return 0;
}
