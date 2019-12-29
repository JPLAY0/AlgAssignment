//#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

#define MAXN 5050
#define INF 0x3f3f3f3f

using namespace std;

int n, m, s, t;
int maxFlow, minCost;

struct Edge {
    int from, to, flow, cap, cost;
};

bool vis[MAXN];
int p[MAXN], a[MAXN], d[MAXN];
vector<int> g[MAXN];
vector<Edge> edges;

void init(int n) {
    for (int i = 0; i <= n; i++)
        g[i].clear();
    edges.clear();
}

void addedge(int from, int to, int cap, int cost) {
    Edge temp1 = {from, to, 0, cap, cost};
    Edge temp2 = {to, from, 0, 0, -cost};//允许反向增广
    edges.push_back(temp1);
    edges.push_back(temp2);
    int len = edges.size();
    g[from].push_back(len - 2);
    g[to].push_back(len - 1);
}

//贝尔曼-福特算法实现
bool bellmanford(int s, int t) {
    for (int i = 0; i < MAXN; i++)
        d[i] = INF;
    d[s] = 0;
    memset(vis, false, sizeof(vis));
    memset(p, -1, sizeof(p));
    p[s] = -1;
    a[s] = INF;
    queue<int> que;
    que.push(s);
    vis[s] = true;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for (int i = 0; i < g[u].size(); i++) {
            Edge &e = edges[g[u][i]];
            if (e.cap > e.flow && d[e.to] > d[u] + e.cost)//进行松弛，寻找最短路径也就是最小费用
            {
                d[e.to] = d[u] + e.cost;
                p[e.to] = g[u][i];
                a[e.to] = min(a[u], e.cap - e.flow);
                if (!vis[e.to]) {
                    que.push(e.to);
                    vis[e.to] = true;
                }
            }
        }
    }
    if (d[t] == INF)
        return false;
    maxFlow += a[t];
    minCost += d[t] * a[t];
    for (int i = t; i != s; i = edges[p[i]].from) {
        edges[p[i]].flow += a[t];
        edges[p[i] ^ 1].flow -= a[t];
    }
    return true;
}


void MCMF() {
    while (bellmanford(s, t))
        continue;
    return;
}


int main() {
    int n, m;
    cin >> n >> m;
    s = 1;
    t = n;
    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        addedge(a, b, c, d);
    }

    MCMF();
    cout << maxFlow << " " << minCost << endl;
    return 0;

}