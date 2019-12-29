#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 101;

int n, m;
bool line[MAX_N][MAX_N], used[MAX_N];
int girl[MAX_N];

bool match(int x) {
    for (int j = 1; j <= m; ++j) {
        if (line[x][j] && !used[j]) {
            used[j] = true;
            if (!girl[j] || match(girl[j])) {
                girl[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int k, x, y;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        cin >> x >> y;
        line[x][y] = true;
    }
    int all = 0;
    for (int i = 1; i <= n; ++i) {
        memset(used, false, sizeof(used));
        if (match(i)) ++all;
    }
    cout << all << endl;
    return 0;
}