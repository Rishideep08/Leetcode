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
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        unordered_map<int,vector<int>> um;
        um[0].push_back(root->val);
        int minVal = 0;
        while(!q.empty()){
            int size = q.size();
            while(size){
                pair<TreeNode*,int> temp = q.front();
                q.pop();
                
                if(temp.first->left){
                    q.push({temp.first->left,temp.second-1});
                    um[temp.second-1].push_back(temp.first->left->val);
                    minVal = min(minVal,temp.second-1);
                }
                
                if(temp.first->right){
                    q.push({temp.first->right,temp.second+1});
                    um[temp.second+1].push_back(temp.first->right->val);
                }
                
                size--;
            }
        }
        
        while(um.size()>0){
            ans.push_back(um[minVal]);
            um.erase(minVal);
            minVal++;
        }
        
        return ans;
        
        
    }
};