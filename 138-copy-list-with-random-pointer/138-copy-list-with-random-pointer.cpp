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
        
        unordered_map<int,int> um;
        unordered_map<Node*,int> um1;
        unordered_map<int,Node*> um2;
        int i=0;
        Node* temp = head;
        while(temp){
            um1[temp] = i;
            temp = temp->next;
            i++;
        }
        
        temp =head;
        i=0;
        
        while(temp){
            int getRandomIndex = -1;
            if(temp->random!=NULL){
                getRandomIndex = um1[temp->random];     
            }
            um[i] = getRandomIndex;
            Node* newTemp = new Node(temp->val);
            um2[i] = newTemp;
            temp = temp->next;
            i++;
        }
        
        temp = head;
        i=0;
        Node* newHead = NULL;
        while(temp){
            int randomIndex = um[i];
            Node* node = um2[i];
            if(temp->next!=NULL){
                node->next = um2[i+1];
            }
            if(randomIndex != -1){
                node->random = um2[randomIndex];
            }
            if(newHead == NULL){
                newHead = node;
            }
            temp = temp->next;
            i++;
        }
        return newHead;
        
    }
};