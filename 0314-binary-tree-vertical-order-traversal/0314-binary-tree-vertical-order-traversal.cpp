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
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        q.push({root,0});
        int colStart = 0;
        unordered_map<int,vector<int>> um;
        while(!q.empty()){
            int size = q.size();
            while(size){
                pair<TreeNode*,int> temp = q.front();
                q.pop();
                colStart = min(colStart,temp.second);
                um[temp.second].push_back(temp.first->val);
                
                if(temp.first->left!=NULL){
                    q.push({temp.first->left,temp.second-1});
                }
                
                if(temp.first->right!=NULL){
                    q.push({temp.first->right,temp.second+1});
                }
                
                
                size--;
            }
        }

        while(um.find(colStart)!=um.end()){
            ans.push_back(um[colStart]);
            um.erase(colStart);
            colStart++;
        }
        return ans;
    }
};