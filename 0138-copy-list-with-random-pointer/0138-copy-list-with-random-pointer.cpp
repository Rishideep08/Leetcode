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
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> um;
        Node* head1 = head;
        while(head){
            Node* temp = new Node(head->val);
            um[head] = temp;
            head = head->next;
        }
        head = head1;
        while(head){
            Node* temp= um[head];
            if(head->next != NULL){
                Node* newNext = um[head->next];
                temp->next =newNext;
            }
            if(head->random != NULL){
                Node* newRandom = um[head->random];
                temp->random = newRandom;
            }
            head = head->next;
        }
        
        return um[head1];
        
    }
};