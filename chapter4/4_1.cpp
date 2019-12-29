#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, S;
    cin >> N >> S;
    int c[N], a[N];
    for (int i = 0; i < N; i++)
        cin >> c[i] >> a[i];
    for (int i = 1; i < N; i++)
        c[i] = min(c[i], c[i - 1] + S);
    long long ans = 0;
    for (int i = 0; i < N; i++)
        ans += c[i] * a[i];
    cout << ans << endl;
    return 0;
}