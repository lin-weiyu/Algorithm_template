#include<bits/stdc++.h>

using namespace std;

void _strcat(char str1[],char str2[])
{
	int i,j;
	for(i=0;str1[i]!='\0';i++);
		for(j=0;str2[j]!='\0';j++)
		{
			str1[i+j]=str2[j];
		}
	str1[i+j]='\0';
}

int main()
{
	char str1[100],str2[100];
	printf("请输入字符串 1：\n");
	gets(str1);
	printf("请输入字符串 2：\n");
	gets(str2);
	_strcat(str1,str2);
	printf("连接之后的字符串是：%s\n",str1);
	return 0;
}
