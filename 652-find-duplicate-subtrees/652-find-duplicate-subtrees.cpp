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
    unordered_map<string,int> um,um1;
    vector<TreeNode*> ans;
    int count = 1;
    
    int func(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        string val = "("+to_string(func(root->left))+")"+to_string(root->val)+"("+to_string(func(root->right))+")";
        um[val]++;
        if(um[val] == 2){
            ans.push_back(root);
        }
        if(um1.find(val) == um1.end()){
            um1[val] = count;
            count++;
        }
        return um1[val];
    }
    
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        func(root);
        return ans;
        
    }
};