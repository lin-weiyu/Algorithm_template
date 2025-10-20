#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
using namespace std;
typedef complex<double> Complex;
const double PI = acos(-1.0);

class FFT_Convolution {
private:
    // 位逆序置换（非递归FFT关键步骤）
    static void bitReverse(vector<Complex>& a) {
        int n = a.size();
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j >= bit; bit >>= 1) j -= bit;
            j += bit;
            if (i < j) swap(a[i], a[j]);
        }
    }

    // 迭代FFT核心
    static void fft(vector<Complex>& a, bool invert) {
        int n = a.size();
        bitReverse(a);  // 预处理位逆序

        for (int len = 2; len <= n; len <<= 1) {
            double angle = 2 * PI / len * (invert ? -1 : 1);
            Complex wn(cos(angle), sin(angle));
            for (int i = 0; i < n; i += len) {
                Complex w(1);
                for (int j = 0; j < len / 2; j++) {
                    Complex u = a[i + j];
                    Complex v = w * a[i + j + len / 2];
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                    w *= wn;
                }
            }
        }

        if (invert) {
            for (Complex& x : a) x /= n;
        }
    }

public:
    // 计算卷积结果，返回数组a_i = sum_{j} b_j * c_{i+j}
    static vector<int> compute(const vector<int>& b, const vector<int>& c) {
        int n = 1;
        while (n < b.size() + c.size()) n <<= 1;

        vector<Complex> fb(n), fc(n);
        // 反转b并补零
        for (int i = 0; i < b.size(); i++) fb[i] = b[b.size() - 1 - i];
        for (int i = 0; i < c.size(); i++) fc[i] = c[i];

        fft(fb, false);
        fft(fc, false);
        for (int i = 0; i < n; i++) fb[i] *= fc[i];
        fft(fb, true);

        vector<int> result;
        for (int i = b.size() - 1; i < (int)c.size() + (int)b.size() - 1; i++)
            result.push_back(round(fb[i].real()));
        return result;
    }
};

/* 使用示例 */
int main() {
    vector<int> b = {1, 2, 3};
    vector<int> c = {4, 5, 6, 7};
    vector<int> a = FFT_Convolution::compute(b, c);
    for (int val : a) cout << val << " ";  // 输出: 32 38 20 7
    return 0;
}