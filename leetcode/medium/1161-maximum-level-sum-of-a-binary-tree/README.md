# Maximum Level Sum of a Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary tree, the level of its root is `1`, the level of its children is `2`, and so on.

Return the  **smallest**  level `x` such that the sum of all the values of nodes at level `x` is  **maximal**.

 

 **Example 1:** 

```
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

```

 **Example 2:** 

```
Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [1, 104].
- -105 <= Node.val <= 105

## Solution

**Language:** C++  
**Runtime:** 9 ms (beats 14.00%)  
**Memory:** 113.2 MB (beats 5.78%)  
**Submitted:** 2026-10-06T06:52:21.055Z  

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxi = INT_MIN;
      int lvl = 1;
      int ans = 0;
        while(!q.empty()){
            int size = q.size();
          vector<int>level;
          for (int i = 0; i < size; i++){
            TreeNode* front = q.front();
            q.pop();
            level.push_back(front->val);
            
            if(front->left ) q.push(front->left);
            if(front-> right) q.push(front->right);
            
          }  int sum = 0;
          for (int j : level) sum += j;
            // maxi = max(maxi,sum);
           if(maxi < sum){
             maxi =  sum; 
             ans = lvl;
          }lvl++;
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)