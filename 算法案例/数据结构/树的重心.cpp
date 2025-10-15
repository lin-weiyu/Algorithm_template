#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
struct Edge{int to,next;}edge[N<<1];    //链式前向星存边
int head[N],cnt=0;
void init(){
    for(int i=0;i<N;i++){
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
int n,d[N],ans[N],num,maxnum=1e9;
void dfs(int u,int fa){
    d[u]=1;
    int tmp=0;
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        d[u]+=d[v];
        tmp=max(tmp,d[v]);
    }
    tmp=max(tmp,n-d[u]);
    if(tmp<maxnum){
        maxnum=tmp;
        num=0;
        ans[++num]=u;
    }
    else if(tmp==maxnum)ans[++num]=u;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    init();
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    dfs(1,0);
    sort(ans+1,ans+1+num);
    for(int i=1;i<=num;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}