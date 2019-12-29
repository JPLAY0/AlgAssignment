#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include<iostream>

using namespace std;

int res[15], yh[15][15] = {0};
bool lk[15];
int n, sum, sear;

void input_data() {
    memset(lk, 0, sizeof(lk));
    scanf("%d%d", &n, &sum);
    yh[1][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
}

void per(int next, int cur) {

    if (cur > sum || sear)
        return;

    if (next == n + 1) {
        if (cur == sum) {
            for (int i = 1; i < n; i++)
                printf("%d ", res[i]);
            printf("%d", res[n]);
            exit(0);
            sear = 1;

        }
    } else {
        for (int i = 1; i <= n && !sear; i++) {
            if (!lk[i]) {
                lk[i] = true;
                res[next] = i;
                per(next + 1, cur + yh[n][next] * i);
                lk[i] = false;
            }
        }
    }
}

int main() {
    input_data();
    per(1, 0);
    if (!sear)
        cout << "GG";
    return 0;
}