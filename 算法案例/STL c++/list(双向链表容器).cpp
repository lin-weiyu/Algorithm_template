#include<bits/stdc++.h>
using namespace std;
//list<int> list1(first,last);	初始化
//list[i]=3			错误  无法使用数组符号 【】
//对list访问通常是使用迭代器，迭代器的用法类似于指针 
int main(){
	cout<<"使用未排序存储0-9的数组初始化list1"<<endl;
	int array[10]={1,3,5,8,9,2,4,6,0};
	list<int>list1(array,array+10);
	cout<<"list1调用sort方法排序 "<<endl;
	list1.sort();
	list<int>::iterator iter =list1.begin();
	//iter = iter+5 			list的 iter 不支持“+ ”运算
	//但指针与vector 中的迭代器支持"+"操作 
	cout<<"通过迭代器访问list双向列表中从头开始向后的第4个元素" <<endl;
	for(int i=0;i<3;i++){
		iter++;
	} 
	cout<<*iter<<endl;
	list1.insert(list1.end(),13);
	cout<<"在末尾插入数字13"<<endl;
	for(list<int>::iterator it=list1.begin();it!=list1.end();it++){
		cout<<" "<<*it; 
	}
	return 0;
} 
/*
assign(first,last)			用迭代器[first,last)范围内的元素替换链表元素
assign(num,val)				用val的num个副本替换链表元素
back		
.0				返回对链表元素的最后一个的引用
begin						返回指向链表最后一个元素的引用
clear						删除链表中的所有元素
empty						如果链表为空，则返回true
end							返回指向链表最后一个元素后一个地址的迭代器
erase(start,end)			删除迭代器【start,end)范围的链表元素 
erase(i)					删除迭代器 i 指向的链表元素
front						返回链表元素第一个元素的引用
insert(i,x)					把x 插入迭代器 i 指向的位置
insert(i,start,end)			把迭代器【start,end)范围的元素插入到迭代器i指明的位置
insert(i,n,x)				把x的n个副本插入由迭代器i指明的位置
max_size					返回链表的最大容量（最多可以容纳的个数）
pop_back					删除链表的最后的一个元素
pop_front					删除链表的第一个元素
push_back(x)				把x放在链表的末尾
push_front(x)				把x放在链表的开头
rbegin						返回一个反向迭代器，指向最后一个元素的后一个位置
rend						返回一个反向迭代器，指向第一个元素
resize(n,x)					重新设置链表的大小为n,新元素的初始值为x
reverse						颠倒元素的顺序
size						返回链表的大小（当前元素个数）
swap(listref)				交换两个链表的内容 
*/
