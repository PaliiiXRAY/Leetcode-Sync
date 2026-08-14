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
    TreeNode* reverseOddLevels(TreeNode* root) {
           if (root == NULL) return {};
           int level = 0;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector <TreeNode*> current_level;
            for (int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                current_level.push_back(node);
                if(node->left != NULL) q.push(node->left);
                if(node -> right != NULL) q.push(node->right);
            }
             if (level % 2 ==  1){
                int left = 0;
                int right = current_level.size() - 1;
               while (left < right){
                swap(current_level[left]->val, current_level[right]->val);
                    left++;
                    right--;
               }
             }
             level++;
        }
        return root;
    }
};