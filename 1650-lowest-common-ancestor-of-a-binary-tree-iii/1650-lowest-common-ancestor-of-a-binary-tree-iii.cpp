/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    int helper(Node* p){
        int depth = 0;
        while(p!=NULL){
            p = p->parent;
            depth++;
        }
        
        return depth;
    }
    
    Node* helper1(int depth,Node* p){
        while(p!=NULL && depth>0){
            p = p->parent;
            depth--;
        }
        
        return p;
    }
    
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int x = helper(p);
        int y = helper(q);
        cout<<x<<" "<<y<<endl;
        if(x>y){
            p = helper1(x-y,p);
        }else{
            q = helper1(y-x,q);
        }
        
        while(p!=q){
            p = p->parent;
            q = q->parent;
        }
        return p;
    }
};