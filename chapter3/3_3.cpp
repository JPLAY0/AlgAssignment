#include <iostream>

#define rep(i, a, b) for(int i=(a);i<(b);++i)
#define per(i, a, b) for(int i=(b);i>(a);--i)


using namespace std;

const int N = 808;
int n, q, f[N][1010], g[N][1010];
struct Node {
    int c, v, k;
} a[N];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n;
    int m = 1000;
    rep(i, 1, n + 1) {
        cin >> a[i].c >> a[i].v >> a[i].k;
        rep(t, 0, a[i].k + 1) {
            rep(j, t * a[i].c, m + 1) {
                f[i][j] = max(f[i][j], f[i - 1][j - t * a[i].c] + t * a[i].v);
            }
        }
        rep(j, 1, m + 1) f[i][j] = max(f[i][j], f[i][j - 1]);
    }
    per(i, 1, n + 1) {
        rep(t, 0, a[i].k + 1) {
            rep(j, t * a[i].c, m + 1) {
                g[i][j] = max(g[i][j], g[i + 1][j - t * a[i].c] + t * a[i].v);
            }
        }
        rep(j, 1, m + 1) g[i][j] = max(g[i][j], g[i][j - 1]);
    }
    cin >> q;
    while (q--) {
        int x, y, ans = 0;
        cin >> x >> y;
        ++y;
        rep(i, 0, x + 1) ans = max(ans, f[y - 1][i] + g[y + 1][x - i]);
        cout << ans << endl;
    }
    return 0;
}