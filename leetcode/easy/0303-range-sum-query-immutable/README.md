# Range Sum Query - Immutable

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer array `nums`, handle multiple queries of the following type:

- Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

Implement the `NumArray` class:

- NumArray(int[] nums) Initializes the object with the integer array nums.
- int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] +... + nums[right]).

 

 **Example 1:** 

```
Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

```

 

 **Constraints:** 

- 1 <= nums.length <= 104
- -105 <= nums[i] <= 105
- 0 <= left <= right < nums.length
- At most 104 calls will be made to sumRange.

## Solution

**Language:** C++  
**Runtime:** 10 ms (beats 17.08%)  
**Memory:** 24.4 MB (beats 21.95%)  
**Submitted:** 2026-10-28T18:24:45.358Z  

```cpp
class NumArray {
public:
    //used the build and query function as same as from leetcode 307
    vector<int> arr;
    vector<int> seg;
    int n;
    void build(int ind, int low, int high) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid + 1, high);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r) {
        // completely overlap
        if (low >= l and high <= r) {
            return seg[ind];
        }
        // completely outside
        if (high < l or low > r)
            return 0;
        // partial overlap
        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
    NumArray(vector<int>& nums) {
        arr= nums;
        n= nums.size();
        if(n>0){
            seg.resize(4*n);
            build(0,0, n-1);
        }
    }
    
    int sumRange(int left, int right) {
        return query(0,0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
```

---

[View on LeetCode](https://leetcode.com/problems/range-sum-query-immutable/)