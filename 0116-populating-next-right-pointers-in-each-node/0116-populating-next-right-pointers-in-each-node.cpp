/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void doBFS(Node* root){
        if(root == NULL){
            return;
        }
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size){
                Node* temp = q.front();
                q.pop();
                if(temp->left!=NULL){
                    temp->left->next = temp->right;
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    if(size>1){
                        temp->right->next = q.front()->left;
                    }else{
                        temp->right->next = NULL;
                    }
                    q.push(temp->right);
                }
                size--;
            }
        }
    }
    
    
    Node* connect(Node* root) {
        doBFS(root);
        return root;
    }
};