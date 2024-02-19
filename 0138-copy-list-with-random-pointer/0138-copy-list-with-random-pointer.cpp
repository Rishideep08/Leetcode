/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> um;
    
    Node* createCopy(Node* node){
        if(node == NULL){
            return NULL;
        }
        Node* newNode = new Node(node->val);
        um[node] = newNode;
        return um[node];
    }
    
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        if(um.find(head) != um.end()){
            return um[head];
        }
        Node* copyNode = createCopy(head);
        copyNode->next = copyRandomList(head->next);
        copyNode->random = copyRandomList(head->random);
        return copyNode;
    }
};