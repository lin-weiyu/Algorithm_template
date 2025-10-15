#include<bits/stdc++.h>

using namespace std;

//下列为结构体的定义方式

struct Product1				//声明后定义 
{
	char cName[10];
	char cShspe[20];
	char cColor[10];
	int iPrice;
 } ;
 struct Product1 product1;
 struct Product1 product2;
 
 
struct Product2 			//声明的同时定义 
{
	char cName[10];
	char cShspe[20];
	char cColor[10];
	int iPrice;
 } product3,product4;
 
struct 						//直接定义结构类型 
{
	char cName[10];
	char cShspe[20];
	char cColor[10];
	int iPrice;
}productb,producta;

//结构体的成员仍可以是结构体        调用日期时应  student1.birthday,year,而不应student1.birthday,因为其本身也是结构体 

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
