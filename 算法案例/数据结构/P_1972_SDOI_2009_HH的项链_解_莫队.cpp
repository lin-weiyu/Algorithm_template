#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
struct node{
    int L,R,k;
}q[N];
int root[N],ans[N],cnt[N],a[N],pos[N];      
bool cmp(node a,node b){               //关键在于排序上的优化
    if(pos[a.L]!=pos[b.L]){
        return pos[a.L]<pos[b.L];
    }
    if(pos[a.L]&1)return a.R>b.R;
    return a.R<b.R;
};
int ANS=0;
void add(int x){
    cnt[a[x]]++;
    if(cnt[a[x]]==1)ANS++;
}
void del(int x){
    cnt[a[x]]--;
    if(cnt[a[x]]==0)ANS--;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,block;
    cin>>n;
    block=sqrt(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[i]=(i-1)/block+1;
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>q[i].L>>q[i].R;
        q[i].k=i;
    }
    sort(q+1,q+1+m,cmp);
    int L=1,R=0;
    for(int i=1;i<=m;i++){
        while(L<q[i].L)del(L++);
        while(R>q[i].R)del(R--);
        while(L>q[i].L)add(--L);
        while(R<q[i].R)add(++R);
        ans[q[i].k]=ANS;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}