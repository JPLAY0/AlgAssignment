#include<iostream>

using namespace std;
string sj[1024] = {" /\\", "/__\\"};

void dfs(int n) {
    int step = (1 << n - 1);
    for (int i = 2 * step - 1; i >= step; --i) {
        sj[i] = sj[i - step];
        for (int j = 1; j < 2 * step - i; j++) sj[i] += " ";
        sj[i] += sj[i - step];
    }
    string tmp;
    for (int i = step - 1; i >= 0; --i) {
        tmp = "";
        for (int j = 1; j <= step; j++) tmp += " ";
        sj[i] = tmp + sj[i];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) dfs(i);
    for (int i = 0; i <= (1 << n) - 1; ++i) cout << sj[i] << endl;
    return 0;
}
