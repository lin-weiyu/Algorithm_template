#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>v1,v2;			//用std::vector<type>name 模板来创造
	v1.reserve(10);				//reverse本来为颠倒元素，这里为设置最小的容量
	v2.reserve(10);
	v1=vector<int>(8,7);		//用std::vector<type>name(size,value)为模板，有size个空间，默认值全为value
	int array[8]={1,2,3,4,5,6,7,8};
	v2=vector<int>(array,array+8);//std::vector<type>name(first,last),以first到last的地址元素创建对象
	cout<<"v1容量"<<v1.capacity()<<endl;//capacity()为返回当前最多可容纳个数
	cout<<"v1当前各项："<<endl;
	for(int i=0;i<v1.size();i++){
		cout<<" "<<v1[i];
	} 
	cout<<endl;
	v1.resize(0);				//resize(n,x) 重新设置容量大小为 n，新元素初始值为x
	cout<<"v1的容量通过resize函数变为0"<<endl;
	if(!v1.empty())				//如果向量为空则返回true 
		cout<<"v1容量"<<v1.capacity()<<endl; 
	else
		cout<<"v1是空的"<<endl;
	cout<<"将v1容量扩展为8"<<endl;
	v1.resize(8);
	cout<<"v1当前各项："<<endl;
	for(int i=0;i<v1.size();i++)cout<<" "<<v1[i];
	cout<<endl;
	v1.swap(v2);				//swap为交换两个向量的内容 
	cout<<"v1与v2 swap了"<<endl;
	cout<<"v1当前各项："<<endl;
	cout<<"v1的容量"<<v1.capacity()<<endl;
	for(int i=0;i<v1.size();i++)cout<<" "<<v1[i];
	cout<<endl;
	v1.push_back(3); 			//将元素放在末尾
	cout<<"v1后边加入了新的元素3"<<endl;
	cout<<"v1容量"<<v1.capacity()<<endl;
	for(int i=0;i<v1.size();i++)cout<<" "<<v1[i];
	cout<<endl;
	v1.erase(v1.end()-2);
	//v1.erase(v1.begin()+1,v1.begin()+3);
//erase(i)删除  i 处的元素或 srase(start,end) start 到 end 范围内的元素,不包括end位置元素 		
	cout<<"删除了倒数第二个元素"<<endl;
	cout<<"v1容量"<<v1.capacity()<<endl; 
	cout<<"v1当前各项："<<endl;
	for(int i=0;i<v1.size();i++)cout<<" "<<v1[i];
	cout<<endl;
	v1.pop_back();				//删除向量的最后一个元素
	cout<<"通过栈操作pop_back放走了最后的元素"<<endl;
	cout<<"v1容量"<<v1.capacity()<<endl;
	cout<<"v1当前各项："<<endl;
	for(int i=0;i<v1.size();i++)cout<<" "<<v1[i];
	cout<<endl;
	return 0;
}
/*
assign(first,last)			用迭代器 【first，last）所下辖范围内的元素替换向量元素
assign(num,val)				用val的num个副本替换向量元素
at(n)						返回向量中第n个元素的值
back						返回对向量末端元素的引用
begin						返回指向向量第一个元素的迭代器
capcity						返回当前向量最多可以容纳的元素个数
clear						清除向量中的所有元素
empty						如果向量为空，则返回true
end							返回指向向量中最后一个元素后一个地址的迭代器
erase(start,end)			删除迭代器 [start,end) 所辖范围内的向量元素
erase(i)					删除 迭代器i指向的元素 
front						返回对向量起始元素的引用
insert(i,x) 				把x插入迭代器i指向的位置
insert(i,start,end)			把迭代器start和end所辖范围内的元素插入向量中i的位置
insert(i,n,x)				把x的n个副本插入到迭代器i指明的位置
max_size					返回向量的最大容量（最多可以容纳的个数）
pop_back					删除向量的最后一个元素
push_back(x)				把x 放在末尾
rbegin						返回一个反向迭代器，指向向量末尾元素之后
rend						返回一个反向迭代器，指向元素起始元素
reverse						颠倒元素的顺序
resize(n,x)					重新设置向量的大小n，新元素的初始值为x
size						返回向量的大小（元素的个数）
swap(vector)				交换两个向量的内容 
*/
/*访问方法 
1 下标访问 ：和普通数组一样 v1[i]
2 迭代器访问 类似指针
3 智能指针 ：只能遍历完数组  auto 能够自动识别并获取类型
vector<int> v;
for(auto val:v)
	cout<<val<<" ";
*/
 
