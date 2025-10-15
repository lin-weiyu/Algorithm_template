#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a[3][4];
	int (*b)[4];			//定义一个数组指针，可以指向一个含有4个整型变量的数组
	int *c[4];				//定义一个指针数组，最多只能存储4个指针
	int *p;
	p=a[0];					//p这时为a中第一个一维数组中的第一个元素的地址 
	b=a;					//b为a中的第一个一维数组的地址   因指针类型不同，指向含义不同 
	cout<<"利用内存的特点，使用int指针将二维int数组初始化"<<endl;
	for(int i=0;i<12;i++)
	{
		*(p+i)=i+1;
		cout<<a[i/4][i%4]<<",";
		if((i+1)%4==0)
		{
			cout<<endl;
		}
	}
	cout<<"使用指向数组的指针，将二维数组的值改变"<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			*(*(b+i)+j)+=10;
		}
	}
	cout<<"再次使用指针数组，再次输出二维数组"<<endl; 
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			c[j]=&a[i][j];
			cout<<*(c[j])<<",";
			if((j+1)%4==0)
			{
				cout<<endl;
			}
		}
	}
	return 0;
}
