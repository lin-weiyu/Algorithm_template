#include<algorithm>
#include<cstdio>
#include<vector>
//洛谷 P8436
using namespace std;
const int N=5e5+5,M=2e6+5;
int n,m,ans;
int tot=1,hd[N];
struct edge{
    int to,nt;
} e[M<<1];
void add(int u,int v){
    e[++tot].to=v;
    e[tot].nt=hd[u];
    hd[u]=tot;
}
void uadd(int u,int v){
    add(u,v),add(v,u);
}
bool bz[M<<1];
int dfncnt,dfn[N],low[N],vis_bcc[N];
vector<vector<int>>bcc;
void tarjan(int u,int in){
    dfn[u]=low[u]=++dfncnt;
    for(int i=hd[u];i;i=e[i].nt){
        int v=e[i].to;
        if(dfn[v]==0){
            tarjan(v,u);
            if(dfn[u]<low[v])bz[i]=bz[i^1]=1;
            low[u]=min(low[u],low[v]);
        }
        else if(u!=(in^1)){
            low[u]=min(low[u],dfn[v]);
        }
    }
}
void dfs(int u,int id){
    vis_bcc[u]=id,bcc[id-1].push_back(u);
    for(int i=hd[u];i;i=e[i].nt){
        int v=e[i].to;
        if(vis_bcc[v]||bz[i])continue;
        dfs(v,id);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        if(u==v)continue;
        uadd(u,v);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0){
            tarjan(i,0);
        }
    }
    for(int i=1;i<=n;i++){
        if(vis_bcc[i]==0){
            bcc.push_back(vector<int>());
            dfs(i,++ans);
        }
    }
    printf("%d\n",ans);
    for(int i=0;i<ans;i++){
        printf("%llu",bcc[i].size());
        for(int j=0;j<bcc[i].size();j++)printf(" %d",bcc[i][j]);
        printf("\n");
    }
    return 0;
}