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
    ListNode *partition(ListNode *head, int x) {
        ListNode* l = new ListNode(0);
        ListNode* r = new ListNode(0);
        
        auto head_l = l;
        auto head_r = r;
        
        while(head)
        {
            if(head->val < x)
            {
                head_l->next = new ListNode(head->val);
                head_l = head_l->next;
            }
            else
            {
                head_r->next = new ListNode(head->val);
                head_r = head_r->next;
            }
            
            head = head->next;
        }
        
        if(l->next && r->next)
        {
            head_l->next = r->next;
            return l->next;
        }
        if(l->next && !r->next)
        {
            return l->next;
        }
        if(r->next && !l->next)
        {
            return r->next;
        }
        
        return NULL;
    }
};
