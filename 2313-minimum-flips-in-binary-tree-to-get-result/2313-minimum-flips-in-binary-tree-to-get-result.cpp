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
    unordered_map<int,int> um;
    int minimumFlips(TreeNode* root, bool result) {
        // pair<TreeNode*,int> temp = {root,result};
        // string temp = to_string(((unsigned long long int)root));
        // temp+=":";
        // temp+=to_string(result);
        int temp = (unsigned long long int)root | result;
        if(um.find(temp) != um.end() ){
            return um[temp];
        }
        int ans = 0;
        if(root == NULL){
            ans = 0;
        }
        
        if(root->left == NULL && root->right==NULL){
            if((result^(root->val)) == 0){
                ans =  0;
            }else{
                ans =  1;
            }
            um[temp] = ans;
            return ans;
        }
        
        if(root->left == NULL){
            result = result == 1?0:1;
            ans = minimumFlips(root->right,result);
            um[temp] = ans;
            return ans;
        }else if(root->right == NULL){
             result = result == 1?0:1;
            ans = minimumFlips(root->left,result);
            um[temp]= ans;
            return ans;
        }
        
        int x = minimumFlips(root->right,1);
        int y = minimumFlips(root->left,1);
        int z = minimumFlips(root->right,0);
        int w = minimumFlips(root->left,0);
        
        if(root->val == 2){
            if(result == 1){
                ans = min(x+min(y,w),z+y);
            }else{
                ans =  z+w;
            }
        }
        
        if(root->val == 3){
            if(result == 1){
                ans =  x+y;
            }else{
                ans =  min(z+min(y,w),x+w);
            }
        }
        
        if(root->val == 4){
            if(result == 1){
                ans =  min(x+w,y+z);
            }else{
                ans =  min(x+y,z+w);
            }
        }
        um[temp] = ans;
        return ans ;
    }
};