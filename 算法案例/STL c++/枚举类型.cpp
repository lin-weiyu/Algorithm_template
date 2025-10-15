#include<bits/stdc++.h>

using namespace std;

int main()
{	//枚举类型用于对数据的限制和便于数据初始化，可以代表如游戏状态，选项列表等，有助于维护 理解 
	enum Weekday {Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturay
	};							//第一个成员默认为0，后续没有定义的成员是前面成员加1 
	int a=2,b=1;
	enum Weekday day;			//在c++中前面的enum能省略 
	day=(Weekday)a;				//不能直接用整数赋给枚举变量，但可以用强制转换
	//day=(Weekday)2等价于day=Tuesday
	cout<<day<<endl;
	day=(Weekday)(a-b);
	cout<<day<<endl; 
	day=(Weekday)(Sunday+Wednesday);
	cout<<day<<endl;
	day=(Weekday)5;
	cout<<day<<endl;
	scanf("%u",&day);
	switch(day){
		case Sunday:
			printf("是星期天");
			break;
	}
	return 0; 
}
