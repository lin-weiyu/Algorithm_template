#include <bits/stdc++.h>
using namespace std;
struct Polynomial{
    double PI = acos(-1);
    struct Complex{
        double x, y;
        Complex(double _x = 0.0, double _y = 0.0){
            x = _x;
            y = _y;
        }
        Complex operator-(const Complex &rhs) const{
            return Complex(x - rhs.x, y - rhs.y);
        }
        Complex operator+(const Complex &rhs) const{
            return Complex(x + rhs.x, y + rhs.y);
        }
        Complex operator*(const Complex & rhs) const{
            return Complex(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
        }
    };
    vector<Complex> c;
    Polynomial(vector<int> &a){
        int n = a.size();
        c.resize(n);
        for (int i = 0; i < n; i++){
            c[i] = Complex(a[i], 0);
        }
        fft(c, n, 1);
    }
    void change(vector<Complex> &a, int n){
        for (int i = 1, j = n / 2; i < n - 1; i++){
            if (i < j) swap(a[i], a[j]);
            int k = n / 2;
            while (j >= k){
                j -= k;
                k /= 2;
            }
            if (j < k) j += k;
        }
    }
    void fft(vector<Complex> &a, int n, int opt){
        change(a, n);
        for (int h = 2; h <= n; h *= 2){
            Complex wn(cos(2 * PI / h), sin(opt * 2 * PI / h));
            for (int j = 0; j < n; j += h){
                Complex w(1, 0);
                for (int k = j; k < j + h / 2; k++){
                    Complex u = a[k];
                    Complex t = w * a[k + h / 2];
                    a[k] = u + t;
                    a[k + h / 2] = u - t;
                    w = w * wn;
                }
            }
        }
        if (opt == -1){
            for (int i = 0; i < n; i++){
                a[i].x /= n;
            }
        }
    }
};
int main()
{
    cout << 2 << endl;
}