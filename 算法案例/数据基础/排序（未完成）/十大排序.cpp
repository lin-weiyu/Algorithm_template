#include<bits/stdc++.h>
using namespace std;
int a[1000005],n;
void selection_sort(){			//ѡ������ 	O(n*n) 
	for(int i=0;i<n-1;i++){
		int m=i;
		for(int j=i-1;j<n;j++){
			if(a[j]<a[m])m=j;
		}
		swap(a[i],a[m]);
	}
}

void bubble_sort(){				//ð������  O(n*n)
	for(int i=0;i<n-1;i++){
		bool swapped=false;
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				swapped=true; 
			}
		} 
		if(swapped)break;//��ѭ��û�н���ʱ�Ѿ������˳� 
	}
}

void insertion_sort1(){			//��������  O(n*n)
	for(int i=1;i<n;i++){
		int key=a[i];
		int j=i-1;
		while(j>=0&&a[j]>key){	//����ʱ��ִ��whileΪO(n) 
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key; 
	} 
}

void insertion_sort2(int gap){	//ϣ������ (���ڲ�������)�����ǿ��⣩ 
	for(int i=gap;i<n;i++){//ͨ���������������gap����whileѭ������ 
		int key=a[i];//�� 3 5 6 2 8 9 4 3 (gap=4) -> 3 5 4 2 8 9 6 3 ->
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

void counting_sort(){			//�������� ������С�����յ����ݣ�
	//�磨5��10^9)����Ϊ���ݲ�������ڶ�����жϣ��һᱬ�ռ� 
	int i;		//�����ݵ�ֵ��Ϊ�±���м�¼
	//Ȼ����ݼ�¼�Ĵ���������� ����a��Ϊ{0,2,1,1},����� 1 1 2 3 
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

void Bucket_sort(){		//Ͱ���� 
	
} 
int tmp[100005];
void radix_sort(){		//��������(�����λ���ȷ�LSD ���λ���ȷ�MSD�� 
	int exp=1;			//��ΪLSD�������� ���������λ�������� 
	int max=a[0];		//�ڴ���λ����������ʱ���� 
	for(int i=1;i<n;i++)
		if(a[i]>max)max=a[i];
	while(max/exp>0){
		int bucket[10]={0};
		for(int i=0;i<n;i++) bucket[(a[i]/exp)%10]++;
		for(int i=1;i<10;i++) bucket[i]+=bucket[i-1];//��¼��ÿ��Ͱ��ĩβλ 
		for(int i=n-1;i>=0;i--){			//�ȴ���ĩβ���ݣ��Ӻ���ǰ����Ȼ����� 
			int k=(a[i]/exp)%10;
			tmp[bucket[k]-1]=a[i];
			bucket[k]--;
		}
		for(int i=0;i<n;i++)a[i]=tmp[i];
		exp*=10;
	}
}

int b[100005];
void Merge(int L,int mid,int R){	//�鲢���򣨷��η��� 
	int i=L,j=mid+1,t=0;
	while(i<=mid&&j<=R){
		if(a[i]>a[j]) b[t++]=a[j++];//�ϲ���С��С�ȣ�������
		else b[t++]=a[i++];			//����i,jΪ���ߺϲ����еĿ�ͷλ�ã����Ҳ��ϱȽ� 
	}
	//һ���������е������������ˣ���һ����û�У�ֱ�ӽ��и���
	while(i<=mid) b[t++]=a[i++];
	while(j<=R) b[t++]=a[j++];
	for(int i=0;i<t;i++) a[L+i]=b[i];	//���ź����b[]���ƹ��� 
} 
void Mergesort(int L,int R){
	if(L<R){
		int mid=(L+R)/2;		//��ƫ 
		Mergesort(L,mid);		//�ȴ�����ײ��������У��󷵻ص���һ�� 
		Mergesort(mid+1,R);		//���Ѿ�����õ����Һϲ���Ȼ�󲻶Ϸ��� 
		Merge(L,mid,R);		//�ϲ� 
	}
}

void qsort(int L,int R){		//�������� 
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
	priority_queue<int,vector<int>,greater<int>> pq;	//���ȶ��У���С����
	for(int i=0;i<n;i++){		//����ʱ�Զ��Ӵ�С�ź��� 
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
