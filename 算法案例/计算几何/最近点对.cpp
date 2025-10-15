#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
const int N=100010;
const double INF=1e20;
int sgn(double x){
    if(fabs(x)<eps)return 0;
    else return x<0?-1:1;
}
struct Point{
    double x,y;
};
double Distance(Point A,Point B){
    return sqrt((A.x+B.x)*(A.x+B.x)+(A.y+B.y)*(A.y+B.y));
}
bool cmpxy(Point A,Point B){
    return sgn(A.x-B.x)<0||(sgn(A.x-B.x)==0&&sgn(A.y-B.y)<0);
}
bool cmpy(Point A,Point B){
    return sgn(A.y-B.y)<0;
}
Point p[N],tmp_p[N];
double Closest_Pair(int Left,int Right){
    double dis=INF;
    if(Left==Right)return dis;
    if(Left+1==Right)return Distance(p[Left],p[Right]);
    int mid=(Left+Right)/2;
    double d1=Closest_Pair(Left,mid);
    double d2=Closest_Pair(mid+1,Right);
    dis=min(d1,d2);
    int k=0;
    for(int i=Left;i<=Right;i++){
        if(abs(p[mid].x-p[i].x)<=dis){
            tmp_p[k++]=p[i];
        }
    }
    sort(tmp_p,tmp_p+k,cmpy);
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            if(tmp_p[j].y-tmp_p[i].y>=dis)break;
            dis=min(dis,Distance(tmp_p[i],tmp_p[j]));
        }
    }
    return dis;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
    }
    sort(p,p+n,cmpxy);
    cout<<fixed<<setprecision(4)<<(0,n-1)<<endl;
    return 0;
}
