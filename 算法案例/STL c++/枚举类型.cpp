#include<bits/stdc++.h>

using namespace std;

int main()
{	//ö���������ڶ����ݵ����ƺͱ������ݳ�ʼ�������Դ�������Ϸ״̬��ѡ���б�ȣ�������ά�� ��� 
	enum Weekday {Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturay
	};							//��һ����ԱĬ��Ϊ0������û�ж���ĳ�Ա��ǰ���Ա��1 
	int a=2,b=1;
	enum Weekday day;			//��c++��ǰ���enum��ʡ�� 
	day=(Weekday)a;				//����ֱ������������ö�ٱ�������������ǿ��ת��
	//day=(Weekday)2�ȼ���day=Tuesday
	cout<<day<<endl;
	day=(Weekday)(a-b);
	cout<<day<<endl; 
	day=(Weekday)(Sunday+Wednesday);
	cout<<day<<endl;
	day=(Weekday)5;
	cout<<day<<endl;
	scanf("%u",&day);
	switch(day){
		case Sunday:
			printf("��������");
			break;
	}
	return 0; 
}
