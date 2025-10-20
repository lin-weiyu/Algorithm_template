#include <iostream>
#include <complex>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef complex<double> Complex;
const double PI = acos(-1.0);

class FFT_Convolution
{
private:
    static void FFT(vector<Complex> &a, bool invert)
    {
        int n = a.size();
        if (n == 1)
            return;

        vector<Complex> a0(n / 2), a1(n / 2);
        for (int i = 0; 2 * i < n; i++)
        {
            a0[i] = a[2 * i];
            a1[i] = a[2 * i + 1];
        }
        FFT(a0, invert);
        FFT(a1, invert);

        double angle = 2 * PI / n * (invert ? -1 : 1);
        Complex w(1), wn(cos(angle), sin(angle));

        for (int i = 0; 2 * i < n; i++)
        {
            a[i] = a0[i] + w * a1[i];
            a[i + n / 2] = a0[i] - w * a1[i];
            if (invert)
            {
                a[i] /= 2;
                a[i + n / 2] /= 2;
            }
            w *= wn;
        }
    }

public:
    // 计算卷积结果，返回数组a_i = sum_{j} b_j * c_{i+j}
    static vector<int> compute(const vector<int> &b, const vector<int> &c)
    {
        int n = 1;
        while (n < b.size() + c.size())
            n <<= 1;

        vector<Complex> fb(n), fc(n);
        // 反转b数组并补零
        for (int i = 0; i < b.size(); i++)
            fb[i] = b[b.size() - 1 - i];
        for (int i = 0; i < c.size(); i++)
            fc[i] = c[i];

        FFT(fb, false);
        FFT(fc, false);
        for (int i = 0; i < n; i++)
            fb[i] *= fc[i];
        FFT(fb, true);

        vector<int> result;
        for (int i = b.size() - 1; i < (int)c.size() + (int)b.size() - 1; i++)
            result.push_back(round(fb[i].real()));
        return result;
    }
};

/* 使用示例 */
int main()
{
    vector<int> b = {1, 2, 3}; // 示例输入
    vector<int> c = {4, 5, 6, 7};
    vector<int> a = FFT_Convolution::compute(b, c);
    for (int val : a)
        cout << val << " "; // 输出: 32 38 20 7
    return 0;
}