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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *l1 = new ListNode(0);
        ListNode *l2 = new ListNode(0);
        ListNode *h1 = l1, *h2 = l2;
        
        while(head)
        {
            if(head->val < x){
                l1->next = new ListNode(head->val);
                l1=l1->next;
            }
            else{
                l2->next = new ListNode(head->val);
                l2=l2->next;
            }            
            head = head->next;
        }
        
        l1->next = h2->next;
        
        return h1->next;
    }
};