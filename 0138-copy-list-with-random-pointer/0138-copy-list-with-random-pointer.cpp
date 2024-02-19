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
    Node* createNode(Node* node){
        return new Node(node->val);
    }
    
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }
        Node* curr = head;
        while(head){
            Node* copy = new Node(head->val);
            Node* next = head->next;
            head->next=copy;
            copy->next = next;
            head = next;
        }
        
        head = curr;
        while(head){
            Node* random = head->random;
            if(random != NULL)
                head->next->random = random->next;
            head = head->next->next;
        }
        
        head = curr;
        Node* ans = head->next;
        Node* temp = ans;
         while(head){
            head->next = ans->next;
             head = head->next;
            if(head != NULL){
                ans->next = head->next;
            }else{
                ans->next = NULL;
            }
             ans = ans->next;
        }
        
        return temp;
        
        
        
    }
};