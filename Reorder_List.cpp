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
    void reorderList(ListNode *head) {
        if(!head || !head->next) return;
        auto mid = getMid(head);
        
        auto h1 = head;
        auto h2 = reverse(mid->next);
        
        mid->next = nullptr;
        
        while(h1 && h2) {
            auto n1 = h1->next;
            auto n2 = h2->next;
            h1->next = h2;
            h2->next = n1;
            h1 = n1;
            h2 = n2;
        }
    }
private:
    // find the middle / tail element of a linked list
    ListNode* getMid(ListNode *head) {
        auto slow = head;
        auto fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }
        
        return slow;
    }
    
    // reverse a linked list
    // return head of the linked list
    ListNode* reverse(ListNode *head) {
        if(!head || !head->next) return head;
        
        auto prev = head;
        auto cur = head->next;
        auto next = cur;
        while(cur) {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        head->next = nullptr;
        
        return prev;
    }
};
