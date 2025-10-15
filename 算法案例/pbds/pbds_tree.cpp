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
const int INF=INT_MAX;
int T,n,m;
/*
tree:第一个参数为键的类型
第二个参数为值得类型(null_type 表示无映射，如set，不是map)
第三个参数为仿函数，比较规则
第四个参数为平衡树的类型：基本比手写的树慢  1/6 左右
红黑树：rb_tree_tag  运行速度比其它几个快
splay树：splay_tree_tag
ov_tree_tag
第5个参数：代表元素的维护策略，只有当使用tree_order_statistics_node_update时才可以求kth和rank，此外还有null_tree_node_update（默认值）等
tree.split(v,tree2):tree中小于等于v的元素给tree，其余的元素给tree2
*/
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>Tree;
Tree tr;
int tr_clock;
template<typename T>
int getOrder(T x){
    /*
    tree.order_of_key(x)
    求x的排名，返回整数，这里的x不一定要在树内
    实际查找：如当树升序时，在树中找严格比x小的元素的数量
    所以最后答案加1
    */
    return tr.order_of_key(x)+1;
}
template<typename T>
T getValue(int k){
    /*
    tree.find_by_order(k-1)
    求平衡树内排名为k的值的元素是多少，返回迭代器it 
    且 k 要在[0,size-1]范围内，所以第k大要查找k-1位置
    不在这个范围内则返回tree.end(),如果元素的类型为int，则其为*tree.end()==0，万一我们平衡树里面存在值为0的元素，就会混淆掉，所以我们还要特判一下
    */
    auto it=tr.find_by_order(k-1);
    if(it!=tr.end()){
        return *it;
    }
    else{
        return make_pair(INF,0);
    }
}
void solve(){
    cin>>n;
    int op,x;
    while(n--){
        cin>>op>>x;
        ++tr_clock;
        if(op==1){
            tr.insert(make_pair(x,tr_clock));
        }
        else if(op==2){
            auto it=tr.upper_bound(make_pair(x,0));
            tr.erase(it);
        }
        else if(op==3){
            int k=getOrder<pair<int,int>>(make_pair(x,0));
            cout<<k<<endl;
        }
        else if(op==4){
            auto v=getValue<pair<int,int>>(x);
            cout<<v.first<<endl;
        }
        else if(op==5){
            auto it=tr.upper_bound(make_pair(x,0));
            --it;
            auto v=*it;
            cout<<v.first<<endl;
        }
        else{
            auto v=*tr.upper_bound(make_pair(x,INF));
            cout<<v.first<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);;
    int t=1;
    tr.insert(make_pair(3,4));
    tr.insert(make_pair(3,4));//并没有被实际存储在内
    tr.insert(make_pair(5,4));
    debug(tr.order_of_key({5,4}));
    for(auto v:tr){
        debug(v);
    }
    // while(t--){
    //     solve();
    // }
    return 0;
}