#include<bits/stdc++.h>
using namespace std;
int main(){
	set<char> cSet;
	cSet.insert('B');
	cSet.insert('C');
	cSet.insert('D');
	cSet.insert('A');
	cSet.insert('F');
	cout<<"old set:"<<endl;
	set<char>::iterator it ;	//访问方法1：迭代器 
	for(it=cSet.begin();it!=cSet.end();it++)
		cout<<*it<<endl;
	char cTmp;
	cTmp='D';
	it=cSet.find(cTmp);			//查找元素，找到返回该元素的迭代器，无则返回结束迭代器
	cout<<"start find:"<<cTmp<<endl;
	if (it==cSet.end()) cout<<"not found"<<endl;
	else cout<<"found"<<endl;
	cTmp='C';
	it=cSet.find(cTmp);
	cout<<"start find:"<<cTmp<<endl;
	if(it==cSet.end()) cout<<"not found"<<endl;
	else cout<<"found"<<endl;
	cout<<"访问集合："<<endl;
	//for(auto i;i:cSet)			//访问方法2：智能指针（只能从头到尾），auto （c++11中启用）自动适应类型 
	//	cout<<i<<endl;
	cout<<"访问最后一个元素："<<endl;
	cout<<"第一种："<<*cSet.rbegin()<<endl;
	cout<<"第二种：";
	set<char>::iterator iter=cSet.end();
	iter--;						//因为end指向最后一个元素的后一个地址 
	cout<<(*iter)<<endl; 
	cout<<"第三种："<<*(--cSet.end())<<endl;
	return 0;
}
/*
改变排序规则（默认为less比较器，即从大到小）（常用）
set<int> s1;		默认从小到大
set<int,greater<int>> s2;		从大到小 
*/
/*
高级数据类型（结构体）
*/ 
