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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return nullptr;
        
        ListNode *dummy = new ListNode(0);
        
        ListNode *p = dummy;
        
        while(head) {
            int c = 0;
            while(head->next && head->next->val == head->val) {
                head = head->next;
                c++;
            }
            if(c==0) {
                p->next = head;
                p = p->next;
            } else {
                p->next = nullptr;
            }
            head = head->next;
        }
        
        return dummy->next;
    }
};
