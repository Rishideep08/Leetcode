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
    vector<TreeNode*> helper(TreeNode* root){
        if(root == NULL){
            return {NULL,NULL};
        }
        
        vector<TreeNode*> l = helper(root->left);
        vector<TreeNode*> r = helper(root->right);
        
        root->left = NULL;
        if(l[0] != NULL){
            root->right = l[0];
            if(r[0]!=NULL){
                l[1]->right = r[0];
            }else{
                return {root,l[1]};
            }
        }else{
            root->right = r[0];
            if(r[0] == NULL){
                return {root,root};
            }
        }
        
        return {root,r[1]};
        
    }
    
    void flatten(TreeNode* root) {
        root = helper(root)[0];
        return;
    }
};