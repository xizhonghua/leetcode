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
        if(!head) return NULL;
        auto slow = head;
        auto fast = head;
        
        while(fast)
        {
            if(!fast->next) return NULL;
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(!fast) return NULL;
            
            if(slow == fast) {
                break;
            }
        }
        
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast;
    }
};
