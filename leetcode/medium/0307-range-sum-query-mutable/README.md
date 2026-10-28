# Range Sum Query - Mutable

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array `nums`, handle multiple queries of the following types:

- Update the value of an element in nums.
- Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

Implement the `NumArray` class:

- NumArray(int[] nums) Initializes the object with the integer array nums.
- void update(int index, int val) Updates the value of nums[index] to be val.
- int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] +... + nums[right]).

 

 **Example 1:** 

```
Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8

```

 

 **Constraints:** 

- 1 <= nums.length <= 3 * 104
- -100 <= nums[i] <= 100
- 0 <= index < nums.length
- -100 <= val <= 100
- 0 <= left <= right < nums.length
- At most 3 * 104 calls will be made to update and sumRange.

## Solution

**Language:** C++  
**Runtime:** 226 ms (beats 7.93%)  
**Memory:** 183.3 MB (beats 13.06%)  
**Submitted:** 2026-10-28T18:23:59.886Z  

```cpp
class NumArray {
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

    void updatetree(int ind, int low, int high, int pos, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (pos <= mid) {
            updatetree(2 * ind + 1, low, mid, pos, val);
        } else {
            updatetree(2 * ind + 2, mid + 1, high, pos, val);
        }
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

public:
    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        if (n > 0) {
            seg.resize(4 * n);
            build(0, 0, n - 1);
        }
    }

    void update(int index, int val) {
        arr[index] = val;
        updatetree(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
```

---

[View on LeetCode](https://leetcode.com/problems/range-sum-query-mutable/)