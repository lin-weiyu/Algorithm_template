#include<bits/stdc++.h>
using namespace std;
//˫�˶��У�deque��
int main(){
	deque<int> intdeque;
	intdeque.push_back(2);					//�ڶ�β���Ԫ�� 
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
	intdeque.pop_front();					//ɾ����һ��Ԫ�� 
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
back				����˫�˶������һ��Ԫ�ص�����
begin				���ض����е�һ��Ԫ�صĵ�����
clear				ɾ�����е�����Ԫ��
empty				�������Ϊ�գ�����true
end					���ض������һ��Ԫ����һ����ַ�ĵ�����
erase(i)			ɾ��������iָ���Ԫ��
erase(start,end)	ɾ����������start,last)��Χ��Ԫ��
front				���ض��е�һ��Ԫ�ص�����
insert(i,x)			�� x ��������� i ָ����λ��
insert(i,start,end) �ѵ�������start,end) ��Χ��Ԫ�ز��뵽�����е�����iָ����λ��
insert(i,n,x)		�� x �� n ���������뵽������ i ָ����λ��
max_size			���ض��е�������������������ɵ�Ԫ������
pop_back			ɾ�����е����һ��Ԫ��
pop_front			ɾ�����еĵ�һ��Ԫ��
push_backj(x)		��x���ڶ��е�β��
push_front(x)		�� x ���ڶ��еĿ�ͷ
rbegin				����һ�������������ָ��������һ��Ԫ��֮��ĵ�ַ
rend				����һ�������������ָ����е�һ��Ԫ��
resize(n,x)			�������ö��еĴ�С n ,��Ԫ�صĳ�ʼֵΪ x
size				���ض��еĴ�С��Ԫ�ظ�����
swap(vector)		������������������   ע��˫�˶��п����� sort�������� 
��С��������
sort(d.begin(),d.end())
�Ӵ�С����
sort(q.begin(),q.end(),greater<int>)   ���������� int ����
sort(q.begin(),q.end(),gertater())   �߰汾���� 
 
*/

