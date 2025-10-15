#include<bits/stdc++.h>
#ifdef LWY
#include "debug.h"
#else
#define debug(...) 0
#endif
using namespace std;
const int N=2e5+10;
int cnt=0;
int a[N],b[N],root[N];
struct{
    int L,R,sum;
}tree[N<<5];
int build(int pl,int pr){                              //当多组样例时要重建树，单组时该函数无必要
    int rt=++cnt;
    tree[rt].sum=0;
    int mid=(pl+pr)>>1;
    if(pl<pr){
        tree[rt].L=build(pl,mid);
        tree[rt].R=build(mid+1,pr);
    }
    return rt;
}
int update(int pre,int pl,int pr,int x){                //仅新建要更新的节点，并指向前一棵树的子节点
    int rt=++cnt;                                       //cnt 为当前节点编号
    tree[rt].L=tree[pre].L;                             //该节点的左右儿子初始化为前一棵树相同位置节点的左右儿子
    tree[rt].R=tree[pre].R;
    tree[rt].sum=tree[pre].sum+1;                         //插入一个树，在前一棵树的相同节点加1 
    int mid=(pl+pr)>>1;
    if(pl<pr){
        if(x<=mid){
            tree[rt].L=update(tree[pre].L,pl,mid,x);
        }
        else{
            tree[rt].R=update(tree[pre].R,mid+1,pr,x);
        }
    }
    return rt;
}
int query(int u,int v,int pl,int pr,int k){             //近似二分，返回的是节点的位置，而不是直接返回数值
    if(pl==pr)return pl;
    int x=tree[tree[v].L].sum-tree[tree[u].L].sum;
    int mid=(pl+pr)>>1;
    if(x>=k){
        return query(tree[u].L,tree[v].L,pl,mid,k);
    }
    else{
        return query(tree[u].R,tree[v].R,mid+1,pr,k-x);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int size=unique(b+1,b+1+n)-b-1;                     //size 为b数组中不重复元素的数字的个数\
  //root[0]=build(1,size);                                初始化一棵包含size个元素的空树，实际上没必要
    for(int i=1;i<=n;i++){
        int x=lower_bound(b+1,b+1+size,a[i])-b;         //找等于a[i]的b[x]，x为离散化后的a[i]对应的值
        debug(a[i],x);
        root[i]=update(root[i-1],1,size,x);             //建第i棵线段树，root[i]为第i棵线段树的根节点
    }
    while(m--){
        int x,y,k;
        cin>>x>>y>>k;
        int t=query(root[x-1],root[y],1,size,k);        //第y棵线段树减去第x-1棵线段树，就是区间[x,y]的线段树
        cout<<b[t]<<endl;
    }
    return 0;
}