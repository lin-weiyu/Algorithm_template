#include<bits/stdc++.h>
using namespace std;

class cPerson{ }; 						//空类的声明方法 

class CPerson{
public:
	//数据成员			需要初始化，但不能在类的声明中初始化   因为类为数据结构，不是具体对象 
	//类的对象可以作为另一个类的成员，但是自身类的对象不可以作为该类的成员
	//但自身类的指针或者引用可以作为该类的成员 
	int m_iIndex;
	char m_cName[25];	
	short m_shAge;		//short m_shAge=22;  错误，不应该在声明时初始化 
	double m_dSalary;
	//成员函数			要添加实现代码 
	short getAge() {return m_shAge;}
	int setAge(short sAge){
		m_shAge=sAge;
		return 0;			//执行成功返回0 
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
};		//定义类和结构体的花括号后要有分号 

int CPerson::getIndex(){		//将类体内的成员函数放在类体外时要用域运算符：： 
	return m_iIndex;
}

int CPerson::setName(char cName[25]){
	strcpy(m_cName,cName);
	return 0;
} 
/*声明对象可以是 对象名，也可以是对象指针 
CPerson q;
CPerson p1,p2;		//名可以一个或多个一起声明 ，通过 q.成员 进行成员的引用 
指针方式 
CPerson *p;			//指针对象则可以通过  p->成员  或者 （*p）.成员   进行成员的引用 
*/ 

int main(){
	int iResult=-1;
	CPerson p; 
	iResult=p.setAge(25);			//类中不对数据初始化，此处通过函数对数据进行初始化
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
