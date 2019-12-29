#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;


long _find_reverse(vector<int> &array, vector<int> &copy, int low, int high) {
    if (low == high) return 0;
    int mid = (low + high) / 2;
    long left = _find_reverse(array, copy, low, mid);
    long right = _find_reverse(array, copy, mid + 1, high);
    long count = 0, i = mid, j = high, loc = high;
    while (i >= low && j > mid) {
        if (array[i] > array[j]) {
            count += j - mid;
            copy[loc--] = array[i--];
        } else {
            copy[loc--] = array[j--];
        }
    }
    for (; i >= low; --i) {
        copy[loc--] = array[i];
    }
    for (; j > mid; --j) {
        copy[loc--] = array[j];
    }
    for (int k = low; k <= high; ++k) {
        array[k] = copy[k];
    }
    return left + right + count;
}

long find_reverse(vector<int> &array) {
    int size = array.size();
    vector<int> copy(size);
    return _find_reverse(array, copy, 0, size - 1);
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    long count = find_reverse(array);
    cout << min(a, b) * count;
}