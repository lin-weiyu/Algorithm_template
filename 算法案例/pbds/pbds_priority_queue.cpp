#include<bits/stdc++.h>
#include<bits/extc++.h>
#ifdef LWY
#include "debug.h"
#else
#define debug(...) 0
#endif
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
const int N=1e6+10;
const int INF=INT_MAX;
/*
为跟std中的priority_queue区分，前面必须加上命名空间。
声明时关键字为：元素类型，仿函数，堆的类型
堆的类型分为：
pairing_heap_tag:配对堆
thin_heap_tag:斐波那契堆
binomial_heap_tag:二项堆
binary_heap_tag：二叉堆
一般情况下配对堆和斐波那契堆效果比较好
*/
__gnu_pbds::priority_queue<pair<int,int>,greater<pair<int,int>>,pairing_heap_tag>q;
/*
新增了修改函数q.modify(迭代器it,新元素):修改迭代器(point_iterator)上的元素为新元素
所以要想修改其中的元素，在加入时就应存储该元素所在的迭代器
并且q.push()会返回该元素所存储的迭代器
q1.jion(q2):把q2队列加入到q1的队列，并且清空q2，时间复杂度为O(logn)
*/
__gnu_pbds::priority_queue<pair<int,int>,greater<pair<int,int>>,pairing_heap_tag>::point_iterator its[N];
int dis[N],n;
vector<pair<int,int>>g[N];
void dijkstra(int sta){
    q.clear();
    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }
    its[sta]=q.push({0,sta});
    dis[sta]=0;
    int u;
    while(!q.empty()){
        u=q.top().second;
        q.pop();
        for(auto e:g[u]){
            if(dis[e.first]>dis[u]+e.second){
                dis[e.first]=dis[u]+e.second;
                if(its[e.first]!=NULL){
                    q.modify(its[e.first],{dis[e.first],e.first});
                }
                else{
                    its[e.first]=q.push({dis[e.first],e.first});
                }
            }
        }
    }
    return;
}
void solve(){
    n=10;
    for(int i=1;i<=n;i++){
        its[n-i]=q.push({n-i,i});
    }
    q.modify(its[5],{12,0});
    q.modify(its[5],{13,0});
    while(q.size()){
        debug(q.top());
        q.pop();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}