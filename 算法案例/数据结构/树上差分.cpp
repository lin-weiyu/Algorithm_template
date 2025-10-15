#include<bits/stdc++.h>//P3128
using namespace std;
#define N 50010
struct Edge{int to,next;}edge[2*N];
int head[2*N],D[N],deep[N],fa[N][20],ans,cnt;
void addedge(int u,int v){
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void init(){
    for(int i=0;i<2*N;i++){
        edge[i].next=-1;
        head[i]=-1;
    }
    cnt=0;
}
void dfs1(int x,int father){
    deep[x]=deep[father]+1;
    fa[x][0]=father;
    for(int i=1;(1<<i)<=deep[x];i++){
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    for(int i=head[x];~i;i=edge[i].next){
        if(edge[i].to!=father){
            dfs1(edge[i].to,x);
        }
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
void dfs2(int u,int fath){
    for(int i=head[u];~i;i=edge[i].next){
        int e=edge[i].to;
        if(e==fath)continue;
        dfs2(e,u);
        D[u]+=D[e];
    }
    ans=max(ans,D[u]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    init();
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    dfs1(1,0);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        int lca=LCA(a,b);
        D[a]++,D[b]++,D[lca]--,D[fa[lca][0]]--;
    }
    dfs2(1,0);
    cout<<ans<<endl;
    return 0;
}