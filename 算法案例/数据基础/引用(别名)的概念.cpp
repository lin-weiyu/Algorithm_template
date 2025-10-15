#include<bits/stdc++.h>

using namespace std;

void lizi()
{
	int a=10;
	int &ia=a;
	cout<<"a="<<a<<endl;
	cout<<"把ia改为2"<<endl; 
	ia=2;
	printf("ia=%d a=%d",ia,a);
}

void swap(int &a,int &b)			//采用引用传递 
{
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}

int main()
{
	int x,y;
	cout<<"请输入x"<<endl;
	cin>>x;
	cout<<"请输入y"<<endl;
	cin>>y;
	cout<<"交换x和y的值"<<endl;
	swap(x,y);
	cout<<"x="<<x<<endl;
	cout<<"y="<<y<<endl;
	lizi();
	return 0;
}
