#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int cnt;
int low[N],num[N],dfn;
int sccno[N],Stack[N],top;
vector<int>G[N];
void dfs(int u){
    Stack[top++]=u;
    low[u]=num[u]==++dfn;
    for(int v:G[u]){
        if(!num[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!sccno[v]){
            low[u]=min(low[u],num[v]);
        }
    }
    if(low[u]==num[u]){
        cnt++;
        while(1){
            int v=Stack[--top];
            sccno[v]=cnt;
            if(u==v)break;
        }
    }
}
void Tarjan(int n){
    cnt=top=dfn=0;
    memset(sccno,0,sizeof(sccno));
    memset(num,0,sizeof(num));
    memset(low,0,sizeof(low));
    for(int i=1;i<=n;i++){
        if(!num[i]){
            dfs(i);
        }
    }
}
int main(){
    int n,m,u,v;
    while(scanf("%d%d",&n,&m),n!=0||m!=0){
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        Tarjan(n);
        printf("%d\n",cnt==1?"YES":"NO");
    }
    return 0;
}