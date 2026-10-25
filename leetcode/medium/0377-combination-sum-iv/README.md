# Combination Sum IV

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of  **distinct**  integers `nums` and a target integer `target`, return  *the number of possible combinations that add up to*  `target`.

The test cases are generated so that the answer can fit in a  **32-bit**  integer.

 

 **Example 1:** 

```
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

```

 **Example 2:** 

```
Input: nums = [9], target = 3
Output: 0

```

 

 **Constraints:** 

- 1 <= nums.length <= 200
- 1 <= nums[i] <= 1000
- All the elements of nums are unique.
- 1 <= target <= 1000

 

 **Follow up:**  What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.3 MB (beats 55.79%)  
**Submitted:** 2026-10-02T20:07:21.362Z  

```cpp
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // Step 1: Use unsigned int to dodge the signed overflow trap
        vector<unsigned int> dp(target + 1, 0);
        
        // Base case: 1 way to make amount 0
        dp[0] = 1;
        
        // Step 2: Amount loop on the OUTSIDE (Permutations logic)
        for (int i = 1; i <= target; i++) {
            
            // Step 3: Coin loop on the INSIDE
            for (int num : nums) {
                // If the coin can physically fit into the current amount
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/combination-sum-iv/)