/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> res;
    
    void doBfs(TreeNode* root,int k){
        if(root == NULL){
            return;
        }
        // cout<<" ris "<<endl;
        // cout<<root->val<<endl;
        // cout<<" ---- "<<endl;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size>0){
                TreeNode* temp = q.front();
                q.pop();
                if(level == k){
                    // cout<<"Hi "<<root->val<<endl;
                    res.push_back(temp->val);
                }
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                size--;
            }
            level++;
        }
    }
    
    int depth(TreeNode* root, TreeNode* target, int k){
        if(root == NULL){
            return -1;
        }
        
        if(root == target){
            return 0;
        }
        
        int la = depth(root->left,target,k);
        int ra = -1;
        if(la != -1){
            la++;
            int lb = k-la-1;
            if(lb == -1){
                res.push_back(root->val);
            }
            if(lb>=0){
                // cout<<root->val<<" "<<la<< " "<<lb <<endl;
                doBfs(root->right,lb);
            }
        }else{
            ra = depth(root->right,target,k);
            if(ra == -1){
                return -1;
            }
            // cout<<root->val<< " adbb "<<ra<<endl;
            ra++;
            int rb = k-ra-1;
            if(rb == -1){
                res.push_back(root->val);
            }
            if(rb>=0){
                // cout<<root->val<<" "<<ra<< " "<<rb <<endl;
                doBfs(root->left,rb);
            }
        }
        
        if(la == -1 && ra == -1){
            return -1;
        }
        
        if(la!=-1){
            return la;
        }
        
        return ra;
        
        
        
    }
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL){
            return res;
        }
        doBfs(target,k);
        depth(root,target,k);
        
        return res;
    }
};