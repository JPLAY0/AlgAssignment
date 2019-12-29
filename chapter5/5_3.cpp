#include <iostream>
#include <map>

using namespace std;

string a, b, ret = "-1";


void perm(int low, int high) {
    if (low == high) {
        if (a[0] != '0' && a <= b && a > ret) ret = a;
    } else {
        for (int i = low; i <= high; ++i) {
            swap(a[i], a[low]);
            perm(low + 1, high);
            swap(a[i], a[low]);
        }
    }
}


int main() {
    cin >> a >> b;
    perm(0, a.length() - 1);
    cout << ret;
    return 0;
}