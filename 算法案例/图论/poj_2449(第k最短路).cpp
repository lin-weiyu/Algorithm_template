#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1005,M=100005;
struct edge{
    int to,w;
    edge(int a,int b){to=a,w=b;}
};
vector<edge>G[M],G2[M];                 //G为原图，G2为反图
struct node{
    int id,dis;
    node(int a,int b){id=a,dis=b;}
    bool operator<(const node &u)const{return dis>u.dis;}
};
int dist[N];                            //当前点i到终点的最短距离
bool done[N];
void dijkstra(int s){                   //利用dijkstra计算各个点到终点的路径长度
    for(int i=0;i<N;i++){
        dist[i]=INF;
        done[i]=0;
    }
    dist[s]=0;
    priority_queue<node>q;
    q.push(node(s,dist[s]));
    while(q.size()){
        node u=q.top();
        q.pop();
        if(done[u.id])continue;
        done[u.id]=true;
        for(int i=0;i<G2[u.id].size();i++){
            edge y=G2[u.id][i];
            if(done[y.to])continue;
            if(dist[y.to]>u.dis+y.w){
                dist[y.to]=u.dis+y.w;
                q.push(node(y.to,dist[y.to]));
            }
        }
    }
}
struct point{
    int v,g,h;
    point(int a,int b,int c){v=a,g=b,h=c;}          //评估函数：f=g+h,  g为从s到i的长度，h为从i到t的长度
    bool operator<(const point &b)const{return g+h>b.g+b.h;}
};
int times[N];
int astar(int s,int t,int k){
    memset(times,0,sizeof(times));
    priority_queue<point>q;
    q.push(point(s,0,0));
    while(q.size()){
        point p=q.top();
        q.pop();
        times[p.v]++;
        if(times[p.v]==k&&p.v==t){                  //终点第k次弹出，则是第k短的路，因为总体统筹兼顾，可以大量优化，但在最坏情况下跟暴力法相同
            return p.g+p.h;
        }
        for(int i=0;i<G[p.v].size();i++){
            edge y=G[p.v][i];
            q.push(point(y.to,p.g+y.w,dist[y.to]));
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        G[a].push_back(edge(b,w));
        G2[b].push_back(edge(a,w));
    }
    int s,t,k;
    cin>>s>>t>>k;
    if(s==t)k++;
    dijkstra(t);
    cout<<astar(s,t,k)<<endl;
    return 0;
}
