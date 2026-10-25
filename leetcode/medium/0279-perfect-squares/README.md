# Perfect Squares

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer `n`, return  *the least number of perfect square numbers that sum to*  `n`.

A  **perfect square**  is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, `1`, `4`, `9`, and `16` are perfect squares while `3` and `11` are not.

 

 **Example 1:** 

```
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

```

 **Example 2:** 

```
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

```

 

 **Constraints:** 

- 1 <= n <= 104

## Solution

**Language:** C++  
**Runtime:** 40 ms (beats 77.02%)  
**Memory:** 13 MB (beats 90.25%)  
**Submitted:** 2026-10-03T06:26:37.544Z  

```cpp
class Solution {
public:
    int numSquares(int n) {
        //we need minimum count, so init with the max imp value n+1
        vector<int>dp(n+1,n+1);
        //takes 0 squares to make the sum 0
        dp[0] = 0;
        for (int i = 1; i<=n; i++){
            for (int j = 1; j*j <= i; j++){
                int square = j*j;
                dp[i] = min(dp[i],dp[i-square] + 1);
            } 
        }
        return dp[n];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/perfect-squares/)