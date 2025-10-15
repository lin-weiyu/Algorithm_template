#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 5, M = 2e6 + 5;
// 单源最短路（负权边，负环），最坏 O(nm)
int n, m;
int pre[N];
void print_path(int s, int t)
{
    if (s == t)
    {
        cout << s << " ";
        return;
    }
    print_path(s, pre[t]);
    cout << t << " " ;
}
int head[N], cnt;
struct
{
    int to, next, w;
}edge[M];
void init()
{
    for (int i = 0; i < N; i++) head[i] = -1;
    for (int i = 0; i < M; i++) edge[i].next = -1;
    cnt = 0;
}
void addedge(int u, int v, int w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
int dis[N];
bool inq[N];
int Neg[N];
int spfa(int s)
{
    memset(Neg, 0, sizeof(Neg));
    Neg[s] = 1;
    for (int i = 1; i < n; i++)
    {
        dis[i] = INF;
        inq[i] = false;
    }
    dis[s] = 0;
    queue<int> Q;
    Q.push(s);
    inq[s] = true;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        for (int i =  head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to, w = edge[i].w;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pre[v] = u;
                if (!inq[v])
                {
                    inq[v] = true;
                    Q.push(v);
                    Neg[v]++;
                    if (Neg[v] > n) return 1; // 在不经过负环的情况下，最短路最多有 n - 1 条边
                }
            }
        }
    }
    return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
    {
        init();
        if (n == 0 && m == 0) return 0;
        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            addedge(u, v, w);
            addedge(v, u, w);
        }
        spfa(1);
        cout << dis[n] << endl;
    }
    return 0;
}