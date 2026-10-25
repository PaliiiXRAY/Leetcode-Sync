# Diameter of Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `root` of a binary tree, return  *the length of the  **diameter**  of the tree*.

The  **diameter**  of a binary tree is the  **length**  of the longest path between any two nodes in a tree. This path may or may not pass through the `root`.

The  **length**  of a path between two nodes is represented by the number of edges between them.

 

 **Example 1:** 

```
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

```

 **Example 2:** 

```
Input: root = [1,2]
Output: 1

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [1, 104].
- -100 <= Node.val <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 23.7 MB (beats 41.14%)  
**Submitted:** 2026-10-05T20:46:57.735Z  

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
  int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        findiameter(root);
        return diameter;
    }
    int findiameter(TreeNode* root){
        if(root == NULL) return 0;
        int left = findiameter(root->left);
        int right = findiameter(root->right);
        int dia = left + right;
        diameter = max(dia, diameter);
        return max(left,right) + 1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/diameter-of-binary-tree/)