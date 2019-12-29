#include <iostream>

using namespace std;

int a, b;

struct Matrix {
    int arr[4];

    Matrix(int A, int B, int c, int d) {
        arr[0] = A;
        arr[1] = B;
        arr[2] = c;
        arr[3] = d;
    }

    Matrix operator*(const Matrix &e) const {
        Matrix ret(0, 0, 0, 0);
        ret.arr[0] = (arr[0] * e.arr[0] + arr[1] * e.arr[2]) % 2013;
        ret.arr[1] = (arr[0] * e.arr[1] + arr[1] * e.arr[3]) % 2013;
        ret.arr[2] = (arr[2] * e.arr[0] + arr[3] * e.arr[2]) % 2013;
        ret.arr[3] = (arr[2] * e.arr[1] + arr[3] * e.arr[3]) % 2013;
        return ret;
    }
};

int fbn(int n) {
    Matrix ret(1, 0, 0, 1), x(a, b, 1, 0);
    while (n > 0) {
        if (n % 2 == 1) { ret = ret * x; }
        x = x * x;
        n /= 2;
    }
    return ret.arr[0] + ret.arr[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, n;
    cin >> q >> a >> b;
    for (int i = 0; i < q; ++i) {
        cin >> n;
        cout << fbn(n - 1) % 2013 << endl;
    }
    return 0;
}
