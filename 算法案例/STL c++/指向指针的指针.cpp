#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a[10],*p1,**p2,n=0;
	printf("please input（只读取10个）:\n");
	for(p1=a;p1-a<10;p1++)
	{
		//cout<<p1-a<<":";
		printf("第%d个输入数据:",p1-a);
		p2=&p1;
		scanf("%d",*p2);
		cout<<endl;
	}
	printf("the array is:");
	for(p1=a;p1-a<10;p1++)
	{
		p2=&p1;
		if(**p2%2==0)
		{
			printf("%5d",**p2);
			n++;
		}
	}
	cout<<endl;
	return 0;
}
