#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
    long long mx = 1e15;
    vector<vector<long long>> dp;

    long long f(int i, const vector<long long>& ans, int k, int x, int n) {
        if (k == 0) return 0;
        if (i > n - x) return mx;
        if (dp[i][k] != -1) return dp[i][k];
        long long c1 = ans[i] + f(i + x, ans, k - 1, x, n);
        long long c2 = f(i + 1, ans, k, x, n);
        return dp[i][k] = min(c1, c2);
    }

    vector<long long> medianSlidingWindow(const vector<int>& arr, int k) {
        map<int, int> left, right;
        int minSz = 0, maxSz = 0;
        int n = arr.size();
        vector<long long> ans(n - k + 1);
        int j = 0;
        long long minSum = 0, maxSum = 0;

        for (int i = 0; i < n; i++) {
            if (minSz == 0 || left.rbegin()->first >= arr[i]) {
                left[arr[i]]++;
                minSz++;
                minSum += arr[i];
            } else {
                right[arr[i]]++;
                maxSz++;
                maxSum += arr[i];
            }

            if (i - k >= 0) {
                int out = arr[i - k];
                auto it = left.find(out);
                if (it != left.end()) {
                    if (--it->second == 0) left.erase(it);
                    minSz--;
                    minSum -= out;
                } else {
                    it = right.find(out);
                    if (--it->second == 0) right.erase(it);
                    maxSz--;
                    maxSum -= out;
                }
            }

            if (minSz > maxSz + 1) {
                auto it = prev(left.end());
                int key = it->first;
                if (--it->second == 0) left.erase(it);
                minSz--;
                minSum -= key;
                right[key]++;
                maxSz++;
                maxSum += key;
            }
            if (maxSz > minSz) {
                auto it = right.begin();
                int key = it->first;
                if (--it->second == 0) right.erase(it);
                maxSz--;
                maxSum -= key;
                left[key]++;
                minSz++;
                minSum += key;
            }

            if (i >= k - 1) {
                long long median = left.rbegin()->first;
                long long curr = ((long long)minSz * median - minSum) + (maxSum - (long long)maxSz * median);
                ans[j++] = curr;
            }
        }
        return ans;
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        vector<long long> ans = medianSlidingWindow(nums, x);
        int n = nums.size();
        dp.assign(n, vector<long long>(k + 1, -1));
        return f(0, ans, k, x, n);
    }
};