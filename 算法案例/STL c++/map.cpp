#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int ,char>cMap;				//键必须可比较，键值对自动进行排序 
	cMap.insert(map<int,char>::value_type(1,'B'));
	cMap[2]='C';					//也可采取这种添加 
	//cMap[2]+=1;					//当不存在时会自动创建新的并赋值 
	cMap.insert(map<int,char>::value_type(4,'D')) ;
	cMap[5]='G';
	cMap[3]='F';
	cout<<"map"<<endl;
	map<int,char>::iterator it;
	for(it=cMap.begin();it!=cMap.end();it++){
		cout<<(*it).first<<"->";	//此处必须加括号，优先级问题 
		cout<<it->second<<endl;		//->和*的作用都是取值 
	} 
	return 0;
}
