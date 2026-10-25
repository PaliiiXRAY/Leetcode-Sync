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
int countLeft(TreeNode* root){
      if(root==nullptr){
            return 0;
        }
        int height=1;
        while(root->left!=nullptr){
            height++;
            root= root->left;
        }
        return height;
    }
    int countRight(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int height=1;
        while(root->right!=nullptr){
            height++;
            root= root->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftheight= countLeft(root);
        int rightheight= countRight(root);
        if (leftheight == rightheight) return pow(2,leftheight) - 1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};