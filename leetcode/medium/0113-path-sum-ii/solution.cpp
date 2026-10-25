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
    vector<int> currentPath;
    vector<vector<int>>ans;
public:
   void dfs(TreeNode* root, int targetSum, vector<int>& currentPath,vector<vector<int>>& ans){
    if (root == NULL) return;
    currentPath.push_back(root->val);
   if (root->left == NULL && root->right == NULL  ) {
    if (root->val == targetSum) 
 ans.push_back(currentPath);
   }
   dfs(root->left,targetSum-root->val,currentPath,ans);
    dfs(root->right,targetSum-root->val,currentPath,ans);
 
  currentPath.pop_back();
   }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return {};
      dfs(root,targetSum,currentPath,ans);
      return ans;
    }
};