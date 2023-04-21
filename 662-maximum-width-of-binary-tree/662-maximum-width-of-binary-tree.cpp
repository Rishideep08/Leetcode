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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<pair<TreeNode*,unsigned long long  >> q;
        
        q.push({root,0});
        unsigned long long start = -1;
        unsigned long long  end = -1;
        unsigned long long  maxVal = 0;
        while(!q.empty()){
            unsigned long long  size = q.size();
            start = -1;
            end = -1;
            while(size){
                pair<TreeNode*,unsigned long long > temp = q.front();
                q.pop();
                
                if(start == -1){
                    start = temp.second;
                    end = temp.second;
                }else{
                    end = temp.second;
                }
                
                // cout<<temp.second<<endl;
                
                if(temp.first->left){
                    q.push({temp.first->left,2*temp.second});
                }
                
                if(temp.first->right){
                    q.push({temp.first->right,2*temp.second+1});
                }
                size--;
            }
            maxVal = max(maxVal,end-start+1);
        }
        return maxVal;
        
    }
};