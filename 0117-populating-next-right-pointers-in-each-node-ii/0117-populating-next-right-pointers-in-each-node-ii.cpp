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
    Node* helper(Node* curr){
        if(curr == NULL){
            return NULL;
        }
        
        Node* temp = helper(curr->next);
        if(curr->left == NULL && curr->right == NULL){
            return temp;
        }
        if(curr->left != NULL && curr->right !=NULL){
            curr->left->next=curr->right;
            curr->right->next = temp;
            return curr->left;
        }
        if(curr->left == NULL){
            curr->right->next = temp;
            return curr->right;
        }
        
        curr->left->next = temp;
        return curr->left;
        
        
    }
    
    Node* connect(Node* root) {
        Node* curr = root;
        while(curr){
            curr = helper(curr);
        }
        return root;
    }
};