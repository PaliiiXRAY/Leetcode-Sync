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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
          if (root == NULL) return {};
        queue <TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector <int> level;
            for (int i = 0; i<size; i++){
                TreeNode* root = q.front();
                q.pop();
                level.push_back(root -> val);
                if(root->left != NULL) q.push(root->left);
                if(root -> right != NULL) q.push(root->right);
            }
             ans.push_back(level);
        }
        for (int i = 0; i< ans.size();i++){
           double sum = 0;
           for (int j = 0; j < ans[i].size();j++){
            sum += ans[i][j];
           }
           double levelAvg = sum / ans[i].size();
           avg.push_back(levelAvg);
        }
        
        return avg;
    }
};