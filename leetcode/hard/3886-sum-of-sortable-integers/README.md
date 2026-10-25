# Sum of Sortable Integers

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` of length `n`.

An integer `k` is called  **sortable**  if `k`  **divides**  `n` and you can sort `nums` in  **non-decreasing**  order by sequentially performing the following operations:

- Partition nums into consecutive subarrays of length k.
- Cyclically rotate each subarray independently any number of times to the left or to the right.

Return an integer denoting the sum of all possible sortable integers `k`.

 

 **Example 1:** 

 **Input:**  nums = [3,1,2]

 **Output:**  3

 **Explanation:** ​​​​​​​

- For n = 3, possible divisors are 1 and 3.
- For k = 1: each subarray has one element. No rotation can sort the array.
- For k = 3: the single subarray [3, 1, 2] can be rotated once to produce [1, 2, 3], which is sorted.
- Only k = 3 is sortable. Hence, the answer is 3.

 **Example 2:** 

 **Input:**  nums = [7,6,5]

 **Output:**  0

 **Explanation:** 

- For n = 3, possible divisors are 1 and 3.
- For k = 1: each subarray has one element. No rotation can sort the array.
- For k = 3: the single subarray [7, 6, 5] cannot be rotated into non-decreasing order.
- No k is sortable. Hence, the answer is 0.

 **Example 3:** 

 **Input:**  nums = [5,8]

 **Output:**  3

 **Explanation:** ​​​​​​​

- For n = 2, possible divisors are 1 and 2.
- Since [5, 8] is already sorted, every divisor is sortable. Hence, the answer is 1 + 2 = 3.

 

 **Constraints:** 

- 1 <= n == nums.length <= 105
- 1 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 177 ms (beats 40.00%)  
**Memory:** 92.6 MB (beats 46.67%)  
**Submitted:** 2026-10-20T21:30:52.096Z  

```cpp
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        vector<int> divs;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divs.push_back(i);
                if (i != n / i) divs.push_back(n / i);
            }
        }
        int ans = 0;
        for (int k : divs) {
            bool ok = true;
            for (int s = 0; s < n && ok; s += k) {
                int desc = 0, pos = -1;
                for (int j = 0; j < k; j++) {
                    int a = nums[s + j];
                    int b = nums[s + (j + 1) % k];
                    if (a > b) {
                        desc++;
                        pos = j;
                        if (desc > 1) break;
                    }
                }
                if (desc > 1) {
                    ok = false;
                    break;
                }
                int r = (desc == 0) ? 0 : (pos + 1) % k;
                for (int j = 0; j < k; j++) {
                    if (nums[s + (r + j) % k] != sorted[s + j]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) ans += k;
        }
        return ans;
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/sum-of-sortable-integers/)