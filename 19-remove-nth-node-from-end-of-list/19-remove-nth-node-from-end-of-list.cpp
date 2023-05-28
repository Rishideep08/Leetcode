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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        ListNode* start = head;
        ListNode* end = head;
        
        while(end->next!=NULL){
            if(n==0){
                start = start->next;
            }else{
                n--; 
            }
            end = end->next;
        }
        
        if(n==0){
            start->next = start->next->next;
        }else if(n==1){
            return head->next;
        }
        return head;
    }
};