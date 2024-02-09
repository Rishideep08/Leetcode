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
    int ans = 0;
    
    vector<int> helper(TreeNode* root){        
        vector<int> l;
        vector<int> r;
        if(root == NULL){
            return vector<int>{1,INT_MAX,INT_MIN,0};
        }
        if(root->left == NULL && root->right==NULL){
            ans = max(ans,1);
            return vector<int>{1,root->val,root->val,1};
        }
        if(root->left == NULL || root->right == NULL){
            if(root->left == NULL){
                r = helper(root->right);
                if(r[0] == 0){
                    return vector<int>{0,INT_MAX,INT_MIN,0};
                }
                if(root->val < r[1]){
                    ans = max(ans,r[3]+1);
                    return vector<int>{1,root->val,r[2],r[3]+1};
                }
                
                return vector<int>{0,INT_MAX,INT_MIN,0};
            }else{
                l = helper(root->left);
                if(l[0] == 0){
                    return vector<int>{0,INT_MAX,INT_MIN,0};
                }
                if(root->val > l[2]){
                    ans = max(ans,l[3]+1);
                    return vector<int>{1,l[1],root->val,l[3]+1};
                }
                
                return vector<int>{0,INT_MAX,INT_MIN,0};
            }
        }
        
        r = helper(root->right);
        l = helper(root->left);
        if(l[0] == 0 || r[0]==0){
            return vector<int>{0,INT_MAX,INT_MIN,0};
        }
        
        if(root->val>l[2] && root->val<r[1]){
            ans = max(ans,l[3]+r[3]+1);
            return vector<int>{1,l[1],r[2],l[3]+r[3]+1};
        }
        return vector<int>{0,INT_MAX,INT_MIN,0};
    }
    
    int largestBSTSubtree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        helper(root);
        return ans;
    }
};