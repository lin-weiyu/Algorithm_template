#include<stdio.h>
#include<string.h>//memset函数的头文件

//设定一个宏，定义数组大小
#define maxn 20010

int vis[maxn];//vis用来判断数字是否访问过
int prime[maxn];//prime用来存储筛选出来的素数


int sieve(int n)
{
    int i,j,k;
    k=0;//i用来控制逐个访问，j用来第二轮标记，k用来标记prime数组位置
    //这里在函数中置为0，保证每一次函数调用时都清空，不会受到上次使用完后的结果
    //理论上需要这样做，但是在此程序中可以省略，因为数字范围彼此之间是子集的关系，而范围的改变不会改变数字的性质
    memset(vis,0,sizeof(int)*maxn);//将访问数组清零。可以使用short或者C++的bool类型节省内存、
    vis[0]=vis[1]=1;//将0和1标记为已访问，不标记其实也可以，因为我们素数的计数是从2开始
    for(i=2;i<=n;i++)//从最小的素数2开始筛选，2以下就没必要筛选
    {
        if(vis[i]==0)//这个数是目前最小的，且未被访问过的
            prime[k++]=i;//因此这个数是素数
        for(j=2;i*j<=n;j++)//j表示倍数，从两倍开始倍增，直到上界为止
            vis[i*j]=1;//将倍数标记为已访问
    }
    return k;//返回范围内素数的个数
}

void print(int k)//打印结果函数
{
    int i;
    for(i=0;i<k;i++)
    {
        printf("%5d ",prime[i]);//每个数字占5个宽度，右对齐，保持输出结果整洁
        if((i+1)%5==0)//每五个为一组换行
            printf("\n");
    }
    printf("\n\n");
}

int main()
{
    int n;//求n以内的素数
    int k;//保存返回的素数个数
    while(scanf("%d",&n)!=EOF)
    {
        k=sieve(n);
        if(k==0)
            printf("(1-%d]范围内没有素数\n",n);
        else
            printf("(1-%d]范围内的素数有:\n",n);
        print(k);
    }
}


