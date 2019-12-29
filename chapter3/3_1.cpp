// cite Yuanyuan Wu

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 100000;

struct Node {
    int tim, c, v, y, o, i;

    Node() {}

    Node(int c, int v, int tim) : c(c), v(v), tim(tim), o(0) {}

    Node(int tim, int y) : tim(tim), y(y), o(1) {}

    bool operator<(const Node &e) const {
        if (tim != e.tim) return tim < e.tim;
        else return o < e.o;
    }
};

int n, m, ans[N];
long f[N];
vector<Node> vec;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vec.reserve(n + m);
    int sum = 0;
    int c, v, t, x, y;
    for (int i = 0; i < n; ++i) {
        cin >> c >> v >> t;
        vec.push_back(Node(c, v, t));
        sum += v;
    }
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        vec.push_back(Node(x, y));
        vec[vec.size() - 1].i = i;
    }
    sort(vec.begin(), vec.end());
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int j = 0; j < vec.size(); ++j) {
        Node u = vec[j];
        if (u.o == 0) {
            for (int i = sum + 1; i >= u.v; --i) f[i] = min(f[i], f[i - u.v] + u.c);
            for (int i = sum; i >= 0; --i) f[i] = min(f[i], f[i + 1]);
        } else {
            int p = upper_bound(f, f + sum + 1, u.y) - f - 1;
            ans[u.i] = p;
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}