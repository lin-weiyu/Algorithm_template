#include<bits/stdc++.h>

using namespace std;

int main()
{
	int *p,a[3][3],i,j,(*q)[3];
	p=a[0];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",p++);
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<a[i][j];
		}
	}
	p=a[0];
	q=&a[0];
	cout<<*(*(a+1)+2)<<endl;			//���Զ����������*(*(a+i)+j)
	cout<<*p+5+1<<endl;					//��ָ��ֻ��Ϊ*(p+i)+j==*p+i+j
	cout<<*(*(q+1)+2);		//����ָ��ɸ��ݱ����ָ���������ͽ���(�÷�Ϊ�����÷��� 
	return 0;
}

