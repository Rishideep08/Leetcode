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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        while(root!=NULL || !s.empty()){
            if(root!=NULL){
                s.push(root);
                root = root->left;
            }else{
                TreeNode* temp = s.top();
                s.pop();
                ans.push_back(temp->val);
                root = temp->right;
            }
            
        }
        
        return ans;
        
    }
};