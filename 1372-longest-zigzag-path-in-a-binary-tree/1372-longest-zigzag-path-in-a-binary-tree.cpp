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
    int maxVal = 0;
    
    pair<int,int> func(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }
        
        pair<int,int> l = func(root->left);
        pair<int,int> r = func(root->right);
        
        int left_val = l.second+1;
        int right_val = r.first+1;
        
        maxVal = max(max(maxVal,left_val),right_val);
        
        return {left_val,right_val};
    }
    
    
    
    int longestZigZag(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        func(root);
        
        return maxVal-1;
        
    }
};