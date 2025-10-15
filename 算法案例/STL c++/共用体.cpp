#include<bits/stdc++.h>

using namespace std;

union myUnion
{
	int iDate;
	char chDate;
	float fDate;
}uStruct;		//uStruct共用体可以有多种数据类型，但以最后一次赋值数据为准进行变化 

int main()
{
	uStruct.chDate ='A';
	uStruct.fDate =0.3;
	uStruct.iDate =100;
	cout<<uStruct.chDate <<endl;
	cout<<uStruct.fDate <<endl;
	cout<<uStruct.iDate <<" 正确行"<<endl;			//因最后存储的是iDate所以只有此数据正确输出 
	uStruct.iDate =100;
	uStruct.fDate =0.3;
	uStruct.chDate ='A';
	cout<<uStruct.chDate <<" 正确行"<<endl;		//只有此行正确输出 
	cout<<uStruct.fDate <<endl;
	cout<<uStruct.iDate <<endl;
	uStruct.chDate ='A';
	uStruct.iDate =100;
	uStruct.fDate =0.3;
	cout<<uStruct.chDate <<endl;				//？此行会输出空白？ 
	cout<<uStruct.fDate <<" 正确行"<<endl;
	cout<<uStruct.iDate <<endl;
	return 0;
}
