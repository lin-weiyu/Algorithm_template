#include<bits/stdc++.h>

using namespace std;

struct Student 
{
	char cName[20];
	int iNumber;
	struct Student *pNext;
};

int iCount;									//����ȫ�ֱ�������ʾ������ 
struct Student *Create()					//�������� 
{
	struct Student *pHead=NULL;
	struct Student *pEnd,*pNew;
	iCount=0;
	pEnd=pNew=(struct Student*)malloc(sizeof(struct Student));		//��̬�����ڴ�ռ����½ڵ� 
	printf("please first enter Name ,then Number\n");
	scanf("%s",&pNew->cName );
	scanf("%d",&pNew->iNumber );
	while(pNew->iNumber !=0)
	{
		iCount++;
		if(iCount==1)
		{
			pNew->pNext =pHead;				//�½ڵ�ָ��NULL 
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
	free(pNew);								//�ͷ�δ�õ����ڴ�ռ� 
	return pHead;							//���������ͷָ�� 
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
