#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int max_n = 305;
vector<int> path[max_n];
int dp[max_n][max_n], val[max_n];

void dfs(int x, int m) {
    dp[x][1] = val[x];
    int to;
    for (int i = 0; i < path[x].size(); ++i) {
        to = path[x][i];
        dfs(to, m - 1);
        for (int j = m; j > 1; --j) {
            for (int k = 1; k < j; ++k) {
                dp[x][j] = max(dp[x][j], dp[x][j - k] + dp[to][k]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        val[i] = b;
        path[a].push_back(i);
    }
    ++m;
    dfs(0, m);
    cout << dp[0][m] << endl;
}