#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


const int maxn = 100001;

struct node {
    long x, y;

    bool operator<(const node &e) {
        return  y < e.y;
    }

    long dis(const node &a) {
        return pow(x - a.x,2) + pow(y - a.y,2);
    }
};

node p[maxn], t[maxn];

long closest(int left, int right) {
    long d = 4e18;
    if (left == right) return d;
    if (left + 1 == right) return p[left].dis(p[right]);
    int mid = (left + right) / 2;
    long d1 = closest(left, mid), d2 = closest(mid + 1, right);
    d = min(d1, d2);
    int k = 0;
    for (int i = left; i <= right; ++i)
        if (pow(p[i].x - p[mid].x,2) <= d) t[k++] = p[i];
    sort(t, t + k);
    for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k && (pow(t[j].y - t[i].y,2) < d); ++j) {
            d = min(d, t[i].dis(t[j]));
        }
    }
    return d;
}

int main() {
    int res = 0, x = 0, n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        res += x;
        p[i].x = i;
        p[i].y = res;
    }
    cout << closest(0, n - 1);
    return 0;
}