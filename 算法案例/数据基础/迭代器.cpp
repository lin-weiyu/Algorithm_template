#include<bits/stdc++.h>
using namespace std;
//�������൱������Ԫ�ص�ָ�룬���Խ�����ǰ����ƶ�
//��ר��Ϊ����������Ԫ��׼���ĵ�����������������ĵ���������ЩΪ���������ṩͨ�÷��� 
//ע�⣺��ͬ�汾�ı�����֧�ֵĵ������еĺ����в�ͬ����c++11�ſ���rbegin�ȷ�����������ǻ�ָ�� 
//�����ò�������* 
//�ڲ�ͬ���������ж�Ӧ�ĵ��������ͣ������ͨ 
/*
std::vector :������ʵ�����
std::deque  :������ʵ�����
std::list   :˫�������
std::set std::multiset :˫�������
std::map std::multiset :˫������� 
std::forward_list  :���������
std::unordered_set  std::unordered_multiset  :���������
std::unordered_map  std::unordered_multimap  :��������� 
*/
int main(){
	//�����������Ӧ��
	vector<int>intVect;
	for(int i=0;i<10;i+=2)
		intVect.push_back(i);
	cout<<"Vect:"<<endl;
	vector<int>::iterator it=intVect.begin();
	while(it!=intVect.end())
		cout<<*it++<<endl;				//�ҽ�ϣ�����it++������++it,������ȡ���ݺ����� 
	//�����������Ӧ�� 
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
