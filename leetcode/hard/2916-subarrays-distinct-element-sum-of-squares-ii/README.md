# Subarrays Distinct Element Sum of Squares II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a  **0-indexed** integer array `nums`.

The  **distinct count**  of a subarray of `nums` is defined as:

- Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called the distinct count of nums[i..j].

Return  *the sum of the  **squares**  of  **distinct counts**  of all subarrays of* `nums`.

Since the answer may be very large, return it  **modulo**  `109 + 7`.

A subarray is a contiguous  **non-empty**  sequence of elements within an array.

 

 **Example 1:** 

```
Input: nums = [1,2,1]
Output: 15
Explanation: Six possible subarrays are:
[1]: 1 distinct value
[2]: 1 distinct value
[1]: 1 distinct value
[1,2]: 2 distinct values
[2,1]: 2 distinct values
[1,2,1]: 2 distinct values
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.

```

 **Example 2:** 

```
Input: nums = [2,2]
Output: 3
Explanation: Three possible subarrays are:
[2]: 1 distinct value
[2]: 1 distinct value
[2,2]: 1 distinct value
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 = 3.
```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 83 ms (beats 92.86%)  
**Memory:** 101.6 MB (beats 75.82%)  
**Submitted:** 2026-10-16T21:07:03.554Z  

```cpp
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        long long MOD = 1'000'000'007;
        int n = nums.size();
      vector<long long> cnt(n + 1, 0);
     vector<long long> tot(n + 1, 0);
    unordered_map<int, int> last;
        
        long long ans = 0;
        
        for (int r = 0; r < n; ++r) {
            int p = -1;
            if (last.find(nums[r]) != last.end()) {
                p = last[nums[r]];
            }
            
            long long c = 0, s = 0;
            for (int i = n - p - 1; i > 0; i -= i & -i) {
                c += cnt[i];
                s += tot[i];
            }
            long long gain = 1LL * (r - p) * (r - p) - 2LL * (s - 1LL * p * c);
            ans = (ans + 1LL * (n - r) * (gain % MOD)) % MOD;
            
            for (int i = n - p; i <= n; i += i & -i) {
                cnt[i]++;
                tot[i] += p;
            }
            last[nums[r]] = r;
        }
        return (ans % MOD + MOD) % MOD;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/)