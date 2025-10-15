#include<bits/stdc++.h>

using namespace std;

struct Student
{
	char cName[20];
	int iNumber;
	struct Student *pNext; 
};

int iCount;

struct Student *Create()
{
	struct Student *pHead=NULL;
	struct Student *pEnd,*pNew;
	iCount=0;
	pEnd=pNew=(struct Student*)malloc(sizeof(struct Student));
	printf("请输入名字，学号：\n");
	scanf("%s",&pNew->cName );
	scanf("%d",&pNew->iNumber );
	while(pNew->iNumber !=0)
	{
		iCount++;
		if(iCount==1)						//是第一个节点 
		{
			pNew->pNext =pHead;		//新节点指向NULL 
			pEnd=pNew;
			pHead=pNew;
		}
		else
		{
			pNew->pNext =NULL;
			pEnd->pNext =pNew;
			pEnd=pNew;
		}
		pNew=(struct Student*)malloc(sizeof(struct Student));
		scanf("%s",&pNew->cName );
		scanf("%d",&pNew->iNumber );
	}
	free(pNew);
	return pHead;
 } 
 
 
 
 void Print(struct Student *pHead)
 {
 	struct Student *pTemp;
 	int iIndex=1;
 	printf("---有%d个成员：---\n",iCount);
 	printf("\n");
 	pTemp=pHead;
 	while(pTemp!=NULL)
 	{
 		printf("NO%d 成员:\n",iIndex);
 		printf("姓名:%s\n",pTemp->cName );
 		printf("学号:%s\n",pTemp->iNumber );
 		printf("\n");
 		pTemp=pTemp->pNext;
 		iIndex++;
	 }
 }
 
 int main()
 {
 	struct Student *pHead;
 	pHead=Create();
	Print(pHead) ;
	return 0;
 }
