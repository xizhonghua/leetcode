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
    ListNode *insertionSortList(ListNode *head) {
        if(!head) return NULL;
        ListNode *v_head = new ListNode(INT_MIN);
        v_head->next = new ListNode(head->val);
        
        ListNode *cur = head->next;
        
        while(cur) {
            ListNode *ptr = v_head;
            while(ptr->next && ptr->next->val < cur->val) 
                ptr = ptr->next;
            
            ListNode *new_node = new ListNode(cur->val);
            
            if(ptr->next) 
                new_node->next = ptr->next;
            ptr->next = new_node;
            
            cur = cur->next;
        }
        
        ListNode* ans = v_head->next;
        delete v_head;
        
        return ans;
    }
};