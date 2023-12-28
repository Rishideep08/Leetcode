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
    ListNode* merge(ListNode* l,ListNode* r){
        if(l == NULL){
            return r;
        }
        if(r == NULL){
            return l;
        }
        if(l->val > r->val){
            r->next = merge(l,r->next);
            return r;
        }        
        l->next = merge(l->next,r);
        return l;
    }
    ListNode* func(vector<ListNode*>& lists,int l,int r){
        if(l==r){
            return lists[l];
        }
        if(l<r){
            int m = l+(r-l)/2;
            ListNode* l1 = func(lists,l,m);
            ListNode* r1 = func(lists,m+1,r);
            ListNode* ans = merge(l1,r1);
            // cout<<ans->val<<endl;
            return ans;
        }
        return NULL;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return func(lists,0,lists.size()-1);
    }
};