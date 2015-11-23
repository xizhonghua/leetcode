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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *cur = head;
        
        if(head == NULL) return head;
        
        while(cur != NULL)
        {
            int val = cur->val;
            while(1)
            {
                
                if(cur->next && cur->next->val == val)            
                    cur->next = cur->next->next;
                else
                    break;
            }
            
            cur = cur->next;
        }
        
        return head;
    }
};