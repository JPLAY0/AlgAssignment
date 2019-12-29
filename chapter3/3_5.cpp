#include <iostream>
#include <algorithm>

const int max_n = 1e4;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, k, ret = -1;
    cin >> n >> k;
    int v[n], c[n], d[n], dp1[max_n], dp2[max_n];
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        d[i] = c[i] * k - v[i];
    }
    fill_n(dp1, max_n, -1e5);
    fill_n(dp2, max_n, -1e5);
    dp1[0] = dp2[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] >= 0) {
            for (int j = max_n - 1; j >= d[i]; --j) {
                dp1[j] = max(dp1[j], dp1[j - d[i]] + v[i]);
            }
        } else {
            for (int j = max_n - 1; j >= -d[i]; --j) {
                dp2[j] = max(dp2[j], dp2[j + d[i]] + v[i]);
            }
        }
    }
    for (int i = 0; i < max_n; ++i) {
        ret = max(ret, dp1[i] + dp2[i]);
    }
    if (ret) cout << ret;
    else cout << -1;
    return 0;
}