#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 21;
static const int mod1 = 1E9 + 7, base1 = 127;
static const int mod2 = 1E9 + 9, base2 = 131;
vector<int> val1;
vector<int> val2;
void init(int n = N)
{
    val1.resize(n + 1), val2.resize(n + 2);
    val1[0] = 1, val2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        val1[i] = 1LL * val1[i - 1] * int(base1) % mod1;
        val2[i] = 1LL * val2[i - 1] * int(base2) % mod2;
    }
}
struct String
{
    vector<int> hash1;
    vector<int> hash2;
    string s;
    String(string s_) : s(s_), hash1{1}, hash2{1}
    {
        for (auto it : s)
        {
            hash1.push_back((1LL * hash1.back() * base1 % mod1 + it) % mod1);
            hash2.push_back((1LL * hash2.back() * base2 % mod2 + it) % mod2);
        }
    }
    pair<int, int> get()
    { // 输出整串的哈希值
        return {hash1.back(), hash2.back()};
    }
    pair<int, int> substring(int l, int r)
    { // 输出子串的哈希值 下标为 [l, r] = [0, n - 1]
        if (l > r)
            swap(l, r);
        int ans1 = (hash1[r + 1] - 1LL * hash1[l] * val1[r - l + 1] % mod1 + mod1) % mod1;
        int ans2 = (hash2[r + 1] - 1LL * hash2[l] * val2[r - l + 1] % mod2 + mod2) % mod2;
        return {ans1, ans2};
    }
    pair<int, int> modify(int idx, char x)
    { // 修改 idx 位为 x
        int n = s.size() - 1;
        int ans1 = (hash1.back() + 1LL * val1[n - idx] * (x - s[idx]) % mod1 + mod1) % mod1;
        int ans2 = (hash2.back() + 1LL * val2[n - idx] * (x - s[idx]) % mod2 + mod2) % mod2;
        return {ans1, ans2};
    }
};
signed main(){
    init();
    string s = "abcdef";
    String sk(s);
    cout << sk.substring(5, 5).first << endl;
}