#include<bits/stdc++.h>//P3379
using namespace std;
const int N=5e5+10;
struct Edge{int to,next;}edge[2*N];
int head[2*N],cnt;
void init(){
    for(int i=0;i<2*N;i++){
        edge[i].next=-1;
        head[i]=-1;
    }
    cnt=0;
}
void addedge(int u,int v){
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
int deep[N],siz[N],son[N],top[N],fa[N];
void dfs1(int x,int father){
    deep[x]=deep[father]+1;
    fa[x]=father;
    siz[x]=1;
    for(int i=head[x];~i;i=edge[i].next){
        int y=edge[i].to;
        if(y!=father){
            fa[y]=x;
            dfs1(y,x);
            siz[x]+=siz[y];
            if(!son[x]||siz[son[x]]<siz[y]){
                son[x]=y;           //重儿子
            }
        }
    }
}
void dfs2(int x,int topx){          //topx为该条重链的链头
    top[x]=topx;
    if(!son[x])return;              //该节点为叶子节点
    dfs2(son[x],topx);
    for(int i=head[x];~i;i=edge[i].next){
        int y=edge[i].to;
        if(y!=fa[x]&&y!=son[x]){
            dfs2(y,y);          //新的一条重链，链头必是轻儿子
        }
    }
}
int LCA(int x,int y){
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]])swap(x,y);
        x=fa[top[x]];
    }
    return deep[x]<deep[y]?x:y;             //在同一条重链上，直接比较深度即可
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    init();
    int n,m,root;
    cin>>n>>m>>root;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    dfs1(root,0);           //预处理出每个节点的深度，和每个节点是否为重儿子
    dfs2(root,root);
    while(m--){
        int a,b;
        cin>>a>>b;
        cout<<LCA(a,b)<<endl;
    }
    return 0;
}