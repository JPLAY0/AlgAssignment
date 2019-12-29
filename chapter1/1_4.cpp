#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    int left[t], right[t];
    for (int i = 0; i < t; ++i) {
        cin >> left[i] >> right[i];
    }
    int min = *min_element(left, left + t);
    int max = *max_element(right, right + t);
    for (int j = 0; j < t; ++j) {
        if (left[j] == min && right[j] == max) {
            cout << j + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}