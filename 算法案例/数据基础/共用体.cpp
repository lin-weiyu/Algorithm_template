#include<bits/stdc++.h>

using namespace std;

union myUnion
{
	int iDate;
	char chDate;
	float fDate;
}uStruct;		//uStruct����������ж����������ͣ��������һ�θ�ֵ����Ϊ׼���б仯 

int main()
{
	uStruct.chDate ='A';
	uStruct.fDate =0.3;
	uStruct.iDate =100;
	cout<<uStruct.chDate <<endl;
	cout<<uStruct.fDate <<endl;
	cout<<uStruct.iDate <<" ��ȷ��"<<endl;			//�����洢����iDate����ֻ�д�������ȷ��� 
	uStruct.iDate =100;
	uStruct.fDate =0.3;
	uStruct.chDate ='A';
	cout<<uStruct.chDate <<" ��ȷ��"<<endl;		//ֻ�д�����ȷ��� 
	cout<<uStruct.fDate <<endl;
	cout<<uStruct.iDate <<endl;
	uStruct.chDate ='A';
	uStruct.iDate =100;
	uStruct.fDate =0.3;
	cout<<uStruct.chDate <<endl;				//�����л�����հף� 
	cout<<uStruct.fDate <<" ��ȷ��"<<endl;
	cout<<uStruct.iDate <<endl;
	return 0;
}
