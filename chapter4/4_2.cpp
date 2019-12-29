#include <algorithm>
#include <iostream>
#include <numeric>
#include <climits>
#include <vector>

using namespace std;

struct hacker {
    long long ci, ti;
    double cost;

    bool operator<(const hacker &d) {
        return cost < d.cost;
    }
};


int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long cost = 0;
    vector<hacker> hackers(n);
    for (int i = 0; i < n; ++i) {
        cin >> hackers[i].ti >> hackers[i].ci;
        hackers[i].ti *= 2;
    }
    long long total_cost = 0;
    for (int i = 0; i < n; ++i) {
        total_cost += hackers[i].ci;
    }
    for (int i = 0; i < n; ++i) {
        hackers[i].cost = hackers[i].ci * 1.0 / hackers[i].ti;
    }
    sort(hackers.begin(), hackers.end());
    for (int i = n - 1; i >= 0; --i) {
        total_cost -= hackers[i].ci;
        cost += total_cost * hackers[i].ti;
    }
    cout << cost;
    return 0;
}