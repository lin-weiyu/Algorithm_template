#include<bits/stdc++.h>

using namespace std;

int a[1000][2];

int tianjia(int head,int c,int d,int t);

int main()
{
	int head,p,h,c,d,t=3,b;
	cout<<"Ҫ���������ڵ㣿"<<endl;
	cin>>t;
	b=0;
	while(b<t)
	{
		printf("��%d�Ľڵ��ֵ�ǣ�",b+1);
		cin>>a[b][0];
		a[b][1]=b+1;
		b++;
	}
	a[t-1][1]=-1;
	head=0;
	p=head;
	while(p!=-1)
	{
		cout<<a[p][0]<<"->";
		p=a[p][1];
	}
	cout<<endl;
	cout<<"�����������1,�������������0"<<endl;
	cin>>h;
	while(1) 
	{
		if(h==1)
		{
			printf("���ĸ�Ԫ�غ���룿\n");
			cin>>c;
			printf("������٣�\n");
			cin>>d;
			a[t][0]=d;
			tianjia(head,c,d,t);
			t+=1;
		}
		else if(h==0)
		{
			break;
		}
		else
		{
			cout<<"����ȷ���룡"�� 
		}
		cout<<"���ٴ����������1,�������������0"<<endl;
		cin>>h;
	}
	cout<<"����Ϊ������ʾ��"<<endl; 
	cout<<"[";
	for(h=0;h<t;h++)
	{
		cout<<"["<<a[h][0]<<","<<a[h][1]<<"]"<<","<<endl;
	}
	cout<<"]";
	return 0;
}

int tianjia(int head,int c,int d,int t)
{
	int p,b;
	p=head;
	while(p!=-1)
	{
		cout<<a[p][0]<<"->";
		if(a[p][0]==c)
		{
			a[t][1]=a[p][1];
			a[p][1]=t;
		}
		b=a[p][1];
		p=b;
	}
	return 0;
}

