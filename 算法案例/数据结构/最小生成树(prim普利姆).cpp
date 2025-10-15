#include<iostream>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn=505;
#define ll long long
int a[maxn][maxn];
int vis[maxn],dist[maxn];
int n,m;
int u,v,w;
ll sum=0;
int prim(int pos){
    dist[pos]=0;
    for(int i=1;i<=n;i++){
        int cur=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&(cur==-1||dist[j]<dist[cur])){
                cur=j;
            }
        }
        if(dist[cur]>INF)return INF;
        sum+=dist[cur];
        vis[cur]=1;
        for(int k=1;k<=n;k++){
            if(!vis[k])dist[k]=min(dist[k],a[cur][k]);
        }
    }
    return sum;
}
int main(){
    cin>>n>>m;
    memset(a,0x3f,sizeof(a));
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w;
    }
    int value=prim(1);
    if(value>=INF)puts("impossible");
    else cout<<sum;
    return 0;
}