#include<bits/stdc++.h>

using namespace std;

int main()
{
	int *p,*q,a[5],b[5],i;
	p=&a[0];				//将数组a的首地址给指针p 
	q=b;					//将数组b的首地址给指针q 
	printf("please input a:");
	for(i=0;i<5;i++)
	 	//scanf("%d",&a[i]);
	 	scanf("%d",p+i);			//&a[i]==p+i 
	printf("please input b:");
	for(i=0;i<5;i++)
		scanf("%d",&b[i]);
	printf("a is:");
	for(i=0;i<5;i++)
		printf("%d",*(p+i));
	printf("\n");
	for(i=0;i<5;i++)
		printf("%d",*p++);			//先*再++； 
	printf("\n");
	printf("b is:");
	for(i=0;i<5;i++)
		printf("%d",*(q+i));
	printf("\n");
	for(i=0;i<5;i++)
		printf("%d",*(b+i));		//数组名就是指针 
	return 0;
}
