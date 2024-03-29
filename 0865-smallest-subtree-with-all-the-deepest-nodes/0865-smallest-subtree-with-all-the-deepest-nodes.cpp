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
    pair<TreeNode*,int> helper(TreeNode* root){
        if(root == NULL){
            return {root,NULL};
        }
        
        pair<TreeNode*,int> l =  helper(root->left);
        pair<TreeNode*,int> r =  helper(root->right);
        
        if(l.second == r.second){
            return {root,l.second+1};
        }
        
        if(l.second>r.second){
            return {l.first,l.second+1};
        }
        
        return {r.first,r.second+1};
        
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root).first;
    }
};