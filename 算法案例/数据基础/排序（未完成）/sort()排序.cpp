#include<bits/stdc++.h>
using namespace std;

bool my_less(int i,int j){return (i<j);}	//�Զ���С��   ����true����н��� 
bool my_greater(int i,int j){return (i>j);} //�Զ������ 

/*
sort(first,last,comp)	�� [first,last) ����
�Դ�4��comp����less(Ĭ��:��С����)��greater,less_equal,grester_equal 

stable_sort(first,last,comp) ��sort()�����𣺲���ı���ֵͬ��Ԫ��λ�� 

partial_sort(first,middle,last,comp) �����洢λ�ã�ʵ�ֲ�������
��[first,last)����С(�����)�� middle - first ��Ԫ���Ƶ�[fist,middle)������
�����ⲿ�������򣨻������� 
ע����ͷ���ҵ����һ��Ԫ�ص�λ���У������ƶ���middleǰ��Ԫ���⣬ʣ�µ�Ԫ��Ҳ�ᱻ���� 

nth_element(first,nth,last,comp) Ĭ������ʱ����ĳ���������ҵ���kС��Ԫ��e(�����±��0��ʼ), 
���� e �ƶ����� k ��λ�ã������������e֮ǰ��Ԫ�ض���eС������֮��Ķ���e��

is_sorted(first,last,comp) ��������Ƿ��ź���Ĭ������ 

*/

int main(){		//C++ STL sort()���� 
	int a[]={1,3,2,2,6,8,5,4};
	sort(a+2,a+6);				//���м�4������1��3��2��2��6��8��5��4
	sort(a,a+8,less<int>());	//��������1��2��2��3��4��5��6��8
	sort(a,a+8,my_less);		//�Զ�������1��2��2��3��4��5��6��8
	sort(a,a+8,greater<int>()); //�Ӵ�С����8��6��5��4��3��2��2��1
	sort(a,a+8,my_greater);		//�Զ�������8,6,5,4,3,2,2,1
	stable_sort(a+3,a+8);		//  8,6,5,1,2,2,3,4
	
	int b[]={3,7,2,5,6,8,5,4};
	partial_sort(b,b+3,b+8);	//�ҳ���С��3������������2,3,4,7,6,8,5,5 
	partial_sort(b,b+3,b+8,greater<int>());//  8,7,6,2,3,4,5,5  (��8��5λ�ã�3~5λ��Ҳ������)
	if(is_sorted(b,b+3,greater<int>())) cout<<"is sorted"<<endl; 
	for(int i=0;i<8;i++)cout<<b[i]<<" ";
	
	vector<int> c={1,2,3,4,5,6,7,8};
	sort(c.begin(),c.end(),my_greater); //8,7,6,5,4,3,2,1
	
	string s="hello,world";
	sort(s.begin(),s.end(),greater<char>());
	cout<<s;				// wroolllhed\0   ������һ���ո� 
	return 0; 
}






