#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 1000005
using namespace std;

int dp[MAX];
int value[MAX], weight[MAX], number[MAX];
int m;

void ZeroOnePack(int weight, int value) {
    int i;
    for (i = m; i >= weight; i--) {
        dp[i] = max(dp[i], dp[i - weight] + value);
    }
}

void CompletePack(int weight, int value) {
    int i;
    for (i = weight; i <= m; i++) {
        dp[i] = max(dp[i], dp[i - weight] + value);
    }
}

void MultiplePack(int weight, int value, int number) {
    if (m <= number * weight) {
        CompletePack(weight, value);
        return;
    } else {
        int k = 1;
        while (k <= number) {
            ZeroOnePack(k * weight, k * value);
            number = number - k;
            k = 2 * k;
        }
        ZeroOnePack(number * weight, number * value);
    }
}

int main() {
    int n;
    scanf("%d%d", &n, &m);
    int i, sum = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
        scanf("%d", &value[i]);
        scanf("%d", &number[i]);
    }
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < n; i++) {
        MultiplePack(weight[i], value[i], number[i]);
    }
    cout << dp[m] << endl;
    return 0;
}