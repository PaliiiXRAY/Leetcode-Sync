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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return{};
        queue <TreeNode*> q;
        vector<vector<int>>ans;
       q.push(root);
       while (!q.empty()){
        int size = q.size();
        vector <int> level;
      
        for (int i = 0; i<size; i++){
            TreeNode* root = q.front();
            q.pop();
            level.push_back(root -> val);
            if (root -> left != NULL) q.push(root->left);
            if (root -> right != NULL) q.push(root->right);
        }
        ans.push_back(level);
       }
        for (int i = 1; i < ans.size(); i += 2) {
            reverse(ans[i].begin(), ans[i].end());
        }
       
       return ans;
    }
};