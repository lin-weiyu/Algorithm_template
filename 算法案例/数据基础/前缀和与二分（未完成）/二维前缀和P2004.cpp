#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N][N],s[N][N];
int main(){
	int n,m,c;cin>>n>>m>>c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		}
	}
	int Max=-1<<30,x,y;
	for(int x1=1;x1<=n-c+1;x1++){
		for(int y1=1;y1<=m-c+1;y1++){
			int x2=x1+c-1,y2=y1+c-1;		//右下角的坐标 
			int ans=s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];//减去左上角坐标之外的面积 
			if(ans>Max){
				Max=ans;
				x=x1,y=y1;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
