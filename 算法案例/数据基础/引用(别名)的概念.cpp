#include<bits/stdc++.h>

using namespace std;

void lizi()
{
	int a=10;
	int &ia=a;
	cout<<"a="<<a<<endl;
	cout<<"��ia��Ϊ2"<<endl; 
	ia=2;
	printf("ia=%d a=%d",ia,a);
}

void swap(int &a,int &b)			//�������ô��� 
{
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}

int main()
{
	int x,y;
	cout<<"������x"<<endl;
	cin>>x;
	cout<<"������y"<<endl;
	cin>>y;
	cout<<"����x��y��ֵ"<<endl;
	swap(x,y);
	cout<<"x="<<x<<endl;
	cout<<"y="<<y<<endl;
	lizi();
	return 0;
}
