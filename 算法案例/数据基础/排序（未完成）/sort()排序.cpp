#include<bits/stdc++.h>
using namespace std;

bool my_less(int i,int j){return (i<j);}	//自定义小于   返回true则进行交换 
bool my_greater(int i,int j){return (i>j);} //自定义大于 

/*
sort(first,last,comp)	对 [first,last) 排序
自带4种comp排序：less(默认:从小到大)，greater,less_equal,grester_equal 

stable_sort(first,last,comp) 于sort()的区别：不会改变相同值的元素位置 

partial_sort(first,middle,last,comp) 交换存储位置，实现部分排序
将[first,last)中最小(或最大)的 middle - first 个元素移到[fist,middle)区域中
并对这部分做升序（或降序）排序 
注：从头到找到最后一个元素的位置中，除被移动到middle前的元素外，剩下的元素也会被有序 

nth_element(first,nth,last,comp) 默认升序时，从某个序列中找到第k小的元素e(序列下标从0开始), 
并将 e 移动到第 k 个位置，经处理后，所有e之前的元素都比e小，所有之后的都比e大

is_sorted(first,last,comp) 检测区域是否排好序，默认升序 

*/

int main(){		//C++ STL sort()排序 
	int a[]={1,3,2,2,6,8,5,4};
	sort(a+2,a+6);				//对中间4个排序：1，3，2，2，6，8，5，4
	sort(a,a+8,less<int>());	//所有排序：1，2，2，3，4，5，6，8
	sort(a,a+8,my_less);		//自定义排序：1，2，2，3，4，5，6，8
	sort(a,a+8,greater<int>()); //从大到小排序：8，6，5，4，3，2，2，1
	sort(a,a+8,my_greater);		//自定义排序：8,6,5,4,3,2,2,1
	stable_sort(a+3,a+8);		//  8,6,5,1,2,2,3,4
	
	int b[]={3,7,2,5,6,8,5,4};
	partial_sort(b,b+3,b+8);	//找出最小的3个并进行排序：2,3,4,7,6,8,5,5 
	partial_sort(b,b+3,b+8,greater<int>());//  8,7,6,2,3,4,5,5  (因8在5位置，3~5位置也被有序)
	if(is_sorted(b,b+3,greater<int>())) cout<<"is sorted"<<endl; 
	for(int i=0;i<8;i++)cout<<b[i]<<" ";
	
	vector<int> c={1,2,3,4,5,6,7,8};
	sort(c.begin(),c.end(),my_greater); //8,7,6,5,4,3,2,1
	
	string s="hello,world";
	sort(s.begin(),s.end(),greater<char>());
	cout<<s;				// wroolllhed\0   最后跟着一个空格 
	return 0; 
}






