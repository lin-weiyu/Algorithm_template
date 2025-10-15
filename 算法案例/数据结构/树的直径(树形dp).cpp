#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct edge{int to,w;};
vector<edge>e[N];
int dp[N];
int maxlen;
bool vis[N];
void dfs(int u){
    vis[u]=true;
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i].to,edge=e[u][i].w;
        if(vis[v])continue;
        dfs(v);
        maxlen=max(maxlen,dp[u]+dp[v]+edge);
        dp[u]=max(dp[u],dp[v]+edge);
    }
    return;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b,w;
        cin>>a>>b>>w;
        e[a].push_back({b,w});
        e[b].push_back({a,w});
    }
    dfs(1);
    cout<<maxlen<<endl;
    return 0;
}