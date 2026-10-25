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