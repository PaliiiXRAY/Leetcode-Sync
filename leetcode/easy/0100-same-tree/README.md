# Same Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

 **Example 1:** 

```
Input: p = [1,2,3], q = [1,2,3]
Output: true

```

 **Example 2:** 

```
Input: p = [1,2], q = [1,null,2]
Output: false

```

 **Example 3:** 

```
Input: p = [1,2,1], q = [1,1,2]
Output: false

```

 

 **Constraints:** 

- The number of nodes in both trees is in the range [0, 100].
- -104 <= Node.val <= 104

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 12.9 MB (beats 12.51%)  
**Submitted:** 2026-10-06T19:51:39.214Z  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
       
        if (p !=  NULL && q == NULL) return false;
        if (p == NULL && q !=  NULL) return false;
        if( p->val != q->val) return false;
        if(!isSameTree(p->left,q->left)) return false;
        if(!isSameTree(p->right,q->right)) return false;
        return true;
    }

};
```

---

[View on LeetCode](https://leetcode.com/problems/same-tree/)