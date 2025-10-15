#include<bits/stdc++.h>

using namespace std;

struct Student 
{
	char cName[20];
	int iNumber;
	struct Student *pNext;
};

int iCount;									//定义全局变量，表示链表长度 
struct Student *Create()					//创造链表 
{
	struct Student *pHead=NULL;
	struct Student *pEnd,*pNew;
	iCount=0;
	pEnd=pNew=(struct Student*)malloc(sizeof(struct Student));		//动态分配内存空间存放新节点 
	printf("please first enter Name ,then Number\n");
	scanf("%s",&pNew->cName );
	scanf("%d",&pNew->iNumber );
	while(pNew->iNumber !=0)
	{
		iCount++;
		if(iCount==1)
		{
			pNew->pNext =pHead;				//新节点指向NULL 
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
	free(pNew);								//释放未用到的内存空间 
	return pHead;							//返回链表的头指针 
}

void Print(struct Student *pHead)
{
	struct Student *pTemp;
	int iIndex=1;
	printf("---the List has %d member:---\n",iCount);
	printf("\n");
	pTemp=pHead;
	while(pTemp!=NULL)
	{
		printf("the NO%d member is:\n",iIndex);
		printf("the name is:%s\n",pTemp->cName );
		printf("the number is:%d\n",pTemp->iNumber );
		printf("\n");
		pTemp=pTemp->pNext ;
		iIndex++;
	}
 } 
 
 int main()
 {
 	struct Student *pHead;
 	pHead=Create();
 	return 0;
 	Print(pHead);
 }
