#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q, op, x, y;
    cin >> n >> m >> q;
    int matrix[n][m], rows[n], cols[m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        rows[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        cols[i] = i;
    }
    for (int i = 0; i < q; ++i) {
        cin >> op >> x >> y;
        if (op == 0) {
            swap(rows[x - 1], rows[y - 1]);
        } else if (op == 1) {
            swap(cols[x - 1], cols[y - 1]);
        } else {
            printf("%d\n", matrix[rows[x - 1]][cols[y - 1]]);
        }
    }
    return 0;
}