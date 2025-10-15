#include <bits/stdc++.h>
using namespace std;
struct BIT
{
    int n;
    vector<int> w;
    BIT(int n) : n(n), w(n + 1) {}
    void add(int x, int v)
    {
        for (; x <= n; x += x & -x)
        {
            w[x] += v;
        }
    }
    int kth(int x)
    {
        // 查找第 k 小的值
        int ans = 0;
        for (int i = __lg(n); i >= 0; i--)
        {
            int val = ans + (1 << i);
            if (val < n && w[val] < x)
            {
                x -= w[val];
                ans = val;
            }
        }
        return ans + 1;
    }
    int get(int x)
    {
        // 查找 x 的排名
        int ans = 1;
        for (x--; x; x -= x & -x)
        {
            ans += w[x];
        }
        return ans;
    }
    int pre(int x)
    {
        // 查找 x 的前驱
        return kth(get(x) - 1);
    }
    int suf(int x)
    {
        // 查找 x 的后继
        return kth(get(x + 1));
    }
};
const int N = 10000000; // 可以用于在线处理平衡二叉树的全部要求
signed main()
{
    BIT bit(N + 1); // 在线处理不能够离散化，一定要开到比最大值更大
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int op, x;
        cin >> op >> x;
        if (op == 1)
            bit.add(x, 1); // 插入 x
        else if (op == 2)
            bit.add(x, -1); // 删除任意一个 x
        else if (op == 3)
            cout << bit.get(x) << "\n"; // 查询 x 的排名
        else if (op == 4)
            cout << bit.kth(x) << "\n"; // 查询排名为 x 的数
        else if (op == 5)
            cout << bit.pre(x) << "\n"; // 求小于 x 的最大值（前驱）
        else if (op == 6)
            cout << bit.suf(x) << "\n"; // 求大于 x 的最小值（后继）
    }
    return 0;
}