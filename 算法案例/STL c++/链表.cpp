#include<bits/stdc++.h>

using namespace std;

int a[1000][2];

int tianjia(int head,int c,int d,int t);

int main()
{
	int head,p,h,c,d,t=3,b;
	cout<<"要创建几个节点？"<<endl;
	cin>>t;
	b=0;
	while(b<t)
	{
		printf("第%d的节点的值是：",b+1);
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
	cout<<"想添加则输入1,结束添加则输入0"<<endl;
	cin>>h;
	while(1) 
	{
		if(h==1)
		{
			printf("在哪个元素后插入？\n");
			cin>>c;
			printf("插入多少？\n");
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
			cout<<"请正确输入！"； 
		}
		cout<<"想再次添加则输入1,结束添加则输入0"<<endl;
		cin>>h;
	}
	cout<<"数组为下列所示："<<endl; 
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

