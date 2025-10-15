#include<bits/stdc++.h>
using namespace std;
//c++采用名字重组技术，通过函数名和参数类型来识别函数
//编译器根据参数的类型和个数区分调用相同函数名的函数，但不能用返回值区分 
//还存在内联函数，在优化程序时使用 
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
