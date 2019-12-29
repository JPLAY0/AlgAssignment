#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>

using namespace std;

bool match(int x, int t) {
    stringstream sm;
    string matcher, m;
    sm << x << endl << t;
    sm >> matcher >> m;
    for (size_t i = 0; i < m.length(); ++i) {
        if (matcher.find(m.substr(i, 1)) != -1) {
            return true;
        }
    }
    return false;
}

int main() {
    int x, t = 1;
    cin >> x;
    set<int> mapping;
    int limit = sqrt(x);
    while (t <= limit) {
        if (x % t == 0 && match(x, t)) {
            mapping.insert(t);
        }
        int f = x / t;
        if (x % f == 0 && match(x, f)) {
            mapping.insert(f);
        }
        ++t;
    }
    cout << mapping.size();
}