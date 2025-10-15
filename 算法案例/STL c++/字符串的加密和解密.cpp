#include<bits/stdc++.h>

using namespace std;
//加密可用位运算进行加密 
int main()
{
	int result = 1;
	int i;
	int count = 0; 
	char Text[128]={'\0'};
	char cryptograph[128]={'\0'};
	while(1)
	{
		if(result==1)
		{
			printf("请输入要加密的明文：\n");
			scanf("%s",&Text);
			count = strlen(Text);						//统计字符串的长度，包括末尾的\0 
			for(i=0;i<count;i++)
			{
				cryptograph[i]=Text[i]+i+5;
			}
			cryptograph[i]='\0';
			printf("加密后的密文是：%s\n",cryptograph);
		}
		else if(result==2)
		{
			count =strlen(Text);
			for(i=0;i<count;i++)
			{
				Text[i]=cryptograph[i]-i-5;
			}
			Text[i]='\0';
			printf("解密后的明文是：%s\n",Text);
		}
		else if(result==3)
		{
			break;
		}
		else
		{
			printf("请输入命令符：\n");
		 } 
		printf("输入1加密新的明文，输入2对刚加密的密文进行解密，输入3退出系统：\n");
		printf("请输入命令符：\n");
		scanf("%d",&result); 
	}
	return 0;
}
