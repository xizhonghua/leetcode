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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(!l1 && !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        
        int j = 0;
        while(1)
        {
            int s = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + j;
            
            j = 0;
            
            if(s>=10) { s-=10; j=1; }
            
            head->next = new ListNode(s);
            
            head = head->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
            
            if(!l1 && !l2 && !j) break;
        }
        
        return dummy->next;
    }
};
