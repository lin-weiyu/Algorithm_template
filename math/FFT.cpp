#include <bits/stdc++.h>
using namespace std;

class Polynomial {
private:
    static const double PI;
    struct Complex {
        double x, y;
        Complex(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}
        Complex operator+(const Complex& rhs) const { return Complex(x + rhs.x, y + rhs.y); }
        Complex operator-(const Complex& rhs) const { return Complex(x - rhs.x, y - rhs.y); }
        Complex operator*(const Complex& rhs) const {
            return Complex(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
        }
    };

    // 位逆序置换（迭代FFT核心）
    static void bitReverse(vector<Complex>& a) {
        int n = a.size();
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

    // 迭代FFT
    static void fft(vector<Complex>& a, int opt) {
        int n = a.size();
        bitReverse(a);
        for (int h = 2; h <= n; h <<= 1) {
            Complex wn(cos(2 * PI / h), opt * sin(2 * PI / h));
            for (int j = 0; j < n; j += h) {
                Complex w(1, 0);
                for (int k = j; k < j + h / 2; k++) {
                    Complex u = a[k], t = w * a[k + h / 2];
                    a[k] = u + t;
                    a[k + h / 2] = u - t;
                    w = w * wn;
                }
            }
        }
        if (opt == -1) {
            for (auto& x : a) x.x /= n;
        }
    }

public:
    // 计算多项式乘法 a * b，返回系数向量（从低次到高次）
    static vector<int> multiply(const vector<int>& a, const vector<int>& b) {
        int n = a.size(), m = b.size();
        int len = 1;
        while (len < n + m) len <<= 1;

        vector<Complex> fa(len), fb(len);
        for (int i = 0; i < n; i++) fa[i] = Complex(a[i], 0);
        for (int i = 0; i < m; i++) fb[i] = Complex(b[i], 0);

        fft(fa, 1);  // 正变换
        fft(fb, 1);
        for (int i = 0; i < len; i++) fa[i] = fa[i] * fb[i];
        fft(fa, -1); // 逆变换

        vector<int> res(n + m - 1);
        for (int i = 0; i < n + m - 1; i++) 
            res[i] = round(fa[i].x);
        return res;
    }
};

const double Polynomial::PI = acos(-1.0);

/* 使用示例 */
int main() {
    vector<int> a = {3, 2, 1}; // 多项式 3 + 2x + 1x^2
    vector<int> b = {4, 3};     // 多项式 4 + 3x
    vector<int> c = Polynomial::multiply(a, b);

    for (int coeff : c) cout << coeff << " "; // 输出: 12 17 10 3
    return 0;
}