# Minimum Size Subarray Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of positive integers `nums` and a positive integer `target`, return  *the  **minimal length**  of a  **subarray**  whose sum is greater than or equal to*  `target`. If there is no such subarray, return `0` instead.

 

 **Example 1:** 

```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

```

 **Example 2:** 

```
Input: target = 4, nums = [1,4,4]
Output: 1

```

 **Example 3:** 

```
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

```

 

 **Constraints:** 

- 1 <= target <= 109
- 1 <= nums.length <= 105
- 1 <= nums[i] <= 104

 

 **Follow up:**  If you have figured out the `O(n)` solution, try coding another solution of which the time complexity is `O(n log(n))`.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 41.8 MB (beats 93.89%)  
**Submitted:** 2026-11-03T20:57:15.319Z  

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0 , i = 0 , n = nums.size() , sum = 0 , ans = INT_MAX ;
        while(j<n){
            sum += nums[j];
            while(sum >= target){
                sum -= nums[i];
                ans = min(ans , j - i + 1 ) ; 
                i++;

            }
        j++;
        }
    return ans == INT_MAX ? 0 : ans ;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-size-subarray-sum/)