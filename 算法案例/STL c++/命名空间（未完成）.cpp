#include<bits/stdc++.h>
//用命名空间来消除一个应用程序中多个文件中同名全局变量的链接错误 
using namespace std;			//cout在namespace std中  namespace是命名空间可以规定作用域 
namespace MyName1{
	int iInt1=10;
	int iInt2=20;
} ;								//分号可有可无 
namespace MyName2{				//如果命名空间没有被命名，则其中为全局变量 
	int iInt1=80;
	int iInt2=90;
};
namespace MyName3{
	int iInt3=48;
	int iInt4=89;
	namespace MyName4{
		void Demo(){			//可在一个文件中声明函数，再另一个文件中使用命名空间定义函数 
			cout<<"调用命名空间的函数 iInt1=12345"<<endl;
		} 
	}
}
int iInt1=50;					//全局变量 
int main()
{
	std::cout<<"he\n"; 			//当第三行代码不存在时可以这样进行调用
	cout<<MyName1::iInt1<<endl; //有多个相同的标识符时，最好使用作用域限定符 
	cout<<MyName2::iInt1<<endl;
	cout<<iInt1<<endl; 
	MyName3::MyName4::Demo();	//嵌套命名空间调用 
	return 0;
 } 
