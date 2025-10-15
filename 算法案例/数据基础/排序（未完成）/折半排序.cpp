#include<bits/stdc++.h>

using namespace std;

void CelerityRun(int left,int right,int array[]);

int main()
{
	int i;
	int a[5];
	printf("为数组元素赋值：\n");
	for(i=0;i<5;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
		CelerityRun(0,4,a);
		printf("排序结果如下：\n");
		for(i=0;i<5;i++)
		{
			printf("%d\t",a[i]);
		}
		printf("\n");
		return 0;
}


void CelerityRun(int left,int right,int array[])
{
	int i,j,g=0;
	int middle,itemp;
	i=left;
	j=right;
	middle=array[(left+right)/2];
	do
	{
		while((array[i]<middle)&&(i<right))
			i++;
		while((array[i]>middle)&&(j>left))
			j--;
		if(i<=j)
		{
			itemp=array[i];
			array[i]=array[j];
			array[j]=itemp;
			i++;
			j--;
		}
	 } while(i<=j);
	for(g=0;g<5;g++)
		{
			printf("%d\t",array[g]);
		}
	printf("\n");
	if(left<j)
 	{
		 CelerityRun(left,j,array);
	}
	if(right>i)
	{
		CelerityRun(i,right,array);
	}
}
