#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>


using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MX = 1e5 + 5;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int siz[MX << 2];

void push_up(int rt) {
    siz[rt] = siz[rt << 1] + siz[rt << 1 | 1];
}

void update(int p, int l, int r, int rt) {
    if (l == r) {
        siz[rt]++;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, lson);
    else update(p, rson);
    push_up(rt);
}

int query(int k, int l, int r, int rt) {
    if (l == r) return l;
    int m = (l + r) >> 1;
    if (k <= siz[rt << 1]) return query(k, lson);
    else return query(k - siz[rt << 1], rson);
}

struct Seg {
    int l, r;

    bool operator<(const Seg &P) const {
        if (r == P.r) return l > P.l;
        return r < P.r;
    }
} s[MX];

int sum[MX];

int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    memset(siz, 0, sizeof(siz));
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        sum[i] = sum[i - 1] + t;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &s[i].l, &s[i].r);
    }
    sort(s + 1, s + 1 + m);
    for (int i = m - k + 2; i <= m; i++) {
        update(s[i].l, 1, n, 1);
    }
    int ans = 0;
    for (int i = m - k + 1; i >= 1; i--) {
        update(s[i].l, 1, n, 1);
        int p = query(k, 1, n, 1);
        if (p <= s[i].r) {
            ans = max(ans, sum[s[i].r] - sum[p - 1]);
        }
    }
    printf("%d\n", ans);

    return 0;
}