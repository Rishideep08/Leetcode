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
    long long int ans;
    unordered_map<long long int,long long int> um;
    
    void func(TreeNode* root,long long int sum,int targetSum){
        if(root == NULL){
            return;
        }
        
        sum = sum + root->val;
        
        if(um.find(sum-targetSum) != um.end()){
            ans = ans + um[sum-targetSum];
            // cout<<ans<<" "<<sum-targetSum;
        }
        
        um[sum]++;
        
        func(root->left,sum,targetSum);
        func(root->right,sum,targetSum);
        um[sum]--;
        if(um[sum] == 0){
            um.erase(sum);
        }
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return 0;
        um[0]= 1;
        func(root,0,targetSum);
        return ans;
    }
};