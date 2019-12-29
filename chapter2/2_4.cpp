#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int m;
vector<int> arr;

bool check(int k) {
    int cnt = 1, tmp = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] - tmp >= k) {
            ++cnt;
            tmp = arr[i];
            if (cnt >= m) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> m;
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());
    int low = 0, high = arr[n - 1];
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid))
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << high;
}