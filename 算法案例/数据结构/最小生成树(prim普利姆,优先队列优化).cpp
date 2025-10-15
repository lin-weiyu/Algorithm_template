#include<bits/stdc++.h>
using namespace std;
template<class T>//下一个结构体中T的数据类型可被自由替换和决定：PrimMst<T>(int n);
struct PrimMst{
    static constexpr T inf=numeric_limits<T>::max();
    int n;
    vector<vector<pair<int,T>>> g;
    vector<T>dis;
    vector<bool>vis;
    PrimMst(int n):n(n),g(n){}
    //或者PrimMst(int n0){n=n0,g.resize(n0);}
    void addEdge(int u,int v,T w){
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    struct Node{
        int t;
        T len;
        bool operator<(const Node &O)const{
            return len>O.len;
        }
    };
    T prim(){
        dis.assign(n,inf);
        vis.assign(n,false);
        priority_queue<Node>q;
        q.push({0,0});
        T ans=0;
        int cnt=0;
        while(q.size()){
            auto [u,len]=q.top();
            q.pop();
            if(vis[u])continue;
            vis[u]=true;
            ans+=len;
            if(++cnt>=n)break;
            for(auto [v,w]:g[u]){
                if(!vis[v]&&w<dis[v]){
                    q.push({v,dis[v]=w});
                }
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}