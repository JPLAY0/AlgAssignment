#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

#define MAX 1000
#define MAXE 100010
#define INF 0x3f3f3f3f
#define S 0
#define T (MAX - 1)
using namespace std;

int shopper, cars;
int src[MAX][MAX];

int head[MAX], total = 1;
int Next[MAXE], aim[MAXE], cost[MAXE], cap[MAXE];

int f[MAX], from[MAX], p[MAX];
bool v[MAX];

inline void Add(int x, int y, int f, int c) {
    Next[++total] = head[x];
    aim[total] = y;
    cap[total] = f;
    cost[total] = c;
    head[x] = total;
}

inline void Insert(int x, int y, int f, int c) {
    Add(x, y, f, c);
    Add(y, x, 0, -c);
}

inline bool SPFA() {
    static queue<int> q;
    while (!q.empty()) q.pop();
    q.push(S);
    memset(v, false, sizeof(v));
    memset(f, 0x3f, sizeof(f));
    f[S] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        v[x] = false;
        for (int i = head[x]; i; i = Next[i])
            if (cap[i] && f[aim[i]] > f[x] + cost[i]) {   //容量为0
                f[aim[i]] = f[x] + cost[i];
                if (!v[aim[i]]) {
                    v[aim[i]] = true;
                    q.push(aim[i]);
                }
                from[aim[i]] = x;
                p[aim[i]] = i;
            }
    }
    return f[T] != INF;
}

// 沿着最小费用路增流
int EdmondsKarp() {
    int result = 0;
    while (SPFA()) {
        int remain_flow = INF;
        for (int i = T; i != S; i = from[i])
            remain_flow = min(remain_flow, cap[p[i]]);
        for (int i = T; i != S; i = from[i]) {
            cap[p[i]] -= remain_flow;
            cap[p[i] ^ 1] += remain_flow;
        }
        result += remain_flow * f[T];
    }
    return result;
}

int main() {
    cin >> shopper >> cars;
    for (int i = 1; i <= cars; ++i)
        for (int j = 1; j <= shopper; ++j)
            cin >> src[i][j];
    for (int i = 1; i <= cars; ++i)
        Insert(S, i, 1, 0);
    for (int i = 1; i <= cars; ++i)
        for (int j = 1; j <= shopper; ++j)
            for (int k = 1; k <= cars; ++k)
                Insert(i, j * cars + k, 1, src[i][j] * k);
    for (int i = 1; i <= shopper; ++i)
        for (int j = 1; j <= cars; ++j)
            Insert(i * cars + j, T, 1, 0);
    cout << EdmondsKarp() << endl;
    return 0;
}