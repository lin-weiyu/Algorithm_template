#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct edge{int to,w;};
vector<edge>e[N];
int dist[N];
void dfs(int u,int fa,int d){
    dist[u]=d;
    for(int i=0;i<e[u].size();i++){
        if(e[u][i].to!=fa){
            dfs(e[u][i].to,u,d+e[u][i].w);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b,w;
        cin>>a>>b>>w;
        e[a].push_back({b,w});
        e[b].push_back({a,w});
    }
    dfs(1,-1,0);                                //先随便以一个节点为根，找离根最远的点，这个点必为直径端点之一
    int s=1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[s])s=i;
    }
    dfs(s,-1,0);                                //以一个端点为根，去dfs寻找另一个端点
    int t=1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[t])t=i;
    }
    cout<<dist[t]<<endl;
    return 0;
}