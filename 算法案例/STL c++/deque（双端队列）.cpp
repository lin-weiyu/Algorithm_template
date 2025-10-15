#include<bits/stdc++.h>
using namespace std;
//双端队列（deque）
int main(){
	deque<int> intdeque;
	intdeque.push_back(2);					//在队尾添加元素 
	intdeque.push_back(3);
	intdeque.push_back(4);
	intdeque.push_back(7);
	intdeque.push_back(9);
	cout<<"Deque:old"<<endl;
	for(int i=0;i<intdeque.size();i++){
		cout<<"intdeque:["<<i<<"]:";
		cout<<intdeque[i]<<endl;
	}
	cout<<endl;
	intdeque.pop_front();					//删除第一个元素 
	intdeque.pop_front();
	intdeque[1]=33;
	cout<<"Deque:new"<<endl;
	for(int i=0;i<intdeque.size();i++){
		cout<<"intdeque["<<i<<"]:";
		cout<<intdeque[i]<<endl;
	} 
	cout<<endl;
	return 0;
} 
/*
back				返回双端队列最后一个元素的引用
begin				返回队列中第一个元素的迭代器
clear				删除队列的所以元素
empty				如果队列为空，返回true
end					返回队列最后一个元素下一个地址的迭代器
erase(i)			删除迭代器i指向的元素
erase(start,end)	删除迭代器【start,last)范围的元素
front				返回队列第一个元素的引用
insert(i,x)			把 x 插入迭代器 i 指明的位置
insert(i,start,end) 把迭代器【start,end) 范围的元素插入到队列中迭代器i指明的位置
insert(i,n,x)		把 x 的 n 个副本插入到迭代器 i 指明的位置
max_size			返回队列的最大容量（最多可以容纳的元素数量
pop_back			删除队列的最后一个元素
pop_front			删除队列的第一个元素
push_backj(x)		把x放在队列的尾端
push_front(x)		把 x 放在队列的开头
rbegin				返回一个反向迭代器，指向队列最后一个元素之后的地址
rend				返回一个反向迭代器，指向队列第一个元素
resize(n,x)			重新设置队列的大小 n ,新元素的初始值为 x
size				返回队列的大小（元素个数）
swap(vector)		交换两个容器的内容   注：双端队列可以用 sort进行排序 
从小到大排序：
sort(d.begin(),d.end())
从大到小排序：
sort(q.begin(),q.end(),greater<int>)   数据类型是 int 类型
sort(q.begin(),q.end(),gertater())   高版本可用 
 
*/

