#include<bits/stdc++.h>
using namespace std;
const int N=100;
struct Node{			//Ҳ��������ģ�� 
	char v;
	int ls,rs;
}t[N];
void print_tree(int u){
	if(u){
		cout<<t[u].v <<" ";
		print_tree(t[u].ls );
		print_tree(t[u].rs );
	}
}
int main(){
	t[5].v='A'; t[5].ls=7; t[5].rs=3;
    t[7].v='B'; t[7].ls=2; t[7].rs=0;
    t[3].v='C'; t[3].ls=9; t[3].rs=6;
    t[2].v='D';    // t[2].ls=0; t[2].rs=0; ���Բ�д����Ϊt[]��ȫ�ֱ������ѳ�ʼ��Ϊ0
    t[9].v='E';    // t[9].ls=0; t[9].rs=0; ���Բ�д
    t[6].v='F';    // t[6].ls=0; t[6].rs=0; ���Բ�д
    int root = 5;  //����tree[5]
    print_tree(5); //����� A B D C E F
    return 0;
}
