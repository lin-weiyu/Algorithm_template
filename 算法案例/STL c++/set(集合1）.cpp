#include<bits/stdc++.h>
using namespace std;
int main(){
	set<int> iSet;
	iSet.insert(1);
	iSet.insert(3);
	iSet.insert(5);
	iSet.insert(7);
	iSet.insert(9);
	cout<<"set:"<<endl;
	set<int>::iterator it;
	for(it=iSet.begin();it!=iSet.end();it++){
		cout<<*it<<endl;
	} 
	return 0;
}
