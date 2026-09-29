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
    int checkbalancedTree(TreeNode * root, bool &ans){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        int left = checkbalancedTree(root->left, ans);
        int right = checkbalancedTree(root->right, ans);
        if(abs(left - right) > 1){
            ans = false;
        }
        int height;
        if(left > right){
            height = left + 1;
        }
        else{
            height = right + 1;
        }
        return height;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        checkbalancedTree(root, ans);
        return ans;
    }
};
