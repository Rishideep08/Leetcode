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
    TreeNode* str2tree(string s) {
        if(s.size()==0){
            return NULL;
        }
        TreeNode* curr = new TreeNode();
        stack<TreeNode*> st;
        int flag = 0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                if(flag == 0){
                     curr->val = curr->val*10+(s[i]-'0');
                }else{
                     curr->val = curr->val*10-(s[i]-'0');
                }
              
            }else if(s[i]=='-'){
                flag = 1;
            }else{
                if(s[i] == '('){
                    st.push(curr);
                    curr = new TreeNode();
                    flag = 0;
                }else{
                    TreeNode* parent = st.top();
                    st.pop();
                    
                    if(parent->left == NULL){
                        parent->left = curr;
                    }else{
                        parent->right = curr;
                    }
                    
                    curr = parent;
                }
            }
        }
        return curr;
    }
};