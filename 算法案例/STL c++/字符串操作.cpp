#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b,e;
	int q,x,c,d;
	cin>>q; 
	cin>>a;				//��scanf����������� 
	while((q--)>0){
		cin>>x;
		switch(x){
			case 1:				//���ĵ�������ַ���str������� 
				cin>>b;
				a=a+b;
				cout<<a<<endl;
				break;
			case 2:				//��ȡ�ӵ�a���ַ����b���ַ� 
				cin>>c>>d;
				a=a.substr(c,d);
				cout<<a<<endl;
				break;
			case 3:				//�ڵ�a���ַ�ǰ�����ַ���str 
			 	cin>>c>>e;
			 	a.insert(c,e);
			 	cout<<a<<endl;
			 	break;
			case 4:				//�ҵ�str���ĵ������ȵ�λ�ã�û����-1 
				cin>>b;
				d=a.find(b);
				cout<<d<<endl;
				break;
		}
	}
	return 0;
}
