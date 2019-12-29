#include <iostream>
#include <cstring>

using namespace std;

char matrix[17][17];
int N, M;

bool str_cmp(const string &str1, const string &str2) {
    if (str1.size() > str2.size()) return true;
    else if (str1.size() < str2.size()) return false;
    else return str1 > str2;
}

string ret = "0";
string mid = "";

void dfs(int x, int y) {
    if (matrix[x][y] == '#') {
        if (str_cmp(mid, ret)) ret = mid;
    } else {
        char t = matrix[x][y];
        mid += t;
        matrix[x][y] = '#';
        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        mid = mid.substr(0, mid.length() - 1);
        matrix[x][y] = t;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        memset(matrix, '#', 17 * 17);
        ret = "0";
        cin >> N >> M;
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= M; ++k) {
                cin >> matrix[j][k];
            }
        }
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= M; ++k) {
                dfs(j, k);
            }
        }
        cout << ret << endl;
    }
    return 0;
}