#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdio.h>

using namespace std;

int n;
int flag[100];
int s[100];
int f = 0;

bool isprime(int a) {
    if (a == 1)
        return false;
    else if (a == 2)
        return true;
    else {
        for (int i = 2; i <= sqrt(a); i++) {
            if (a % i == 0)
                return false;
        }
        return true;
    }


}

void dfs(int cd) {
    if (f == 1)
        return;
    if (cd == n + 1) {
        f = 1;
        for (int i = 1; i <= n; i++)
            printf("%d ", s[i]);
        printf("\n");
    }
    for (int i = 1; i <= n; i++) {
        if (flag[i] == 0) {
            if (cd != 1 && !isprime(i + s[cd - 1]))
                continue;
            flag[i] = 1;
            s[cd] = i;
            dfs(cd + 1);
            flag[i] = 0;
        }
    }
}


int main() {
    scanf("%d", &n);
    dfs(1);
    if (f == 0)
        cout << "-1" << endl;
    return 0;
}