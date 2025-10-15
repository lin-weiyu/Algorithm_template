#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int dfn[N],low[N],dfncnt,s[N],in_stack[N],tp;
int scc[N],sc;
int sz[N];
struct node{
    int nex,t;
}e[N];//链式前向星
int h[N],cnt=1;
void add(int u,int v){
    e[cnt].t=v;
    e[cnt].nex=h[u];
    h[u]=cnt++;
}
void tarjan(int u){
    low[u]=dfn[u]=++dfncnt,s[++tp]=u,in_stack[u]=1;
    for(int i=h[u];i;i=e[i].nex){
        const int &v=e[i].t;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(in_stack[v]){
         low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        ++sc;
        while(s[tp]!=u){
            scc[s[tp]]=sc;
            sz[sc]++;
            in_stack[s[tp]]=0;
            --tp;
        }
        scc[s[tp]]=sc;
        sz[sc]++;
        in_stack[s[tp]]=0;
        --tp;
    }
}
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        add(u,v);
    }
    tarjan(1);
    return 0;
}