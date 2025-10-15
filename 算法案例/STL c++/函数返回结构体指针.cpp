#include<bits/stdc++.h>

using namespace std;

struct Student 
{
	char cName[20];
	int num;
	int fScore[3];
};

struct Student *search(struct Student *stud,int *n)
{
	char name[20];
	struct Student *student;
	cout<<"输入学生姓名："<<endl;
	cin>>name;
	for(student=stud;student<stud+6;student++)
	{
		if(strcmp(student->cName,name)==0)
		{
			*n=1;
			break;
		}
	}
	return student;
}

void print(struct Student *stu)
{
	printf("%-11s%3d%8d%8d%8d\n",stu->cName ,stu->num ,stu->fScore[0],stu->fScore[1],stu->fScore[2]);
}

int main()
{
	int n=0;
	struct Student *result;
	struct Student stu[6]={{"liu",1001,79,87,80
	},{"zhang",1003,80,84,86},{"wu",1004,89,87,98},{"wei",1005,74,84,91},{"lin",1006,70,64,50}
	};
	result=search(stu,&n);
	if(n>0)
		print(result);
	else
		printf("not found");
}
