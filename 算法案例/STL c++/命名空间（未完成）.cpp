#include<bits/stdc++.h>
//�������ռ�������һ��Ӧ�ó����ж���ļ���ͬ��ȫ�ֱ��������Ӵ��� 
using namespace std;			//cout��namespace std��  namespace�������ռ���Թ涨������ 
namespace MyName1{
	int iInt1=10;
	int iInt2=20;
} ;								//�ֺſ��п��� 
namespace MyName2{				//��������ռ�û�б�������������Ϊȫ�ֱ��� 
	int iInt1=80;
	int iInt2=90;
};
namespace MyName3{
	int iInt3=48;
	int iInt4=89;
	namespace MyName4{
		void Demo(){			//����һ���ļ�����������������һ���ļ���ʹ�������ռ䶨�庯�� 
			cout<<"���������ռ�ĺ��� iInt1=12345"<<endl;
		} 
	}
}
int iInt1=50;					//ȫ�ֱ��� 
int main()
{
	std::cout<<"he\n"; 			//�������д��벻����ʱ�����������е���
	cout<<MyName1::iInt1<<endl; //�ж����ͬ�ı�ʶ��ʱ�����ʹ���������޶��� 
	cout<<MyName2::iInt1<<endl;
	cout<<iInt1<<endl; 
	MyName3::MyName4::Demo();	//Ƕ�������ռ���� 
	return 0;
 } 
