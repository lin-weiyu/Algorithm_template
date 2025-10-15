#include <bits/stdc++.h>
using namespace std;
class Manacher 
{
    const int n;
    vector<int> r, f;
    public:
    Manacher(const string &t)
    : n(t.size()), r(2 * t.size() + 3), f(2 * t.size() + 3)
    {
        string s = "[-";
        for (int i = 0; i < n; i++)
        {
            s += t[i];
            s += '-';
        }
        s.push_back(']');
        int mid = 1, far = 1; 
        for (int i = 1; i < static_cast<int>(s.size()); i++)
        {
            r[i] = min(r[2 * mid - i], far - i);
            while (s[i + r[i]] == s[i - r[i]])
            {
                r[i] += 1;
            }
            if (far < i + r[i])
            {
                mid = i;
                far = i + r[i];
            }
            f[i + r[i] - 1] = max(f[i + r[i] - 1], r[i]);
        }
        for (int i = f.size() - 2; i; i--)
        {
            f[i] = max(f[i], f[i + 1] - 1);
        }
    }
    int getPalinLenFromCenter(int i, int center) const
    {
        assert((!center && 0 <= i && i < n) || (center && 0 <= i && i < n - 1));
        return r[2 * (i + 1) + center] - 1;
    }
    int getPalinLenFromTail(int i) const
    {
        assert(0 <= i && i < n);
        return f[2 * (i + 1)];
    }
};