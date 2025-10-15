#include<bits/stdc++.h>
using namespace std;
int a[1000005],n;
void selection_sort(){			//选择排序 	O(n*n) 
	for(int i=0;i<n-1;i++){
		int m=i;
		for(int j=i-1;j<n;j++){
			if(a[j]<a[m])m=j;
		}
		swap(a[i],a[m]);
	}
}

void bubble_sort(){				//冒泡排序  O(n*n)
	for(int i=0;i<n-1;i++){
		bool swapped=false;
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				swapped=true; 
			}
		} 
		if(swapped)break;//内循环没有交换时已经有序，退出 
	}
}

void insertion_sort1(){			//插入排序  O(n*n)
	for(int i=1;i<n;i++){
		int key=a[i];
		int j=i-1;
		while(j>=0&&a[j]>key){	//有序时不执行while为O(n) 
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key; 
	} 
}

void insertion_sort2(int gap){	//希尔排序 (基于插入排序)（需加强理解） 
	for(int i=gap;i<n;i++){//通过（排序间距变量）gap减少while循环次数 
		int key=a[i];//如 3 5 6 2 8 9 4 3 (gap=4) -> 3 5 4 2 8 9 6 3 ->
		int j=i-1;	 //(gap=2) 3 2 4 3 6 5 8 9 ->(gap=1)2 3 3 4 5  6 8 9
		while(j>=gap-1&&a[j-gap+1]>key){
			a[j+1]=a[j-gap+1];
			j-=gap;
		}
		a[j+1]=key;
	}
}
void shell_sort(int n){
	for(int gap=n/2;gap>0;gap/=2)insertion_sort2(gap);
}

void counting_sort(){			//计数排序 （适用小而紧凑的数据）
	//如（5，10^9)则因为数据差过大，有众多多余判断，且会爆空间 
	int i;		//把数据的值作为下标进行记录
	//然后根据记录的次数进行输出 ，如a中为{0,2,1,1},则输出 1 1 2 3 
	int max=a[0];		
	for(i=0;i<n;i++){
		if(a[i]>max)max=a[i];
	} 
	int* cnt=(int*)calloc(max+1,sizeof(int));
	for(i=0;i<n;i++)cnt[a[i]]++;
	i=0;
	for(int j=0;j<=max;j++){
		while(cnt[j]>0){
			a[i++]=j;
			cnt[j]--;
		}
	}
	free(cnt);
}

void Bucket_sort(){		//桶排序 
	
} 
int tmp[100005];
void radix_sort(){		//基数排序(有最低位优先法LSD 最高位优先法MSD） 
	int exp=1;			//此为LSD基数排序 先依据最低位进行排序 
	int max=a[0];		//在处理位数较少数据时较优 
	for(int i=1;i<n;i++)
		if(a[i]>max)max=a[i];
	while(max/exp>0){
		int bucket[10]={0};
		for(int i=0;i<n;i++) bucket[(a[i]/exp)%10]++;
		for(int i=1;i<10;i++) bucket[i]+=bucket[i-1];//记录着每个桶的末尾位 
		for(int i=n-1;i>=0;i--){			//先处理末尾数据，从后往前，不然会出错 
			int k=(a[i]/exp)%10;
			tmp[bucket[k]-1]=a[i];
			bucket[k]--;
		}
		for(int i=0;i<n;i++)a[i]=tmp[i];
		exp*=10;
	}
}

int b[100005];
void Merge(int L,int mid,int R){	//归并排序（分治法） 
	int i=L,j=mid+1,t=0;
	while(i<=mid&&j<=R){
		if(a[i]>a[j]) b[t++]=a[j++];//合并后小与小比，大与大比
		else b[t++]=a[i++];			//所以i,j为两边合并子列的开头位置，左右不断比较 
	}
	//一个子序列中的数都处理完了，另一个还没有，直接进行复制
	while(i<=mid) b[t++]=a[i++];
	while(j<=R) b[t++]=a[j++];
	for(int i=0;i<t;i++) a[L+i]=b[i];	//把排好序的b[]复制过来 
} 
void Mergesort(int L,int R){
	if(L<R){
		int mid=(L+R)/2;		//左偏 
		Mergesort(L,mid);		//先处理最底层的左边子列，后返回到上一层 
		Mergesort(mid+1,R);		//对已经处理好的左右合并，然后不断返回 
		Merge(L,mid,R);		//合并 
	}
}

void qsort(int L,int R){		//快速排序 
	int i=L,j=R;
	int key=a[(L+R)/2];
	while(i<=j){
		while(a[i]<key)i++;
		while(a[j]>key)j++;
		if(i<=j){
			swap(a[i],a[j]);
			i++;j--;
		}
	}
	if(j>L)qsort(L,j);
	if(i<R)qsort(i,R);
} 

void heap_sor(int n){
	priority_queue<int,vector<int>,greater<int>> pq;	//优先队列，是小根堆
	for(int i=0;i<n;i++){		//放入时自动从大到小排好序 
		int a;cin>>a;
		pq.push(a);
	} 
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
} 

int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	selection_sort();
	for(int i=0;i<n;i++)cout<<a[i]<<" "; 
}
