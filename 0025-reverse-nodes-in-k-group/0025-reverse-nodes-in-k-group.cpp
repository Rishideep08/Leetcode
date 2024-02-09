/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    pair<ListNode*,ListNode*> reverse(ListNode* head,ListNode* tail){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        
        while(curr!=tail){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return {prev,head};
    }
      
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail = head;
        int k1 = k;
        while(k1>0 && tail!=NULL){
            tail = tail->next;
            k1--;
        }
    
        
        if(k1>0 && (tail == NULL)){
            return head;
        }
        
        pair<ListNode*,ListNode*> temp = reverse(head,tail);
        // cout<<temp.first->val<<" "<<temp.second->val<<endl;
        temp.second->next = reverseKGroup(tail,k);
        return temp.first;
    }
};