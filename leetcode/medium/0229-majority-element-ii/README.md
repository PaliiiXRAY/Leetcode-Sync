# Majority Element II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array of size `n`, find all elements that appear more than `⌊n / 3⌋` times.

 

 **Example 1:** 

```
Input: nums = [3,2,3]
Output: [3]

```

 **Example 2:** 

```
Input: nums = [1]
Output: [1]

```

 **Example 3:** 

```
Input: nums = [1,2]
Output: [1,2]

```

 

 **Constraints:** 

- 1 <= nums.length <= 5 * 104
- -109 <= nums[i] <= 109

 

 **Follow up:**  Could you solve the problem in linear time and in `O(1)` space?

## Solution

**Language:** C++  
**Runtime:** 10 ms (beats 22.22%)  
**Memory:** 26.6 MB (beats 23.49%)  
**Submitted:** 2026-10-27T22:05:26.114Z  

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map <int,int> mp;
        vector <int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++ ){
            mp[nums[i]]++;
        }
        for (auto it: mp){
            if (it.second > n/3) ans.push_back(it.first);
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/majority-element-ii/)