#include<bits/stdc++.h>
using namespace std;

class cPerson{ }; 						//������������� 

class CPerson{
public:
	//���ݳ�Ա			��Ҫ��ʼ��������������������г�ʼ��   ��Ϊ��Ϊ���ݽṹ�����Ǿ������ 
	//��Ķ��������Ϊ��һ����ĳ�Ա������������Ķ��󲻿�����Ϊ����ĳ�Ա
	//���������ָ��������ÿ�����Ϊ����ĳ�Ա 
	int m_iIndex;
	char m_cName[25];	
	short m_shAge;		//short m_shAge=22;  ���󣬲�Ӧ��������ʱ��ʼ�� 
	double m_dSalary;
	//��Ա����			Ҫ���ʵ�ִ��� 
	short getAge() {return m_shAge;}
	int setAge(short sAge){
		m_shAge=sAge;
		return 0;			//ִ�гɹ�����0 
	}
	int getIndex(); 
	int setIndex(int iIndex)
	{
		m_iIndex=iIndex;
		return 0;
	}
	char *getName(){
		return m_cName;
	}
	int setName(char cName[25]); 
	double getSalary(){
		return m_dSalary;
	}
	int setSalary(double dSalary){
		m_dSalary=dSalary;
		return 0;
	}
};		//������ͽṹ��Ļ����ź�Ҫ�зֺ� 

int CPerson::getIndex(){		//�������ڵĳ�Ա��������������ʱҪ������������� 
	return m_iIndex;
}

int CPerson::setName(char cName[25]){
	strcpy(m_cName,cName);
	return 0;
} 
/*������������� ��������Ҳ�����Ƕ���ָ�� 
CPerson q;
CPerson p1,p2;		//������һ������һ������ ��ͨ�� q.��Ա ���г�Ա������ 
ָ�뷽ʽ 
CPerson *p;			//ָ����������ͨ��  p->��Ա  ���� ��*p��.��Ա   ���г�Ա������ 
*/ 

int main(){
	int iResult=-1;
	CPerson p; 
	iResult=p.setAge(25);			//���в������ݳ�ʼ�����˴�ͨ�����������ݽ��г�ʼ��
	if(iResult>=0){
		cout<<"m_shAge is:"<<p.getAge() <<endl;
	} 
	iResult=p.setIndex(0);
	if(iResult>=0){
		cout<<"m_cName is:"<<p.getIndex()<<endl;
	} 
	char bufTemp[]="Mary";
	iResult=p.setName(bufTemp);
	if(iResult>=0){
		cout<<"m_cName is:"<<p.getName() <<endl;
	}
	iResult=p.setSalary(1700.25);
	if(iResult>=0){
		cout<<"m_dSalary is:"<<p.getSalary() <<endl;
	} 
	return 0;
} 
