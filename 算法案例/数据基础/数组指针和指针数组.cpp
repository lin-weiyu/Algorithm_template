#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a[3][4];
	int (*b)[4];			//����һ������ָ�룬����ָ��һ������4�����ͱ���������
	int *c[4];				//����һ��ָ�����飬���ֻ�ܴ洢4��ָ��
	int *p;
	p=a[0];					//p��ʱΪa�е�һ��һά�����еĵ�һ��Ԫ�صĵ�ַ 
	b=a;					//bΪa�еĵ�һ��һά����ĵ�ַ   ��ָ�����Ͳ�ͬ��ָ���岻ͬ 
	cout<<"�����ڴ���ص㣬ʹ��intָ�뽫��άint�����ʼ��"<<endl;
	for(int i=0;i<12;i++)
	{
		*(p+i)=i+1;
		cout<<a[i/4][i%4]<<",";
		if((i+1)%4==0)
		{
			cout<<endl;
		}
	}
	cout<<"ʹ��ָ�������ָ�룬����ά�����ֵ�ı�"<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			*(*(b+i)+j)+=10;
		}
	}
	cout<<"�ٴ�ʹ��ָ�����飬�ٴ������ά����"<<endl; 
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
