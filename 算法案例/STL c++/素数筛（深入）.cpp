#include<bits/stdc++.h>
using namespace std;
bool isPrime[200000];			//���趼������ 
void getPrime(int n)			//����ɸ
{
	for(int i=2;i<n;i++){		//��2��ʼɸѡ 
		if(isPrime[i]==0){
			for(int j=1;j*i<=n;j++){
				isPrime[j*i]=true;//�����������ȥ�� 
			}
		}
	}
 } 
int main(){
	return 0;
}
