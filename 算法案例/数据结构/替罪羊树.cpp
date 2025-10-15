#include<bits/stdc++.h>//P3369
using namespace std;
const int N=1e6+10;
const double alpha=0.75;        //不平衡率
struct Node{
    int ls,rs;
    int val;
    int tot;
    int size;
    int del;
}t[N];
int order[N],cnt;               //拍平后存储数据的栈
int tree_stack[N],top=0;        //存储可用空间的栈
int root=0;
void inorder(int u){
    if(!u)return;
    inorder(t[u].ls);
    if(t[u].del)order[++cnt]=u;
    else tree_stack[++top]=u;
    inorder(t[u].rs);
}
void Initnode(int u){
    t[u].ls=t[u].rs=0;
    t[u].size=t[u].tot=t[u].del=1;
}
void Update(int u){
    t[u].size=t[t[u].ls].size=t[t[u].rs].size+1;
    t[u].tot=t[t[u].ls].tot+t[t[u].rs].tot+1;
}
void build(int l,int r,int &u){
    int mid=(l+r)>>1;
    u=order[mid];
    if(l==r){
        Initnode(u);
        return;
    }
    if(l<mid)build(1,mid-1,t[u].ls);
    if(l==mid)t[u].rs=0;
    build(mid+1,r,t[u].rs);
    Update(u);
}
void rebuild(int &u){
    cnt=0;
    inorder(u);
    if(cnt)build(1,cnt,u);
    else u=0;
}
bool notbalance(int u){
    if((double)t[u].size*alpha<=(double)max(t[t[u].ls].size,t[t[u].rs].size)){
        return true;
    }
    return false;
}
void Insert(int &u,int x){
    if(!u){
        u=tree_stack[top--];
        t[u].val=x;
        Initnode(u);
        return;
    }
    t[u].size++;
    t[u].tot++;
    if(t[u].val>=x)Insert(t[u].ls,x);
    else Insert(t[u].rs,x);
    if(notbalance(u))rebuild(u);
}
int Rank(int u,int x){
    if(u==0)return 0;
    if(x>t[u].val)return t[t[u].ls].size+t[u].del+Rank(t[u].rs,x);
    return Rank(t[u].ls,x);
}
int kth(int k){
    int u=root;
    while(u){
        if(t[u].del&&t[t[u].ls].size+1==k)return t[u].val;
        else if(t[t[u].ls].size>=k)u=t[u].ls;
        else{
            k-=t[t[u].ls].size+t[u].del;
            u=t[u].rs;
        }
    }
    return t[u].val;
}
void Del_k(int &u,int k){
    t[u].size--;
    if(t[u].del&&t[t[u].ls].size+1==k){
        t[u].del=0;
        return;
    }
    if(t[t[u].ls].size+t[u].del>=k)Del_k(t[u].ls,k);
    else Del_k(t[u].rs,k-t[t[u].ls].size-t[u].del);
}
void Del(int x){
    Del_k(root,Rank(root,x)+1);
    if(t[root].tot*alpha>=t[root].size){
        rebuild(root);
    }
}
void print_tree(int u){
    if(u){
        cout<<"v="<<t[u].val<<",l="<<t[u].ls<<",r="<<t[u].ls<<endl;
        print_tree(t[u].ls);
        print_tree(t[u].rs);
    }
}
int tree_deep[N]={0},deep_timer=0,max_deep=0;
void cnt_deep(int u){
    if(u){
        tree_deep[u]=++deep_timer;
        max_deep=max(max_deep,tree_deep[u]);
        cnt_deep(t[u].ls);
        cnt_deep(t[u].rs);
        deep_timer--;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    for(int i=N-1;i>=1;i--){
        tree_stack[++top]=i;
    }
    int q;
    cin>>q;
    while(q--){
        int opt,x;
        cin>>opt>>x;
        switch (opt)
        {
            case 1:Insert(root,x);break;
            case 2:Del(x);break;
            case 3:cout<<Rank(root,x)+1<<endl;break;
            case 4:cout<<kth(x)<<endl;break;
            case 5:cout<<kth(Rank(root,x))<<endl;break;
            case 6:cout<<kth(Rank(root,x+1)+1)<<endl;break;
        }
    }
    return 0;
}
