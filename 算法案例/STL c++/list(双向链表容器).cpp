#include<bits/stdc++.h>
using namespace std;
//list<int> list1(first,last);	��ʼ��
//list[i]=3			����  �޷�ʹ��������� ����
//��list����ͨ����ʹ�õ����������������÷�������ָ�� 
int main(){
	cout<<"ʹ��δ����洢0-9�������ʼ��list1"<<endl;
	int array[10]={1,3,5,8,9,2,4,6,0};
	list<int>list1(array,array+10);
	cout<<"list1����sort�������� "<<endl;
	list1.sort();
	list<int>::iterator iter =list1.begin();
	//iter = iter+5 			list�� iter ��֧�֡�+ ������
	//��ָ����vector �еĵ�����֧��"+"���� 
	cout<<"ͨ������������list˫���б��д�ͷ��ʼ���ĵ�4��Ԫ��" <<endl;
	for(int i=0;i<3;i++){
		iter++;
	} 
	cout<<*iter<<endl;
	list1.insert(list1.end(),13);
	cout<<"��ĩβ��������13"<<endl;
	for(list<int>::iterator it=list1.begin();it!=list1.end();it++){
		cout<<" "<<*it; 
	}
	return 0;
} 
/*
assign(first,last)			�õ�����[first,last)��Χ�ڵ�Ԫ���滻����Ԫ��
assign(num,val)				��val��num�������滻����Ԫ��
back		
.0				���ض�����Ԫ�ص����һ��������
begin						����ָ���������һ��Ԫ�ص�����
clear						ɾ�������е�����Ԫ��
empty						�������Ϊ�գ��򷵻�true
end							����ָ���������һ��Ԫ�غ�һ����ַ�ĵ�����
erase(start,end)			ɾ����������start,end)��Χ������Ԫ�� 
erase(i)					ɾ�������� i ָ�������Ԫ��
front						��������Ԫ�ص�һ��Ԫ�ص�����
insert(i,x)					��x ��������� i ָ���λ��
insert(i,start,end)			�ѵ�������start,end)��Χ��Ԫ�ز��뵽������iָ����λ��
insert(i,n,x)				��x��n�����������ɵ�����iָ����λ��
max_size					���������������������������ɵĸ�����
pop_back					ɾ�����������һ��Ԫ��
pop_front					ɾ������ĵ�һ��Ԫ��
push_back(x)				��x���������ĩβ
push_front(x)				��x��������Ŀ�ͷ
rbegin						����һ�������������ָ�����һ��Ԫ�صĺ�һ��λ��
rend						����һ�������������ָ���һ��Ԫ��
resize(n,x)					������������Ĵ�СΪn,��Ԫ�صĳ�ʼֵΪx
reverse						�ߵ�Ԫ�ص�˳��
size						��������Ĵ�С����ǰԪ�ظ�����
swap(listref)				����������������� 
*/
