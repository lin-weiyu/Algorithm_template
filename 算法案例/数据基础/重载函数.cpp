#include<bits/stdc++.h>
using namespace std;
//c++�����������鼼����ͨ���������Ͳ���������ʶ����
//���������ݲ��������ͺ͸������ֵ�����ͬ�������ĺ������������÷���ֵ���� 
//�������������������Ż�����ʱʹ�� 
int ADD(int x,int y){
	cout<<"int add"<<endl;
	return x+y;
}
double ADD(double x,double y){
	cout<<"double add"<<endl;
	return x+y;
}
int main(){
	int ivar=ADD(5,2);
	float fvar=ADD(10.5,11.4);
	return 0;
}
