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
	set<char>::iterator it ;	//���ʷ���1�������� 
	for(it=cSet.begin();it!=cSet.end();it++)
		cout<<*it<<endl;
	char cTmp;
	cTmp='D';
	it=cSet.find(cTmp);			//����Ԫ�أ��ҵ����ظ�Ԫ�صĵ����������򷵻ؽ���������
	cout<<"start find:"<<cTmp<<endl;
	if (it==cSet.end()) cout<<"not found"<<endl;
	else cout<<"found"<<endl;
	cTmp='C';
	it=cSet.find(cTmp);
	cout<<"start find:"<<cTmp<<endl;
	if(it==cSet.end()) cout<<"not found"<<endl;
	else cout<<"found"<<endl;
	cout<<"���ʼ��ϣ�"<<endl;
	//for(auto i;i:cSet)			//���ʷ���2������ָ�루ֻ�ܴ�ͷ��β����auto ��c++11�����ã��Զ���Ӧ���� 
	//	cout<<i<<endl;
	cout<<"�������һ��Ԫ�أ�"<<endl;
	cout<<"��һ�֣�"<<*cSet.rbegin()<<endl;
	cout<<"�ڶ��֣�";
	set<char>::iterator iter=cSet.end();
	iter--;						//��Ϊendָ�����һ��Ԫ�صĺ�һ����ַ 
	cout<<(*iter)<<endl; 
	cout<<"�����֣�"<<*(--cSet.end())<<endl;
	return 0;
}
/*
�ı��������Ĭ��Ϊless�Ƚ��������Ӵ�С�������ã�
set<int> s1;		Ĭ�ϴ�С����
set<int,greater<int>> s2;		�Ӵ�С 
*/
/*
�߼��������ͣ��ṹ�壩
*/ 
