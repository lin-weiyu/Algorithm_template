#include<bits/stdc++.h>
using namespace std;
template<class T>
struct KruskalMst{
    int n;
    vector<int>f;
    vector<tuple<T,int,int>>e;
    KruskalMst(int n):n(n),f(n){}
    vodi addEdfe(int u,int v,T w){
        e.emplace_back(w,u,v);
    }
    int get(int u){
        return f[u]==u?u:f[u]=get(f[u]);
    }
    T kruskal(){
        iota(f.begin(),f.end(),0);
        sort(e.begin(),e.end());
        T ans=0;
        int cnt=0;
        for(auto [w,u,v]:e){
            if((u=get(u))==(v=get(v)))continue;
            f[u]=v;
            ans+=w;
            if(++cnt==n-1)break;
        }
        return ans;
    }
};
int main(){
    return 0;
}