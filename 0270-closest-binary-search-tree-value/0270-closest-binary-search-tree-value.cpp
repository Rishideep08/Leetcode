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
    int lb = INT_MIN;
    int ub = INT_MAX;
    
    void helper(TreeNode* root, double target){
        if(root == NULL){
            return;
        }
        
        helper(root->left,target);
        
        if(root->val == target){
            lb = root->val;
            ub = root->val;
        }else if(root->val>target){
            ub = min(ub,root->val);
        }else{
            lb = max(lb,root->val);
        }
        helper(root->right,target);
    }
    
    int closestValue(TreeNode* root, double target) {
        helper(root,target);
        
        if(lb == INT_MIN && ub == INT_MAX){
            return -1;
        }
        
        if(lb == INT_MIN){
            return ub;
        }
        
        if(ub == INT_MAX){
            return lb;
        }
        
        if(target-lb>ub-target){
            return ub;
        }
        return lb;
    }
    
};