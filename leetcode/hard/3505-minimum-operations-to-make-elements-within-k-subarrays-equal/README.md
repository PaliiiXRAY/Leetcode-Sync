# Minimum Operations to Make Elements Within K Subarrays Equal

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` and two integers, `x` and `k`. You can perform the following operation any number of times (**including zero**):

- Increase or decrease any element of nums by 1.

Return the  **minimum**  number of operations needed to have  **at least**  `k`  *non-overlapping subarrays*  of size  **exactly**  `x` in `nums`, where all elements within each subarray are equal.

 

 **Example 1:** 

 **Input:**  nums = [5,-2,1,3,7,3,6,4,-1], x = 3, k = 2

 **Output:**  8

 **Explanation:** 

- Use 3 operations to add 3 to nums[1] and use 2 operations to subtract 2 from nums[3]. The resulting array is [5, 1, 1, 1, 7, 3, 6, 4, -1].
- Use 1 operation to add 1 to nums[5] and use 2 operations to subtract 2 from nums[6]. The resulting array is [5, 1, 1, 1, 7, 4, 4, 4, -1].
- Now, all elements within each subarray [1, 1, 1] (from indices 1 to 3) and [4, 4, 4] (from indices 5 to 7) are equal. Since 8 total operations were used, 8 is the output.

 **Example 2:** 

 **Input:**  nums = [9,-2,-2,-2,1,5], x = 2, k = 2

 **Output:**  3

 **Explanation:** 

- Use 3 operations to subtract 3 from nums[4]. The resulting array is [9, -2, -2, -2, -2, 5].
- Now, all elements within each subarray [-2, -2] (from indices 1 to 2) and [-2, -2] (from indices 3 to 4) are equal. Since 3 operations were used, 3 is the output.

 

 **Constraints:** 

- 2 <= nums.length <= 105
- -106 <= nums[i] <= 106
- 2 <= x <= nums.length
- 1 <= k <= 15
- 2 <= k * x <= nums.length

## Solution

**Language:** C++  
**Runtime:** 1230 ms (beats 36.11%)  
**Memory:** 445.1 MB (beats 29.17%)  
**Submitted:** 2026-11-04T21:25:42.865Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/)