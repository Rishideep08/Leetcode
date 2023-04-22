/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // cout<<"Hi"<<endl;
        if(head == NULL || head->next ==NULL){
            return NULL;
        }
        // ListNode* head1 = head;
        // while(head != NULL){
        //     cout<<head->val<<endl;
        //     head = head->next;
        // }
        // cout<<"HI"<<endl;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(slow != fast && fast!=NULL && fast->next!=NULL ){
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(slow != fast){
            return NULL;
        }
    
        slow = head;
        fast = fast->next;

        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};