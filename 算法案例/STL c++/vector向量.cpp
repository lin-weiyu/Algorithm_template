#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>v1,v2;			//��std::vector<type>name ģ��������
	v1.reserve(10);				//reverse����Ϊ�ߵ�Ԫ�أ�����Ϊ������С������
	v2.reserve(10);
	v1=vector<int>(8,7);		//��std::vector<type>name(size,value)Ϊģ�壬��size���ռ䣬Ĭ��ֵȫΪvalue
	int array[8]={1,2,3,4,5,6,7,8};
	v2=vector<int>(array,array+8);//std::vector<type>name(first,last),��first��last�ĵ�ַԪ�ش�������
	cout<<"v1����"<<v1.capacity()<<endl;//capacity()Ϊ���ص�ǰ�������ɸ���
	cout<<"v1��ǰ���"<<endl;
	for(int i=0;i<v1.size();i++){
		cout<<" "<<v1[i];
	} 
	cout<<endl;
	v1.resize(0);				//resize(n,x) ��������������СΪ n����Ԫ�س�ʼֵΪx
	cout<<"v1������ͨ��resize������Ϊ0"<<endl;
	if(!v1.empty())				//�������Ϊ���򷵻�true 
		cout<<"v1����"<<v1.capacity()<<endl; 
	else
		cout<<"v1�ǿյ�"<<endl;
	cout<<"��v1������չΪ8"<<endl;
	v1.resize(8);
	cout<<"v1��ǰ���"<<endl;
	for(int i=0;i<v1.size();i++)cout<<" "<<v1[i];
	cout<<endl;
	v1.swap(v2);				//swapΪ������������������ 
	cout<<"v1��v2 swap��"<<endl;
	cout<<"v1��ǰ���"<<endl;
	cout<<"v1������"<<v1.capacity()<<endl;
	for(int i=0;i<v1.size();i++)cout<<" "<<v1[i];
	cout<<endl;
	v1.push_back(3); 			//��Ԫ�ط���ĩβ
	cout<<"v1��߼������µ�Ԫ��3"<<endl;
	cout<<"v1����"<<v1.capacity()<<endl;
	for(int i=0;i<v1.size();i++)cout<<" "<<v1[i];
	cout<<endl;
	v1.erase(v1.end()-2);
	//v1.erase(v1.begin()+1,v1.begin()+3);
//erase(i)ɾ��  i ����Ԫ�ػ� srase(start,end) start �� end ��Χ�ڵ�Ԫ��,������endλ��Ԫ�� 		
	cout<<"ɾ���˵����ڶ���Ԫ��"<<endl;
	cout<<"v1����"<<v1.capacity()<<endl; 
	cout<<"v1��ǰ���"<<endl;
	for(int i=0;i<v1.size();i++)cout<<" "<<v1[i];
	cout<<endl;
	v1.pop_back();				//ɾ�����������һ��Ԫ��
	cout<<"ͨ��ջ����pop_back����������Ԫ��"<<endl;
	cout<<"v1����"<<v1.capacity()<<endl;
	cout<<"v1��ǰ���"<<endl;
	for(int i=0;i<v1.size();i++)cout<<" "<<v1[i];
	cout<<endl;
	return 0;
}
/*
assign(first,last)			�õ����� ��first��last������Ͻ��Χ�ڵ�Ԫ���滻����Ԫ��
assign(num,val)				��val��num�������滻����Ԫ��
at(n)						���������е�n��Ԫ�ص�ֵ
back						���ض�����ĩ��Ԫ�ص�����
begin						����ָ��������һ��Ԫ�صĵ�����
capcity						���ص�ǰ�������������ɵ�Ԫ�ظ���
clear						��������е�����Ԫ��
empty						�������Ϊ�գ��򷵻�true
end							����ָ�����������һ��Ԫ�غ�һ����ַ�ĵ�����
erase(start,end)			ɾ�������� [start,end) ��Ͻ��Χ�ڵ�����Ԫ��
erase(i)					ɾ�� ������iָ���Ԫ�� 
front						���ض�������ʼԪ�ص�����
insert(i,x) 				��x���������iָ���λ��
insert(i,start,end)			�ѵ�����start��end��Ͻ��Χ�ڵ�Ԫ�ز���������i��λ��
insert(i,n,x)				��x��n���������뵽������iָ����λ��
max_size					����������������������������ɵĸ�����
pop_back					ɾ�����������һ��Ԫ��
push_back(x)				��x ����ĩβ
rbegin						����һ�������������ָ������ĩβԪ��֮��
rend						����һ�������������ָ��Ԫ����ʼԪ��
reverse						�ߵ�Ԫ�ص�˳��
resize(n,x)					�������������Ĵ�Сn����Ԫ�صĳ�ʼֵΪx
size						���������Ĵ�С��Ԫ�صĸ�����
swap(vector)				������������������ 
*/
/*���ʷ��� 
1 �±���� ������ͨ����һ�� v1[i]
2 ���������� ����ָ��
3 ����ָ�� ��ֻ�ܱ���������  auto �ܹ��Զ�ʶ�𲢻�ȡ����
vector<int> v;
for(auto val:v)
	cout<<val<<" ";
*/
 
