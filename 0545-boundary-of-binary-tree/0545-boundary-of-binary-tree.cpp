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
     void getTheLeft(TreeNode* root,vector<int> &left){
        if(root == NULL){
            return;
        }
         if(root->left == NULL && root->right == NULL){
             return;
         }
         left.push_back(root->val);
         if(root->left){
            getTheLeft(root->left,left);
             return;
         }
         getTheLeft(root->right,left);
         return;
    }
    
    void getTheRight(TreeNode* root,vector<int> &right){
        if(root == NULL){
            return;
        }
         if(root->left == NULL && root->right == NULL){
             return;
         }
         right.push_back(root->val);
         if(root->right){
            getTheRight(root->right,right);
             return;
         }
         getTheRight(root->left,right);
         return;
    }
    
    void getTheLeaves(TreeNode* root,vector<int> &leaves){
        if(root == NULL){
            return;
        }
         if(root->left == NULL && root->right == NULL){
             leaves.push_back(root->val);
             return;
         }
         getTheLeaves(root->left,leaves);
         getTheLeaves(root->right,leaves);
         return;
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> left;
        if(root == NULL){
            return left;
        }
        left.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            return left;
        }
        
        getTheLeft(root->left,left);
        vector<int> leaves;
        getTheLeaves(root,leaves);
        vector<int> right;
        getTheRight(root->right,right);
        
        reverse(right.begin(),right.end());
        for(int i=0;i<leaves.size();i++){
            left.push_back(leaves[i]);
        }
        for(int i=0;i<right.size();i++){
            left.push_back(right[i]);
        }
        return left;
    }
};