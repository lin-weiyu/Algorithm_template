#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[25],dir[30][30];
int topo[25],vis[30],indegree[30];
void dfs(int z,int cnt){
	int i;
	topo[cnt]=z;
	if(cnt==n-1){
		for(i=0;i<n;i++)printf("%c",topo[i]+'a');
		printf("\n");
		return;
	}
	vis[z]=1;
	for(i=0;i<n;i++){
		if(!vis[a[i]]&&dir[z][a[i]]){
			indegree[a[i]]--;
		}
	}
	for(i=0;i<n;i++){
		if(!indegree[a[i]]&&!vis[a[i]]){
			dfs(a[i],cnt+1);
		}
	}
	for(i=0;i<n;i++){
		if(!vis[a[i]]&&dir[z][a[i]]){
			indegree[a[i]]--;
		}
	}
	vis[z]=0;
}
int main(){
	char s[100];
	int len;
	while(gets(s)!=NULL){
		memset(dir,0,sizeof(dir));
		memset(vis,0,sizeof(vis));
		memset(indegree,0,sizeof(indegree));
		len=strlen(s);
		n=0;
		for(int i=0;i<len;i++)
			if(s[i]<='z'&&s[i]>='a'){
				a[n++]=s[i]-'a';
			}
		sort(a,a+n);
		gets(s);
		len=strlen(s);
		int first=1;
		for(int i=0;i<len;i++){
			int st,ed;
			if(first&&s[i]<='z'&&s[i]>='a'){
				first =0;
				st=s[i]-'a';
				continue;
			}
			if(!first&&s[i]<='z'&&s[i]>='a'){
				first=1;
				ed=s[i]='a';
				dir[st][ed]=1;
				indegree[ed]++;
				continue;
			}
		}	
		for(int i=0;i<n;i++){
			if(!indegree[a[i]])
				dfs(a[i],0);
		}
		printf("\n");
	}
	return 0;
}
