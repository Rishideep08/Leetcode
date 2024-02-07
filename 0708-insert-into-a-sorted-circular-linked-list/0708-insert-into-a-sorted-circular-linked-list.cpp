/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* curr = head;
        Node* node = new Node(insertVal);
        if(head == NULL){
            node->next = node;
            return node;
        }
        if(head == head->next){
            head->next = node;
            node->next = head;
            return head;
        }
        Node* tail= curr;
        if(curr->val<=insertVal && insertVal<=curr->next->val){
            node->next = curr->next;
            curr->next = node;
            return head;
        }
        if(curr->val>curr->next->val){
                tail = curr;
            }
        curr = curr->next;
        while(curr!=head){
            if(curr->val<=insertVal && insertVal<=curr->next->val){
                node->next = curr->next;
                curr->next = node;
                return head;
            }
            if(curr->val>curr->next->val){
                tail = curr;
            }
            curr = curr->next;
        }
        node->next = tail->next;
        tail->next= node;
        return head;
        
        
        
    }
};