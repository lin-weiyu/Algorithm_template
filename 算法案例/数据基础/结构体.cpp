#include<bits/stdc++.h>

using namespace std;

//����Ϊ�ṹ��Ķ��巽ʽ

struct Product1				//�������� 
{
	char cName[10];
	char cShspe[20];
	char cColor[10];
	int iPrice;
 } ;
 struct Product1 product1;
 struct Product1 product2;
 
 
struct Product2 			//������ͬʱ���� 
{
	char cName[10];
	char cShspe[20];
	char cColor[10];
	int iPrice;
 } product3,product4;
 
struct 						//ֱ�Ӷ���ṹ���� 
{
	char cName[10];
	char cShspe[20];
	char cColor[10];
	int iPrice;
}productb,producta;

//�ṹ��ĳ�Ա�Կ����ǽṹ��        ��������ʱӦ  student1.birthday,year,����Ӧstudent1.birthday,��Ϊ�䱾��Ҳ�ǽṹ�� 

struct date
{
	int year;
	int month;
	int day;
};

struct student
{
	int num;
	char name[30];
	char sex;
	int age;
	struct date birthday;
}student1;

int main()
{
	return 0;
 } 
