#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int ,char>cMap;				//������ɱȽϣ���ֵ���Զ��������� 
	cMap.insert(map<int,char>::value_type(1,'B'));
	cMap[2]='C';					//Ҳ�ɲ�ȡ������� 
	//cMap[2]+=1;					//��������ʱ���Զ������µĲ���ֵ 
	cMap.insert(map<int,char>::value_type(4,'D')) ;
	cMap[5]='G';
	cMap[3]='F';
	cout<<"map"<<endl;
	map<int,char>::iterator it;
	for(it=cMap.begin();it!=cMap.end();it++){
		cout<<(*it).first<<"->";	//�˴���������ţ����ȼ����� 
		cout<<it->second<<endl;		//->��*�����ö���ȡֵ 
	} 
	return 0;
}
