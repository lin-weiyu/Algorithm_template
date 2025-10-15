#include<algorithm>
#include<cstring>
#include<vector>
#include<stdio.h>
using namespace std;
//poj 1144 Network
const int N=110;
int low[N],num[N],dfn;
bool incut[N];
vector<int>G[N];
void dfs(int u,int father){
    low[u]=num[u]=++dfn;
    int child=0;
    for(auto v:G[u]){
        if(!num[u]){
            child++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=num[u]&&u!=1)incut[u]=1;
        }
        else if(num[v]<num[u]&&v!=father){
            low[u]=min(low[u],num[v]);
        }
    }
    if(u==1&&child>=2){
        incut[u]=1;
    }
}
int main(){
    int ans,n;
    while(scanf("%d",&n)!=-1){
        if(n==0)break;
        memset(low,0,sizeof(low));
        memset(num,0,sizeof(num));
        dfn=0;
        for(int i=0;i<=n;i++)G[i].clear();
        int a,b;
        while(scanf("%d",&a)&&a){
            while(getchar()!='\n'){
                scanf("%d",&b);
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }
        memset(incut,0,sizeof(incut));
        ans=0;
        dfs(1,1);
        for(int i=1;i<=n;i++)ans+=incut[i];
        printf("%d\n",ans);
    }
    return 0;
}