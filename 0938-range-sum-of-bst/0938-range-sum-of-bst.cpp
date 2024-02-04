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
    int rangeSumBST(TreeNode* root, int l, int h) {
        stack<TreeNode*> s;
        int ans =0;
        while(!s.empty() || root){
            while(root!=NULL && root->val>=l){
                s.push(root);
                root = root->left;
            }
            if(root!=NULL){
                s.push(root);
            }

            TreeNode* curr = s.top();
            s.pop();
            if(curr->val >=l && curr->val <=h){
                ans = ans + curr->val;
            }
            if(curr->val<=h){
                root= curr->right;
            }else{
                root = NULL;
            }
        }
        return ans;
    }
};