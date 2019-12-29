#include<iostream>

using namespace std;


int countLength(int n) {
    int total = 1;
    while (n > 1) {
        total += total + 1;
        n /= 2;
    }
    return total;
}

int count(int n, int l, int r) {
    if (n == 1) return 1;
    int middle = countLength(n) / 2 + 1;
    if (l == r) {
        if (r == middle)return n % 2;
    }
    if (r <= middle) {
        if (r == middle)
            return count(n / 2, l, r - 1) + n % 2;
        else
            return count(n / 2, l, r);
    } else if (l >= middle) {
        if (l == middle)
            return count(n / 2, (r - (r - middle) * 2), l - 1) + n % 2;
        else
            return count(n / 2, (r - (r - middle) * 2), (l - (l - middle) * 2));
    } else {
        return n % 2 + count(n / 2, l, middle - 1)
               + count(n / 2, (r - (r - middle) * 2), middle - 1);
    }
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    cout << count(n, l, r);
    return 0;
}
