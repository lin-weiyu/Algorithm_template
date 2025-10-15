#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b,e;
	int q,x,c,d;
	cin>>q; 
	cin>>a;				//用scanf不会进行输入 
	while((q--)>0){
		cin>>x;
		switch(x){
			case 1:				//在文档后插入字符串str，并输出 
				cin>>b;
				a=a+b;
				cout<<a<<endl;
				break;
			case 2:				//截取从第a个字符起的b个字符 
				cin>>c>>d;
				a=a.substr(c,d);
				cout<<a<<endl;
				break;
			case 3:				//在第a个字符前插入字符串str 
			 	cin>>c>>e;
			 	a.insert(c,e);
			 	cout<<a<<endl;
			 	break;
			case 4:				//找到str在文档中最先的位置，没有则-1 
				cin>>b;
				d=a.find(b);
				cout<<d<<endl;
				break;
		}
	}
	return 0;
}
