#include<bits/stdc++.h>
#ifdef LWY
#include "debug.h"
#else
#define debug(...) 0
#endif
using namespace std;
#define ll long long
#define endl '\n'
#define mod1=1e9+7,mod2=998244353;
const int N=5e5+5;
int fa[N][20],deep[N];
vector<int>edge[N];
void dfs(int u,int father){
    deep[u]=deep[father]+1;
    fa[u][0]=father;
    for(int i=1;(1<<i)<=deep[u];i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for(auto v:edge[u]){
        if(v==father)continue;
        dfs(v,u);
    }
}
int LCA(int x,int y){
    if(deep[x]<deep[y])swap(x,y);
    for(int i=19;i>=0;i--){
        if(deep[x]-(1<<i)>=deep[y]){
            x=fa[x][i];
        }
    }
    if(x==y)return x;
    for(int i=19;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}
void solve(){
    int n,m,root,u,v,x,y;
    cin>>n>>m>>root;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(root,0);
    while(m--){
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}