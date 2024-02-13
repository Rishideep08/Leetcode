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
    int ans =0;
    void helper(TreeNode* root,int parent){    
    
        parent = parent*10+(root->val);
        if(root->left){
            helper(root->left,parent);
        }
        if(root->right){
            helper(root->right,parent);
        }
        
        if(root->left == NULL && root->right == NULL){
            ans = ans + parent;
        }
        
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        helper(root,0);
        return ans;
    }
};