#include<bits/stdc++.h>
using namespace std;
string sub2(string a,string b){
	string res;
	int n=a.size(),m=b.size(),i,by=1;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(i=0;i<m;++i){
		int t=a[i]-b[i]+9+by;		//�����by=1ʱû�б���λ����û�н�λ��10Ϊ�� 
		res+=t%10+'0';					 
		by=t/10;					//������ʱС��10 
	}
	for(;i<n;++i){
		int t=a[i]-'0'+9+by;
		res+=t%10+'0';
		by=t/10;
	}
	while(res[--i]=='0'&&i>0);
	res=res.substr(0,i+1);				//����res��0��ʼ��i+1���ַ�
	reverse(res.begin(),res.end());
	return res; 
}
int main(){
	string s1,s2,res,ans;
	cin>>s1>>s2;
	bool h=false;
	int n=s1.size(),m=s2.size(),t;
	int f=n-1;
	while(s1[f]=='0')f--;				//�Ҵӵ�λ��ʼ��Ϊ0��λ�� 
	for(int i=0;i<n;i++){
		ans+=s1[i];
		t=0;
		while(ans.size()>m||ans.size()==m&&ans>=s2){
			ans=sub2(ans,s2);			//����ģ����� 
			t++;
		}
		if(t||h){						//�ȴ��̵���λ 
			h=true;
			res+=t+'0';
		}
		if(ans.empty()&&i>=f){			//������ʱ�����Ϻ�׺0 
			while(++i<n)res+='0';
		}
	}
	if(res.empty())res+='0';	 
	if(ans.empty())ans+='0';
	cout<<res<<endl<<ans;
	return 0;
}
