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
	printf("���������֣�ѧ�ţ�\n");
	scanf("%s",&pNew->cName );
	scanf("%d",&pNew->iNumber );
	while(pNew->iNumber !=0)
	{
		iCount++;
		if(iCount==1)						//�ǵ�һ���ڵ� 
		{
			pNew->pNext =pHead;		//�½ڵ�ָ��NULL 
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
 	printf("---��%d����Ա��---\n",iCount);
 	printf("\n");
 	pTemp=pHead;
 	while(pTemp!=NULL)
 	{
 		printf("NO%d ��Ա:\n",iIndex);
 		printf("����:%s\n",pTemp->cName );
 		printf("ѧ��:%s\n",pTemp->iNumber );
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
