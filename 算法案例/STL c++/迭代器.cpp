#include<bits/stdc++.h>
using namespace std;
//迭代器相当于容器元素的指针，可以进行向前向后移动
//有专门为输入或者输出元素准备的迭代器，和随机操作的迭代器。这些为访问容器提供通用方法 
//注意：不同版本的编译器支持的迭代器中的函数有不同，如c++11才可用rbegin等反向迭代器和智慧指针 
//解引用操作符：* 
//在不同的容器中有对应的迭代器类型，大多相通 
/*
std::vector :随机访问迭代器
std::deque  :随机访问迭代器
std::list   :双向迭代器
std::set std::multiset :双向迭代器
std::map std::multiset :双向迭代器 
std::forward_list  :正向迭代器
std::unordered_set  std::unordered_multiset  :正向迭代器
std::unordered_map  std::unordered_multimap  :正向迭代器 
*/
int main(){
	//输出迭代器的应用
	vector<int>intVect;
	for(int i=0;i<10;i+=2)
		intVect.push_back(i);
	cout<<"Vect:"<<endl;
	vector<int>::iterator it=intVect.begin();
	while(it!=intVect.end())
		cout<<*it++<<endl;				//右结合，但是it++而不是++it,所以先取内容后自增 
	//输入迭代器的应用 
	it=intVect.begin();
	*it++=1;
	*it++=3;
	*it++=5;
	*it++=7;
	*it=9;
	it=intVect.begin();
	cout<<"Vect:"<<endl;
	while(it!=intVect.end())
		cout<<*it++<<" ";
	cout<<endl;
	return 0;
}
