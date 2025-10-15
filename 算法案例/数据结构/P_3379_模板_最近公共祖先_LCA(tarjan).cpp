#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int fa[N],head[N],cnt,head_query[N],cnt_query,ans[N];
bool vis[N];
struct Edge{
    int to,next,num;
}edge[2*N],query[2*N];
void init(){
    for(int i=0;i<2*N;i++){
        edge[i].next=-1;
        head[i]=-1;
        query[i].next=-1;
        head_query[i]=-1;
    }
    cnt=0,cnt_query=0;
}
void addedge(int u,int v){
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void add_query(int x,int y,int num){
    query[cnt_query].to=y;
    query[cnt_query].num=num;
    query[cnt_query].next=head_query[x];
    head_query[x]=cnt_query++;
}
int find_set(int x){
    return fa[x]==x?x:find_set(fa[x]);
}
void tarjan(int x){
    vis[x]=true;
    for(int i=head[i];~i;i=edge[i].next){
        int y=edge[i].to;
        if(!vis[y]){
            tarjan(y);
            fa[y]=x;
        }
    }
    for(int i=head_query[x];~i;i=query[i].next){
        int y=query[i].to;
        if(vis[y]){
            ans[query[i].num]=find_set(y);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    init();
    memset(vis,0,sizeof(vis));
    int n,m,root;
    cin>>n>>m>>root;
    for(int i=1;i<n;i++){
        fa[i]=i;
        int u,v;
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    fa[n]=n;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add_query(a,b,i);
        add_query(b,a,i);
    }
    tarjan(root);
    for(int i=1;i<=m;i++)cout<<ans[i]<<endl;
}