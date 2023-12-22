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
    int ans;
    
    pair<bool,vector<int>> helper(TreeNode *root){
        if(root == NULL){
            return {true,{INT_MAX,INT_MIN,0}};
        }
        pair<bool,vector<int>> l = helper(root->left);
        pair<bool,vector<int>> r = helper(root->right);
        
        if(l.first == true && r.first == true){
            int x = l.second[1];
            int y = r.second[0];
            int x1 = l.second[0];
            int y1 = r.second[1];
            if(x< root->val && y >root->val){
                if(x == INT_MIN){
                    x = root->val;
                    x1 = root->val;
                }
                if(y == INT_MAX){
                    y = root->val;
                    y1 = root->val;
                }
                ans = max(ans,l.second[2]+r.second[2]+1);
                return {true,{x1,y1,l.second[2]+r.second[2]+1}};
            }
            return {false,{x,y,0}};
        }
        
        return {false,{-1,-1,0}};
    }
    
    int largestBSTSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};