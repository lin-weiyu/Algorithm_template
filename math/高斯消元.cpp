#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 110;
const double eps = 1e-8;
LL n;
vector<vector<double>> a(N , vector<double>(N));
LL gauss(){
    LL c, r;
    for (c = 0, r = 0; c < n; c++){
        LL t = r;
        for (int i = r; i < n; i++){
            if (fabs(a[i][c]) > fabs(a[t][c])){
                t = i;
            }
        }
        if (fabs(a[t][c]) < eps) continue;
        for (int j = c; j < n + 1; j++){
            swap(a[t][j], a[r][j]);
        }
        for (int j = n; j >= c; j--) a[r][j] /= a[r][c];
        for (int i = r + 1; i < n; i++){
            if (fabs(a[i][c]) > eps){
                for (int j = n; j >= c; j--){
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }
        r++;
    }
    if (r < n){
        for (int i = r; i < n; i++){
            if (fabs(a[i][n]) > eps) return 2;
        }
        return 1;
    }
    for (int i = n - 1; i >= 0; i--){
        for (int j = i + 1; j < n; j++){
            a[i][n] -= a[i][j] * a[j][n];
        }
    }
    return 0;   
}
/* 最后第n列存储等式结果， 前0 - (n - 1) 列为未知量系数
a11 * x1 + a12 * x2 + ... + a1n * xn = k1
a21 * x1 + ... = k2
*/
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n + 1; j++){
            cin >> a[i][j];
        }
    }
    LL t = gauss();
    if (t == 0){
        for (int i = 0; i < n; i++){
            if (fabs(a[i][n]) < eps) a[i][n] = abs(a[i][n]);
            cout << a[i][n] << endl; 
        }
    }
    else if (t == 1) cout << "多个解" << endl;
    else cout << "无解" << endl;
}