#include<stdio.h>
#include<string.h>

int pair[101][101] = {0};
int coder[101] = {0};
int used[101] = {0};
int n, m, k;

int find(int i) {
    int j;
    for (j = 1; j <= n; j++) {
        if (pair[i][j] && !used[j]) {
            used[j] = 1;
            if (!coder[j] || find(coder[j])) {
                coder[j] = i;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int i, j, l;
    int sum = 0;
    scanf("%d%d", &n, &m);
    for (l = 0; l < m; l++) {
        scanf("%d%d", &i, &j);
        pair[i][j] = 1;
    }
    for (int i = 1; i <= n; i++) {
        memset(used, 0, sizeof(used));
        if (find(i)) sum++;
    }
    printf("%d", n - sum);
    return 0;
}