#include<bits/stdc++.h>

using namespace std;

int main()
{
	int *p,*q,a[5],b[5],i;
	p=&a[0];				//������a���׵�ַ��ָ��p 
	q=b;					//������b���׵�ַ��ָ��q 
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
		printf("%d",*p++);			//��*��++�� 
	printf("\n");
	printf("b is:");
	for(i=0;i<5;i++)
		printf("%d",*(q+i));
	printf("\n");
	for(i=0;i<5;i++)
		printf("%d",*(b+i));		//����������ָ�� 
	return 0;
}
