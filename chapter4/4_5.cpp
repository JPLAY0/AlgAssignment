#include <queue>
#include <iostream>

using namespace std;
typedef long long LL;

int main() {
    string S;
    cin >> S;
    int n = S.length();
    priority_queue<int> Q;
    LL sum = 0;
    bool ok = true;
    int L[n], R[n];
    for (int i = 0; i < n; i++) {
        if (S[i] == '*') {
            cin >> L[i] >> R[i];
            sum += R[i];
        }
    }
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] == 'o') now++;
        else if (S[i] == 'x' || S[i] == '*') now--;
        if (S[i] == '*') Q.push(R[i] - L[i]);
        if (now < 0) {
            if (Q.empty()) {
                ok = false;
                break;
            }
            sum -= Q.top();
            Q.pop();
            now += 2;
        }
    }
    if (now != 0) ok = false;
    cout << (ok ? sum : -1);
    return 0;
}