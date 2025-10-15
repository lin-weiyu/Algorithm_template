//尖括号是在c语言函数头文件的目录下寻找文件
//双引号是在用户当前目录下寻找文件，若找不到再到c语言函数头文件下寻找 
#include<bits/stdc++.h>
using namespace std;
//宏定义好处是提升代码速度（不存在函数调用），但会增加代码行 ，宏定义必须单独成行 
//注意：宏名与带参数的括号之间不要有空格，不然会被当成替代字符串的一部分
// 宏定义不是c语句不加；号
//带参宏定义：宏字符串中的形参和整体必须加括号 
//形参不分配内存空间，所以不用声明类型 
#define MIN(a,b) ((a)*(b)+(b))
#define P printf
#define D "%d"
//条件编译是一部分内容只有再满足条件时才会进行编译，使目标程序变小，运行时间变短
#define NUM 50
int main(){
	int x=5,y=9;
	P("the min number is" D ".\n",MIN(x,y));
	int i=0;
	#if NUM>50
		i++;
	//endif用来表示#if段的结束 
	#endif				
	#if NUM==50
		i=i+50;
	#endif
	#if NUM<50
		i--;
	#endif
	P("目前的值是："D"\n",i);
	#if NUM%2==0
		P("NUM是偶数");
	#else
		P("NUM是奇数");
	//在字符串中的NUM不会被替换
	#endif 
	return 0;
}

