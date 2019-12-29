#include <iostream>
#include<stdio.h>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;


bool dfs(vector<int> &nums, vector<int> &snums, int pos, int target) {
    if (pos >= nums.size()) {
        return snums[0] == target && snums[1] == target && snums[2] == target;
    }

    for (int i = 0; i < 3; ++i) {
        if (snums[i] + nums[pos] > target) {
            continue;
        }
        snums[i] += nums[pos];
        if (dfs(nums, snums, pos + 1, target)) {
            return true;
        }
        snums[i] -= nums[pos];
    }
    return false;
}

int main() {


    int t, n;
    cin >> t;


    while (t--) {
        vector<int> nums;
        vector<int> snums(100, 0);
        cin >> n;
        nums.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        int all_sum = accumulate(nums.begin(), nums.end(), 0);
        if (all_sum % 3 != 0) {
            cout << "No" << endl;
            continue;
        }

        sort(nums.begin(), nums.end());

        if (dfs(nums, snums, 0, all_sum / 3)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}