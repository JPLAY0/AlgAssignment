#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret ^= arr[i];
    }
    cout << ret;
    return 0;
}