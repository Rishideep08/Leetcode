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
    vector<vector<int>> ans;
    void doDfs(TreeNode* root,TreeNode* parent,vector<int>&temp){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            if(parent->left == root){
                parent->left = NULL;
            }else{
                parent->right = NULL;
            }
            temp.push_back(root->val);
            return;
        }
        
        doDfs(root->left,root,temp);
        doDfs(root->right,root,temp);
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(root == NULL){
            return ans;
        }

        
        while(!(root->left == NULL && root->right == NULL)){
            vector<int> temp;
            doDfs(root,NULL,temp);
            ans.push_back(temp);
        }
        
        if(root->left == NULL && root->right == NULL){
            vector<int> temp;
            temp.push_back(root->val);
            ans.push_back(temp);
        }
        
        return ans;

        
    }
};